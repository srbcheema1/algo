#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int mod=1e9+7;

int add(int a,int b){int res=(a+b)%mod;return (res<0)?res+mod:res;}
int mul(int a,int b){int res=(a*1LL*b)%mod;return (res<0)?res+mod:res;}

#define ii pair<int,int>
#define LEFT(i) (id<=i)?i-id:b[i]+1+id-i
#define RIGHT(i) (id<=i)?i-id+b[i]+1:id-i
#define P(i) (min(n-1,i+b[i])-max(0,i-b[i])+1)

string a;
int n,b[N];
vector<int> v[100];
int ri,rj;

bool check(int id,int i,int j) {
    return __gcd(P(i),P(j))!=1;
}

signed main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>a;
        n=a.length();

        for(int i=0;i<n;i++) v[i].clear();

        for(int i=0;i<n;i++) {
            if(a[i]=='.') {b[i]=0;continue;}
            b[i]=a[i]-'0';
            for(int j=max(0,i-b[i]);j<=min(n-1,i+b[i]);j++){
                v[j].push_back(i);
            }
        }
        bool ok=1;
        for(int i=0;i<n && ok;i++) {
            for(int j=1;j<v[i].size();j++) ok&=check(i,v[i][j-1],v[i][j]);
        }

        if(ok) cout<<"safe\n";
        else cout<<"unsafe\n";
    }
}
