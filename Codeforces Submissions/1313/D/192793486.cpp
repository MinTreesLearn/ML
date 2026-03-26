// LUOGU_RID: 93184384
#include <bits/stdc++.h>
#define cnt(x) __builtin_parity(x)
using namespace std;
constexpr int N = 1e5 + 9, S = 64;
int n, m, k, dp[S], bt[N];
vector<pair<int, int>> es;
signed main() {
cin.tie(nullptr)->sync_with_stdio(false);
cin >> n >> m >> k, es.reserve(n << 1), k = 1 << k;
for (int i = 1, l, r; i <= n; ++i) {
cin >> l >> r;
es.emplace_back(l, i);
es.emplace_back(r + 1, -i);
}
ranges::sort(es);
for (int q = 0, tot = 0; auto [p, id] : es) {
q += p -= q;
if (id > 0) {
int h = bt[id] = (tot + 1) & ~tot;
for (int i = 0; i < k; ++i)
if ((i & tot) == i) dp[i | h] = dp[i] += p * cnt(i);
tot ^= h;
} else {
int h = bt[-id];
tot ^= h;
for (int i = 0; i < k; ++i)
if ((i & tot) == i)
dp[i] = max(dp[i] + p * cnt(i), dp[i | h] + p * cnt(i | h));
}
}
return cout << dp[0] << endl, 0;
}