#include <bits/stdc++.h>
using namespace std;

// clang-format off
//#define int long long
#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cerr<<" "
#define endl "\n";cout.flush()
#ifdef ONLINE_JUDGE
#define DEBUG 0.0
#else
#define DEBUG 1
#endif
int debug = DEBUG;// it will take care of itself on online-judge
int debug_test = 0; // test_case to be debugged ... 0 means all ... -1 means none
int _t = 0;// test_case counter

template<class T>void show(T first){dout<<first<<"\n";}
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
#define trace(...) _s(#__VA_ARGS__, __VA_ARGS__)
template<class T>void _s(const char* c,T& first){dout<<c<<" : "<<first<<"\n";}
template<class T,class... Args>void _s(const char *c,T first,Args... args)
{const char* t=strchr(c+1,',');dout;if(debug)cerr.write(c,t-c)<<" : "<<first<< " |";_s(t+1,args...);}
template<class T>void _p(T x){int i=0;for(auto a: x){dout<<a<<",";if(i++ > 20)break;}}
template<class T,class U>ostream &operator<<(ostream &o,pair<T,U> &x){return o<<"("<<x.first<<","<<x.second<<")";}
template<class T>ostream &operator<<(ostream &os,vector<T> &x){dout<<"[";_p(x);dout<<"] ";return os;}
template<class T>ostream &operator<<(ostream &os,set<T> &x){dout<<"{";_p(x);dout<< "} ";return os;}

typedef unsigned long long ulli;// rarely will be used
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef set<int> si;
template<class A,class B> using umap = unordered_map<A,B>;
template<class A,class B> using pqueue = priority_queue<A,vector<A>,B>;
typedef vector<vector<int>> matrix; // matrix matt(n,vector<int>(m,0));
#define dmatrix(n,m) matrix(n,vector(m,0)) // to define matrix use dmatrix(n,m)
#define substring(i,j) substr(i,(j-i+1)) // both i,j are included
#define all(container) container.begin(),container.end()
#define FF first
#define SS second

template<class T>int sz(T &x){return (int)x.size();}
template<class T>bool sort_fun(T a,T b){return a>b;} // for desc sort // default sort is asc, use <() fxn
template<class T,class U>bool found(T t,U u){if(t.find(u)==t.end())return false;return true;}
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort
struct AscPQ{bool operator()(int a,int b){return a>b;}}; // for ascending PQ, does descending by default

const int mod = 1e9+7, inf = ((1LL<<((sizeof mod)*8-2))-1)<<1|1, none = inf/2-9;// inf is self adjustable
int add(int x,int y){int res=(x+y)%mod;return res<0?res+mod:res;}
int mul(int x,int y){int res=(x*1LL*y)%mod;return res<0?res+mod:res;}
int dx[] = {0,1,0,-1,1,1,-1,-1},dy[] = {1,0,-1,0,1,-1,-1,1};// use 0-3 for 4dir 0-7 for 8dir
// clang-format off

// code begins here

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

int MaxUtil(int* st, int ss, int se, int l,
            int r, int node)
{
    if (l <= ss && r >= se)
        return st[node];

    if (se < l || ss > r)
        return -1;

    int mid = getMid(ss, se);

    return max(MaxUtil(st, ss, mid, l, r,
                       2 * node + 1),
               MaxUtil(st, mid + 1, se, l,
                       r, 2 * node + 2));
}

void updateValue(int arr[], int* st, int ss, int se,
                 int index, int value, int node)
{
    if (index < ss || index > se)
    {
        cout << "Invalid Input" << endl;
        return;
    }

    if (ss == se)
    {
        arr[index] = value;
        st[node] = value;
    }
    else {
            int mid = getMid(ss, se);

            if (index >= ss && index <= mid)
                updateValue(arr, st, ss, mid, index,
                            value, 2 * node + 1);
            else
                updateValue(arr, st, mid + 1, se,
                            index, value, 2 * node + 2);

            st[node] = max(st[2 * node + 1],
                       st[2 * node + 2]);
    }
    return;
}

int getMax(int* st, int n, int l, int r)
{
    if (l < 0 || r > n - 1 || l > r)
    {
        printf("Invalid Input");
        return -1;
    }

    return MaxUtil(st, 0, n - 1, l, r, 0);
}

int constructSTUtil(int arr[], int ss, int se,
                    int* st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
                 constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
    return st[si];
}

int* constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    int* st = new int[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}


void solve()
{
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int *st = constructST(arr, n);
    while(q--) {
        int t,a,b;
        cin>>t>>a>>b;
        if(t==0) {
            a--;b--;
            cout << getMax(st,n,a,b) << endl;
        }
        if(t==1) {
            a--;
            updateValue(arr, st,0, n-1, a, b, 0);
        }
    }
}

void preprocess()
{
    int arr[] = { 1, 3, 5, 7, 9, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int* st = constructST(arr, n);
    cout << getMax(st, n, 1, 3) << endl;
    updateValue(arr, st, 0, n - 1, 1, 8, 0);
    cout << getMax(st, n, 1, 3) << endl;
}

signed main()
{
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("Input.txt","r",stdin);
    #endif
    std::cout << std::fixed; std::cout.precision(7);
    //preprocess();
    int test=1;
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// a code by srbcheema1
