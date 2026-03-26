#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  //cin >> tt;
  while (tt--) {
    ll n;
    cin >> n;
    vector <pair <double, double>> a(n);
    for (int i = 0;i < n; i++)
      cin >> a[i].first >> a[i].second;
    if (n % 2) {
      cout << "NO\n";
      break;
    }
    a.push_back(a[0]);
    bool f = true;
    for (int i = 0; i < n / 2; i++) {
      int k = i + n / 2;
      if (a[i + 1].first - a[i].first != a[k].first - a[k + 1].first or a[i + 1].second - a[i].second != a[k].second - a[k + 1].second)
        f = false;
    }
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
