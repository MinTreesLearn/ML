#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dout(...) 0
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int i = 0;
  while (m > 0) {
    if (i == n) {
      cout << -1 << '\n';
      return 0;
    }
    if (m > i / 2) {
      a[i] = i + 1;
      m -= i / 2;
    } else {
      a[i] = i + 1;
      int extra = i / 2 - m;
      a[i] += extra * 2;
      m = 0;
    }
    i += 1;
  }
  while (i < n) {
    a[i] = 1e9 - 5005 * (n - 1 - i);
    i += 1;
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " \n"[i + 1 == n];
  }
  return 0;
}
