#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int INF = 1e9;
int lpf[N], lca[N][N];
int vp[N], freq[N], freqs[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  iota(lpf, lpf+N, 0);
  for (int l = 1; l < N; l++) {
    for (int r = l+1; r < N; r++) {
      lca[l][r] = INF;
    }
  }
  for (int i = 2; i < N; i++) {
    if (lpf[i] == i) {
      for (int j = i; j < N; j += i) {
        lpf[j] = i;
      }
    }
  }
  
  for (int i = 2; i < N; i++) {
    lca[i-1][i] = 0;
    for (int j = lpf[i]; j < i; j++) {
      lca[i-1][i] += vp[j];
    }
    lca[i][i-1] = lca[i-1][i];
    int v = i;
    while (v > 1) {
      vp[lpf[v]]++;
      v /= lpf[v];
    }
    for (int j = 0; j <= i; j++) {
      lca[i][i] += vp[j];
    }

  }

  for (int l = 1; l < N; l++) {
    for (int r = l+2; r < N; r++) {
      lca[l][r] = min(lca[l][r-1], lca[r-1][r]);
      lca[r][l] = lca[l][r];
    }
  }

  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    freq[x]++;
    ans += lca[x][x];
  }
  for (int i = 1; i < N; i++) {
    freqs[i] = freqs[i-1]+freq[i];
  }

  int dep = 0;
  while (1) {
    bool found = 0;
    for (int l = 1; l < N; l++) {
      int r = l;
      if (lca[l][l] <= dep) continue;
      while (r+1 < N && lca[l][r+1] > dep) r++;
      int cnt = freqs[r]-freqs[l-1];
      if (cnt > n-cnt) {
        ans -= 1LL*(2*cnt-n)*(lca[l][r]-dep);
        dep = lca[l][r];
        found = 1;
        break;
      }
    }
    if (!found) break;
  }
  cout << ans << '\n';
}
