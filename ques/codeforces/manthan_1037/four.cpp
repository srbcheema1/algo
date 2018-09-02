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
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort // templated
struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort

int temp = -1,last = -1,hell=-1;
bool good=true,bad=false;

struct Node{
    int v,c,d,t;
    vector<int> next;
    Node(){
        v=0;
        c=0;
        t=-1;
    }
}node[200005];

void dfs(int aa,int d=0){
    if(node[aa].v) return;
    node[aa].v=1;
    node[aa].d = d;
    for(auto a: node[aa].next) {
        if(node[a].v==0) {
            dfs(a,d+1);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        node[a].next.push_back(b);
        node[b].next.push_back(a);
    }
    for(int i=0;i<n;i++)
        cin>>vec[i];

    if(vec[0]!=1){
        cout << "No" << endl;
        return;
    }
    dfs(vec[0],0);

    int pd = 0,turn = 1,pt=1; // pd = present depth
    for(auto a: node[vec[0]].next) node[a].t = 1;
    for(int i=1;i<n;i++) {
        int ii = vec[i];

        if(pd == node[ii].d) {
            if(node[ii].t < pt) {
                show(i,"here %:",ii,"depth",pd,node[ii].d,"turn",turn);
                cout << "No" << endl;
                return;
            }
            pt = max(pt,node[ii].t);
            show(i,"here 1:",ii,"depth",pd,node[ii].d,"turn",turn);
            for(auto a: node[ii].next){
                node[a].t = turn;
            }
            turn++;
        }
        else if(pd > node[ii].d) {
            show(i,"here 2:",ii,"depth",pd,node[ii].d,"turn",turn);
            cout << "No" << endl;
            return;
        }
        else {
            show(i,"here 3:",ii,"depth",pd,node[ii].d,"turn",turn);
            pd = node[ii].d;
            turn = 1;
            pt = 1;
            pt = max(pt,node[ii].t);
            for(auto a: node[ii].next){
                node[a].t = turn;
            }
            turn++;
        }
        show(i,"here #:",ii,"depth",pd,node[ii].d,"turn",turn);
    }
    cout << "Yes" <<  endl;

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    //freopen("input","r",stdin);
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
