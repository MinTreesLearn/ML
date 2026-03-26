#include "bits/stdc++.h"

using namespace std;

#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while (t--) {

    int n; cin >> n;
    string s; cin >> s;

    vector<int> a;
    int cc = 1;
    for (char c : s) {
      if (c == '<') cc++;
      else {
        a.push_back(cc);
        cc = 1;
      }
    }
    a.push_back(cc);

    {
      int sf = n;
      for (int x : a) {
        sf -= (x - 1);
        for (int i = 0; i < x; i++) {
          cout << (sf++) << " ";
        }
        sf -= (x + 1);
      }
      cout << "\n";
    }
    {
      int tot = n - a.size();
      int st = n - tot + 1;
      int fv = n - tot;

      for (int x : a) {
        cout << (fv--) << " ";
        for (int i = 1; i < x; i++) {
          cout << (st++) << " ";
        }
      }

      cout << "\n";

    }

  }
  
}