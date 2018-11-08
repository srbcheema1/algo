#include<bits/stdc++.h>
using namespace std;

#define int long long

int thh = 10000;
void solve(){
    int r,n,m;
    cin>>r>>n>>m;

    int hazar = 0; // value of r + rr + rrr + rrrr .... r**10000
    int rr = 1; // contain value of r ** 10000
    for(int i=0;i<thh;i++) {
        rr *= r;
        rr %= m;
        hazar += rr;
        hazar %= m;
    }

    int how = n/thh;
    int rem = n%thh;

    int prd = 1;
    int ans = 0;
    for(int i=0;i<how;i++) {
        ans += prd * hazar;
        ans%=m;

        prd *= rr;
        prd%= m;
    }
    for(int i=0;i<rem;i++) {
        prd *= r;
        prd %= m;

        ans += prd;
        ans%=m;
    }
    cout << ans << endl;
}

signed main(){
    int test=1;
    cin>>test;
    for(int t = 1; t <= test; t++)solve();
}
