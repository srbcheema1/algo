#include<bits/stdc++.h>
#define ll long long int
using namespace std;

/*
 * Problem was to find no of triplets a,b,c
 * such that a*b*c = x
 * 1,2,3 and 3,2,1 are same
 */

set<int> factorise(int x) {
    set<int> vec;
    for(int i=1;i<3500;i++) if(x%i==0){
       vec.insert(i); vec.insert(x/i);
    }
    return vec;
}

bool check(int a,int b,int c) {
    if(b>a || c>b) return false;
    return true;
}

int main() {
    freopen ("input","r",stdin);
    int n,x;
    cin>>n>>x;
    set<int> factors = factorise(x);
    map<int,int> hell;

    for(int i=0;i<n;i++) {
        int temp; cin>>temp;
        if(factors.find(temp) != factors.end()) hell[temp]++;
    }

    ll ans = 0;
    for (auto a: hell) {
        int r = x/a.first;

        for (auto b: hell) if (r%b.first==0) {
            int c = r/b.first, local =0;
            if(!check(a.first,b.first,c)) continue;

            if (hell.find(r/b.first) != hell.end()) {
                if ( a.first == b.first and a.first == c ) {
                    if(a.second >= 3) local = a.second*(a.second-1)*(a.second-2)/6;
                }
                else if (a.first == b.first) {
                    if(a.second >= 2) local = a.second*(a.second-1)/2;
                }
                else if (a.first == c) {
                    if(a.second >=2) local = a.second*(a.second-1)/2;
                }
                else if (b.first == c) {
                    if (b.second >= 2) local = a.second*b.second*(b.second-1)/2;
                }
                else
                    local = a.second*b.second*(hell[c]);
            }
            ans += local;
        }
    }
    cout << ans << endl;
}

/*
input :
8 93
1 3 31 93 1 31 93 1
output :
12
*/

