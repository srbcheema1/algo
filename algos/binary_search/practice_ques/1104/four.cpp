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

bool solve()
{
    int a = 0,d = 1;
    string v;
    cin>>v;
    while(true) {
        cout << "? " << a << " " << a+d << endl;
        cin>>v;
        if(v=="x") {
            int l = a+1,r = a+d;
            int ans = r;
            while(l<=r) {
                int mid = (l+r)/2;
                cout << "? " << a << " " << mid << endl;
                cin>>v;// verdict read
                if(v=="y") {// changed
                    l = mid+1;
                } else {// same sign
                    ans = mid;
                    r = mid-1;// done
                }
            }
            cout << "! " << ans << endl;
            cin>>v;
            if(v=="end") {
                return true;
            }
            if(v=="e" or v=="mistake") return false;
            a = 0,d = 1;
            continue;
        }
        if(v=="y") { }
        if(v=="mistake" or v=="e"){
            return false;
        }
        a = a+d;
        d*=2;
    }
}

signed main()
{
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("Input.txt","r",stdin);
    #endif
    assert(solve());
}
// a code by srbcheema1

// https://codeforces.com/contest/1104/problem/D
// https://codeforces.com/contest/1104/submission/48773414
