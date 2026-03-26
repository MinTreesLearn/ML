#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back

const int P = 998244353;
inline int plu(int x, int y) {return x + y >= P ? x + y - P : x + y;}
inline int del(int x, int y) {return x - y <  0 ? x - y + P : x - y;}
inline void add(int &x, int y) {x = plu(x, y);}
inline void sub(int &x, int y) {x = del(x, y);}
inline int qpow(int a, int b) {int s = 1; for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) s = 1ll * s * a % P; return s;}

const int N = 2025;
int n, k;

namespace K1 {
	int f[N];
	void solve() {
		f[0] = 1; int ans = 0;
		rep(i, 1, n) rep(j, 0, n - i) add(f[j + i], f[j]);
		rep(i, 1, n) add(ans, f[i]);
		printf("%d\n", ans);
	}
}

namespace K2 {
	int f[N];
	void solve() {
		f[0] = 1; int ans = 0;
		for(int i = 1; i * (i + 1) / 2 <= n; i ++)
			for(int j = 0; j + i * (i + 1) / 2 <= n; j ++) add(f[j + i * (i + 1) / 2], f[j]);
		rep(i, 1, n) add(ans, f[i]);
		printf("%d\n", ans);
	}
}

namespace Brute {
	int ans = 0; vector<int> cur;
	
	bool check() {
		vector<int> tmp = cur;
		per(i, k - 1, 1) {
			sort(tmp.begin(), tmp.end());
			reverse(tmp.begin(), tmp.end());
			int sum = 0, len = tmp.size();
			rep(j, 0, len - 1) sum += tmp[j] * (j + 1);
			if(sum > n) return false;
			if(i > 3 && sum > 23) return false;
			if(i == 1) continue;
			vector<int> nxt;
			rep(j, 0, len - 1) rep(t, 1, tmp[j]) nxt.eb(j + 1);
			tmp = nxt;
		}
		return true;
	}
	
	bool dfs(int lim) {
		if(! check()) return false; else ans ++;
		rep(i, lim, n) {
			cur.eb(i); bool now = dfs(i); cur.pop_back();
			if(!now) return true;
		}
		return true;
	}
	
	void solve() {dfs(1); printf("%d\n", ans - 1);}
}

int main() {
	scanf("%d %d", &n, &k);
	if(k == 1) K1::solve(); else if(k == 2) K2::solve(); else Brute::solve();
	return 0;
}
