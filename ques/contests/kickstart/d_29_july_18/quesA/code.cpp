#include<bits/stdc++.h>
#define dout if(debug) cout<<" "
using namespace std;

// https://code.google.com/codejam/contest/6364486/dashboard
// proble A. Candies

#ifndef ONLINE_JUDGE
#define DEBUG 0
#else
#define DEBUG 0.0
#endif
int debug = DEBUG;// it will take care of itself on online-judge

typedef long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix; // matrix matt(n,vector<int>(m,0));

const int mod = 1e9+7;

#define int ulli

template<class T>int sz(T &x){return (int)x.size();}
template <typename T>void show(T first){dout << first << "\n";}
template <typename T, typename... Args>void show(T first, Args... args){dout << first; show(args...);}
template<class T,class U>ostream &operator<<(ostream &os,pair<T,U> &x){return os<<x.first<<","<<x.second;}
struct Desc{bool operator()(int a,int b){return a>b;} }desc; // for descending sort

// mst begins here
const int nn = 2e6;// size of vec being used
vector<int> tree[4*nn];
void build_tree(int l, int r,vector<int> &vec, int i=1){
    // call it as build(1,n,vec);
    // vec is 1 based
    if(l==r){
        tree[i].push_back(vec[l]);
        return;
    }
    int mid = (l+r)>>1;
    build_tree(l,mid,vec,2*i);
    build_tree(mid+1,r,vec,2*i+1);

    // merge into tree[i]
    merge(tree[2*i].begin(),tree[2*i].end(),tree[2*i+1].begin(),tree[2*i+1].end(),back_inserter(tree[i]));
}

int query(int s,int e, int l, int r, int k, int i=1){
    /*
     * call it as query(1,vec.size(),l,r,k);
     * returns element just smaller than k in given range
     * INT_MIN if all elements are larger than k
     */
    if(l==s and r==e){
        int pos = lower_bound(tree[i].begin(),tree[i].end(),k) - tree[i].begin();// pos of first elem not less than k
        if(pos == 0) return INT_MIN;// no elem less than k
        if(pos == (int)tree[i].size()) return *tree[i].rbegin();// all are smaller return last elem
        return tree[i][pos-1];
    }

    int mid = (s+e)/2;
    if(mid < l)return query(mid+1,e,l,r,k,2*i+1);
    if(mid >= r) return query(s,mid,l,r,k,2*i);
    return max(query(s,mid,l,mid,k,2*i),query(mid+1,e,mid+1,r,k,2*i+1));
}
// mst ends here

void print(int t,int ans){
    if(ans == INT_MIN) cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
    else cout << "Case #" << t << ": " << ans << endl;
}
void preprocess(int n){
    for(int i=0;i<=4*n;i++)tree[i].clear();
}

int temp = -1,last = -1, n = 0;
void solve(int t){
    int n,o,d;
    cin>>n>>o>>d;
    int x1,x2,a,b,c,m,l;
    cin>>x1>>x2>>a>>b>>c>>m>>l;
    vector<int> vec(n+1);
    vector<int> odd(n+1);
    vector<int> prefix(n+1);

    vec[1] = x1; vec[2] = x2;
    for(int i=3;i<=n;i++)
        vec[i] = (a*vec[i-1] + b*vec[i-2] + c) %m;
    for(int i=1;i<=n;i++)
        vec[i]+=l;
    for(int i=1;i<=n;i++){
        prefix[i] = prefix[i-1]+vec[i];
        odd[i] = odd[i-1];
        if(vec[i]%2) odd[i]++;
    }

	preprocess(n);
    build_tree(1,n,prefix);
    int maxx = INT_MIN;
    for(int i=1;i<=n;i++){
        int pos_r,pos_l = i;
        if(vec[i]%2==0) pos_r = lower_bound(odd.begin(),odd.end(),odd[i]+o+1) - odd.begin() - 1;
        else pos_r= lower_bound(odd.begin(),odd.end(),odd[i]+o) - odd.begin() - 1;
        if(o == 0 and vec[i]%2)continue;
        int ans = query(1,n,pos_l,pos_r,prefix[pos_l-1]+d+1);
        if(ans != INT_MIN) ans -= prefix[pos_l-1];
        maxx = max(ans,maxx);
    }
    if(maxx == INT_MIN) print(t,INT_MIN);
    else print(t,maxx);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // freopen("input","r",stdin);
    cin>>t;
    int T = t;
    while(t--)solve(T-t);
}
