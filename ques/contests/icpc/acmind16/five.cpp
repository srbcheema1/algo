#include<bits/stdc++.h>
using namespace std;

#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cerr<<" "
#define fcout if(fdebug) cout<<" "

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
bool fdebug = false;

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
int temp = -1,last = -1,hell=-1;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// code begins here

set<int> Factors(int a){
    set<int> ret;
    for(int i=2;i*i<=a;i++) {
        if(a%i==0) ret.insert(i),ret.insert(a/i);
    }
    ret.insert(a);
    ret.insert(1);
    return ret;
}

const int N = 750009;
int dp[N];
matrix factors(N,vector<int>());
//matrix divisors(N,vector<int>());
vector<bool> avail(N,false);

int rec(int a){
    int &dpp = dp[a];
    if(dpp != -1) return dpp;

    auto &vec = factors[a];
    dpp = 0;
    for(auto i: vec) {
        if(not avail[i]) continue;
        if(i==a) continue;
        dpp = (dpp + rec(i))%mod;
    }
    dpp = (dpp + 1)%mod;
    return dpp;
}

void solve(){
    // never forget sorting input
    memset(dp, -1 , sizeof dp);
    std::fill(all(avail),false);

    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i],avail[vec[i]] = true;

    int ans = 0;
    for(int i=0;i<n;i++) {
        ans += rec(vec[i]);
        show(vec[i],dp[vec[i]]);
        ans %= mod;
    }
    cout << ans << endl;
}

void preprocess() {
    for(int i=1;i<N;i++) {
        for(int j=i;j<N;j+=i) {
            factors[i].push_back(j);
        }
    }
}

signed main() {
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("input","r",stdin);
    #endif
    std::cout << std::fixed; std::cout.precision(7);
    int test=1;
    cin>>test;
    preprocess();
    for(int t = 1; t <= test; t++)_t = t,solve();
}
