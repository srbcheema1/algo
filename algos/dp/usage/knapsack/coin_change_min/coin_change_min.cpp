// https://www.hackerrank.com/contests/justcode/challenges/minimum-number-of-coins-for-possible-sum/problem
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

const int mod = 1e9+7, inf = LLONG_MAX, big = inf/4+9;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// manual.begin

int n;
int arr[123456];
int get_min(int v) {// best way
    /*
     * time : v*arr.size()
     * space : v
     */
    vector<int> dp(v+1,INT_MAX);
    dp[0] = 0;// it take 0 elems to make val 0
    for(int i=1;i<=v;i++) {
        for(int j=0;j<n;j++)
            if(i>=arr[j] and dp[i-arr[j]]!=INT_MAX) dp[i] = min(dp[i],1+dp[i-arr[j]]);
    }
    return dp[v];
}

const int V = 256329;
const int N = 100;
int dp[V][N];
int get_min2(int v, int i) {// 2nd best way
    /*
     * time: v*arr.size()
     * space v*arr.size()
     */
    if(v==0) return 0;
    if(v<0) return mod;
    if(i >= n) return mod;

    int &dpp = dp[v][i];
    if(dpp != -1) return dpp;
    return dpp = min(get_min2(v-arr[i],i)+1,get_min2(v,i+1));
}

int get_min3(int v) {// worst
    /*
     * time : n^2
     * space : n
     */
    vector<int> dp(V,big);
    vector<bool> arr(V,false);
    for(int i=0;i<n;i++) arr[::arr[i]] = true;

    for(int i=1;i<=v;i++) {
        if(arr[i]){
            dp[i] = 1; continue;
        }
        for(int j=1;j<i;j++) {
            if(arr[i-j] and dp[j]!=big) dp[i] = min(dp[i],dp[j]+1);
        }
    }
    return dp[v];
}

void solve() {
    int v,ans; // v is total value, n is number of arr coins
    cin>>n>>v;
    for(int i=0;i<n;i++) cin>>arr[i];

    memset(dp,-1,sizeof dp);
    ans =  get_min2(v,0);
    assert(ans==get_min(v));
    if(ans >= mod) cout << -1 << endl;
    else cout << ans << endl;
}
//manual.end

signed main()
{
    int t=1;
    //cin>>t;
    while(t--) solve();
}
//https://www.hackerrank.com/contests/justcode/challenges/minimum-number-of-coins-for-possible-sum/submissions/code/1312694350
//this code is passing there but SEG-Fault locally due to large stack size (while using get_min)
/*
6 256324
1 2 5 10 20 50

5129
*/

/* TAGS
 * minimum number of coins for possible sum
 * https://www.hackerrank.com/contests/justcode/challenges/minimum-number-of-coins-for-possible-sum/problem
 * https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
 */
