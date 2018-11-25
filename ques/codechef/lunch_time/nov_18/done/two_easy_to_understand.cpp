#include<bits/stdc++.h>
using namespace std;

#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cerr<<" "
#define endl "\n"
//#define int long long // got passed by commenting this
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
//
/* 32000 is fine to calculate prime numbers upto.
 * there are 3432 primes till here.
 * to check number is prime_or not use this approach
 */
const int range = 1e5;// will calculate prime numbers till this
vector<int> big_div(range+9); // biggest divisor of i, for primes big_div[i] == i
vector<int> primes; // will contain all the prime numbers
vector<int> pprimes; // will contain all the psudo prime numbers
vector<int> pp(range+9,0); // will contain all the pprime numbers bool
vector<int> sieve(){
    for(int i=0;i<=range;i++) big_div[i] = i;
    for(int i=2;i<range;i++)
        if(big_div[i] == i)
            for(int j=2*i;j<range;j+=i)
                big_div[j]=i;
    for(int i=2;i<range;i++)
        if(big_div[i]==i)
            primes.push_back(i);
    return primes;
}

template<class T>
vi divisors(int a, T &primes) {
    show(sz(primes));
    vi f;
    for(int p=2;p*p<=a;p++) {
        if(a%p == 0){
            if(pp[p])f.push_back(p);
            if(pp[a/p] and p*p!=a) f.push_back(a/p);
        }
    }
    if(pp[a]) f.push_back(a);
    return f;
}


void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    vector<int> locs(range,0);
    for(int i=0;i<n;i++){// 1e5
        cin>>vec[i];
        auto divs = divisors(vec[i],pprimes);// 400 times at max
        for(auto a: divs) {// 400
            locs[a]++;
        }
    }

    int ans = 0;
    for(int i=2;i<range;i++) {
        ans = max(locs[i] * pp[i]   , ans);
    }
    cout << ans << endl;
}

template<class T>
vi _primeFactors(int a, T &primes){// max 400
    vi f;
    for(auto p: primes) {
        if(p*p>a) break;
        if(a%p == 0) f.push_back(p), a /= p;
        if(a%p == 0) {
            f.push_back(0);
            return f;
        }
    }
    if(a > 1) f.push_back(a);// still if remains then its prime
    return f;
}

void preprocess() {
    sieve();
    for(int i=2;i<=range;i++) {
        auto a = _primeFactors(i,primes);
        int hell = 1;
        for(auto b: a) {
            hell *=b;
        }
        if(hell == i) pprimes.push_back(i),pp[i] = sz(a);
    }
}

signed main(){
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("input","r",stdin);
    #endif
    preprocess();
    int test=1;
    cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// a code by srbcheema1
