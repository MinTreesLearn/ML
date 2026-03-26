#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
const ll INF = 1e18+1;

class bounded_long {
  public:
    ll n;
    bounded_long() {n=0;};
    bounded_long(ll n): n(n){};
    bounded_long& operator+=(const bounded_long& other) {
      this->n = min(INF, this->n+other.n);
      return *this;
    }
};

int n, m;
ll k;
string s;
bounded_long dp[N][N];
bounded_long dp2[N][N];
// dp[i][j] = number of ways to split first i characters into exactly j
// substrings which are all greater than t

ll f(string& t) {
  // return the number of ways to split s into m strings so that every substring
  // is greater than t
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = 0;
      dp2[i][j] = 0;
    }
  }

  dp[0][0] = 1;
  int d = t.size();
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp2[i+1][j] += dp2[i][j];
      dp[i][j] += dp2[i][j];
    }
    int c = -1;
    // s[i:c] > t
    for (int j = i; j < n; j++) {
      if (j-i >= d || s[j] > t[j-i]) {
        c = j;
        break;
      }
      if (s[j] < t[j-i]) {
        break;
      }
    }
    if (c != -1) {
      for (int j = 0; j < m; j++) {
        dp2[c+1][j+1] += dp[i][j];
      }
    }
  }

  return dp[n][m].n;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k >> s;
  set<string> substringset;
  for (int i = 0; i < n; i++) {
    for (int j = 1; i+j <= n; j++) {
      substringset.insert(s.substr(i, j));
    }
  }
  vector<string> substrings(substringset.begin(), substringset.end());
  int z = substrings.size();
  int low = -1;
  int high = z-1;
  while (low+1 < high) {
    int mid = (low+high)/2;
    if (f(substrings[mid]) >= k) low = mid;
    else high = mid;
  }
  cout << substrings[high] << '\n';
}
