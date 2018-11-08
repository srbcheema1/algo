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

const int N = 100;
int sx,sy,si;// starting x y and init-energy
int dp[N][N];
int vec[N][N];
int x_max,y_max; // max point of x and y

bool good_x (int x) {
    if(x<0 and x>x_max) return false;
    return true;
}

bool good_y (int y) {
    if(y<0 and y>y_max) return false;
    return true;
}


int rec(int x,int y) {
    // edge contidions
    if(x == sx and y == sy) return si;
    if(x < 0 or x> x_max or y< 0 or y>y_max) return -inf;

    // pre calculated
    int &dpp = dp[x][y];
    if(dpp != -1) return dpp;

    // calculate best ans as if  x,y was exit point.
    int l = -inf,r = -inf,u = -inf,d = -inf;
    if(good_x(x-1) and good_y(y))
        l = rec(x-1,y) - vec[x-1][y];
    if(good_x(x+1) and good_y(y))
        r = rec(x+1,y) - vec[x+1][y];
    if(good_x(x) and good_y(y+1))
        u = rec(x,y+1) - vec[x][y+1];
    if(good_x(x) and good_y(y-1))
        d = rec(x,y-1) - vec[x][y-1];

    return dpp = max(max(l,r),max(u,d));
}

void solve(){
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
