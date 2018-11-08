#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int mod=1e9+7;
const double eps=0.000001;

int add(int a,int b){int res=(a+b)%mod;return (res<0)?res+mod:res;}
int mul(int a,int b){int res=(a*1LL*b)%mod;return (res<0)?res+mod:res;}

#define int long long

int n,m,x,y;
bool ok;
//i row

int col(int i,int j){
    bool can=y==j;
    int ans=m-1;
    if(can) {
        ans-=(y<j)?y:m-1-y;
    }
    ok|=can;
    return ans;
}

int row(int i,int j){
    bool can=x==i;
    int ans=n-1;
    if(can) {
        ans-=(x<i)?x:n-1-x;
    }
    ok|=can;
    return ans;
}

int diagl(int i,int j){
    bool can=0;
    int ans=min(i,j)+min(n-1-i,m-1-j);
    if(ans==0) return 0;
    if(ok) return ans;
    double let=(double)(x-i)/(y-j);
    int li=(i<j)?0:i-j,lj=(j<i)?0:j-i;
    double sec=(double)(x-li)/(y-lj);
    if(abs(let-sec)<eps) can=1;
    if(!can) return ans;
    if(x<i) ans-=min(x,y);
    else ans-=min(n-1-x,m-1-y);
    ok|=can;
    return ans;
}

int diagr(int i,int j){
    bool can=0;
    int ans=min(i,m-1-j)+min(n-1-i,j);
    if(ans==0) return 0;
    if(ok) return ans;
    double let=(double)(x-i)/(y-j);
    int lj=(i<m-1-j)?j+i:m-1;
    int li=(i<m-1-j)?0:i-m+1+j;
    double sec=(double)(x-li)/(y-lj);
    if(abs(let-sec)<eps) can=1;
    if(!can) return ans;
    if(x<i) ans-=min(x,m-1-y);
    else ans-=min(n-1-x,y);
    ok|=can;
    return ans;
}

int solve(int i,int j){
    return col(i,j)+row(i,j)+diagl(i,j)+diagr(i,j);
}


signed main(){
    int t;
    cin>>t;
    for(int test=1;test<=t;test++) {
        cin>>n>>m>>x>>y;--x,--y;
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ok=0;
                if(i==x && j==y) continue;
                ans+=(n*1LL*m)-1-solve(i,j);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
