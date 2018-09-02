#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define debug(x) cout << (#x) << " is " << (x) << endl
#define fast_io() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

const ll N = 2e5 + 10;
set < ll > g[N], s;
ll q[N];
bool seen[N];

int main() {
    fast_io();
    ll n;
    cin >> n;
    for (ll i = 1, x, y; i <= n - 1; ++i) {
        cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
    }
    for (ll i = 1; i <= n; ++i)
        cin >> q[i];

    ll ctr = 1, checked = 1;

    while (ctr != n) {
        auto u = q[ctr];// take out u
        ++ctr;// ok
        if (seen[u]) continue;
        seen[u] = true;

        s.clear();
        for (auto &v : g[u])
            if (!seen[v])
                s.insert(v);

        for (ll i = 1; i <= (int)s.size(); ++i) {
            ++checked;
            if (s.find(q[checked]) == s.end()) {// nahi milla
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}
