#include<bits/stdc++.h>
#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cout<<" "
#define endl "\n"
#define int long long
using namespace std;

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

template<class T>void _p(T x){int i=0;for(auto a: x){dout<<a<<",";if(i++ > 20)break;}}
template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T,class U>ostream &operator<<(ostream &o,pair<T,U> &x){return o<<"("<<x.first<<","<<x.second<<")";}
template<class T>ostream &operator<<(ostream &os,vector<T> &x){dout<<"[";_p(x);dout<<"] ";return os;}
template<class T>ostream &operator<<(ostream &os,set<T> &x){dout<<"{";_p(x);dout<< "} ";return os;}
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort // templated

const int mod = 1e9+7, inf = LLONG_MAX;
int temp = -1,last = -1,hell=-1;
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

// code begins here
struct Node{
    vector<mp> connected;
    Node(){
    }
}node[52];

bool sort_closer(mp a,mp b){return a.second < b.second;} // for descending sort // templated

bool bad = false;

void solve(){
    cout << "Case #" << _t << ": ";
    //dout << endl;
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        node[a].connected.push_back({b,c});
        node[b].connected.push_back({a,c});
    }
    for(int i=1;i<=n;i++){
        sort(node[i].connected.begin(),node[i].connected.end(),sort_closer);
    }

    show("hell");
    map <int,int> mapp;
    for(int i=0;i<(1<<n);i++) {
        int cost = 0;
        for(int j=1;j<=n;j++) {
            int me = i & (1<<(j-1));
            if(me > 0) me = 1;
            int local_cost = inf;
            for(auto a: node[j].connected) {
                int he = i&(1<<(a.first-1));
                if(he > 0) he = 1;
                if(me != he) {
                    //show(" match ",j,a.first,me,he);
                    local_cost = a.second;
                    break;
                }
                //show("nomatch ",j,a.first,me,he);
            }
            show(i,j,local_cost);
            if(local_cost == inf) {
                cost = 0;
                break;
            }
            cost+= local_cost;
        }
        show(" for i =",i,"cost is",cost);
        if(cost > 0)
            mapp[cost]++;
    }

    int min_a = inf, min_c = inf;
    for(auto a: mapp) {
        if(a.first < min_c) {
            min_a = a.second;
            min_c = a.first;
        }
    }
    show("min cost" , min_c);
    cout << min_a << endl;
}

signed main(){
    int test=1;
    //freopen("input","r",stdin);
    cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
// a code by srbcheema1
