#include <bits/stdc++.h>
// v.erase( unique(all(v)) , v.end() )    ----->   removes duplicates and resizes the vector as so
using namespace std;
#define ll long long
#define lld long double
const lld pi = 3.14159265358979323846;
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
constexpr int mod = (int)(1e9+7);
#define log(x) (31^__builtin_clz(x)) // Easily calculate log2 on GNU G++ compilers
const int N=2e5+7;
vector<int> adj[N];

int main()
{ios_base::sync_with_stdio(0),cin.tie(0);
int n;cin>>n;
for(int i=0;i<n-1;i++){
  int a,b;cin>>a>>b;adj[a].pb(b);adj[b].pb(a);
}
int d[n+1];memset(d,-1,sizeof(d));d[1]=0;
queue<int> q;q.push(1);
int x[3]={1,2,3};
while(!q.empty()){
  int node=q.front();q.pop();
  x[0]=node;
  for(int u:adj[node]){
    if(d[u]!=-1)continue;
    d[u]=d[node]+1;q.push(u);
  }
}
memset(d,-1,sizeof(d));d[x[0]]=0;q.push(x[0]);
int p[n+1];
while(!q.empty()){
  int node=q.front();q.pop();
  x[1]=node;
  for(int u:adj[node]){
    if(d[u]!=-1)continue;
    d[u]=d[node]+1;q.push(u);p[u]=node;
  }
}
ll ans=d[x[1]];
memset(d,-1,sizeof(d));d[x[0]]=d[x[1]]=0;
int virt_node=x[1];
while(virt_node!=x[0]){
  virt_node=p[virt_node];d[virt_node]=0;
  if(virt_node!=x[0])q.push(virt_node);
}
q.push(x[0]);q.push(x[1]);
int mx=0;
while(!q.empty()){
  int node=q.front();q.pop();
  if(d[node]>=mx&&node!=x[0]&&node!=x[1]){
    x[2]=node;mx=d[node];
  }
  for(int u:adj[node]){
    if(d[u]!=-1)continue;
    d[u]=d[node]+1;q.push(u);p[u]=node;
  }
}
ans+=d[x[2]];
cout<<ans<<'\n'<<x[0]<<" "<<x[1]<<" "<<x[2]<<'\n';






 
 
    return 0;
}
/*









*/