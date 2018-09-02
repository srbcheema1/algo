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
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int count = 0;
    for(size_t i=1;i<vec.size()-1;i++){
        if(vec[i] > vec[i-1] and vec[i] > vec[i+1] ) count++;
        if(vec[i] < vec[i-1] and vec[i] < vec[i+1] ) count++;
    }
    cout << count << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // freopen("input","r",stdin);
    // cin>>t;
    while(t--)solve();
}
