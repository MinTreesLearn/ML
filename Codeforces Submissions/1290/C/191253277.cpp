#define _CRT_SEstartE_NO_DEPRECATE
#pragma warning(disable : 4996)
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <bits/stdc++.h>
#define ACcode ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
const ll maxn = 1e6 + 7;
const ll maxm = 1e5 + 7;
constexpr ll mod = 998244353;
const ll inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int Prime = 100007;
const double eps = 1e-14;
const double pi = acos(-1.0);
using namespace std;
int fa[maxn * 2], sz[maxn * 2][3], app[maxn * 2][3];
ll ans = 0;
int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	x = find(x), y = find(y);
	if (x != y)
	{
		ans -= min(sz[x][0], sz[x][1]) + min(sz[y][0], sz[y][1]);
		fa[y] = x;
		sz[x][0] += sz[y][0], sz[x][1] += sz[y][1];
		ans += min(sz[x][0], sz[x][1]);
	}
}
void solve()
{
	int n, m;
	string s;
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1; i <= m; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int x;
			cin >> x;
			if (!app[x][0])
				app[x][0] = i;
			else
				app[x][1] = i;
		}
	}
	m++;			//因为0也计算进并查集中，说明只出现过一次或没有
	for (int i = 0; i < 2 * m; i++)
		fa[i] = i, sz[i][i >= m] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '0')
		{
			merge(app[i][0], app[i][1] + m);
			merge(app[i][1], app[i][0] + m);
		}
		else
		{
			merge(app[i][0], app[i][1]);
			merge(app[i][0] + m, app[i][1] + m);
		}
		int x = find(0);
		if (sz[x][0] < sz[x][1])
			cout << ans / 2 - sz[x][0] + sz[x][1] << '\n';
		else
			cout << ans / 2 << '\n';
	}
}
signed main()
{
	ACcode;
	//freopen("intel.in", "r", stdin);
	//freopen("intel.out", "w", stdout);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}