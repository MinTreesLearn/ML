/* Code by Reflective-FG */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forr(i, a, b) for (int i = a; i <= b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repp(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define init(a, i) memset(a, i, sizeof(a))
#define fi first
#define se second
#define MAXN 0x3f3f3f3f
#define ls node * 2 + 1
#define rs node * 2 + 2
int T_ = 1, case_;
const int N = 200005;
int n, m, k, l, r;
vector<pair<int, int>>p;
int dp[N][1 << 8];
vector<int>cur, tmp;
void solve() {
    cin >> n >> m >> k;
    repp(i, n) {
        cin >> l >> r;
        p.pb(mp(l, i)), p.pb(mp(r + 1, -i));
    }
    sort(p.begin(), p.end());
    init(dp, 128);
    dp[0][0] = dp[0][1] = 0;
    cur.pb(p[0].se);
    repp(i, 2 * n - 1) {
        int x = p[i].fi, f = p[i].se;
        int sz = cur.size();
        if (f > 0) {
            rep(msk, 1 << sz) {
                int add = (x - p[i - 1].fi) * (__builtin_popcount(msk) % 2);
                dp[i][msk] = max(dp[i][msk], dp[i - 1][msk] + add);
                dp[i][msk + (1 << sz)] = max(dp[i][msk + (1 << sz)], dp[i - 1][msk] + add);
            }
            cur.pb(f);
        }
        else {
            f *= -1;
            rep(msk, 1 << sz) {
                int add = (x - p[i - 1].fi) * (__builtin_popcount(msk) % 2);
                int nxt = 0, cnt = 0;
                rep(j, sz) {
                    if (cur[j] == f)continue;
                    if (msk & (1 << j))nxt += (1 << cnt);
                    cnt++;
                }
                dp[i][nxt] = max(dp[i][nxt], dp[i - 1][msk] + add);
            }
            tmp.clear();
            rep(j, sz) if (cur[j] != f)tmp.pb(cur[j]);
            cur = tmp;
        }
    }
    int ans = 0;
    rep(i, 256)ans = max(ans, dp[2 * n - 1][i]);
    cout << ans;
}
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    // cin >> T_;
    for (case_ = 1; case_ <= T_; case_++)solve();
    return 0;
}