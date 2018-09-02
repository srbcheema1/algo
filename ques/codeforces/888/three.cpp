#include<bits/stdc++.h>
#define dout if(debug) cout<<" "
using namespace std;

int debug = 1;

typedef unsigned long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix;

const int mod = 1e9+7;

struct Desc{ bool operator() (int a, int b) { return a > b; } }desc; // for descending sort

void solve(){
    string s;
    cin>>s;
    vector<int> mapp(26,0);
    int ans = INT_MAX;

    for(int i = 0 ; i<26;i++){
        int last = -1;
        for(int j=0; j<(int)s.size();j++){
            if(s[j] == 'a'+i) {
                mapp[i] = max(mapp[i],j-last);
                last = j;
            }
        }
        if(mapp[i]!=0){
            mapp[i] = max(mapp[i],(int)s.size() - last);
            ans = min(ans, mapp[i]);
        }
    }

    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // freopen("input","r",stdin);
    // cin>>t;
    while(t--)solve();
}
