#include<bits/stdc++.h>
#define dout if(debug) cout<<" "
using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG 1
#else
#define DEBUG 0.0
#endif
int debug = DEBUG;// it will take care of itself on online-judge

typedef unsigned long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix; // matrix matt(n,vector<int>(m,0));

const int mod = 1e9+7;

template<class T>int sz(T &x){return (int)x.size();}
template <typename T>void show(T first){cout << first << "\n";}
template <typename T, typename... Args>void show(T first, Args... args){cout << first << " ";prn(args...);}
template<class T,class U>ostream &operator<<(ostream &os,pair<T,U> &x){return os<<x.first<<","<<x.second;}
struct Desc{bool operator()(int a,int b){return a>b;} }desc; // for descending sort

int temp = -1,last = -1, n = 0;

int kadane(vector<int> &arr){
    // for negative case
    int maxx = INT_MIN;
    for(int i=0;i<(int)arr.size();i++) maxx = max(maxx,arr[i]);
    if(maxx <=0) return maxx;

    int local_max=0,ans = 0;
    for(int i=0;i<(int)arr.size();i++){
        if(local_max + arr[i] <= 0) local_max = 0;
        else local_max += arr[i];
        ans = max(local_max,ans);
    }
    return ans;
}

void solve(){
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    cout << kadane(vec) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // freopen("input","r",stdin);
     cin>>t;
    while(t--)solve();
}
