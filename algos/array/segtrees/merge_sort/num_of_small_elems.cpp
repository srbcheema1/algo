#include<bits/stdc++.h>
using namespace std;

#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cout<<" "
#define endl "\n"
#define int long long
#define substring(i,j) substr(i,(j-i+1)) // both i,j are included

#ifdef ONLINE_JUDGE
#define DEBUG 0.0
#else
#define DEBUG 1
#endif
int debug = DEBUG;// it will take care of itself on online-judge
int debug_test = 0; // test_case to be debugged ... 0 means all ... -1 means none
int _t = 0;// test_case counter

#define umap unordered_map
#define pqueue priority_queue
typedef unsigned long long ulli;// rarely will be used
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix; // matrix matt(n,vector<int>(m,0));

template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort // templated
template<class T,class U>bool found(T t,U u){if(t.find(u)==t.end())return false;return true;}

// helping templates ignore them
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T>void _p(T x){int i=0;for(auto a: x){dout<<a<<",";if(i++ > 20)break;}}
template<class T,class U>ostream &operator<<(ostream &o,pair<T,U> &x){return o<<"("<<x.first<<","<<x.second<<")";}
template<class T>ostream &operator<<(ostream &os,vector<T> &x){dout<<"[";_p(x);dout<<"] ";return os;}
template<class T>ostream &operator<<(ostream &os,set<T> &x){dout<<"{";_p(x);dout<< "} ";return os;}

const int mod = 1e9+7, inf = LLONG_MAX;
int temp = -1,last = -1,hell=-1;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// code begins here
int N = 2e5+9;
vector<int> vec(N);
vector<vector<int>> tree(4*N);

void make_tree(int st,int ed,int i) {
    if(st == ed) {
        tree[i].push_back(vec[st]);
        return;
    }

    int mid = (st+ed)/2;
    make_tree(st,mid,2*i);
    make_tree(mid+1,ed,2*i+1);

    merge(tree[2*i].begin(),tree[2*i].end(),tree[2*i+1].begin(),tree[2*i+1].end(),back_inserter(tree[i]));
}

int query (int l, int r, int st, int ed, int i, int n) {
    if(l==st and r==ed) {
        return lower_bound(tree[i].begin(),tree[i].end(),n) - tree[i].begin();
    }

    int mid = (st+ed)/2;
    if(r <= mid) return query(l,r,st,mid,2*i,n);
    if(l > mid) return query(l,r,mid+1,ed,2*i+1,n);

    return query(l,mid,st,mid,2*i,n) + query(mid+1,r,mid+1,ed,2*i+1,n);
}

void solve(){
    //dout << "Case #" << _t << ": " << endl;
    int n,t;
    cin>>n>>t;
    vec[0] = 0;
    for(int i=1;i<=n;i++) {
        cin>>temp;
        vec[i] = vec[i-1] + temp;
    }

    make_tree(1,n,1);

    int ans = 0;
    for(int i=1;i<=n;i++) {
        temp = query(i,n,1,n,1,vec[i-1]+t);
        show(temp);
        ans += temp;
    }
    cout << ans << endl;
}

signed main(){
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    std::cout << std::fixed; std::cout.precision(7);
    #else
    //freopen("input","r",stdin);
    #endif
    int test=1;
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// a code by srbcheema1

// https://codeforces.com/contest/1042/problem/D
