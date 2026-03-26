#include <bits/stdc++.h>
using namespace std;
 
const int N=110000;
int n, x, y, q, par[N][21], dep[N]={0};
vector<int>e[N];
 
void dfs(int i, int p){
  dep[i]=dep[p]+1;
  par[i][0]=p;
  for(int j:e[i])if(j!=p)dfs(j,i);}
 
int dis(int a, int b){
  int res=0;
  if(dep[a]!=dep[b]){
    if(dep[a]<dep[b])swap(a,b);
    int dif=dep[a]-dep[b];
    for(int i=0; i<20; i++)if(dif&(1<<i))a=par[a][i];
    res+=dif;
  }
  if(a==b)return res;
  for(int i=19; i+1; i--){
    if(par[a][i]!=par[b][i]){
      a=par[a][i];
      b=par[b][i];
      res+=(1<<i)*2;}}
  res+=2;
return res;}
 
bool solve(){
  int x, y, a, b, k;
  cin >> x >> y >> a >> b >> k;
  int zz;
  zz=dis(a,b);
  if( !((zz^k)&1) && k>=zz )return 1;
  zz= dis(a,x)+dis(b,y)+1;
  if( !((zz^k)&1) && k>=zz )return 1;
  zz= dis(a,y)+dis(b,x)+1;
  if( !((zz^k)&1) && k>=zz )return 1;
return 0;}
 
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for(int i=1; i<n; i++){
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);}
 
  dfs(1,1);
  for(int j=1; j<20; j++){
    for(int i=1; i<=n; i++)par[i][j]=par[par[i][j-1]][j-1];
  }
  
  // for(int i=1; i<=n; i++)for(int j=i+1; j<=n; j++)cout << i << ' ' << j << ' ' << dis(i,j) << '\n';
  
  cin >> q;
  while(q--){
    if(solve())cout << "YES\n";
    else cout << "NO\n";
  }
  
}