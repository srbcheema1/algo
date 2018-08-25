#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> mp;

void solve(){
    int n,a,b;
    cin>>n;
    vector<mp> vec;
    map<int,int> aa;
    map<int,int> bb;
    int zero = -1;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vec.push_back(mp(a,b));
        if(a==b) zero = i;
        aa[a]++;
        bb[b]++;
    }
    if(n==1){
        cout << 0 << endl;
        return;
    }
    if(zero!=-1){
        int minn = INT_MAX, maxx = -1;
        for(int i=0;i<n;i++){
            if(i==zero) continue;
            a = vec[i].first;
            b = vec[i].second;
            minn = min(minn,b);
            maxx = max(maxx,a);
        }
        cout << max(0,minn-maxx) << endl;
        return;
    }
    int maxx = 0;
    int good = -1;
    for(int i=0;i<n;i++){
        a = vec[i].first; b = vec[i].second;
        aa[a]--;
        bb[b]--;
        mp l_max = *aa.rbegin();
        if(l_max.second==0) {
            aa.erase(l_max.first);
            l_max = *(aa.rbegin());
        }
        mp r_min = *bb.begin();
        if(r_min.second==0) {
            bb.erase(r_min.first);
            r_min = *bb.begin();
        }
        if(r_min.first - l_max.first > maxx){
            maxx = r_min.first - l_max.first;
            good = i;
        }
        aa[a]++;
        bb[b]++;
    }
    if(good != -1){
        int minn = INT_MAX, maxx = -1;
        for(int i=0;i<n;i++){
            if(i==good) continue;
            a = vec[i].first;
            b = vec[i].second;
            minn = min(minn,b);
            maxx = max(maxx,a);
        }
        cout << max(0,minn-maxx) << endl;
    }
    else {
        cout << 0 << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    while(t--)solve();
}
