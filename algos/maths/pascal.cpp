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

// manual.begin
int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}
int power(int x,int y){
    int res=1; //x^y
    while(y){
        if(y&1) res=mul(res,x);
        x=mul(x,x);
        y=y>>1;
    }
    return res;
}
const int NN=1000+9;
int pw2[NN];
int fact[NN],invf[NN];
void build_pascal(){// for NN >= 1000
    pw2[0]=1;
    for(int i=1;i<NN;i++) pw2[i]=mul(pw2[i-1],2);

    fact[0]=1,invf[0]=power(fact[0],mod-2);

    for(int i=1;i<NN;i++) fact[i]=mul(i,fact[i-1]), invf[i]=power(fact[i],mod-2);
}

int pascal[NN][NN]; // for NN upto 1000
void build_pascal_small(){
    pascal[0][0] = pascal[1][0] = pascal[1][1] = 1;
    for(int i=2;i<NN;i++) {
        pascal[i][0] = pascal[i][i] = 1;
        for(int j=1;j<i;j++) {
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            pascal[i][j] %= mod;
        }
    }
}
int C(int n,int r){
    return pascal[n][r]; // for NN upto 1000
    return mul(mul(fact[n],invf[r]),invf[n-r]);// for NN >= 1000 // this one is twice slower
}

signed main(){
    cout << C(10,5) << endl;
}
//manual.end

/*
 * tested on https://www.codechef.com/viewsolution/21531255 // big_pascal
 * tested on https://www.codechef.com/viewsolution/21531245 // small_pascal
 */
/* TAGS
 *
 */
