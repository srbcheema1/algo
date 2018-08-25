#include<bits/stdc++.h>
using namespace std;

typedef long long int ulli;
typedef pair<int,int> mp;

const int mod = 1e9+7;

void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int ans = 1;
    int now = 1;
    for(int i=1;i<n;i++){
        if(vec[i] > vec[i-1]*2){
            ans = max(ans,now);
            now = 1;
        }
        else {
            now++;
        }
    }
    ans = max(ans,now);
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // freopen("input","r",stdin);
    // cin>>t;
    while(t--)solve();
}
