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

#define umap unordered_map
#define pqueue priority_queue
typedef unsigned long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix; // matrix matt(n,vector<int>(m,0));

const int mod = 1e9+7;

template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T,class U>ostream &operator<<(ostream &os,pair<T,U> &x){return os<<x.first<<","<<x.second;}
template<class T>void print(T first,T last){for(auto it = first;it != last;it++)dout<<*it;dout<<endl;}
template<class T>void print(T container){print(container.begin(),container.end());}; // print(vec);
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort // templated
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// manual.begin
/* sqrt(1e9) is 31623
 * primes till 32000 are 3432 remember 4000
 * so we can check is_prime in 3432 steps only, instread of 31623 steps
 *
 * primes till 1e6 are < 80,000
 *
 * a number can have max log2(n) factors.
 * 32 bit int can have max 32 prime factors, and max 8 unique prime factors remember 10
 * 32 bit int can have max 8 unique prime factors
 * 32 bit number cant have more than root(n) factors, except numbers below 100
 *
 * 32 bit number cant have more than 2300 divisors
 * maximum divisors are found of 6,983,776,800 which are 2304
 * it is not 32bit number though
 *
 */
/* https://primes.utm.edu/howmany.html
 * https://primes.utm.edu/
 *
 *
 */

/* primes till
1	10	                4
2	100	                25
3	1,000	            168
4	10,000	            1,229
5	100,000	            9,592
6	1,000,000	        78,498
7	10,000,000	        664,579
8	100,000,000	        5,761,455
9	1,000,000,000	    50,847,534
10	10,000,000,000	    455,052,511
11	100,000,000,000	    4,118,054,813
12	1,000,000,000,000	37,607,912,018
13	10,000,000,000,000	346,065,536,839
   */

signed main(){
    long long int primes_till[] = {0,4,25,168,1229,9592,78498,664579,5761455,50847534,455052511,4118054813};
    int n;
    cin>>n;
    if(n < (int)sizeof primes_till)
        cout << primes_till[n] << endl;
    else
        cout << "enter number below" << sizeof primes_till << endl;

}
//manual.end

/* TAGS
 *
 */
