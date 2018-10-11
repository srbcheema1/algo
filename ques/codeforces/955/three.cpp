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
#define pqueue priority_queue
typedef unsigned long long ulli;// rarely will be used
typedef pair<int,int> mp;
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

const int mod = 1e9+7, inf = LLONG_MAX;
int temp = -1,last = -1,hell=-1;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// code begins here


/* 32000 is fine to calculate prime numbers upto.
 * there are 3432 primes till here.
 * to check number is prime_or not use this approach
 */
const int range = 70;// will calculate prime numbers till this
vector<int> big_div(range);
vector<int> primes; // will contain all the prime numbers
vector<int> sieve(){
    for(int i=0;i<range;i++) big_div[i] = i;
    for(int i=2;i<range;i++)
        if(big_div[i] == i)
            for(int j=2*i;j<range;j+=i)
                big_div[j]=i;
    for(int i=3;i<range;i++)
        if(big_div[i]==i)
            primes.push_back(i);
    return primes;
}

double log(double x, double base) {
    return (log(x) / log(base));
}

int get_low(double l,double p) {
    int b = 1;
    while(b<1e9){
        if(powl(b,p) >= l) break;
        b*=2;
    }

    int low = 1,high = b,last_good = b;
    while(low <= high) {
        int i = (low+high)/2;
        if(powl(i,p)<l) {
            low = i+1;
        } else {
            high = i-1;
            last_good = i;
        }
    }
    return last_good;
}

int get_high(int l,int p) {
    int b = 1;
    while(b<1e9){
        if(powl(b,p) > l) break;
        b*=2;
    }

    int low = 1,high = b,last_good = 1;
    show(low,high);
    while(low <= high) {
        int i = (low+high)/2;
        if(powl(i,p)<=l) {
            low = i+1;
            last_good = i;
            show(last_good,powl(i,p),l);
        } else {
            high = i-1;
        }
    }
    return last_good;
}
// double of 99999999999999999 was takenn as 1000000000000000000
// be careful for it

bool is_sqrt2(int a) {
    double root = sqrt(a);
    if(root - (int)root > 0) return false;
    return true;
}

void solve(){
    int q;
    cin>>q;
    auto primes = sieve();

    set<int> sett;
    for(auto p: primes) {
        int low = get_low(2,p);
        int high = get_high(1e18,p);
        if(powl(low,p) > 1e18) low=high+1;
        if(powl(high,p) < 2) high=-1;
        while (low <= high) {
            if(not is_sqrt2(powl(low,p))) {
                sett.insert((int)powl(low,p));
            }
            low++;
        }
    }

    vector<int> hell(sett.begin(),sett.end());
    while(q--) {
        int l,r,ans=0;
        cin>>l>>r;
        int l2 = get_low(max(2LL,l),2);
        int h2 = get_high(r,2);
        if(powl(l2,2) > r) l2=h2+1;
        if(powl(h2,2) < l) h2=-1;
        if(l2 <= h2) ans+=(h2-l2+1);
        show(l2,h2,"ans is ",ans);

        int low = lower_bound(hell.begin(),hell.end(),l)-hell.begin();
        int high = upper_bound(hell.begin(),hell.end(),r)-hell.begin();
        ans+=(high-low);
        if(l==1) ans++;
        cout << ans << endl;
    }
}

signed main(){
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("input","r",stdin);
    #endif
    std::cout << std::fixed; std::cout.precision(7);
    int test=1;
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// a code by srbcheema1

// https://codeforces.com/contest/955/problem/C
