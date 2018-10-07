#include<bits/stdc++.h>
using namespace std;

#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cout<<" "
#define endl "\n"
#define int long long
#define substring(i,j) substr(i,(j-i+1))

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

template<class T>void _p(T x){int i=0;for(auto a: x){dout<<a<<",";if(i++ > 20)break;}}
template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T,class U>ostream &operator<<(ostream &o,pair<T,U> &x){return o<<"("<<x.first<<","<<x.second<<")";}
template<class T>ostream &operator<<(ostream &os,vector<T> &x){dout<<"[";_p(x);dout<<"] ";return os;}
template<class T>ostream &operator<<(ostream &os,set<T> &x){dout<<"{";_p(x);dout<< "} ";return os;}
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort // templated

const int mod = 1e9+7, inf = LLONG_MAX;
int temp = -1,last = -1,hell=-1;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// code begins here

void solve(){
    cout << "Case #" << _t << ": ";
    //dout << endl;
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    set<string> sett;
    for(int i=0;i<n;i++) {
        for(int j = i;j<n;j++) {
            string temp = b.substr(i,j-i+1);
            sort(temp.begin(),temp.end());
            sett.insert(temp);
        }
    }

    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j = i;j<n;j++) {
            //string temp = a.substr(i,j-i+1);
            string temp = a.substring(i,j);
            sort(temp.begin(),temp.end());
            if(sett.find(temp) != sett.end()) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    //freopen("input","r",stdin);
    cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// a code by srbcheema1
