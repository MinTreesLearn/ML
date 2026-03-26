#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vvii vector<vector<ii>>
#define pb push_back
#define vpi vector<ii> 
#define forcin for(int i = 0; i<n; ++i) cin>>v[i];
#define pq priority_queue<ii>
#define mp make_pair
#define ld long double
#define vc vector<char>
#define vvc vector<vc>
#define vb vector<bool>
#define vvb vector<vb>
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define For(i, n, x) for (int i = x; i < n; i++)
#define rsz(a,x) assign(a,x)
#define endl "\n"
int n,k; 
vvi G;
map<ii,int> ans;
set<int> bad;
bitset<200002> used;
int r;
void dfs(int u, int c){
  used[u] = 1;
  int act = 0;
  for(int v : G[u]){
    if(used[v]) continue;
    act++;
    if(act == c) act++;
    if(act > r) act = 1;
    ans[{u,v}] = ans[{v,u}] = act;
    dfs(v,act);
  }
}

bool check(int m){
  int c = 0;
  For(i,n,0){
    c+=(G[i+1].size() > m);
  }
  return c<=k;
}

signed main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  G.rsz(n+1,vi());
  vpi edges;
  For(i,n,1){
    int u,v; cin>>u>>v;
    G[u].pb(v); G[v].pb(u);
    edges.pb({u,v});
  }
  int l = 0;  r = n;
  while(r > l+1){
    int m = (l+r)/2;
    if(check(m)) r = m;
    else l = m;
  }
  cout<<r<<endl;
  //pillar construccio valida
  For(i,n+1,1){
    if(G[i].size() > r) bad.insert(i);
  }
  //filling notbad and refilling bad
  dfs(1,0);
  for(auto x : edges) cout<<ans[x]<<" ";

}

