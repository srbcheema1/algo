#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll calculate(ll a, ll b,ll m);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while (t--)
    {
    ll r,n,m;
        cin>>r>>n>>m;
        cout<<((calculate(r,n,m))*r)%m;
        cout<<"\n";
    }
    return 0;
}
ll calculate(ll r, ll n,ll m) {
    if(n==0) return 0;
    ll sum;
    if(n&1) { // n is odd
        sum = calculate((r*r)%m , (n-1)/2 , m);
        sum = (sum+r*sum)%m;
        sum = (1+r*sum)%m;
    } else { // n is even
        sum = calculate((r*r)%m , n/2 , m);
        sum = (sum+r*sum)%m;
    }
    return sum%m;
}
