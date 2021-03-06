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

typedef long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix; // matrix matt(n,vector<int>(m,0));

#define int ulli


const int mod = 1e9+7;

template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T,class U>ostream &operator<<(ostream &os,pair<T,U> &x){return os<<x.first<<","<<x.second;}
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// manual.begin

/* 32000 is fine to calculate prime numbers upto.
 * there are 3432 primes till here.
 * to check number is prime_or not use this approach
 */
const int range = 1e5;// will calculate prime numbers till this
vector<int> big_div(range+9); // biggest divisor of i, for primes big_div[i] == i
vector<int> primes; // will contain all the prime numbers
vector<int> sieve(){// verified using assert
    for(int i=0;i<=range;i++) big_div[i] = i;
    for(int i=2;i<range;i++)
        if(big_div[i] == i)
            for(int j=2*i;j<range;j+=i)
                big_div[j]=i;
    for(int i=2;i<range;i++)
        if(big_div[i]==i)
            primes.push_back(i);
    show("prime numbers till",range,":",primes.size());//3432
    show("last prime is",*primes.rbegin());//31991
    assert(primes.size() == 9592);// for 1e5
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

bool is_prime(int n){
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

template<class T>
set<int> prime_factors(int a, T &primes) {
    // find prime factor of 1e9 in max 3500
    // T can be set or array of prime numbers till 32000
    set<int> f;
    if(a < 2) return f;
    for(auto p: primes) {
        if(a%p == 0) f.insert(p), a/=p;
        while(a%p == 0 and a > 1) a /= p;
    }
    if(a > 1) f.insert(a);// still if remains then its prime
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

set<int> divisors(int a) {// get divisors in root(n)
    set<int> f;
    for(int i=1;i*i<=a;i++) {
        if(a%i == 0) {
            f.insert(i);
            f.insert(a/i);
        }
    }
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
