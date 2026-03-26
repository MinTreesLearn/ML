#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll binpow(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            n--;
            res = res * a;
        }
        else
        {
            n /= 2;
            a = a * a;
        }
    }
    return res;
}
void solve()
{
    ll n;
    cin >> n;
    ll temp = n;
    map<ll, ll> m;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            m[i]++;
            n /= i;
        }
    }
    if (n >= 2)
        m[n]++;
    n = temp;
    ll mn = n;
    for (ll i = 2; i * i <= n; i++)
    {
        ll res = 1;
        if (n % i == 0)
        {
            for (auto it : m)
            {
                ll x = binpow(it.first, it.second);
                if (i % x == 0)
                {
                    res = res * x;
                }
            }
            mn = min(mn, max(res, n / res));
        }
    }
    cout << mn << " " << n / mn << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
