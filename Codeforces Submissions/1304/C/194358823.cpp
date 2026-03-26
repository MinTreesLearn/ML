#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    // sort(a.begin(), a.end());
    int lt = m, ht = m;
    int prvt = 0;
    for (int i = 0; i < n; i++)
    {
        int ftime = (a[i][0] - prvt);

        lt -= ftime;
        ht += ftime;
        if (lt > a[i][2] || ht < a[i][1])
        {
            cout << "NO";
            // cout << " -> " << i;
            return;
        }
        lt = max(lt, a[i][1]);
        ht = min(ht, a[i][2]);
        prvt = a[i][0];
    }
    cout << "YES";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}