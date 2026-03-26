#include <bits/stdc++.h>
using namespace std;

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout); 
typedef long long ll;

template <typename T> void rd(T &x) {
    x = 0; char c; bool f = false;
    while (c = getchar(), !isdigit(c)) f |= (c == '-');
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x *= -1;
}

const int maxn = 2020 + 5;
const int mod = 998244353;
int qpow(int a, int b) {
    int c = 1;
    for (; b; b >>= 1, a = (ll)a * a % mod) if (b & 1) c = (ll)c * a % mod;
    return c;
}
int inv(int x) { return qpow(x, mod - 2); }

int n, k;

namespace Solve1 {
int f[maxn], A;
void solve() {
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j) (f[j] += f[j - i]) %= mod;
	for (int i = 1; i <= n; ++i) (A += f[i]) %= mod;
	printf("%d", A);
}
}
namespace Solve2 {
int f[maxn], A;
void solve() {
	f[0] = 1;
	for (int i = 1, u; (u = i * (i + 1) / 2) <= n; ++i)
		for (int j = u; j <= n; ++j) (f[j] += f[j - u]) %= mod;
	for (int i = 1; i <= n; ++i) (A += f[i]) %= mod;
	printf("%d", A);
}
}

int A;
vector<int> v, p, q;
bool chk() {
	p = v;
	for (int _ = 0; _ < k - 2; ++_) {
		for (int i = 0; i < (int)p.size(); ++i)
			for (int j = 0; j < p[i]; ++j) q.push_back(i + 1);
		p = move(q), q.clear(), reverse(p.begin(), p.end());
		ll C = 0;
		for (int i = 0; i < (int)p.size(); ++i) C += ll(i + 1) * p[i];
		if (C > n) return false;
	}
	return true;
}
void dfs(int p) {
	if (!chk()) return;
	++A;
	for (int i = p; i >= 1; --i) {
		v.push_back(i); dfs(i); v.pop_back();
	}
}

void solve() {
	dfs(64);
	printf("%d", A - 1);
}

int main() {
    // fo(function)
    rd(n), rd(k);
	if (k == 1) return Solve1::solve(), 0;
	if (k == 2) return Solve2::solve(), 0;
	solve();
    return 0;
}

