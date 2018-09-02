#include<bits/stdc++.h>
#define dout if(debug) cout<<" "
using namespace std;

int debug = 1;

typedef unsigned long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix;

const int mod = 1e9+7;

struct Desc{ bool operator() (int a, int b) { return a > b; } }desc; // for descending sort

void solve(){
    int n;
    cin>>n;
    map<int,int> mapp;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        mapp[temp]++;
    }
    int p = 0;
    for(auto a: mapp){
        p = max(p,a.second);
    }
    cout << n - p << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // freopen("input","r",stdin);
    // cin>>t;
    while(t--)solve();
}
