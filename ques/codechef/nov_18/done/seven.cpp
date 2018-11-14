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

int good;
int rec(int n,bool first_time=false) {
    if(n==2) return 1;
    if(first_time and n%2==0) { // n is even
        int mid = n/2;
        if(mid & 1) { // odd
            return rec(n-mid+1) +1;
        }
    }
    return rec((n+1)/2) + 1;
}

int rem(int n,int k,bool first_time = false) {
    if(k==0) return n;
    if(first_time and n%2==0) { // n is even
        int mid = n/2;
        if(mid & 1) { // odd
            return rem(n-mid+1,k-1);
        }
    }
    return rem((n+1)/2,k-1);
}

void solve(){
    int n,k;
    cin>>n>>k;
    if(n==1) {
        cout << 1.0 << endl;
        return;
    }
    if(n==2) {
        cout << 0.5 << endl;
        return;
    }

    good = 0;
    int how = rec(n,true);
    if(k>= how) {
        cout << 1.0 << endl;
        return;
    }

    double ans = 1.0;
    int left = rem(n,k,true);
    ans /= left;
    cout << ans << endl;
}

signed main() {
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("input.txt","r",stdin);
    #endif
    std::cout << std::fixed; std::cout.precision(7);
    int test=1;
    cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
