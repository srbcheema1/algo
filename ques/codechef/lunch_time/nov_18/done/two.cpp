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

int temp = -1,last = -1,hell=-1;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// code begins here
const int range = 1e5;// will calculate prime numbers till this
vector<int> big_div(range+9); // biggest divisor of i, for primes big_div[i] == i
vector<int> primes; // will contain all the prime numbers
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
    show("prime numbers till",range,":",primes.size());//3432
    return primes;
}

void solve(){
    int n;
    cin>>n;
    vector<int> locs(range,0);
    for(int i=0;i<n;i++) { // 1e5
        cin>>temp;
        int j=1;
        for(j=1;j*j<temp;j++)
            if(temp%j == 0)
                locs[j]++,locs[temp/j]++;
        if(j*j==temp) locs[j]++;
    }

    int ans = 0;
    for(int i=2;i<range;i++)
        ans = max(locs[i] * pp[i]   , ans);
    cout << ans << endl;
}

template<class T>
int unique_prime_factors(int a, T &primes){// max 400
    int ans = 0;
    for(auto p: primes) {
        if(p*p>a) break;
        if(a%p == 0) ans++,a /= p;
        if(a%p == 0) return 0;// still there we dont need such case
        while(a%p == 0) a/=p;
    }
    if(a>1) ans++;
    return ans;
}

void preprocess() {
    sieve();
    for(int i=2;i<=range;i++)
        pp[i] = unique_prime_factors(i,primes);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    preprocess();
    int test=1;
    cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// a code by srbcheema1
