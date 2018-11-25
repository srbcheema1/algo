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

void process_str(string & temp) {
    while(sz(temp)<20) {
        temp = "0"+temp;
    }
}

int xorr_it(string a,string b) {
    int hell = 0;
    for(int i=0;i<20;i++) {
        int j = 20-i;
        if(a[i] != b[i]) hell+= (1<<j);
    }
    return hell;
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<string> str;
    for(int i=0;i<n;i++) {
        string temp;
        cin>>temp;
        process_str(temp);
        str.push_back(temp);
    }

    int l,r;
    string x;
    for(int i=0;i<q;i++) {
        cin>>l>>r>>x;
        process_str(x);
        l--;r--;
        int ans = l;
        int xorr = 0;
        for(int j=l;j<=r;j++) {
            show(i,j,str[j]);
            int temp = xorr_it(str[j],x);
            if(temp > xorr) {
                ans = j;
                xorr = temp;
            }
        }
        cout << ans + 1 << endl;
    }
}

void preprocess() {

}

signed main() {
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("input.txt","r",stdin);
    #endif
    std::cout << std::fixed; std::cout.precision(7);
    preprocess();
    int test=1;
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
