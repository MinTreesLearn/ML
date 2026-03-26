// LUOGU_RID: 102631276
#include <bits/stdc++.h>

constexpr int N = 1e5 + 10;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> divs(N);
  std::vector<int> mu(N);
  for (int i = 1; i < N; ++i) {
    mu[i] += i == 1;
    divs[i].emplace_back(i);
    for (int j = i * 2; j < N; j += i) {
      divs[j].emplace_back(i);
      mu[j] -=  mu[i];
    }
  }


  std::vector<int> a(N);
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    std::cin >> x;
    for (int j : divs[x]) {
      a[j] = 1;
    }
    res = std::max(res, 1LL * x);
  }

  std::stack<int> sta;
  std::vector<int> cnt(N);
  for (int i = N - 1; i; --i) {
    if (a[i]) {
      int sum = 0;
      for (int j : divs[i]) {
        sum += mu[j] * cnt[j];
      }
      while (!sta.empty()) {
        if (sum == 0) {
          break;
        }
        int x = sta.top();
        res = std::max(res, 1LL * i * x / std::__gcd(i, x));
        for (int j : divs[x]) {
          --cnt[j];
          if (i % j == 0) {
            sum -= mu[j];
          }
        }
        sta.pop();
      }
      sta.push(i);
      for (int j : divs[i]) {
        ++cnt[j];
      }
    }
  }

  std::cout << res << '\n';
}