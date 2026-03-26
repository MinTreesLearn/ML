#include "bits/stdc++.h"

using namespace std;

#define ll long long

string query(int l, int r) {

  cout << "? " << l << " " << r << "\n";
  cout.flush();

  int n = r - l + 1;

  vector<vector<int>> a(n + 1, vector<int>(26));

  for (int i = 0; i < (n * (n + 1)) / 2; i++) {
    string curr; cin >> curr;
    for (char c : curr) {
      a[curr.size()][c - 'a']++;
    }
  }

  string cv(n, '?');

  if (n == 2) {
    int ind = 0;
    for (int i = 0; i < a[n].size(); i++) {
      while (a[n][i]) {
        cv[ind++] = 'a' + i;
        a[n][i]--;
      }
    }
    return cv;
  }

  vector<pair<char,int>> sf;
  for (int i = 0; i < n - i - 1; i++) {
    int cc = i + 2;

    for (auto [c, x] : sf) {
      a[cc][c - 'a'] += (cc - x - 1);
    }

    for (int j = 0; j < a[cc].size(); j++) {
      if (a[cc][j] < a[n][j] * cc) {
        if (cv[i] == '?') cv[i] = 'a' + j;
        else cv[n - i - 1] = 'a' + j;
        sf.push_back({'a' + j, i});
        a[cc][j]++;
        j--;
      }
    }
  }

  if (n % 2) {
    for (auto [c, x] : sf) {
      a[n][c - 'a']--;
    }
    for (int i = 0; i < a[n].size(); i++) {
      if (a[n][i]) {
        cv[n / 2] = 'a' + i;
        break;
      }
    }
    assert(cv[n / 2] != '?');
  }

  return cv;

}

char diff(string a, string b) {

  vector<int> fr(26);
  for (char c : a) fr[c - 'a']++;
  for (char c : b) fr[c - 'a']--;

  for (int i = 0; i < fr.size(); i++) {
    if (fr[i] != 0) {
      return 'a' + i;
    }
  }

  return 0;

}

char other(char x, char y, char z) {
  if (y == x) return z;
  return y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;

  if (n <= 3) {

    string ans = "";
    for (int i = 1; i <= n; i++) {
      ans += query(i, i);
    }

    cout << "! " << ans << "\n";
    cout.flush();
    return 0;

  }

  int fs = (n + 1) / 2;

  string fp = query(1, fs);
  string sp = query(2, fs);
  string av = query(1, n);

  string ans(n, '?');

  ans[0] = diff(fp, sp);
  int l = 1, r = fs - 1;
  while (l <= r) {
    ans[r] = other(ans[l - 1], fp[r], fp[fs - r - 1]);
    int ind = r - 1;
    ans[l] = other(ans[r], sp[ind], sp[fs - ind - 2]);
    l++; r--;
  }

  for (int i = 0; i < n; i++) {
    int oi = (n - i - 1);
    if (i >= oi) break;
    ans[oi] = other(ans[i], av[i], av[oi]);
  }

  cout << "! " << ans << "\n";
  
}

// ~ BucketPotato