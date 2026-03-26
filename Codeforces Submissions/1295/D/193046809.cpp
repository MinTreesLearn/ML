#include <bits/stdc++.h>
using namespace std;
#define E 1e-9
#define PI 3.141592653589793238462
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define INF 1e18
#define MOD 1000000007
#define SZ(a) int((a).size())
#define setbits(a) (__builtin_popcountll(a))
#define right(a) (__builtin_ctzll(a))
#define left(a) (__builtin_clzll(a))
#define parity(a) (__builtin_parityll(a))
#define msb(a) (__lg(a))
#define lsb(a) ((ll)(log2(a & -a)))
typedef std::numeric_limits<double> dbl;
typedef long long ll;
#define REP(i, a, b) for (ll i = a; i < b; i++)
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef pair<ll, pi> pii;
ll power(ll a, ll n)
{
    ll ans = 1ll;
    while (n > 0)
    {
        int last_bit = (n & 1ll);
        if (last_bit)
        {
            ans = ans * a;
        }
        a = a * a;
        n = n >> 1ll;
    }
    return ans;
}

//*********************DSU***********************

#define MAXV 110
vector<ll> Parent(MAXV), Rank(MAXV);
void Init(int n)
{
    REP(i, 1, n + 1)
    {
        Parent[i] = i;
        Rank[i] = 1;
    }
}
int Root(int x)
{
    if (Parent[x] != x)
        Parent[x] = Root(Parent[x]);
    return Parent[x];
}
void Union(int x, int y)
{
    int rx = Root(x), ry = Root(y);
    if (rx == ry)
        return;
    if (Rank[rx] > Rank[ry])
    {
        Parent[ry] = rx;
        Rank[rx] += Rank[ry];
    }
    else
    {
        Parent[rx] = ry;
        Rank[ry] += Rank[rx];
    }
}

//**********************END*************************

void PrimeFactors(ll m, map<ll, ll> &mp)
{
    for (ll j = 2; j * j <= m; j++)
    {
        while ((m % j) == 0)
        {
            mp[j] += 1;
            m /= j;
        }
    }
    if (m > 1)
        mp[m] += 1;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, m;
        cin >> a >> m;
        ll g = __gcd(a, m);
        map<ll, ll> gmp;
        map<ll, ll> mmp;
        PrimeFactors(m, mmp);
        PrimeFactors(g, gmp);
        for (auto it = gmp.begin(); it != gmp.end(); it++)
        {
            mmp[it->F] -= it->S;
        }
        vi res;
        for (auto it = mmp.begin(); it != mmp.end(); it++)
        {
            if (it->S > 0)
            {
                res.PB(it->F);
            }
        }
        ll ans = ((a + m - 1) / g) - ((a - 1) / g);
        for (ll i = 1; i < (1ll << SZ(res)); i++)
        {
            ll prod = g;
            ll cnt = 0ll;
            for (ll j = msb(i); j >= 0; j--)
            {
                if (i & (1ll << j))
                {
                    prod *= res[j];
                    cnt++;
                }
            }
            ll tmp = ((a + m - 1) / prod) - ((a - 1) / prod);
            if (cnt & 1ll)
                ans -= tmp;
            else
                ans += tmp;
        }
        cout << ans << '\n';
    }
    return 0;
}