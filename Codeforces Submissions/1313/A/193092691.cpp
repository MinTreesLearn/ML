#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int ans = 0;
    for (int mask = 0; mask < (1 << 7); mask++) {
      int b[3] = {a[0], a[1], a[2]};
      for (int i = 1; i <= 7; i++)
        if ((mask >> (i - 1)) & 1)
          for (int j = 0; j < 3; j++)
            if ((i >> j) & 1)
              b[j]--;

      if (b[0] >= 0 && b[1] >= 0 && b[2] >= 0)
        ans = max(ans, __builtin_popcount(mask));
    }
    cout << ans << "\n";
  }
}