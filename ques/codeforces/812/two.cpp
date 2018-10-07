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
    int n,m;
    cin>>n>>m;
    m+=2;
    vector<string> vec(n);
    int k = -1;
    for(int i=n-1;i>=0;i--){
        cin>>vec[i];
        if(k==-1)
            for(int j=0;j<m;j++) {
                if(vec[i][j] == '1'){
                    k=i;break;
                }
            }
    }

    if(k==-1){
        cout << "0" << endl;
        return;
    }

    if(k==0){
        for(int j=m-1;j>0;j--) {
            if(vec[0][j]=='1') {
                cout << j << endl;
                return;
            }
        }
    }

    vector<int> ll(n);
    vector<int> rr(n);
    for(int i=0;i<=k;i++){
        int l = m-1;
        int r = 0;//

        for(int j=0;j<m;j++) {
            show(i,j,":",vec[i][j]);
            if(vec[i][j]=='1') {
                l = j; break;
            }
        }
        for(int j=m-1;j>0;j--) {
            if(vec[i][j]=='1') {
                r = j; break;
            }
        }
        show(i,l,r);

        if(i==0){
            ll[0] = 2*r + 1;// ok
            rr[0] = m; // ok
            show("if",i,ll[i],rr[i]);
        } else if(i==k) {
            show("elif",i,l,r);
            cout << min(ll[i-1] + r, rr[i-1] + m-1-l) << endl;
            return;
        } else {
            ll[i] = min(ll[i-1] + 2*r + 1, rr[i-1] + m);
            rr[i] = min(ll[i-1] + m, rr[i-1] + 2*(m-1-l) + 1);
            show("el",i,ll[i],rr[i]);
        }
        show("");
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test=1;
    //freopen("input","r",stdin);
    //cin>>test;
    for(int t = 1; t <= test; t++)_t = t,solve();
}
