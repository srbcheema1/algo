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
typedef long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix; // matrix matt(n,vector<int>(m,0));
#define int ulli

const int mod = 1e9+7;

template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T,class U>ostream &operator<<(ostream &os,pair<T,U> &x){return os<<x.first<<","<<x.second;}
template<class T>void print(T first,T last){for(auto it = first;it != last;it++)dout<<*it;dout<<endl;}
template<class T>void print(T container){print(container.begin(),container.end());}; // print(vec);
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort // templated
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

int temp = -1,last = -1,hell=-1;
bool good=true,bad=false;

void solve(){
    //dout << "Case #" << _t << ": " << endl;
    int n;
    cin>>n;
    vector<int> vec(32000,mod);
    vector<int> arr(32000,mod);

    arr[0] = 0;
    arr[1] = 1;
    for(int i=2;i<32000;i++) {
        arr[i] = arr[i-1] *2;
        if(arr[i] > mod) break;
    }

    vec[0]=0;
    for(int i=1;i<32000;i++) {
        vec[i] = vec[i-1] + arr[i];
        if(vec[i] > mod) break;
    }

    int ans = lower_bound(vec.begin(),vec.end(),n) - vec.begin();
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    //freopen("input","r",stdin);
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
