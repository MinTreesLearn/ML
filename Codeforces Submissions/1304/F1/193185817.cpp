#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  
  vector<vector<int>> p(n, vector<int>(m + 1));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      p[i][j + 1] = p[i][j] + a[i][j];

  vector<int> dp(m - k + 1);
  for (int i = 0; i + k <= m; i++)
    dp[i] = p[0][i + k] - p[0][i];

  for (int x = 1; x < n; x++) {
    vector<int> new_dp(m - k + 1);
    for (int y = 0; y + k <= m; y++) {
      for (int z = max(0, y - k + 1); z <= y; z++)
        new_dp[z] = max(new_dp[z], dp[y] + p[x][y + k] - p[x][z]);

      for (int z = y + 1; z < y + k && z + k <= m; z++)
        new_dp[z] = max(new_dp[z], dp[y] + p[x][z + k] - p[x][y]);
    }

    multiset<int> s;
    for (int y = k - 1; y < m - k + 1; y++)
      s.insert(dp[y] + p[x][y + k] - p[x][y]);
    
    for (int y = 0; y + k <= m; y++) {
      if (y + 2 * k - 1 <= m)
        s.erase(s.find(dp[y + k - 1] + p[x][y + 2 * k - 1] - p[x][y + k - 1]));

      if (y >= k)
        s.insert(dp[y - k] + p[x][y] - p[x][y - k]);

      if (!s.empty())
        new_dp[y] = max(new_dp[y], *s.rbegin() + p[x][y + k] - p[x][y]);
    }
    dp = new_dp;
  }
  cout << *max_element(dp.begin(), dp.end()) << "\n";
}