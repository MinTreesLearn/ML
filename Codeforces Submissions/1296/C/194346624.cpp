#include <bits/stdc++.h>
using namespace std;
// #define int long long int

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int u = 0, v = 0;
    map<pair<int, int>, int> mp;
    int ans = (n + 5);
    int l, r;
    mp[{0, 0}] = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            u++;
        else if (s[i] == 'R')
            u--;
        else if (s[i] == 'U')
            v++;
        else if (s[i] == 'D')
            v--;

        pair<int, int> t = {u, v};
        // cout<<u<<" "<<v<<" -> "<<i<<"\n";
        if (mp.find(t) != mp.end())
        {

            if (ans > (i + 1 - mp[t] + 1))
            {
                ans = (i + 1) - mp[t] + 1;
                l = mp[t] + 1;
                r = i + 1;
            }
        }
        mp[{u, v}] = i + 1;
    }
    if (ans == (n + 5))
        cout << -1;
    else
        cout << l << " " << r;
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