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

const int mod = 1e9+7, inf = LLONG_MAX, big = inf/4+9;
int temp = -1,last = -1,hell=-1;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// manual.begin

int dp[100000][100];
int get_min(int n, int i, vector<int> &avail) {
    /*
     * time: n*avail
     * space n*avail
     *
     * better for n > 10000 and avail small (say their product < n^2)
     */
    if(n==0) return 0;
    if(n<0) return big;
    if(i >= (int)avail.size()) return big;

    int &dpp = dp[n][i];
    if(dpp != -1) return dpp;

    int a = get_min(n-avail[i],i,avail)+1;
    int b = get_min(n,i+1,avail);

    if (a>=big and b>=big) dpp = big;
    else if (a>=big) dpp = b;
    else if (b>=big) dpp = a;
    else dpp = min(a,b);

    return dpp;
}

int get_min_space_optimized(int n,vector<int> &_avail) {
    /*
     * time : n^2
     * space : n
     *
     * better for small n say n < 100
     */
    vector<int> dp(10009,big);
    vector<bool> avail(10009,false);
    for(int i=0;i<(int)_avail.size();i++) {
        avail[_avail[i]] = true;
    }

    for(int i=1;i<=n;i++) {
        if(avail[i]){
            dp[i] = 1; continue;
        }
        for(int j=1;j<i;j++) {
            if(avail[i-j] and dp[j]!=big) {
                dp[i] = min(dp[i],dp[j]+1);
            }
        }
    }
    return dp[n];
}


signed main(){
    int n,m; // n is main coin, m is number of avail
    cin>>m>>n;
    vector<int> avail(m);
    for(int i=0;i<m;i++)
        cin>>avail[i];

    memset(dp,-1,sizeof dp);
    int ans =  get_min(n,0,avail);
    //int ans =  get_min_space_optimized(n,avail);
    if(ans >= big) cout << -1 << endl;
    else cout << ans << endl;
}
//manual.end

/* TAGS
 * minimum number of coins for possible sum
 * https://www.hackerrank.com/contests/justcode/challenges/minimum-number-of-coins-for-possible-sum/problem
 * https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
 */
