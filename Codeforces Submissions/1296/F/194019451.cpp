#include <bits/stdc++.h> 
using namespace std;

#define fs first
#define sc second
#define pii pair<int,int>

int f[7000]={0}, n, m, x, y, v[7000], now;
vector<pii>e[7000];
vector<int>q[7000];

bool dfs(int i, int par){
  bool yes=(i==y);
  for(pii ee:e[i]){
    if(ee.fs==par)continue;
    bool z=dfs(ee.fs,i);
    if(z){
      f[ee.sc]=max(f[ee.sc],v[now]);
      q[now].push_back(ee.sc);
    }
    yes|=z;
  }  
  return yes;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for(int i=1; i<n; i++){
    cin >> x >> y;
    e[x].push_back({y,i});
    e[y].push_back({x,i});
  }
  cin >> m;
  for(now=0; now<m; now++){
    cin >> x >> y >> v[now];
    dfs(x, x);
  }
  for(int i=0; i<m; i++){
    int mn=INT_MAX;
    for(int z:q[i])mn=min(mn, f[z]);
    if(mn!=v[i]){
      cout<<-1<<'\n';
      exit(0);
    }
  }
  for(int i=1; i<n; i++){
    if(f[i]==0)f[i]=1e6;
    cout << f[i] << ' ';}
  cout << '\n';
}