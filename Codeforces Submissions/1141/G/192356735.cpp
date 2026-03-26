#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>

using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,k;
ll g[N],d[N];
vector<pair<int,int>> adj[N];
map<int,int>f;

void dfs(int u,int p,int c){
  int color=0;
  if(d[u]>m)c=-1;
  for(auto edge : adj[u]){
    int v=edge.first;
    int e=edge.second;
    if(v==p)continue;
    color=(color+1)%m;
    if(color==c){
      color=(color+1)%m;
    }
    g[e]=color;
    dfs(v,u,color);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin>>n>>k;
  for(int i=1,x,y;i<n;++i){
    cin>>x>>y;
    ++d[x];++d[y];
    adj[x].push_back({y,i});
    adj[y].push_back({x,i});
  }
  for(int i=1;i<=n;++i)++f[d[i]];
  int kk=n;
  m=n-1;
  for(auto x : f){
    if(kk>k){
      kk-=x.second;
      m=x.first;
    }
  }
  dfs(1,0,-1);
  cout << m << '\n';
  for(int i=1;i<n;++i)cout << g[i]+1 << ' ';
}

