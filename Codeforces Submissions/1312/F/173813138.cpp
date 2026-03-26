#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << '\n';
}

const int N = 1000;
const int K = 100;
int dp[N][3];
int d[3];
int cyc = -1;

void pre() {
  for (int i = 0; i < N; ++i) for (int j = 0; j < 3; ++j) dp[i][j] = 0;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      set<int> st;
      for (int k = 0; k < 3; ++k) { 
        if (j == k && j != 0) continue;
        int to = max(0, i - d[k]);
        st.insert(dp[to][k]);
      }
      int mex = 0;
      while (st.count(mex)) ++mex;
      dp[i][j] = mex;
    }
  }
  for (int len = 1; len * 2 < N; ++len) {
    bool ok = true;
    for (int i = K; ok && i + len < N; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (dp[i][j] != dp[i + len][j]) ok = false;
      }
    } 
    if (ok) {
      cyc = len;
      break;
    }
  }
  // cout << cyc << '\n';
  // cout << '\n';
  // for (int i = 1; i <= N; ++i) {
  //   for (int j = 0; j < 3; ++j) {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
}

int grundy(ll n, int at) {
  if (n < N) return dp[n][at];
  int len = (n - K) % cyc;
  // deb("Hi");
  return dp[K + len][at];
}

void solve() {
  int n;
  cin >> n;
  for (int j = 0; j < 3; ++j) cin >> d[j];
  cyc = -1;
  pre();
  assert(cyc != -1);

  int ans = 0;
  vector<ll> a(n);
  for (ll &x : a) {
    cin >> x;
    ans ^= grundy(x, 0);
  }

  int cnt = 0;
  for (ll x : a) {
    ans ^= grundy(x, 0);
    for (int j = 0; j < 3; ++j) {
      ll to = max(0ll, x - d[j]);
      if ((ans ^ grundy(to, j)) == 0) ++cnt;
    }
    ans ^= grundy(x, 0);
  }

  cout << cnt << '\n';
}

int main() {
  // freopen("out.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
}