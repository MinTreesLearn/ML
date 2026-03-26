#include "bits/stdc++.h"

using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while (t--) {

    int n, m; cin >> n >> m;

    int tot = 0;
    while (n--) {
      int x; cin >> x;
      tot += x;
    }

    cout << min(tot, m) << "\n";

  }
  
}

// ~ BucketPotato