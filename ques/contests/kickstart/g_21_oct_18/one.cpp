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

// code begins here

void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    map<int,vector<int>> input;
    int ones = 0;
    int zeros = 0;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(vec[i] == 1) ones++;
        if(vec[i] == 0) zeros++;
    }
    sort(vec.begin(),vec.end());
    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int p = vec[i]*vec[j];
            if(vec[i] == 0 and vec[j] == 0) continue;
            if(vec[i] == 1 and vec[j] == 1) continue;
            count += upper_bound(vec.begin()+j,vec.end(),p) - lower_bound(vec.begin()+j,vec.end(),p);
        }
    }
    if(ones > 2)
       count += (ones*(ones-1)*(ones-2))/6;// 1 1 1
    if(zeros > 2)
       count += (zeros*(zeros-1)*(zeros-2))/6;// 0 0 0
    count += (zeros*(zeros-1)*(n-zeros))/2;// 0 0 a
    cout << "Case #" << _t << ": " ;
    cout << count << endl;
}

signed main(){
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("input","r",stdin);
    #endif
    int test=1;
    cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// a code by srbcheema1
