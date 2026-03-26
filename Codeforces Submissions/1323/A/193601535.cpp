#include <bits/stdc++.h>
#include <random>
#include <fstream>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define dbg(x) cout << #x << '=' << x << endl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define nl cout<<endl
#define ret return
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pr(x) cout << x << endl
#define forauto(v)        \
    for (auto &i : v)     \
        cout << i << ' '; \
    cout << endl;
#define iterate(x)                                    \
    for (auto itr = x.begin(); itr != x.end(); ++itr) \
    {                                                 \
        cout << *itr << ' ';                          \
    }                                                 \
    cout << endl;
ll myceil(ll a, ll b)
{
    if (a % b == 0)
        return a / b;
    else
        return a / b + 1;
}
bool isPerSquare(long double a)
{
    if (a < 0)
        return false;
    ll sr = sqrt(a);
    return (sr * sr == a);
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

void sumeet()
{
    ll n;
    cin >> n;
    v64 v(n);
    ll ct = 0;
    v64 odd, even;
    forn(i, n)
    {
        cin >> v[i];
        if (v[i] % 2 == 0)
            even.pb(i + 1);
        else
            odd.pb(i + 1);
    }
    if (odd.size() == 1 && even.size() == 0)
    {
        cout << -1;
        nl;
        ret;
    }
    if (even.size() == 0)
    {
        cout << "2\n";
        cout << odd[0] << " " << odd[1];
        nl; ret;
    }
    cout << "1\n";
    cout << even[0];
    nl;
}

int main()
{

    fast_cin();
    ll t = 1;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        sumeet();
        // cout << endl;
    }

    return 0;
}
