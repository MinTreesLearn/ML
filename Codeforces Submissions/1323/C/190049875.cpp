#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<string>
#include<deque>
#include<stack>
#include<queue>
#include<iomanip>
#include<fstream>
#include<cmath>
#include<math.h>
#define int long long
#define all(x) x.begin(), x.end()
#define YN(a) cout << (a ? "YES" : "NO") << endl;
#define size(v) (int) v.size()
#define left node * 2, l, (l + r) / 2
#define right node * 2 + 1, (l + r) / 2 + 1, r
#define debug cout << "!" << endl;
#define mod (int) 998244353
#define mod1 (int) 1e9 + 7
#define N (int) 500005
using namespace std;
void solve(){
     int n;
     cin >> n;
     string s;
     cin >> s;
     int ans = 0;
     int cnt = 0;
     for(int i = 0; i < size(s); i++){
          int prev = cnt;
          if(s[i] == '(') cnt++;
          else cnt--;
          if(cnt < 0 || prev < 0) ans++;
     }
     if(cnt != 0){
          cout << -1 << endl;
          return;
     }
     cout << ans << endl;
}
signed main() {
     int q = 1;
     //cin >> q;
     while (q--) {
          solve();
     }
}
