#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long m; //!
    cin >> m;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum < m) {
      cout << -1 << '\n';
    } else {
      int ans = 0;
      vector<int> bits;
      for (int bit = 0; bit < 63; bit++) {
        if ((1LL << bit) & m) {
          bits.push_back(bit);
        }
      }
      reverse(bits.begin(), bits.end());
      sort(a.begin(), a.end());
      reverse(a.begin(), a.end());
      long long cur = 0;
      while ((int) a.size() > 0) {
        auto x = a.back();
        a.pop_back();
        cur += x;
        if (bits.empty()) {
          break;
        }
        if (cur >= (1LL << bits.back())) {
          if (cur & (1LL << bits.back())) {
            cur -= (1LL << bits.back());
            bits.pop_back();
          } else {
            cur -= x;
            int cValue = x;
            while (cValue > (1LL << bits.back())) {
              ans += 1;
              cValue /= 2;
              a.push_back(cValue);
            }
            assert(cValue == (1LL << bits.back()));
            bits.pop_back();
          }
        }
      }
      assert(bits.empty());
      cout << ans << '\n';
    }
  } 
  return 0; 
}