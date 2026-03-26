#include <bits/stdc++.h>
using namespace std;

const int N = 505, inf = 0x3f3f3f3f;

namespace flow_graph {
	int n, s, t, S, T, cnt, h[N], cur[N], in[N], d[N], sum;
	bool vis[N];
	struct edge {
		int nxt, fl, w, to;
		void insert(int x, int y, int z, int ww) {
			nxt = h[x], to = y, w = ww, fl = z, h[x] = cnt++;
		}
	} e[N * N];
	void init(int len) {
		n = len;
		s = 0;
		t = n + 1;
		S = t + 1;
		T = S + 1;
		memset(h, -1, sizeof(h));
		return;
	}
	void add(int w, int up, int low, int u, int v) {
		in[u] -= low;
		in[v] += low;
		e[cnt].insert(u, v, up - low, w);
		e[cnt].insert(v, u, 0, -w);
		return;
	}
	void add(int w, int flow, int u, int v) {
		e[cnt].insert(u, v, flow, w);
		e[cnt].insert(v, u, 0, -w);
		return;
	}
	void build() {
		for (int i = s; i <= t; i++) {
			if (in[i] > 0) {
				sum += in[i];
				add(0, in[i], 0, S, i);
			} else {
				add(0, -in[i], 0, i, T);
			}
		}
	}
	bool spfa() {
		memcpy(cur, h, sizeof(h));
		memset(d, 63, sizeof(d));
		queue<int> Q;
		d[S] = 0, Q.push(S);
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop(), vis[u] = 0;
			for (int i = h[u], v; ~i; i = e[i].nxt) {
				if (e[i].fl && d[(v = e[i].to)] > d[u] + e[i].w) {
					d[v] = d[u] + e[i].w;
					if (!vis[v]) Q.push(v), vis[v] = 1;
				}
			}
		}
		return d[T] != inf;
	}
	int dfs(int u, int sum) {
		if (u == T) return sum;
		int used = 0;
		vis[u] = 1;
		for (int &i = cur[u], v; ~i; i = e[i].nxt) {
			if (e[i].fl && !vis[v = e[i].to] && d[v] == d[u] + e[i].w) {
				int fl = dfs(v, min(sum - used, e[i].fl));
				e[i].fl -= fl;
				e[i ^ 1].fl += fl;
				if ((used += fl) == sum) break;
			}
		}
		vis[u] = 0;
		return used;
	}
	int dinic() {
		int maxflow = 0, cost = 0;
		while (spfa()) {
			int flow = dfs(S, inf);
			cost += flow * d[T], maxflow += flow;
		}
		return maxflow == sum ? cost : -1;
	}
} using namespace flow_graph;

int n1, n2, m, R, B;
char c1[N], c2[N];

int main() {
	scanf("%d%d%d%d%d%s%s", &n1, &n2, &m, &R, &B, c1 + 1, c2 + 1);
	init(n1 + n2);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(R, 1, 0, u, v + n1);
		add(B, 1, 0, v + n1, u);
	}
	for (int i = 1; i <= n1 + n2; i++) {
		char c = i <= n1 ? c1[i] : c2[i - n1] == 'U' ? 'U' : 'R' + 'B' - c2[i - n1];
		if (c == 'R') {
			add(0, inf, 1, s, i);
		}
		if (c == 'B') {
			add(0, inf, 1, i, t);
		}
		if (c == 'U') {
			add(0, inf, 0, s, i);
			add(0, inf, 0, i, t);
		}
	}
	add(0, inf, 0, t, s);
	build();
	int cost = dinic();
	if (cost == -1) {
		puts("-1");
		return 0;
	}
	printf("%d\n", cost);
	for (int i = 0; i < 4 * m; i += 4) {
		if (!e[i].fl) {
			putchar('R');
		} else if (!e[i + 2].fl) {
			putchar('B');
		} else {
			putchar('U');
		}
	}
	puts("");
	return 0;
}