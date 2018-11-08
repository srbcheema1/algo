#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000010;
int a[N];
signed main(){
    int t,n;
    cin>>t;
    for(int test=1,ans = 0;test<=t;test++) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        ans=0;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++){
            if(a[i]==0 && a[j]==0) {ans+=n-(j+1);continue;}
            ans+=lower_bound(a+j+1,a+n,(a[i]*a[j])+1)-lower_bound(a+j+1,a+n,a[i]*a[j]);
        }
        cout<<"Case #"<<test<<": "<<ans<<endl;
    }
}
