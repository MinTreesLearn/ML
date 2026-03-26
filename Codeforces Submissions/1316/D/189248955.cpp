///Moba8ta gya mn el 2alb
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define popCnt(x) (__builtin_popcountll(x))
#define int ll

using ll = long long;
using ull = unsigned long long;
using uint = uint32_t;
using ii = pair<int, int>;

const int N = 1e5 + 5, A = 12, LG = 18, MOD = 1e9 + 7;
const long double PI = acos(-1);
const long double EPS = 1e-9;
const int INF = 1e18;
string DIC = "UDRLX";
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int n;
int dX[1005][1005], dY[1005][1005];
int ans[1005][1005];
void dfs(int x, int y)
{
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (dX[nx][ny] == dX[x][y] && dY[nx][ny] == dY[x][y])
        {
            if (ans[nx][ny] == -1)
            {
                ans[nx][ny] = k ^ 1;
                dfs(nx, ny);
            }
        }
    }
}
void doWork()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dX[i][j] >> dY[i][j];
            ans[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dX[i][j] == -1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (dX[nx][ny] == -1)
                    {
                        ans[i][j] = k;
                        break;
                    }
                }
            }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == dX[i][j] && j == dY[i][j])
            {
                ans[i][j] = 4;
                dfs(i, j);
            }
    f(i, 1, n + 1)
        f(j, 1, n + 1) if (ans[i][j] == -1)
    {
        cout << "INVALID\n";
        return;
    }
    cout << "VALID\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << DIC[ans[i][j]];
        cout << '\n';
    }
}
int32_t main()
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif // ONLINE_JUDGE
    int t = 1;
    // cin >> t;
    while (t--)
    {
        doWork();
    }
    return 0;
}