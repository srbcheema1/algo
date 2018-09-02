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

set<int> factors(int a){
    set<int> s;
    for(int i=1;i<=sqrt(a);i++){
        if(a%i==0) s.insert(i),s.insert(a/i);
    }
    return s;
}

string ts(int a){
    string s = to_string(a);
    for(int i=(int)s.length();i<7;i++)
        s+="_";
    return s;
}

void solve(){
    vector<int> aa(3);
    cin>>aa[0]>>aa[1]>>aa[2];
    sort(aa.begin(),aa.end());
    set<int> fa = factors(aa[0]);
    set<int> fb = factors(aa[1]);
    set<int> fc = factors(aa[2]);

    int count = 0;
    string s;
    set<string> ss;
    for(auto aa: fa)
        for(auto bb:fb)
            for (auto cc:fc)
                if(bb>=aa and cc>=bb)
                    ss.insert(ts(aa)+ ts(bb)+ts(cc));
    for(auto aa: fa)
        for(auto bb:fc)
            for (auto cc:fb)
                if(bb>=aa and cc>=bb)
                    ss.insert(ts(aa)+ ts(bb)+ts(cc));
                    count++;
    for(auto aa: fb)
        for(auto bb:fa)
            for (auto cc:fc)
                if(bb>=aa and cc>=bb)
                    ss.insert(ts(aa)+ ts(bb)+ts(cc));
    for(auto aa: fb)
        for(auto bb:fc)
            for (auto cc:fa)
                if(bb>=aa and cc>=bb)
                    ss.insert(ts(aa)+ ts(bb)+ts(cc));
    for(auto aa: fc)
        for(auto bb:fa)
            for (auto cc:fb)
                if(bb>=aa and cc>=bb)
                    ss.insert(ts(aa)+ ts(bb)+ts(cc));
    for(auto aa: fc)
        for(auto bb:fb)
            for (auto cc:fa)
                if(bb>=aa and cc>=bb)
                    ss.insert(ts(aa)+ ts(bb)+ts(cc));
    cout << ss.size() << endl;
    for(auto a: ss)
        dout << a << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // freopen("input","r",stdin);
    cin>>t;
    while(t--)solve();
}
