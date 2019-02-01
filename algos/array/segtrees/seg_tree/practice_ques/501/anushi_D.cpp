#include<bits/stdc++.h>
using namespace std;

const int N=200010;
const int mod=1e9+7;

#define ii pair<int,int>

int n;
int a[N],b[N],c[N];
int BIT[N];
int ans;

int query(int pos,int ans=0){
    for(;pos;pos-=pos&(-pos)) ans+=BIT[pos];return ans;
}

void update(int pos,int val=1){
    for(;pos<=n;pos+=pos&(-pos)) BIT[pos]+=val;
}

int main(){
    int x;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>x;
        a[i]=x-query(x);
        update(++x);
    }
    memset(BIT,0,sizeof BIT);
    for(int i=0;i<n;i++) {
        cin>>x;
        b[i]=x-query(x);
        update(++x);
    }
    int carry=0;
    for(int i=n-1;i>=0;i--) {
        c[i]+=a[i]+b[i]+carry;
        carry=c[i]/(n-i);
        c[i]%=(n-i);
    }
    memset(BIT,0,sizeof BIT);
    for(int i=0;i<n;i++) {
        int low=0,high=n-1,mid;
        while(low<=high){
            mid=(low+high)>>1;
            x=mid-query(mid);
            if(x>c[i]) high=mid-1;
            else low=mid+1;
        }
        cout<<high<<' ';
        update(high+1);
    }
    return 0;
}
//https://codeforces.com/contest/501/submission/48443789
