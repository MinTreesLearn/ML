#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.rbegin(), a.rend());

    int ans = 0;
    if (a[0] > 0)
      ans++, a[0]--;
    if (a[1] > 0)
      ans++, a[1]--;
    if (a[2] > 0)
      ans++, a[2]--;
    if (a[0] > 0 and a[1] > 0)
      ans++, a[0]--, a[1]--;
    if (a[0] > 0 and a[2] > 0)
      ans++, a[0]--, a[2]--;
    if (a[1] > 0 and a[2] > 0)
      ans++, a[1]--, a[2]--;
    if (a[0] > 0 and a[1] > 0 and a[2] > 0)
      ans++, a[0]--, a[1]--, a[2]--;

    cout << ans << "\n";
  }
}
