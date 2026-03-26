#include <bits/stdc++.h>
using namespace std;
//#define int long long
int ans = 1;
vector<int> pr;
vector<int> val, w, sz;
vector<vector<int>> e;
void dfs(int u)
{
	if (w[u] >= val.size())
	{
		ans = 0;
		return;
	}
	pr[u] = val[w[u]];
	val.erase(val.begin() + w[u]);
	for (int v : e[u]) dfs(v);
}
void dfs1(int u)
{
	sz[u]++;
	for (int v : e[u])
	{
		dfs1(v);
		sz[u] += sz[v];
	}
	if (sz[u] <= w[u]) ans = 0;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	val.resize(n);
	w.resize(n);
	e.resize(n);
	pr.resize(n);
	sz.resize(n);
	iota(val.begin(), val.end(), 0);
	int root;
	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p >> w[i];
		p--;
		if (p != -1)
		{
			e[p].push_back(i);
		}
		else
		{
			root = i;
		}
	}
	dfs1(root);
	if (!ans)
	{
		cout << "NO\n";
		return 0;
	}
	dfs(root);
	if (!ans) cout << "NO\n";
	else
	{
		cout << "YES\n";
		for (int i : pr) cout << i + 1 << ' ';
	}
	return 0;
}