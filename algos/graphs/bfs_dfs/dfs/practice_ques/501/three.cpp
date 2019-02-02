#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cerr<<" "
#define endl "\n";cout.flush()
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
typedef set<int> si;
typedef vector<vector<int>> matrix; // matrix matt(n,vector<int>(m,0));

template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort // normally sory is ascending, use <() fxn
template<class T,class U>bool found(T t,U u){if(t.find(u)==t.end())return false;return true;}

// helping templates ignore them
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T>void _p(T x){int i=0;for(auto a: x){dout<<a<<",";if(i++ > 20)break;}}
template<class T,class U>ostream &operator<<(ostream &o,pair<T,U> &x){return o<<"("<<x.first<<","<<x.second<<")";}
template<class T>ostream &operator<<(ostream &os,vector<T> &x){dout<<"[";_p(x);dout<<"] ";return os;}
template<class T>ostream &operator<<(ostream &os,set<T> &x){dout<<"{";_p(x);dout<< "} ";return os;}

const int mod = 1e9+7, inf = LLONG_MAX, none = inf/2-9;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort, PQ does descending sort by default
// clang-format off

// code begins here

struct Node{
    int i,d,x;
}node[1<<17];

struct Sort_q{
    bool operator()(int a,int b) { return node[a].d > node[b].d; }
};
struct Sort_v{
    bool operator()(int a,int b) { return node[a].d < node[b].d; }
}sort_v;

vector<mp> ans;
void dfs(int a) {
    if(node[a].d != 1) return;
    node[a].d--;
    int next = node[a].x;
    node[next].d --;
    node[next].x ^= a;
    node[a].x ^= next;
    ans.push_back({a,next});
    dfs(next);
}

void solve()
{
    int n;
    cin>>n;
    vector<int> ind(n);
    for(int i=0;i<n;i++){
        cin>>node[i].d>>node[i].x;
        node[i].i = i;
        ind[i] = i;// o index = 1
    }

    sort(all(ind),sort_v);
    for(auto a: ind) show(node[a].i,node[a].d,node[a].x);

    while(sz(ind)) {
        vi temp(all(ind));
        ind.clear();
        for(auto a: temp) {
            if(node[a].d==0) continue;
            ind.push_back(a);
        }
        for(int i=0;i<sz(ind);i++) {
            int a = ind[i];
            dfs(a);
        }
    }

    cout << sz(ans) << endl;
    for(auto a: ans) {
        cout << a.first << " " << a.second << endl;
    }
}

void preprocess()
{

}

signed main()
{
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("Input.txt","r",stdin);
    #endif
    std::cout << std::fixed; std::cout.precision(7);
    preprocess();
    int test=1;
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// a code by srbcheema1

// https://codeforces.com/contest/501/problem/C
