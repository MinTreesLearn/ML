#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    string text = "SET";
    for (int i = 0; i < n; i++)
    {
        map<string, int> mp;
        for (int j = i + 1; j < n; j++)
            mp[a[j]]++;

        for (int j = i + 1; j < n; j++)
        {
            mp[a[j]]--;
            string t;
            for (int w = 0; w < k; w++)
            {
                if (a[i][w] == a[j][w])
                    t.push_back(a[j][w]);
                else
                {
                    for (int m = 0; m < 3; m++)
                    {
                        if (a[i][w] != text[m] && a[j][w] != text[m])
                        {
                            t.push_back(text[m]);
                        }
                    }
                }
            }
            ans += mp[t];
        }
    }
    cout << ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}