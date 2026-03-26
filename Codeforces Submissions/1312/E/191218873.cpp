#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define f first
#define s second
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
const int inf = 1e9 + 7;
int dp[510][510];
int ans[510];
int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL); cout.tie(NULL);
     int n; cin >> n;
     for (int i = 1; i <= n; i++) {
          cin >> dp[i][i];
     }
     for (int len = 2; len <= n; len++) {
          for (int l = 1; l + len - 1 <= n; l++) {
               int r = l + len - 1;
               for (int j = l; j < r; j++) {
                    if (dp[l][j] == dp[j + 1][r] and dp[l][j]) {
                         dp[l][r] = dp[l][j] + 1;
                    }
               }
          }
     }
     for (int i = 1; i <= n; i++) {
          ans[i] = inf;
          for (int j = 0; j < i; j++) {
               if (dp[j + 1][i]) {
                    ans[i] = min(ans[i], ans[j] + 1);
               }
          }
     }
     cout << ans[n] << '\n';
     return 0;
}