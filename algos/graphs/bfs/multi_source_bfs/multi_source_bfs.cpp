#include<bits/stdc++.h>
using namespace std;
//https://www.hackerearth.com/problem/algorithm/four/

// manual.begin
struct Node{
    int dist;
    vector<int> next;
    Node(){
        dist = INT_MAX;
    }
    void clear(){
        dist = INT_MAX;
        next.clear();
    }
}node[100009];

bool comp(int a,int b){return node[a].dist < node[b].dist;}
void preprocess(int n){for(int i=0;i<=n;i++) node[i].clear();}

void bfs(queue<int> &q){
    /*
     * input takes queue with location of all the sources
     */
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        /*
         * no need to add visited. node may not enter queue if its distance is optimal already
         */
        for (auto a: node[i].next) if (node[a].dist > node[i].dist + 1) {
            node[a].dist = node[i].dist + 1;
            q.push(a);
        }
    }
}

signed main(){
    int n,m,x,k;
    cin>>n>>m>>k>>x;
    preprocess(n);
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        node[a].next.push_back(b);
        node[b].next.push_back(a);
    }

    queue<int> q;
    for(int i=1;i<=x;i++) {
        int a; cin>>a;
        node[a].dist = 0;
        q.push(a);
    }
    bfs(q);

    vector<int> arr(n);
    for(int i=0;i<n;i++) arr[i] = i+1;
    sort(arr.begin(),arr.end(),comp);

    int ans = 0;
    for(int i=0;i<k;i++) ans += node[arr[i]].dist;
    cout << ans << endl;
}
//manual.end

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
