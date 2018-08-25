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

bool isc(char a){
    if(a == 'a' || a == 'e' || a=='i' || a=='o' || a=='u' || a=='n') return false;
    return true;
}
bool isv(char a){
    if(a == 'a' || a == 'e' || a=='i' || a=='o' || a=='u' ) return true;
    return false;
}
bool isn(char a){
    if( a=='n' ) return true;
    return false;
}

void solve(){
    string s;
    cin>>s;
    int st = 0;
    for(int i=0;i<(int)s.length();i++){
        if(st == -1) break;
        if(st == 0) {
            if(isc(s[i])) st = 1;
            if(isv(s[i])) st = 2;
            if(isn(s[i])) st = 3;
            continue;
        }
        if(st==1){
            if(isc(s[i])) st = -1;
            if(isv(s[i])) st = 2;
            if(isn(s[i])) st = -1;
            continue;
        }
        if(st==2){
            if(isc(s[i])) st = 1;
            if(isv(s[i])) st = 2;
            if(isn(s[i])) st = 3;
            continue;
        }
        if(st==3){
            if(isc(s[i])) st = 1;
            if(isv(s[i])) st = 2;
            if(isn(s[i])) st = 3;
            continue;
        }
    }
    if(st == -1 || st == 1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    // freopen("input","r",stdin);
    // cin>>t;
    while(t--)solve();
}
