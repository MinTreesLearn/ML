#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 5e5 + 10;
int n, a[N], m, b[N], tim, ans[N];
bool vis[N];
vector<int> g[N];
set<int> pos, valid;

void calc(int l, int r, int v) {
	auto it = valid.lower_bound(l);
	while(it != valid.end() && *it <= r) ans[*it] = v, it = valid.erase(it);
}

void update(int p, int v) {
	if(p < 1 || p > n) return;
	auto it = pos.lower_bound(p); int r = *it, l = *(-- it) + 1;
	tim = max(tim, (r - l) >> 1);
	int mid = (l + r) >> 1;
	if(vis[l]) calc(l, mid, v);
	if(vis[r]) calc(mid + 1, r, v);
}

void insert(int p) {
	vis[p] = true;
	if(p > 1 && !vis[p - 1]) pos.erase(p - 1); else pos.insert(p - 1);
	if(p < n && !vis[p + 1]) pos.erase(p); else pos.insert(p);
}

int main() {
	n = m = read();
	rep(i, 1, n) a[i] = b[i] = read();
	sort(b + 1, b + m + 1);
	m = unique(b + 1, b + m + 1) - (b + 1);
	pos.insert(0);
	rep(i, 1, n)
		pos.insert(i), valid.insert(i), 
		a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b, g[a[i]].eb(i);
	rep(i, 1, m) {
		for(int o : g[i]) insert(o);
		for(int o : g[i]) rep(d, -1, 1) update(o + d, i);
	}
	printf("%d\n", tim);
	rep(i, 1, n) printf("%d%c", b[ans[i]], i == n ? '\n' : ' ');
	return 0;
}
