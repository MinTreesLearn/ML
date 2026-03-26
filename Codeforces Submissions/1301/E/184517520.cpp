#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <random>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define AboTaha_on_da_code ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second

const int dx[8]={0, 0, 1, -1, 1, -1, -1, 1}, dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
const int M = 1e9+7, M2 = 998244353;
const double EPS = 1e-9;

vector <vector <int>> dp[10][10], ps[4];

void burn(int tc)
{
    map <char, int> mp{{'R', 0}, {'G', 1}, {'B', 2}, {'Y', 3}};
    int n, m, q; cin >> n >> m >> q;
    for (auto &i : ps) i.resize(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x; cin >> x;
            ps[mp[x]][i][j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                ps[k][i][j]+=ps[k][i][j-1];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                ps[k][j][i]+=ps[k][j-1][i];
            }
        }
    }
    for (auto &i : dp) for (auto &j : i) j.resize(n, vector <int> (m, 0));
    int mx[] = {0, 0, 1, 1}, my[] = {0, 1, 1, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int st = 1, en = n*m;
            while(st <= en) {
                int mi = (st+en)/2;
                bool ok = true;
                for (int k = 0; k < 4; k++) {
                    int nx = i-mi+1+mi*mx[k], ny = j-mi+1+mi*my[k];
                    if (nx < 0 || ny < 0 || nx+mi-1 >= n || ny+mi-1 >= m) {
                        ok = false;
                        break;
                    }
                    int sm = ps[k][nx+mi-1][ny+mi-1];
                    if (nx > 0) sm-=ps[k][nx-1][ny+mi-1];
                    if (ny > 0) sm-=ps[k][nx+mi-1][ny-1];
                    if (nx > 0 && ny > 0) sm+=ps[k][nx-1][ny-1];
                    if (sm != 1LL*mi*mi) ok = false;
                }
                if (ok) dp[0][0][i][j] = mi, st = mi+1;
                else en = mi-1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int p = 1; p < 10; p++) {
            for (int j = 0; j+(1<<p) <= m; j++) {
                dp[0][p][i][j] = max(dp[0][p-1][i][j], dp[0][p-1][i][j+(1<<(p-1))]);
            }
        }
    }
    for (int p1 = 0; p1 < 10; p1++) {
        for (int p2 = 1; p2 < 10; p2++) {
            for (int i = 0; i+(1<<p1) <= m; i++) {
                for (int j = 0; j+(1<<p2) <= n; j++) {
                    dp[p2][p1][j][i] = max(dp[p2-1][p1][j][i], dp[p2-1][p1][j+(1<<(p2-1))][i]);
                }
            }
        }
    }

    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        int st = 1, en = n*m, ans = 0;
        while(st <= en) {
            int mi = (st+en)/2;
            int r1 = x1+mi-1, c1 = y1+mi-1, r2 = x2-mi, c2 = y2-mi;
            bool ok = true;
            if (r1 > r2 || c1 > c2 || r2 >= n || c2 >= m) ok = false;
            else {
                int hei = 31-__builtin_clz(r2-r1+1), wid = 31-__builtin_clz(c2-c1+1);
                int opt = max({dp[hei][wid][r1][c1], dp[hei][wid][r1][c2-(1<<wid)+1],
                               dp[hei][wid][r2-(1<<hei)+1][c1], dp[hei][wid][r2-(1<<hei)+1][c2-(1<<wid)+1]});
                if (opt < mi) ok = false;
            }
            if (ok) ans = 4*mi*mi, st = mi+1;
            else en = mi-1;
        }
        cout << ans << '\n';
    }
}

int main()
{
    AboTaha_on_da_code

//    freopen("Ain.txt", "r", stdin);
//    freopen("Aout.txt", "w", stdout);

    int T = 1; // cin >> T;

    for (int i = 1; i <= T; i++) {
//        cout << "Case #" << i << ": ";
        burn(i);
        cout << '\n';
    }
    return 0;
}