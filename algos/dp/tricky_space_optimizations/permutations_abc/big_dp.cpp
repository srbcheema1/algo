#include<bits/stdc++.h>
using namespace std;

#define int long long

int dp[4][4][4][33];

int rec(int a,int b, int c, int l) {
    int arr[3] = {a,b,c};
    int &ans = dp[a][b][c][l];
    sort(arr,arr+3);
    if(ans != -1) return ans;
    if(arr[0] == 1 and arr[1] == 2 and arr[2] == 3) {
        ans = pow(3,l);
        return ans;
    }

    if(l == 0) {
        ans = 0;
        return ans;
    }

    ans = 0;
    ans += rec(b,c,1,l-1);
    ans += rec(b,c,2,l-1);
    ans += rec(b,c,3,l-1);

    return ans;
}

signed main(){
    int t;
    cin>>t;
    memset(dp,-1,sizeof dp);
    while(t--) {
        int n;
        cin>>n;
        if(n<3) {
            cout << 0 << endl;
        }
        else {
            int ans = 0;
            for(int i=1;i<4;i++)
                for(int j=1;j<4;j++)
                    for(int k=1;k<4;k++) {
                        int temp = rec(i,j,k,n-3);
                        ans += temp;
                    }
            cout << ans << endl;
        }
    }
}
