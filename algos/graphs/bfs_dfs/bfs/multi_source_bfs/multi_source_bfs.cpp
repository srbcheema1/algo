#include<bits/stdc++.h>
using namespace std;
//https://www.hackerearth.com/problem/algorithm/four/

// manual.begin
const int N = 1e5+9;
struct Node{
    int dist = INT_MAX;
    vector<int> next;
}node[N];

void bfs(queue<int> &q){// q contain location of all the sources
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        /* no need to add visited. node may not enter queue if its distance is optimal already */
        for (auto a: node[i].next) if (node[a].dist > node[i].dist + 1) {
            node[a].dist = node[i].dist + 1;
            q.push(a);
        }
    }
}

void bfs(queue<int> &q,bitset<N> &vis){// using visited bitmap
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (auto a: node[i].next) if (!vis[a]) {
            node[a].dist = node[i].dist + 1;
            vis[a] = 1;
            q.push(a);
        }
    }
}

void solve() {
    int n,m,x,k;
    cin>>n>>m>>k>>x;
    for(int i=1;i<n;i++) {
        node[i].dist = INT_MAX;
        node[i].next.clear();
    }

    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        node[a].next.push_back(b);
        node[b].next.push_back(a);
    }

    queue<int> q;
    bitset<N> vis; vis.reset();
    for(int i=1;i<=x;i++) {
        int a; cin>>a;
        node[a].dist = 0;
        vis[a] = 1; q.push(a);
    }
    //bfs(q);
    bfs(q,vis);

    vector<int> arr(n);
    for(int i=0;i<n;i++) arr[i] = i+1;
    sort(arr.begin(),arr.end(), [](int a,int b){return node[a].dist < node[b].dist;});

    int ans = 0;
    for(int i=0;i<k;i++) ans += node[arr[i]].dist;
    cout << ans << endl;
}

void preprocess()
{

}
//manual.end

signed main(){
    int t;
    cin>>t;
    preprocess();
    while(t--) {
        solve();
    }
}

/* TAGS
 * multi source bfs
 */

/* INPUT
1
5 5 3 1
1 2
1 4
2 3
3 4
3 5
2

* OUTPUT

2
*/
