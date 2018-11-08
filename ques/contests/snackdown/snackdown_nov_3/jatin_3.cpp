#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define f(i,x,n) for(int i=x;i<n;i++)

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int flag=0;
    f(i,1,n)
        if(s[i]=='#'&&s[i-1]=='.')
            flag=1;

    if(flag==0) {
        cout<<"0"<<endl;
        return;
    } // fully filled

    int check=0;
    f(i,0,n) {
        if(s[i]=='#') check++;
        else break;
    }

    f(i,0,n-check)
        s[i]=s[i+check];

    n-=check;
    vector <int> pos;
    int hash=0,dot=0;
    flag=0;
    f(i,0,n)
        if(s[i]=='#')
            pos.push_back(i);

    for(int i=n-1;i>=0;i--) {
        if(s[i]=='#') {
            hash++;
            if(hash>dot)
                flag=1;
        }
        else
            dot++;
    }
    if(flag==1)
        cout<<-1<<endl;
    else if(pos.size()==0)
        cout<<0<<endl;
    else {
        int start=pos[0],ans=0,siz=pos.size();
        f(i,1,siz) {
            if(start+2>pos[i]) {
                ans+=start+2-pos[i];
                pos[i]=start+2;
            }
            start=pos[i];
        }
        f(i,0,siz)
            ans+=pos[i]-i;
        cout<<ans<<endl;
    }
}

int32_t main() {
    int t;
    cin>>t;
    while(t--) solve();
}
