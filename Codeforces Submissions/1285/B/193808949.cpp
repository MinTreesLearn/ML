#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
int a[N], s[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int ans = -1e18, minm = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            ans = max(ans, a[i]);
            for (int j = 1; j < n; j++)
                ans = max(ans, s[i] - s[j]);
        }
        else
            ans = max(ans, s[i] - minm);
        minm = min(minm, s[i]);
    }
    // cout << ans << endl;
    if (ans >= s[n])
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}