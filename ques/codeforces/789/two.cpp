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

void solve(){
    //dout << "Case #" << _t << ": " << endl;
    int b,q,l,m;
    cin>>b>>q>>l>>m;
    set<int> vec;

    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        vec.insert(temp);
    }

    if(abs(b) > l ) {
            cout << "0" << endl;
        return;
    }

    if(abs(q)<2) {
        if(q==0){ // handled
            if(vec.find(0)!=vec.end()){ // is there
                if(b == 0) cout << 0 << endl;
                else if(vec.find(b) != vec.end()) cout << 0 << endl;
                else cout << 1 << endl;
            } else {
                cout << "inf" << endl;
            }
        }
        if(q==1){ //handleled
            if(vec.find(b)!=vec.end()) {// present
                cout << "0" << endl;
            }
            else {
                cout << "inf" << endl;
            }
        }
        if(q==-1){ // handled
            if(vec.find(b)!=vec.end() and vec.find(-b)!=vec.end()) cout << "0" << endl;
            if(vec.find(b)==vec.end() or vec.find(-b)==vec.end()) cout << "inf" << endl;
        }
        return;
    }// end misc cases
    if(b==0) {
        if(vec.find(0)==vec.end())// nahi milla
            cout << "inf" << endl;
        else
            cout << 0 << endl;
        return;
    }


    vector<int> hell(40);
    hell[0] = b;
    int ans = 0;
    if(vec.find(b) == vec.end()) ans ++;
    for(int i=1;i<40;i++) {
        hell[i] = hell[i-1] * q;
        if(abs(hell[i]) > l) break;
        if(vec.find(hell[i]) == vec.end()) {
            dout << hell[i] << endl;
            ans++;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    //freopen("input","r",stdin);
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
