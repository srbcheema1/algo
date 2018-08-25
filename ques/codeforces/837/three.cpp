#include<bits/stdc++.h>
#define dout if(debug) cout<<" "

using namespace std;

int debug = 0;

typedef unsigned long long int ulli;
typedef unsigned int ui;
typedef pair<int,int> mp;
typedef vector<vector<int> > matrix;

const int mod = 1e9+7;

int check_max(mp s1, mp s2,mp paper ){
    int ans = s1.first * s1.second + s2.first * s2.second;

    if(s1.first + s2.first <= paper.first and max(s1.second, s2.second) <= paper.second) return ans;
    if(s1.first + s2.second <= paper.first and max(s1.second, s2.first) <= paper.second) return ans;
    if(s1.second + s2.second <= paper.first and max(s1.first, s2.first) <= paper.second) return ans;

    int x = paper.first, y = paper.second;
    paper.first = y; paper.second = x;

    if(s1.first + s2.first <= paper.first and max(s1.second, s2.second) <= paper.second) return ans;
    if(s1.first + s2.second <= paper.first and max(s1.second, s2.first) <= paper.second) return ans;
    if(s1.second + s2.second <= paper.first and max(s1.first, s2.first) <= paper.second) return ans;

    return -1;
}

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    mp paper(a,b);
    vector<mp> vec;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        vec.push_back(mp(x,y));
    }

    dout << "start" << endl;
    int maxx = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            int local = check_max (vec[i],vec[j],paper);
            maxx = max(maxx,local);
        }
    }
    cout << maxx << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
}
