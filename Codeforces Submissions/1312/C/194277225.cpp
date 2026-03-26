#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        ll cnt = 0;
        if (a[i] == 1)
        {
            m[0]++;
            continue;
        }
        while (a[i])
        {
            while (a[i] % k == 0)
            {
                a[i] /= k;
                cnt++;
            }
            a[i]--, m[cnt]++;
        }
    }
    for (auto it : m)
    {
        // cout << it.first << " " << it.second << endl;
        if (it.second > 1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
