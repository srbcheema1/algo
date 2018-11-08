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
struct st{
    string str;
    int val;
    st(){}
    st(int val_,string str_){val = val_; str = str_;}

    // by default priority queue sorts in Descending order
    // coz default priority queue is descending ....
    // we just make it fool by defining operator< in wrong direction.
    bool operator<(const st& o)const{return val > o.val;}
};

signed main(){
    int n;
    cin>>n;
    priority_queue<st> q;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        q.push(st(temp,""));
    }
    while(!q.empty()){
        st a = q.top();
        q.pop();
        cout << a.val << endl;
    }
}
//manual.end

/* TAGS
 *
 */
