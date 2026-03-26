/**
 * author:  magnus_hegdahl
 * created: 01.02.2023 00:25
 * problem: E2. String Coloring (hard version)
 * url:     https://codeforces.com/contest/1296/problem/E2
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  string s;
  cin >> n >> s;

  vector<int> color(n, -1);
  map<char, int> active;

  for (int i = 0; i < n; ++i) {
    auto it = active.upper_bound(s[i]);
    if (it == active.begin()) {
      color[i] = (int)active.size();
    } else {
      --it;
      color[i] = it->second;
      active.erase(it);
    }
    active.emplace(s[i], color[i]);
  }

  cout << active.size() << '\n';
  for (int c : color) cout << c + 1 << ' ';
  cout << '\n';
}
