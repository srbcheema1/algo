#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <set>
#include <ctime>
#include <map>
#include <cstring>
#include <iterator>
#include <queue>
#include <assert.h>
#include <bitset>
#include <complex>

//#pragma comment(linker, "/STACK:512000000")

using namespace std;

#define pb emplace_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int infi = 1e9 + 7;
const ll infl = (ll)1e18 + (ll)7;

int get_cnt(int a) {// number of unique prime factors of a number in root
    int ans = 0;
    for (int i = 2; i * i <= a; ++i) {
        if (a % i)
            continue;
        ++ans;
        while (a % i == 0)
            a /= i;
    }
    if (a > 1)
        ++ans;
    return ans;
}

int del[100500];
int cnt[100500];

int main() {
    for (int i = 2; i < 100500; ++i)
        del[i] = get_cnt(i);
    int t;
    cin >> t;

    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        int n;
        cin >> n;

        forn(i, n) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        ll ans = 0;
        for (int g = 2; g < 100500; ++g) {
            int cur_cnt = 0;
            for (int i = g; i < 100500; i += g)
                cur_cnt += cnt[i];
            ans = max(ans, 1LL * cur_cnt * del[g]);
        }
        cout << ans << '\n';
    }
}
