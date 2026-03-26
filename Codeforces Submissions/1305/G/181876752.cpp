// LUOGU_RID: 94953770
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1 << 18;
int n, fa[N], sz[N];
long long ans;
int findf(int x) { return x == fa[x] ? x : fa[x] = findf(fa[x]); }
void unite(int u, int v, int w) {
  if (!sz[u] || !sz[v]) return;
  if ((u = findf(u)) == (v = findf(v))) return;
  ans += w * (sz[u] + sz[v] - 1ll), sz[fa[u] = v] = 1;
}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n, sz[0] = 1;
  for (int i = 1, a; i <= n; ++i) cin >> a, ans -= a, ++sz[a];
  iota(fa, fa + N, 0);
  for (int i = N - 1; i; --i) {
    int j = i;
    do unite(j, i ^ j, i), j = (j - 1) & i;
    while (j != i);
  }
  return cout << ans << endl, 0;
}