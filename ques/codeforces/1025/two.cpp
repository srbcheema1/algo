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
template<class T>void print(T first,T last){for(auto it = first;it != last;it++)dout<<*it;dout<<endl;}
template<class T>void print(T container){print(container.begin(),container.end());}; // print(vec);
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort


/* 32000 is fine to calculate prime numbers upto.
 * there are 3432 primes till here.
 * to check number is prime_or not use this approach
 */
const int range = 32000;// will calculate prime numbers till this
vector<int> big_div(range);
vector<int> primes; // will contain all the prime numbers
vector<int> sieve(){// can get set as well as vector
    for(int i=0;i<range;i++) big_div[i] = i;
    for(int i=2;i<range;i++)
        if(big_div[i] == i)
            for(int j=2*i;j<range;j+=i)
                big_div[j]=i;
    for(int i=2;i<range;i++)
        if(big_div[i]==i)
            primes.push_back(i);
    return primes;
}

bool is_prime(int n){
    int i=0;
    for(;i<(int)primes.size() and primes[i]<=sqrt(n);i++)
        if(n%primes[i]==0)return false;
    // this loop wont execute if value of range is 32000
    for(int i = *primes.rbegin();i <= sqrt(n);i++)// still if number if bigger than largest prime
        if(n%i==0)return false;
    return true;
}

template<class T>
set<int> primeFactors(int a, T &primes){
    // find prime factor of 1e9 in max 3500
    set<int> f;
    for(auto p: primes){
        if(a<=1 and p>a)break;
        if(a%p == 0) f.insert(p), a /= p;
        while(a%p == 0 and a > 1) a /= p;
    }
    if(a > 1) f.insert(a);// still if remains then its prime
    return f;
}

set<int> common_factorise(int a, int b, set<int> factors){
    set<int> f;
    for(auto p: factors){
        if(a<=1 and p>a)break;
        if(a%p == 0) f.insert(p), a /= p;
        while(a%p == 0 and a > 1) a /= p;
    }
    for(auto p: factors){
        if(b<=1 and p>b)break;
        if(b%p == 0) f.insert(p), b /= p;
        while(b%p == 0 and b > 1) b /= p;
    }
    return f;
}

void solve(){
    int n,a,b;
    cin>>n;
    sieve();
    set<int> prime(primes.begin(),primes.end());
    vector<mp> vec(n);
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vec[i] = {a,b};
    }

    set<int> facts;
    set<int> fa = primeFactors(vec[0].first,prime);
    set<int> fb = primeFactors(vec[0].second,prime);
    set_union(fa.begin(),fa.end(),fb.begin(),fb.end(),inserter(facts,facts.begin()));

    for(int i=1;i<n;i++) facts = common_factorise(vec[i].first,vec[i].second,facts);

    if(facts.size() == 0) cout << "-1" << endl;
    else cout << *facts.begin() << endl;
}

signed main() {
    int test=1;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
