#include<bits/stdc++.h>
using namespace std;

#define int long long

int dp[3][3][30];
int rec(int a,int b, int l) {
    if(l == 0) return 0;

    int &ans = dp[a][b][l];
    if(ans != -1) return ans;

    ans = 0;
    for(int i=0;i<3;i++) {
        int arr[3] = {a,b,i};
        sort(arr,arr+3);
        if(arr[0] == 0 and arr[1] == 1 and arr[2] == 2) ans += pow(3,l-1);
        else ans += rec(b,i,l-1);
    }
    return ans;
}

signed main(){
    int t;
    cin>>t;
    memset(dp,-1,sizeof dp);
    while(t--) {
        int n;
        cin>>n;
        if(n<3)
            cout << 0 << endl;
        else {
            int ans = 0;
            for(int i=0;i<3;i++)
                for(int k=0;k<3;k++)
                    ans = rec(i,k,n-2);
            cout << ans << endl;
        }
    }
}
