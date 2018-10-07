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

long long get(vector<long long> &a) {
    // get value of number stored in binary represention inside a vector
    // entries of vector should be 0 or 1
    long long ans = 0;
    for(int i=0;i<(int)a.size();i++){
        if(a[i]) ans += (1LL<<i);
    }
    return ans;
}

void solve(){
    //dout << "Case #" << _t << ": " << endl;
    int x,l,r;
    cin>>x>>l>>r;

    vector<int> arr(32,0);

    for(int i=0;i<32;i++){
        int a = x & (1<<i);
        if(a)
            arr[i] = 1;
    }

    print(arr);

    vector<int> arr_y(32,0);
    vector<int> arr_x(32,1);

    for(int i=31;i>=0;i--) {
        if(arr[i]==0) {
            arr_y[i]=arr_x[i]=1;
            dout << "1 --- " <<  get(arr_y);
            if(get(arr_y)>r){
                arr_y[i]=arr_x[i]=0;
            }
        }
        else {
            arr_y[i]=arr_x[i]=0;
            dout << "2 --- " <<  get(arr_y);
            if(get(arr_x)<l) {
                arr_y[i]=arr_x[i]=1;
            }
        }
        arr[i] = (arr[i]^(arr_y[i])) & (1);
        //print(arr_y);
        //show(get(arr_y));
    }

    //print(arr);
    cout << get(arr) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    //freopen("input","r",stdin);
    cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
