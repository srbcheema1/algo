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
#define int ulli

int C(int n,int k){
    int ans =1;
    for(int i=n;i> n-k ; i--)
        ans *= i;
    for(int i=1;i<=k;i++)
        ans /= i;
    dout << ans << endl;
    return ans;
}

void solve(){
    int n,k;
    cin>>n>>k;
    if(k == 0)
        cout << 1 << endl;
    if(k == 1)
        cout << 1 << endl;
    if(k==2)
        cout << 1+ C(n,2) << endl;
    if(k==3)
        cout << 1+ C(n,2) + C(n,3)*2 << endl;
    if(k==4)
        cout << 1+ C(n,2) + C(n,3)*2 + C(n,4)*9 << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // freopen("input","r",stdin);
    // cin>>t;
    while(t--)solve();
}
