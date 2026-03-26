#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef map<ll, ll> mll;

#define N 200'006
#define MOD 1000000007
#define FOR(i, n) for (i = 0; i < n; i++)
#define FORR(i, a, b) for (i = a; i <= b; i++)
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define FREOPEN                  \
    freopen("i.in", "r", stdin); \
    freopen("o.out", "w", stdout);
#define gohome      \
    cout << "NO\n"; \
    return;
#define arprt(x)           \
    for (auto it : x)      \
        cout << it << " "; \
    cout << "\n";

int main()
{
    FASTIO
    ll i, j, n, m, p = -1;
    cin >> n >> m;
    ll a[n];
    ll trips = 0;
    for (i = 0; i < n; i++)
    {
        trips += i / 2;
        if (trips > m)
        {
            trips -= i / 2;
            p = i - 1;
            break;
        }
    }
    if (p == -1)
    {
        if (trips == m)
        {
            for (i = 1; i <= n; i++)
                cout << i << " ";
        }
        else
            cout << -1;
        return 0;
    }
    for (i = 0; i <= p; i++)
        a[i] = i + 1;

    ll t = m - trips;
    a[p + 1] = 2 * (p + 1) - 2 * t + 1;

    for (i = p + 2; i < n; i++)
    {
        a[i] = N * i + 1;
    }
    arprt(a);
    return 0;
}
