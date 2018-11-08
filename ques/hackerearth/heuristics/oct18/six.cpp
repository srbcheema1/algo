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
int temp = -1,last = -1,hell=-1;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// code begins here

map<string,int> mapp0,mapp1;
string a = "XXS";
string b = "XS";
string c = "S";
string d = "M";
string e = "L";
string f = "XL";
string g = "XXL";

void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    mapp0[a] = 0;
    mapp0[b] = 0;
    mapp0[c] = 0;
    mapp0[d] = 0;
    mapp0[e] = 0;
    mapp0[f] = 0;
    mapp0[g] = 0;

    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        mapp0[str]++;
    }
    for(int i=0;i<n;i++){
        cin>>str;
        mapp0[str]--;
    }
    int sum = 0;
    for(auto a: mapp0) {
        if(a.second < 0) sum += -a.second;
        else sum+= a.second;
    }
    cout << sum/2 << endl;

}

void preprocess(){

}

signed main(){
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("input.txt","r",stdin);
    #endif
    std::cout << std::fixed; std::cout.precision(7);
    preprocess();
    int test=1;
    cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// a code by srbcheema1
