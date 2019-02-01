#include<bits/stdc++.h>
using namespace std;

// clang-format off
#define int long long
#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cerr<<" "
#define endl "\n";cout.flush()
#ifdef ONLINE_JUDGE
#define DEBUG 0.0
#else
#define DEBUG 1
#endif
int debug = DEBUG;// it will take care of itself on online-judge
int debug_test = 0; // test_case to be debugged ... 0 means all ... -1 means none
int _t = 0;// test_case counter

template<class T>void show(T first){dout<<first<<"\n";}
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
#define trace(...) _s(#__VA_ARGS__, __VA_ARGS__)
template<class T>void _s(const char* c,T& first){dout<<c<<" : "<<first<<"\n";}
template<class T,class... Args>void _s(const char *c,T first,Args... args)
{const char* t=strchr(c+1,',');dout;if(debug)cerr.write(c,t-c)<<" : "<<first<< " |";_s(t+1,args...);}
template<class T>void _p(T x){int i=0;for(auto a: x){dout<<a<<",";if(i++ > 20)break;}}
template<class T,class U>ostream &operator<<(ostream &o,pair<T,U> &x){return o<<"("<<x.first<<","<<x.second<<")";}
template<class T>ostream &operator<<(ostream &os,vector<T> &x){dout<<"[";_p(x);dout<<"] ";return os;}
template<class T>ostream &operator<<(ostream &os,set<T> &x){dout<<"{";_p(x);dout<< "} ";return os;}

typedef unsigned long long ulli;// rarely will be used
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef set<int> si;
template<class A,class B> using umap = unordered_map<A,B>;
template<class A,class B> using pqueue = priority_queue<A,vector<A>,B>;
typedef vector<vector<int>> matrix; // matrix matt(n,vector<int>(m,0));
#define dmatrix(n,m) matrix(n,vector(m,0)) // to define matrix use dmatrix(n,m)
#define substring(i,j) substr(i,(j-i+1)) // both i,j are included
#define all(container) container.begin(),container.end()
#define FF first
#define SS second

template<class T>int sz(T &x){return (int)x.size();}
template<class T>bool sort_fun(T a,T b){return a>b;} // for desc sort // default sort is asc, use <() fxn
template<class T,class U>bool found(T t,U u){if(t.find(u)==t.end())return false;return true;}
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort
struct AscPQ{bool operator()(int a,int b){return a>b;}}; // for ascending PQ, does descending by default

const int mod = 1e9+7, inf = ((1LL<<((sizeof mod)*8-2))-1)<<1|1, none = inf/2-9;// inf is self adjustable
int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}
int dx[] = {0,1,0,-1,1,1,-1,-1},dy[] = {1,0,-1,0,1,-1,-1,1};// use 0-3 for 4dir 0-7 for 8dir
// clang-format off

// manual.begin
const int N = 2e6;// size of vec being used
int arr[N];
vector<int> mst[4*N];
#define full(container) container.begin(),container.end()
void build_tree(int l, int r, int i=1) { // build(1,n);
    if(l==r){
        mst[i].push_back(arr[l]);
        return;
    }
    int mid = (l+r)>>1;
    build_tree(l,mid,i<<1);
    build_tree(mid+1,r,i<<1|1);
    merge(full(mst[i<<1]),full(mst[i<<1|1]),back_inserter(mst[i]));
}
int query(int l,int r, int s, int e, int k, int i=1){ // query(1,n,l,r,k);
    if(l==s and r==e){
        int pos = lower_bound(full(mst[i]),k) - mst[i].begin();// pos of first elem not less than k
        if(pos==0) return 0;// no elem less than k
        if(pos == (int)mst[i].size()) return pos;// all are smaller than k
        return pos;
    }
    int mid = (l+r)>>1;
    if(e<=mid) return query(l,mid,s,e,k,i<<1);
    if(s>mid) return query(mid+1,r,s,e,k,i<<1|1);
    return query(l,mid,s,mid,k,i<<1)+query(mid+1,r,mid+1,e,k,i<<1|1);
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    build_tree(1,n);
    while(q--){
        int a,b,k; // range a to b number of elems less than k
        cin>>a>>b>>k;
        int ans =  query(1,n,a,b,k);
        cout << ans << endl;
    }
}

void preprocess() {

}
// manual.end

signed main(){
    solve();
}

/* TAGS
 * number just less than k in given range
 * numbers smaller than k in given range
 * merge sort
 * merge_sort
 */
