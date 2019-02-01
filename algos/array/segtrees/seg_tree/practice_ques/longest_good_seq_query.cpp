#include<bits/stdc++.h>
using namespace std;

#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cerr<<" "
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

#define all(container) container.begin(),container.end()
#define umap unordered_map
#define pqueue priority_queue // kept them macro coz we need to use <> also
typedef unsigned long long ulli;// rarely will be used
typedef pair<int,int> mp;
typedef vector<int> vi;
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

const int mod = 1e9+7, inf = LLONG_MAX, none = inf/2-9;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// code begins here

const int N = 2e5+9;
vector<int> vec(2*N,0);
vector<int> tree(4*N,0);
vector<int> tree_l(4*N,0);
vector<int> tree_r(4*N,0);
vector<int> cap(4*N,0);

void build_tree(int l, int r, int i) {
    if(l==r) {
        tree[i] = vec[l];
        cap[i] = 1;
        if(vec[l]) tree_l[i] = 1,tree_r[i] = 1;
        return;
    }

    int mid = (l+r)/2;
    build_tree(l,mid,2*i);
    build_tree(mid+1,r,2*i+1);

    // merging
    cap[i] = cap[2*i] + cap[2*i+1];
    if(tree[2*i] == cap[2*i] and tree[2*i+1] == cap[2*i+1]) {
        tree[i] = cap[i];
        tree_l[i] = cap[i];
        tree_r[i] = cap[i];
        return;
    }
    if(tree[2*i] == cap[2*i]) {
        tree[i] = max(tree_r[2*i] + tree_l[2*i+1], tree[2*i+1]);
        tree_l[i] = tree_r[2*i] + tree_l[2*i+1];
        tree_r[i] = tree_r[2*i+1];
        return;
    }
    if(tree[2*i+1] == cap[2*i+1]) {
        tree[i] = max(tree_r[2*i] + tree_l[2*i+1], tree[2*i]);
        tree_l[i] = tree_l[2*i];
        tree_r[i] = tree_r[2*i] + tree_l[2*i+1];
        return;
    }
    tree[i] = max(tree_r[2*i] + tree_l[2*i+1], max(tree[2*i],tree[2*i+1]) );
    tree_l[i] = tree_l[2*i];
    tree_r[i] = tree_r[2*i+1];
    return;
}

struct res {
    int l,a,r,c;
};

res query(int l,int r,int st,int ed,int i) {
    if(l==st and r==ed) {
        return {tree_l[i],tree[i],tree_r[i],r-l+1};
    }

    int mid = (st+ed)/2;
    if(r<=mid) return query(l,r,st,mid,2*i);
    if(l>mid) return query(l,r,mid+1,ed,2*i+1);

    res ans_l = query(l,mid,st,mid,2*i);
    res ans_r = query(mid+1,r,mid+1,ed,2*i+1);

    res ret{0,max(ans_l.r + ans_r.l,max(ans_l.a,ans_r.a)),0,ans_l.c + ans_r.c};
    ret.l = ans_l.l;
    ret.r = ans_r.r;
    if(ans_l.l == ans_l.c) ret.l = ans_l.l + ans_r.l;
    if(ans_r.r == ans_r.c) ret.r = ans_r.r + ans_l.r;
    return ret;
}

void solve() {
    int n,q,k;
    cin>>n>>q>>k;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        vec[n+i] = vec[i];
    }

    build_tree(0,2*n-1,1);
    query(8,13,8,15,3);
    string str;
    cin>>str;
    int l = n,r = n+ n-1;
    for(auto a: str) {
        if(a == '?') {
            show(l,r);
            cout << min(query(l,r,0,2*n-1,1).a,k) << endl;
        } else {
            l--;r--;
            if(l==0) {
                l = n; r = n+n-1;
            }
        }
    }
}

void preprocess() {

}

signed main() {
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("input.txt","r",stdin);
    #endif
    std::cout << std::fixed; std::cout.precision(7);
    preprocess();
    int test=1;
    // cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// a code by srbcheema1

// Note this was not a question of seggie. it could have been done easily
//https://www.codechef.com/NOV18B/problems/HMAPPY1
