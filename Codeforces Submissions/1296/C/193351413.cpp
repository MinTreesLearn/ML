#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#define lana_del_rey ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll   long long int
#define clr(v,d ) memset(v, d, sizeof(v))
#define deb(x) cout<<#x<<"="<<x<<endl
using namespace std;
const ll Mod = 1000000007;
const ll N = 2002000;


map<pair<int, int>,int> mp;

void solve() {
   mp.clear();
   int n; cin>>n;
   string s; cin >> s;
   s = "0" + s;
   pair<int, int> ans = { -1, 1000000};
   pair<int, int> cur = {0, 0}; //LR  UD
   mp[cur] = 0;
   for (int i = 1; i <= n; i++) {
      if (s[i] == 'U') {
         cur.second++;
      }
      else if (s[i] == 'L') {
         cur.first++;
      }
      else if (s[i] == 'D') {
         cur.second--;
      }
      else if (s[i] == 'R') {
         cur.first--;
      }
      if (cur.first==0 && cur.second== 0|| mp[cur]) {
         if (ans.second - ans.first + 1 > i - mp[cur] + 1) {
            ans.first=mp[cur]+1;
            ans.second=i;
         }
      }
      mp[cur] = i;
   }

   if (ans.first==-1) cout << -1 << endl;
   else cout << ans.first << " " << ans.second << endl;


}

int main()
{
   lana_del_rey;
   int t = 1;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}