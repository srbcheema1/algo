//https://www.hackerrank.com/contests/gs-codesprint/challenges/buy-maximum-stocks
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> mp;

/*
 * return maximum number of elements we can buy...
 * we can buy max i elements at i day
 * vector a is 0 based
 * a[i] contains price of that elem
 * k = max amount to be spent
 */
int buyMaximumProducts(int n, int k, vector <int> a) {
    vector<mp > vec(n);
    for(int i=0;i<n;i++) vec[i]=mp(i+1,a[i]);

    sort(vec.begin(),vec.end(),[](mp a,mp b){return a.second < b.second;});

    int amount = k,bought = 0,buy;
    for(int i=0;i<n;i++) {
        buy = min(vec[i].first,amount/vec[i].second);
        bought += buy;
        amount -= buy*vec[i].second;
        if(vec[i].second > amount) break;
    }
    return bought;
}

signed main() {
    int n,k;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
       cin >> arr[i];

    cin >> k;

    int result = buyMaximumProducts(n, k, arr);
    cout << result << endl;
}
// a code by srbcheema1
