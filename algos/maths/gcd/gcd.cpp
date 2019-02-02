#include<bits/stdc++.h>
using namespace std;

// manual.begin
int gcd(int a,int b){// a != 0
    if(b%a==0) return a;
    return gcd(b%a,a);
}
void solve() {
    int a,b;
    cin>>a>>b;
    cout << gcd(a,b) << endl;
}
// manual.end

int main()
{
    int t=1;
    //cin>>t;
    while(t--) solve();
}

/* TAGS
 * gcd
 */
