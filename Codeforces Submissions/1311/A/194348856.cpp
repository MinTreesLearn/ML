#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << __LINE__ << "| " << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define YES cout << "YES\n"
#define NO cout << "NO\n"

void solve() {
  int x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "0\n";
    return;
  }

  if ((x ^ y) & 1) {
    cout << 1 + (x > y) << "\n";
    return;
  }
  cout << 1 + (x < y) << "\n";
}

int main(int argc, char *argv[]) {
  // ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
