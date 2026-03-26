#include <bits/stdc++.h>
#define ll long long

ll a[(int)2e3 + 5], dp[(int)2e3 + 5][(int)2e3 + 5];
ll n, h, l, r;
ll vaild(int x) {
  return ((x >= l && x <= r) ? 1ll : 0ll);
}

void solve() {
  std::cin >> n >> h >> l >> r;
  for(int i = 0; i < n; ++i)
    std::cin >> a[i];
  
  for(int i = (n - 1); i >= 0; --i) {
    for(int j = h; j >= 0; --j) {
      ll v1 = dp[i + 1][(j + a[i]) % h] + vaild((j + a[i]) % h);
      ll v2 = dp[i + 1][(((j + a[i] - 1) % h) + h) % h] + vaild((((j + a[i] - 1) % h) + h) % h);
      dp[i][j] = std::max(v1, v2);
    }
  }
  std::cout << dp[0][0] << "\n";
}

int main() {
  //#
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  //#

  solve();
  //std::cout << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
  return 0;
}
