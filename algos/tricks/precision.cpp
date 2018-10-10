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

/*
 * here, precision means total number of digits printed, not digits after decimal
 * to fix number of digits after decimal use std::fixed;
 * it wont effect on any datatype other than double and float.
 * so feel free to put it in templates
 */
signed main(){
    double hell = 321.123456789;
    double a = 32123456789;
    int b = 12345678;

    cout << hell << endl;
    cout << a << endl;
    cout << b << endl;
    cout << endl;

    std::cout.precision(7);
    cout << hell << endl;
    cout << a << endl;
    cout << b << endl;
    cout << endl;

    std::cout << std::fixed;
    cout << hell << endl;
    cout << a << endl;
    cout << b << endl;
    cout << endl;
}
//manual.end

/* TAGS
 * precision
 */
