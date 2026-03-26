// Submitted by Sakshi Agrawal

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T-- != 0) {
    int a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    string res = s;
    s = "C" + s;
    int n = s.length(), cnt = 0, f = -1, prev = -1;
    for (int i = n - 2; i > 0; i--) {
      if (s[i] != s[i - 1]) {
        cnt += (s[i] == 'A' ? a : b);
        if (cnt > p) {
          f = (prev == -1 ? n - 1 : prev);
          break;
        }
        prev = i;
      }
    }
    if (f == -1)
      cout << 1 << endl;
    else
      cout << f << endl;
  }
  return 0;
}
