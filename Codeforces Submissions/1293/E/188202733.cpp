#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 3005;
int n, rt, p[N][N], s[N][N];
LL f[N][N], ans;
vector<int> G[N];
void build(int u)
{
	s[rt][u] = 1;
	for(int v : G[u]) if(v ^ p[rt][u])
	{
		p[rt][v] = u;
		build(v);
		s[rt][u] += s[rt][v];
	}
}
LL dp(int u, int v)
{
	if(u == v) return 0;
	if(f[u][v]) return f[u][v];
	return f[u][v] = max(dp(u, p[u][v]), dp(v, p[v][u])) + s[u][v] * s[v][u];
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) { rt = i; build(i); }
	for(int u = 1; u <= n; u++) 
        for(int v = 1; v <= n; v++)
            ans = max(ans, dp(u, v));
	cout << ans << endl;
	return 0;
}
 					 	 			   					 		 		 	  	