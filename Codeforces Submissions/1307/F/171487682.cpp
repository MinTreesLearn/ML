#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
//#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void dfs(int u, int fa, vector<int>& depth, vector<vector<int>>& f, vector<vector<int>>& g){
	depth[u] = depth[fa] + 1;
	f[u][0] = fa;
	for (auto v : g[u]){
		if (v == fa)
			continue;
		dfs(v, u, depth, f, g);
	}
}

int LCA(int x, int y, vector<int>& depth, vector<vector<int>>& f){
	if (depth[x] < depth[y])
		swap(x, y);
	for (int i = 19; i >= 0; i--){
		if (depth[f[x][i]] >= depth[y])
			x = f[x][i];
	}
	if (x == y)
		return x;
	for (int i = 19; i >= 0; i--){
		if (f[x][i] != f[y][i] && f[x][i] != 0 && f[y][i] != 0){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

int get(int x, int k, vector<vector<int>>& f){
	for (int i = 19; i >= 0; i--){
		if (k >= (1 << i)){
			x = f[x][i];
			k -= (1 << i);
		}
	}
	return x;
}

int find(int x, vector<int>& fa){
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x], fa);
}

int main(){
	IOS;
	int n, k, r;
	cin>>n>>k>>r;
	int n1 = n + n - 1;
	vector<vector<int>> g(n1 + 10);
	for (int i = 1; i < n; i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(n + i);
		g[n + i].push_back(u);
		g[v].push_back(n + i);
		g[n + i].push_back(v);
	}
	vector<vector<int>> f(n1 + 10, vector<int> (20));
	vector<int> depth(n1 + 10);
	dfs(1, 0, depth, f, g);
	for (int i = 1; i <= 19; i++){
		for (int j = 1; j <= n1; j++){
			f[j][i] = f[f[j][i - 1]][i - 1];
		}
	}
	vector<int> dist(n1 + 10, -1);
	queue<int> q;
	for (int i = 1; i <= r; i++){
		int x;
		cin>>x;
		q.push(x);
		dist[x] = 0;
	}
	vector<int> fa(n1 + 10);
	for (int i = 1; i <= n1; i++){
		fa[i] = i;
	}
	while (!q.empty()){
		int u = q.front();
		q.pop();
		if (dist[u] == k)
			break;
		for (auto v : g[u]){
			int fu = find(u, fa), fv = find(v, fa);
			fa[fu] = fv;
			if (dist[v] == -1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	int t;
	cin>>t;
	while (t--){
		int x, y;
		cin>>x>>y;
		int lca = LCA(x, y, depth, f);
		int len = depth[x] - depth[lca] + depth[y] - depth[lca];
		if (len <= 2 * k){
			cout << "YES" << endl;
			continue;
		}
		int x1, y1;
		if (depth[x] - depth[lca] >= k){
			x1 = get(x, k, f);
		}
		else
			x1 = get(y, len - k, f);
		if (depth[y] - depth[lca] >= k)
			y1 = get(y, k, f);
		else
			y1 = get(x, len - k, f);
		if (find(x1, fa) == find(y1, fa))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}



	return 0;
}