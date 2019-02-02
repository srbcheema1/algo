#include<bits/stdc++.h>
#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cout<<" "
#define endl "\n"
using namespace std;

#ifdef ONLINE_JUDGE
#define DEBUG 0.0
#else
#define DEBUG 1
#endif
int debug = DEBUG;// it will take care of itself on online-judge
int debug_test = 0; // test_case to be debugged ... 0 means all ... -1 means none
int _t = 0;

#define umap unordered_map
#define pqueue priority_queue
#define int lli
typedef long long lli;
typedef unsigned long long ulli;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix; // matrix matt(n,vector<int>(m,0));

const int mod = 1e9+7;

template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T,class U>ostream &operator<<(ostream &os,pair<T,U> &x){return os<<x.first<<","<<x.second;}
template<class T>void print(T first,T last){for(auto it = first;it != last;it++)dout<<*it;dout<<endl;}
template<class T>void print(T container){print(container.begin(),container.end());}; // print(vec);
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort // templated
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort
// manual.begin

#define dpp dp[n][i]

const int N = 1009;
int dp[N][N];

/*
Given n and avail array. you have to tell the number of ways in which n can be exchanged.
input format:
n m
list avail of length m
*/

int rec(int n,int i,vector<int> &avail) {
    /*
     * time : n*avail
     * space : n*avail
     */
    if (n<0) return 0;
    if (n==0) return 1;
    if (i==(int)avail.size()) return 0;

    if (dpp !=-1) return dpp;

    dpp = rec(n,i+1,avail)+rec(n-avail[i],i,avail);
    return dpp;
}

int better_way(int n,vector<int> &avail) {
    /*
     * time : n*avail
     * space : n
     */
    vector<int> vec(n+1,0);
    vec[0] = 1;
    for(int i=0;i<(int)avail.size();i++)
        for(int j=avail[i];j<=n;j++)
            vec[j] += vec[j-avail[i]];

    return vec[n];
}

signed main() {
    int n,m;
    cin>>n>>m;
    vector<int> avail(m);
    for(int i=0;i<m;i++)
        cin>>avail[i];

    memset(dp,-1,sizeof dp);
    int ans_1 = rec(n,0,avail);
    cout << ans_1 << endl;

    int ans_2 = better_way(n,avail);
    cout  << ans_2 << endl;
}

//manual.end

/* TAGS
 * coin change
 * dp
 * https://www.hackerrank.com/challenges/coin-change/problem
 */
