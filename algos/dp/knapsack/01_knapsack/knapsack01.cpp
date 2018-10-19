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

// manual.begin
const int N = 100009;
vector<int> value(N,0);
vector<int> weight(N,0);

const int max_weight = 1000;
const int avail_size = 100;
int dp[max_weight][avail_size];

int rec(int w, int i, int n) {
    /*
     * time : max_weigiht * avail_size
     * memory : max_weigiht * avail_size
     */
    if(w<0) return -none;
    if(w==0) return 0;
    if(i>=n) return 0; // coz we dont want bag to be full

    int &dpp = dp[w][i];
    if(dpp !=-1) return dpp;

    int a = rec(w-weight[i],i+1,n) + value[i]; // for single instance of i
    //int a = rec(w-weight[i],i,n) + value[i]; // for infinite instances of i
    int b = rec(w,i+1,n);

    if(a < -1 and b < -1) dpp = -none;
    else if(a < -1 ) dpp = b;
    else if(b < -1 ) dpp = a;
    else dpp = max(a,b);
    return dpp;
}

signed main(){
    int n,w;
    cin>>n>>w;
    for(int i=0;i<n;i++) {
        cin>>value[i];
    }
    for(int i=0;i<n;i++) {
        cin>>weight[i];
    }

    memset(dp,-1,sizeof dp);
    cout << rec(w,0,n) << endl;
}
//manual.end

/* TAGS
 * 01 knapsack
 */
