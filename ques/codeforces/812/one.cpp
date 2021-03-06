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

int temp = -1,last = -1,hell=-1;
bool good=true,bad=false;


void solve(){
    //dout << "Case #" << _t << ": " << endl;

    int arr[5][5];
    for(int i=1;i<=4;i++){
        for(int j = 1;j<=4;j++)
            cin>>arr[i][j];
    }

    if(arr[1][4]){
        mp a[] = { {1,1},{1,2},{1,3},{2,1},{3,2},{4,3} };
        for(int i=0;i<6;i++){
            if(arr[a[i].first][a[i].second]){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    if(arr[2][4]){
        mp a[] = { {2,1},{2,2},{2,3},{3,1},{4,2},{1,3} };
        for(int i=0;i<6;i++){
            if(arr[a[i].first][a[i].second]){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    if(arr[3][4]){
        mp a[] = { {3,1},{3,2},{3,3},{4,1},{1,2},{2,3} };
        for(int i=0;i<6;i++){
            if(arr[a[i].first][a[i].second]){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    if(arr[4][4]){
        mp a[] = { {4,1},{4,2},{4,3},{1,1},{2,2},{3,3} };
        for(int i=0;i<6;i++){
            if(arr[a[i].first][a[i].second]){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    //freopen("input","r",stdin);
    solve();
}
