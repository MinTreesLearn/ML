#include<bits/stdc++.h>

const int N = 2e6 + 101;

int n, m;

int dep[N], f[N][25], du[N], belong[N], vis[N];

std::vector<int> e[N], t[N];

std::queue<int> q;

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for (int i = 0; i <= 22; ++i) f[u][i + 1] = f[f[u][i]][i];
	for (auto v : e[u]) {
		if (v == fa) continue;
		dfs(v, u);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int i = 22; i >= 0; --i) {
		if (dep[f[x][i]] >= dep[y]) x = f[x][i];
		if (x == y) return x;
	}
	for (int i = 22; i >= 0; --i) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

int find(int x) {
	if (belong[x] == x) return x;
	else return belong[x] = find(belong[x]);
}

signed main() {
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> n;
	for (int i = 1; i <= n; ++i) belong[i] = i;
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		e[u].push_back(v), e[v].push_back(u);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		t[u].push_back(v), t[v].push_back(u);
		++du[u], ++du[v];
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) {
		if (du[i] == 1) q.push(i);
	}
	//for (int i = 1; i <= n; ++i) std::cout << dep[i] << '\n';
	std::cout << n - 1 << '\n';
	while (q.size() >= 2) {
		int u = q.front(), v;
		q.pop();
		vis[u] = 1;
		for (auto to : t[u]) {
			if (vis[to] == 1) continue;
			v = to;
			--du[v];
			if (du[v] == 1) q.push(v);
			break;	
		}
		int k = lca(u, v);
		int a = find(u), b;
		//std::cout << "a: " << a << " u: " << u << " v: " << v << " k: " << k << '\n';
		if (dep[a] > dep[k]) {
			b = f[a][0];
			std::cout << a << " " << b << " " << u << " " << v << '\n';
			belong[a] = find(b);
		}
		else {
			b = v;
			for (int i = 22; i >= 0; --i) {
				//std::cout << "b: " << b << '\n';
				if (dep[f[b][i]] > dep[k] && find(f[b][i]) != a) b = f[b][i];
			}
			std::cout << b << " " << f[b][0] << " " << u << " " << v << '\n';
			belong[b] = a;
		}
	}
	
	return 0;
}
	 	 					  	  				 	  			 	 			