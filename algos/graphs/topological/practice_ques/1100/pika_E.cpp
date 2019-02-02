#include<bits/stdc++.h>
using namespace std;

const int N=100010;
const int mod=1e9+7;

struct tri{
  int s,e,w,i;
  tri(int a,int b,int c,int d):s(a),e(b),w(c),i(d){};
};

int n,m;
vector<tri> edge;

vector<int> pri;
int ans;

int in[N],order[N];
bool ok(int lim){
  vector<int> adj[N];
  memset(in,0,sizeof in);
  for(auto i:edge){
    if(i.w>lim){
      adj[i.s].push_back(i.i);
      in[i.e]++;
    }
  }
  queue<int> q;
  for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
  vector<int> topo;
  while(!q.empty()){
    int who=q.front();
    q.pop();
    topo.push_back(who);
    for(auto i:adj[who]){
      in[edge[i].e]--;
      if(!in[edge[i].e]) q.push(edge[i].e);
    }
  }
  if((int)topo.size()!=n) return false;
  memset(order,0,sizeof order);
  for(int i=0;i<(int)topo.size();i++) order[topo[i]]=i;
  ans=lim;
  pri.clear();
  for(auto i:edge)
    if(i.w<=lim && (order[i.s]>order[i.e]))
        pri.push_back(i.i);
  return true;
}


int main(){
  int x,y,z;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>x>>y>>z;
    edge.push_back({x,y,z,i});
  }
  int low=0,high=mod,mid;
  while(low<=high){
    mid=(low+high)>>1;
    if(ok(mid)) high=mid-1;
    else low=mid+1;
  }
  cout<<ans<<' '<<pri.size()<<endl;
  for(auto i:pri) cout<<i+1<<' ';
  return 0;
}
// a code by anushi

// https://codeforces.com/contest/1100/problem/E
