#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back
typedef pair<int, int> pii;
#define mp make_pair
#define fi first
#define se second

const int N = 1010;
int n, m, t, lcp[N][N]; ll k; char str[N];
pii arc[N * N];

bool cmp(pii p, pii q) {
	int lenp = p.se - p.fi + 1;
	int lenq = q.se - q.fi + 1;
	int len = lcp[p.fi][q.fi];
	if(len < min(lenp, lenq)) return str[p.fi + len] < str[q.fi + len];
	return lenp < lenq;
}

ll f[N][N];

bool check(int mid) {
	f[n + 1][0] = 1;
	int len = arc[mid].se - arc[mid].fi + 1;
	per(i, n, 1) {
		rep(j, 0, m) f[i][j] = 0;
		int lim = min(len, lcp[arc[mid].fi][i]);
		if(lim == len || str[i + lim] > str[arc[mid].fi + lim])
			rep(j, 1, m) f[i][j] = f[i + lim + 1][j - 1];
		if(i > 1) rep(j, 0, m) f[i][j] = min(k, f[i + 1][j] + f[i][j]);
	}
	return (f[1][m] >= k);
}

int main() {
	scanf("%d %d %lld", &n, &m, &k);
	scanf("%s", str + 1);
	per(i, n, 1) per(j, n, 1) lcp[i][j] = (str[i] == str[j]) ? lcp[i + 1][j + 1] + 1 : 0;
	rep(l, 1, n) rep(r, l, n) arc[++ t] = mp(l, r);
	sort(arc + 1, arc + t + 1, cmp);
	
	/* rep(i, 1, t) {
		rep(j, arc[i].fi, arc[i].se) cerr << str[j];
		cerr << "\n";
		cerr << "current " << check(i) << endl;
	} */
	
	int l = 1, r = t;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid; else r = mid - 1;
	}
	
	l ++;
	rep(i, arc[l].fi, arc[l].se) putchar(str[i]);
	puts("");
	return 0;
}
