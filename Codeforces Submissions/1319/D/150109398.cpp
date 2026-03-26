#define _CRT_SECURE_NO_WARNINGS
#define debug(l) cerr<<" smotri huinyi : "<<#l<<' '<<l<<'\n';
#include "bits/stdc++.h"
using namespace std;
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef long double ld;
signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	srand(time(NULL));
	vector<vector<ll>> gr;
	vector<vector<ll>> re_gr;
	ll n, m;
	cin >> n >> m;
	gr.resize(n);
	re_gr.resize(n);
	for (ll i = 0; i < m; i++) {
		ll v, u;
		cin >> v >> u;
		u--, v--;
		gr[v].push_back(u);
		re_gr[u].push_back(v);
	}
	ll k;
	cin >> k;
	vector<ll> p(k);
	for (ll i = 0; i < k; i++) {
		cin >> p[i];
		p[i]--;
	}
	const ll inf = 1e18;
	vector<ll> dist(n, inf);
	dist[p.back()] = 0;
	queue <ll> q;
	q.push(p.back());
	while (!q.empty()) {
		ll to = q.front();
		q.pop();
		for (ll& u : re_gr[to]) {
			if (dist[to] + 1 < dist[u]) {
				dist[u] = dist[to] + 1;
				q.push(u);
			}
		}
	}
	ll mx = 0, mn = 0;
	for (ll i = 0; i < k-1; i++) {
		if (dist[p[i]] - 1 != dist[p[i + 1]]) {
			mn++;
			mx++;
		}
		else {
			bool fnd = false;
			for (ll& u : gr[p[i]]) {
				if (u != p[i + 1] && dist[p[i]] - 1 == dist[u]) {
					fnd = true;
				}
			}
			mx += fnd;
		}
	}
	cout << mn << ' ' << mx << '\n';


	

}

