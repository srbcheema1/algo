#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cerr<<" "
#define endl "\n";cout.flush()
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

// code begins here

string vec[109];

struct Node{
    vi b;
    bool v = false;
    int in=0;
}node[27];

bool build(string a,string b) {
    int i=0;
    while(i<sz(a) and i<sz(b)) {
        if(a[i] != b[i]) {
            node[a[i]-'a'].b.push_back(b[i]-'a');
            node[b[i]-'a'].in++;
            return true;
        }
        i++;
    }
    if(sz(a) > sz(b)) return false;// all chars equal but a is bigger
    return true;
}

void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    bool ret;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            ret = build(vec[i],vec[j]);
            if(!ret){
                cout << "Impossible" << endl;
                return;
            }
        }
    }

    queue<int> q;
    for(int i=0;i<26;i++) {
        if(node[i].in==0)q.push(i);
    }
    show(q.size());

    vector<int> ans;
    while(q.size()) {
        int t = q.front(); q.pop();
        ans.push_back(t);
        for(auto c: node[t].b) {
            node[c].in--;
            if(node[c].in==0) {
                q.push(c);
            }
        }
    }

    if(ans.size() != 26) {
        cout << "Impossible" << endl;
        return;
    }

    for(int i=0;i<26;i++) {
        cout << (char)(ans[i]+'a');
    }
    cout << endl;
}

void preprocess()
{

}

signed main()
{
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("Input.txt","r",stdin);
    #endif
    std::cout << std::fixed; std::cout.precision(7);
    preprocess();
    int test=1;
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// topological sort
// a code by srbcheema1

// https://codeforces.com/contest/510/problem/C
