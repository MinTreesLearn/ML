#include <bits/stdc++.h>

using namespace std;

#define i64 long long
#define db double
#define INF INT_MAX
#define endl "\n"
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define lc (node << 1)
#define rc (lc | 1)
#define pii pair<int, int>
#define pdd pair<db, db>

using namespace std;
const int N = 1e5 + 10;
const int mod = 998244353;

int vis[3][N];

void solve()
{
    int n, q;
    cin >> n >> q;
    int cnt = 0;
    for (int i = 1; i <= q; i++)
    {
        int r, c;
        cin >> r >> c;
        if (vis[r][c])
        {
            if (r == 1)
            {
                if (vis[2][c])
                    cnt--;
                if (vis[2][c + 1] && c + 1 <= n)
                    cnt--;
                if (vis[2][c - 1] && c - 1 >= 1)
                    cnt--;
            }
            else
            {
                if (vis[1][c])
                    cnt--;
                if (vis[1][c + 1] && c + 1 <= n)
                    cnt--;
                if (vis[1][c - 1] && c - 1 >= 1)
                    cnt--;
            }
        }
        else
        {
            if (r == 1)
            {
                if (vis[2][c])
                    cnt++;
                if (vis[2][c + 1] && c + 1 <= n)
                    cnt++;
                if (vis[2][c - 1] && c - 1 >= 1)
                    cnt++;
            }
            else
            {
                if (vis[1][c])
                    cnt++;
                if (vis[1][c + 1] && c + 1 <= n)
                    cnt++;
                if (vis[1][c - 1] && c - 1 >= 1)
                    cnt++;
            }
        }
        vis[r][c] ^= 1;
        if (cnt > 0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}

int main()
{
    int T;
    // cin >> T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}