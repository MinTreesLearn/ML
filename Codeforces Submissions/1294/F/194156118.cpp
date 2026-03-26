#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long,long long>
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vll vector<long long>
#define ent(v) for(auto &k:v)cin>>k
#define print(v) for(auto &k:v)cout<<k<<' ';cout<<endl
#define range(n) for(int i=0;i<n;i++)
#define mp(x,y) make_pair(x,y)
///////////////////////////
ll mod=1000000007;
ll poww(ll a,ll b){
  if(b<0)b=mod+b-1;
  if(!b)return 1;
  if(b&1)return a*poww(a*a%mod,b>>1)%mod;
  return poww(a*a%mod,b>>1);
}
//ll inv6=poww(6,-1);
/////////////////////////////
/*vi tree;
vi a;

void add(int k,int n){
  while(k<=n){
    tree[k]++;
    k+=k&-k;
  }
}

int sum(int k){
int ans=0;
  while(k){
    ans+=tree[k];
    k-=k&-k;
  }
  return ans;
}*/

int n;
vi v[200002];
vi dis,path;
vector<bool> vis;

void dfs(int x,int p){
  
  for(int k:v[x]){
    if(k!=p){
      dis[k]=dis[x]+1;
      dfs(k,x);
    }
  }
}

void road(int x,int p,int t){
  path.pb(x);
  if(x==t)return;
  for(int k:v[x]){
    if(k!=p){
      road(k,x,t);
      if(path.back()==t)return;
    }
  }
  path.pop_back();
}

void solve()
{
  cin>>n;
  dis.resize(n+1);
  vis.resize(n+1);
  range(n-1){
    int a,b;
    cin>>a>>b;
    v[a].pb(b);
    v[b].pb(a);
  }
  
  dfs(1,0);
  int a=0;
  range(n){
    if(dis[a]<dis[i+1]){
      a=i+1;
    }
  }
  
  dis.assign(n+1,0);
  dfs(a,0);
  int b=0;
  range(n){
    if(dis[b]<dis[i+1]){
      b=i+1;
    }
  }
  
  road(a,0,b);
  
  dis.assign(n+1,0);
  queue<int> q;
  for(int k:path){
    vis[k]=1;
    q.push(k);
  }
  
  while(!q.empty()){
    int cur=q.front();
    q.pop();
    
    for(int k:v[cur]){
      if(!vis[k]){
        dis[k]=dis[cur]+1;
        q.push(k);
        vis[k]=1;
      }
    }
  }
  
  int ans=path.size()-1;
  int c=0;
  range(n){
    if(dis[c]<dis[i+1]){
      c=i+1;
    }
  }
  
  if(dis[c]==0){
    if(a==1 || b==1){
      if(a==2 || b==2){
        c=3;
      }
      else{
        c=2;
      }
    }
    else{
      c=1;
    }
  }
  ans+=dis[c];
  cout<<ans<<endl;
  cout<<a<<' '<<b<<' '<<c<<endl;
}

////////////////////////////
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

//freopen("/storage/emulated/0/input.txt","r",stdin);

int t=1;

//cin>>t;

while(t--)solve();

return 0;
}