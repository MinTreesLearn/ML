#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

using namespace std;
using namespace __gnu_pbds;

// less<int> -> increasing order, greater<int>->decreasing order, less_equal<int> -> work as multiset
typedef tree<pair<long long int, long long int>, null_type, less<pair<long long int, long long int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order(index) -> iterator of element at x
// order_of_key(key) -> all element strictly less than key.

typedef long long ll;
typedef long double ld;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<pair<ll, ll>> vp64;
typedef vector<vector<ll>> vv64;

#define forauto(v)        \
    for (auto i : v)      \
    {                     \
        cout << i << " "; \
    }                     \
    cout << ln;

#define fori(n) for (ll i = 0; i < n; i++)
#define fori1(n) for (ll i = 1; i <= n; i++)
#define forj1(n) for (ll j = 1; j <= n; j++)
#define forj(n) for (ll j = 0; j < n; j++)
#define forsn(i, s, n) for (ll i = s; i < n; i++)
#define ln "\n"
#define pb push_back
#define m1e9 998244353
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const ll N = 2e5 + 5;
ll fact[N], invfact[N];
ll power(ll x, ll y)
{
    ll res = 1;
    x = x % m1e9;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % m1e9;
        }

        y = y >> 1;
        x = (x * x) % m1e9;
    }
    return res;
}
ll modinv(ll n)
{
    return power(n, m1e9 - 2);
}
void f()
{
    fact[0] = 1;
    invfact[0] = 1;
    fori1(N)
    {
        fact[i] = (fact[i - 1] * i) % m1e9;
        invfact[i] = modinv(fact[i]);
    }
}
ll NCR(ll n, ll r)
{

    if (n < r)
    {
        return 0;
    }

    if (r < 0)
    {
        return 0ll;
    }
    if (r == 0 or r == n)
        return 1ll;
    return ((fact[n] * invfact[r] % m1e9) * invfact[n - r]) % m1e9;
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    /*
    n= 6
    m= 10
    1 2 3 4 5 6

    ct -> n-1

    equal pair -> n-2


    */

    ll ans = NCR(m, n - 1);
    ans = (ans * (n - 2)) % m1e9;

    ans = (ans * power(2, n - 3)) % m1e9;
    cout<<ans<<ln;
}
int main()
{
    fast_cin();
    ll t = 1;
    f();
    while (t--)
    {

        solve();
    }

    return 0;
}