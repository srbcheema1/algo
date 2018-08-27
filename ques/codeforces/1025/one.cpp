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

typedef unsigned long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix; // matrix matt(n,vector<int>(m,0));

const int mod = 1e9+7;

template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T,class U>ostream &operator<<(ostream &os,pair<T,U> &x){return os<<x.first<<","<<x.second;}
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

vector<char> vec(1e6);
int temp = -1,last = -1;
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    map<int,int> mapp;
    for(int i=0;i<n;i++){
        mapp[str[i]-'a']++;
    }
    int ct = 0;
    for(auto a: mapp){
        if(a.second > 1)ct++;
    }
    if(ct == 0 and n!=1)cout << "No" << endl;
    else cout << "Yes" << endl;

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    //freopen("input","r",stdin);
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
