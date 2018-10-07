#include<bits/stdc++.h>
#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cout<<" "
#define endl "\n"
using namespace std;

#ifdef ONLINE_JUDGE
#define DEBUG 0.0
#else
#define DEBUG 0
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


bool is_one(int a, int b){
    int c = 1;
    c<<=b;
    if(a & c) return true;
    else return false;
}

int kk = 0;
void solve(){
    //dout << "Case #" << _t << ": " << endl;
    int n;
    cin>>n;
    vector<int> vec(n+1,17179869183);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }

    int final = 0;
    for(int i=0;i<33;i++) {
        int local = 0;
        int cnt = 0;
        int last = 1;
        for(int j=0;j<n+1;j++){
            if(last == 0 and is_one(vec[j],i)) {
                local += (cnt *(cnt+1))/2;
                cnt = 0;
                last = 1;
                if(i == kk)dout << 1 << endl;
            }
            else if(last == 1 and is_one(vec[j],i)){
                last = 1;
                if(i == kk)dout << 2 << endl;
                //dout << 2 << endl;
            }
            else if(last == 1 and !is_one(vec[j],i)){
                last = 0;
                cnt = 1;
                if(i == kk)dout << 3 << endl;
                //dout << 3 << endl;
            }
            else if(last == 0 and !is_one(vec[j],i)){
                last = 0;
                cnt ++;
                if(i == kk)dout << 4 << endl;
                //dout << 4 << endl;
            }
        }
        //show(i,local);
        local = (n*(n+1))/2 - local;
        //show(i,local);
        final += local * (1<<i);
    }
    cout << final << endl;

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    //freopen("input","r",stdin);
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
