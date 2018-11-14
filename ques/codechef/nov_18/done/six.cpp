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

const int mod = 1e9+7, inf = INT_MAX, none = inf/2-9;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// code begins here

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
    //return pascal[n][r]; // for NN upto 1000
    return mul(mul(fact[n],invf[r]),invf[n-r]);// for NN >= 1000
}
int dp[1009][1009];

vi vec;
void solve(){
    int n;
    cin>>n;
    map<int,int> mapp;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        mapp[temp]++;
    }
    vec.clear();
    vec.push_back(0);
    for(auto a: mapp) vec.push_back(a.second);
    vec.push_back(0);

    vector<int> pre(sz(vec));
    pre[0] = 0;
    for(int i=1;i<sz(vec);i++) pre[i] = pre[i-1] + vec[i];

    int ans = 0;
    long long hell;
    for(int i=1;i<(int)vec.size()-1;i++) { //1000 * 1000 * 500 ==> 5*1e8 at max
        int how = vec[i];
        int l_sum = pre[i-1];
        int r_sum = pre[sz(vec)-1] - how - l_sum;

        // even one
        for(int left=0;left<how;left++) {
            for(int right =left+1;right<how;right++) {
                int left_side = l_sum + left;
                int right_side = r_sum + how - 1 - right;
                if(dp[left_side][right_side] != -1) {
                    ans += dp[left_side][right_side];
                    ans %= mod;
                    continue;
                }
                int turns = min(left_side,right_side);
                hell = 0;
                for(int ii=0;ii<=turns;ii++) {
                    hell += C(left_side,ii)*C(right_side,ii);
                    hell%=mod;
                }
                dp[left_side][right_side] = hell;
                ans += hell;
                ans%=mod;
            }
        }
    }

    for(int i=0;i<n;i++) {// 1000*500
        int left_side = i;
        int right_side = n - 1 - i;
        if(dp[left_side][right_side] != -1) {
            ans += dp[left_side][right_side];
            ans %= mod;
            continue;
        }

        int turns = min(left_side,right_side);
        hell = 0;
        for(int ii=0;ii<=turns;ii++) {
            hell += C(left_side,ii)*C(right_side,ii);
            hell%=mod;
        }
        dp[left_side][right_side] = hell;
        ans += hell;
        ans%=mod;
    }
    cout << ans << endl;
}

void preprocess() {
    build_pascal();
    memset(dp,-1,sizeof dp);
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
    cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
