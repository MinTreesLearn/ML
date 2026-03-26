#include "bits/stdc++.h"

using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m, p;
  cin >> n >> m >> p;

  vector<int> a(n), b(m);

  for (int &i : a) cin >> i;
  for (int &i : b) cin >> i;

  int i1 = n - 1;
  while (a[i1] % p == 0) i1--;

  int i2 = m - 1;
  while (b[i2] % p == 0) i2--;

  cout << (i1 + i2) << "\n";
  
}