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

int dp_l[1003][1003];
int dp_r[1003][1003];
vector<int> vec;
int rec_l(int v,int i) {
    if(v<0) return 0;
    if(v==0) return 1;
    if(i==0 or i+1==sz(vec)) return 0;

    int &dpp = dp_l[v][i];
    if(dpp != -1) return dpp;

    dpp = 0;
    for(int a=0;a<=vec[i];a++)
        dpp+=rec_l(v-a,i-1);
    dpp %= mod;
    return dpp;
}
int rec_r(int v,int i) {
    if(v<0) return 0;
    if(v==0) return 1;
    if(i==0 or i+1==sz(vec)) return 0;

    int &dpp = dp_l[v][i];
    if(dpp != -1) return dpp;

    dpp = 0;
    for(int a=0;a<=vec[i];a++)
        dpp+=rec_l(v-a,i+1);
    dpp %= mod;

    return dpp;
}

void solve(){
    int n;
    cin>>n;
    map<int,int> mapp;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        mapp[temp]++;
    }
    memset(dp_l,-1,sizeof dp_l);
    memset(dp_r,-1,sizeof dp_r);

    vec.clear();
    vec.push_back(0);
    for(auto a: mapp) vec.push_back(a.second);
    vec.push_back(0);

    vector<int> pre(sz(vec));
    pre[0] = 0;
    for(int i=1;i<sz(vec);i++) pre[i] = pre[i-1] + vec[i];

    int ans = 0;
    for(int i=1;i<(int)vec.size()-1;i++) {
        int how = vec[i];
        int l_sum = pre[i-1];
        int r_sum = pre[sz(vec)-1] - how - l_sum;
        vector<int> pdiff(1003,0);
        vector<int> ndiff(1003,0);
        for(int d = 0;d<how;d++)
            for(int r=0;r<=r_sum and r+d <= l_sum; r++)
                pdiff[d] += (rec_l(r+d,i-1) * rec_r(r,i+1)) % mod;

        for(int d = 1;d<how;d++)
            for(int l=0;l<=r_sum and l+d <= r_sum; l++)
                ndiff[d] += (rec_l(l,i-1) * rec_r(l+d,i+1)) % mod;

        // odd one
        for(int left=0;left<how;left++) {// these two loops can be optimised more
            for(int right =0;right+left<how;right++) {
                int diff = right - left;// can be negative
                if(diff >=0) ans += pdiff[diff];
                else ans+= ndiff[-diff];
                ans %= mod;
                show("loop 1: ",left,right,ans);
            }
        }
        // even one
        show(i,l_sum,r_sum,"ans",ans);
        how--;
        for(int left=0;left<how;left++) {// these two loops can be optimised more
            for(int right =0;right+left<how;right++) {
                int diff = right - left;// can be negative
                if(diff >=0) ans += pdiff[diff];
                else ans+= ndiff[-diff];
                ans %= mod;
                show("loop 2: ",left,right,ans);
            }
        }
        show(i,l_sum,r_sum,"ans",ans);
        show(pdiff);
        show(ndiff);
        show(' ');
    }
    cout << ans << endl;
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
    cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
