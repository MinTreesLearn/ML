#include <bits/stdc++.h>
using LL = long long;
[[maybe_unused]] constexpr int mod = 1e9 + 7, N = 3e5 + 10;

LL a[N], n, sum[N];

void solve() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  std::map<LL, int> c1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      c1[sum[j] - sum[i - 1]]++;
    }
  }
  std::vector<std::pair<LL, LL>> ans;
  for (auto [x, c] : c1) {
    if (c > 1)
      ans.emplace_back(c, x);
  }
  if (ans.empty()) {
    std::cout << "1\n1 1\n";
  } else {
    std::sort(ans.begin(), ans.end());
    std::reverse(ans.begin(), ans.end());
    int m = 0;
    std::vector<std::pair<int, int>> real_ans;
    for (auto [c, x] : ans) {
      // std::cout << x << ' ' << c << '\n';
      std::map<LL, int> mp;
      std::vector<std::pair<int, int>> tmp;
      mp[0] = 0;
      for (int i = 1; i <= n; ++i) {
        if (mp.count(sum[i] - x)) {
          tmp.emplace_back(mp[sum[i] - x] + 1, i);
          mp.clear();
        }
        mp[sum[i]] = i;
      }
      if (tmp.size() > real_ans.size())
        real_ans.swap(tmp);
      // if (m++ == 5 * n) break;
    }
    std::cout << real_ans.size() << '\n';
    for (auto [l , r] : real_ans) {
      std::cout << l << ' ' << r << '\n';
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}