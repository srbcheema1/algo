#include<bits/stdc++.h>
#define dout if(debug) cout<<" "
using namespace std;

int debug = 0;

typedef unsigned long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix;

const int mod = 1e9+7;

struct Desc{ bool operator() (int a, int b) { return a > b; } }desc; // for descending sort

void solve(){
    int n;
    cin>>n;
    int a,b;
    int maxx=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(max(a,b) <= maxx){
            maxx = max(a,b);
            dout << maxx << endl;
        } else if(min(a,b) <= maxx){
            maxx = min(a,b);
            dout << maxx << endl;
        } else {
            cout << "NO" << endl;
            return;
        }
        dout << maxx << endl;
    }
    cout << "YES" << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // freopen("input","r",stdin);
    // cin>>t;
    while(t--)solve();
}
