#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")

using ll = long long;
#define int long long
#define forn(i,n) for(int i=0; i<n; ++i)
#define pb push_back
#define pi pair<int,int>
#define f first
#define s second
#define vii(a,n) vector<int> a(n); forn(i,n) cin>>a[i];
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//const int inf = 1e18;
const int mod = 1e9+7;//998244353;

const int maxn=3e3;
vector<int> adj[maxn];

int sz[maxn][maxn]; //sz[v][par_v];
int dp[maxn][maxn];
int pu[maxn][maxn];
int pv[maxn][maxn];
int vis[maxn][maxn];

int getsz(int u, int p) {
	int r=1;
	for(auto&v:adj[u]) {
		if (v==p) continue;
		r+=getsz(v,u);
	}
	return r;
}

void solve() {

	int n; cin>>n;
	forn(i,n-1) {
		int u,v; cin>>u>>v; --u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	forn(i,n) forn(j,n) dp[i][j]=sz[i][j]=pu[i][j]=pv[i][j]=vis[i][j]=0;
	forn(u,n) {
		for(auto&v:adj[u]) {
			sz[u][v]=getsz(u,v);
		}
	}
	queue<pi> q;
	forn(u,n) {
		for(auto&v:adj[u]) {
			dp[u][v]=sz[u][v]*sz[v][u];
			pu[u][v]=v, pv[u][v]=u;
			q.push({u,v});
		}
	}
	while (q.size()) {
		auto it = q.front();
		int u=it.f, v=it.s;
		q.pop();
		for(auto&u1:adj[v]) {
			if (u1==pv[u][v]) continue;
			if (!vis[u][u1]) q.push({u,u1});
			vis[u][u1]=1;
			int x=sz[u][pu[u][v]]*sz[u1][v]+dp[u][v];
			if (x>dp[u][u1]) {
				dp[u][u1]=x;
				pu[u][u1]=pu[u][v];
				pv[u][u1]=v;
			}
		}
		for(auto&v1:adj[u]) {
			if (v1==pu[u][v]) continue;
			if (!vis[v1][v]) q.push({v1,v});
			vis[v1][v]=1;
			int x=sz[v1][u]*sz[v][pv[u][v]]+dp[u][v];
			if (x>dp[v1][v]) {
				dp[v1][v]=x;
				pu[v1][v]=u;
				pv[v1][v]=pv[u][v];
			}
		}
	}
	int ans=0;
	forn(i,n) forn(j,n) ans=max(ans,dp[i][j]);
	cout<<ans;
	
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1;
	//cin>>t;
	while (t--) solve();
	return 0;
}