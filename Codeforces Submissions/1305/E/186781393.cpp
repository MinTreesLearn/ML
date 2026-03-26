#include <bits/stdc++.h>
// #pragma GCC optimize(2)
#define N 5005
// #define mod 998244353
// #define endl '\n'
#define int long long
// #define double long double
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
using namespace std;

int n, m, tmp[N], num[N];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) num[i] = i;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (i - 1) / 2;
        if (ans >= m)
        {
            num[i] -= (m - ans) * 2;
            for (int j = i + 1; j <= n; j++) num[j] = num[j - 1] + num[i] * 2;
            for (int i = 1; i <= n; i++) cout << num[i] << " ";
            return;
        }
    }
    cout << -1 << endl;
}
signed main()
{
    // fastio;
    // freopen("data.in", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    // fclose(stdin);
}