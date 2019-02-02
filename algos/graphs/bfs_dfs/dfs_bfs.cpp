#include<bits/stdc++.h>
#define dout if(debugg) cout<<" "
using namespace std;

const int N = 1009;
vector<int> adj[N];
bitset<N> vis;

void dfs(int a){
    cout << a << " ";
    vis[a] = 1;
    for(auto i : adj[a]){
        if(!vis[i]) dfs(i);
    }
}

void bfs(int a){
    queue<int> q;

    vis.set(a), q.push(a);
    while(!q.empty()){
        for(auto i : adj[q.front()]){
            if(!vis[i]) vis.set(i), q.push(i);
        }
        cout<<q.front()<<" ";
        q.pop();
    }
}

void solve() {
    int n,temp;
    cin>>n;

    for(int i=1; i<=n; i++) {//insert adj nodes
        int m,faltu;
        cin>>faltu>>m;
        adj[i].clear();
        while(m--) {
            cin>>temp;
            adj[i].push_back(temp);
        }
    }

    while(true){
        int a,type;
        cin>>a>>type;
        if(a==0)break;

        vis.reset();
        if(type) { bfs(a); }
        else { dfs(a); }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
        cout << "graph " << i+1 << endl;
        solve();
    }
}
//http://www.spoj.com/problems/TDBFS/
