
#include <bits/stdc++.h>
using namespace std;

// clang-format off
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
typedef set<int> si;
typedef vector<vector<int>> matrix; // matrix matt(n,vector<int>(m,0));

template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort // normally sory is ascending, use <() fxn
template<class T,class U>bool found(T t,U u){if(t.find(u)==t.end())return false;return true;}

// helping templates ignore them
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T>void _p(T x){int i=0;for(auto a: x){dout<<a<<",";if(i++ > 20)break;}}
template<class T,class U>ostream &operator<<(ostream &o,pair<T,U> &x){return o<<"("<<x.first<<","<<x.second<<")";}
template<class T>ostream &operator<<(ostream &os,vector<T> &x){dout<<"[";_p(x);dout<<"] ";return os;}
template<class T>ostream &operator<<(ostream &os,set<T> &x){dout<<"{";_p(x);dout<< "} ";return os;}

const int mod = 1e9+7, inf = LLONG_MAX, none = inf/2-9;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort, PQ does descending sort by default
// clang-format off
// manual.begin

/* 32000 is fine to calculate prime numbers upto.
 * there are 3432 primes till here.
 * to check number is prime_or not use this approach
 */
const int range = 32000;// will calculate prime numbers till this
vector<int> integers(range+9); // integers[i] == i+1, simply for some purposes where we need array of integers
vector<int> big_div(range+9); // biggest divisor of i, for primes big_div[i] == i
vector<int> primes; // will contain all the prime numbers
vector<int> sieve(){
    for(int i=0;i<=range;i++) big_div[i] = i,integers[i] = i+1;
    for(int i=2;i<range;i++)
        if(big_div[i] == i)
            for(int j=2*i;j<range;j+=i)
                big_div[j]=i;
    for(int i=2;i<range;i++)
        if(big_div[i]==i)
            primes.push_back(i);
    show("prime numbers till",range,":",primes.size());//3432
    show("last prime is",*primes.rbegin());//31991
    return primes;
}

vector<int> big_primes;
vector<int> segmented_seive(int s,int r) {
    // value of range should be greater than sqrt(s+r) here
    // while running seive
    // s is starting point
    // r is length of array (should be less than range)
    vector<int> seg_big_div(r+9);
    for(int i=0;i<r;i++) seg_big_div[i]=s+i;

    for(int i : primes){
        int rem = s%i, ind = (!rem)?0:(i-rem);
        for(;ind<r;ind+=i) seg_big_div[ind]=i;
    }

    for(int i=0;i<r;i++)
        if(seg_big_div[i]==s+i)
            big_primes.push_back(s+i);
    show("prime numbers form",s,"to",s+r-1,":",big_primes.size());
    show("first prime is",*big_primes.begin());
    show("last prime is",*big_primes.rbegin());
    return big_primes;
}

bool is_prime_small(int n) {
    /*
     * check upto `range` in O(1)
     * check upto 1e9 in 32000
     * sqrt(1e9) < 32000 ... 31263
     * primes till 1e6 are 80,000
     */
    if(n<2) return false;
    if(n < range) return big_div[n] == n;

    for(int i=0;i<(int)primes.size() and primes[i]<=sqrt(n);i++)
        if(n%primes[i]==0)return false;
    // this loop wont execute if value of range is 32000
    for(int i = *primes.rbegin();i <= sqrt(n);i++)// still if number if bigger than largest prime
        if(n%i==0)return false;
    return true;
}

bool is_prime_miller_rabin(int n,int k = 5){
    assert(k>0);
    return is_prime_small(n);
    // implement primality test for large numbers say miller rabin
}

bool is_prime(int n) {
    if(n<1e12) return is_prime_small(n);
    return is_prime_miller_rabin(n);
}

template<class T>
vector<int> prime_factors(int a, T &primes) {
    // complexity is no, of primes till root of element
    // find prime factor of 1e9 in max 3500
    // T can be set or array of prime numbers till 32000
    vector<int> f;
    for(auto p: primes) {
        if(a<=1 or p*p>a)break;
        if(a%p == 0) f.push_back(p), a/=p;
        while(a%p == 0) a /= p;
    }
    if(a > 1) f.push_back(a);// still if remains then its prime
    return f;
}

template<class T>
int unique_prime_factors(int a, T &primes){// max 400
    int ans = 0;
    for(auto p: primes) {
        if(p*p>a) break;
        if(a%p == 0) ans++,a /= p;
        //if(a%p == 0) return 0;// comment it if you dont want 0 on number with a prime twice ex: 4 = 2*2
        while(a%p == 0) a/=p;
    }
    if(a>1) ans++;
    return ans;
}

vector<int> divisors(int a) {// get divisors in root(n)
    vector<int> f;
    int i;
    for(i=1;i*i<a;i++) {
        if(a%i == 0){
            f.push_back(i);
            f.push_back(a/i);
        }
    }
    if(i*i==a) f.push_back(i);
    return f;
}

void solve(){
    for(int i=0;i<10000;i++) {
        auto a = prime_factors(i,primes);
        cout << a.size() << endl;
        auto b = divisors(i);
        cout << b.size() << endl;
    }
}

signed main(){
    sieve();
    solve();
}
//manual.end

/* TAGS
 *
 */
