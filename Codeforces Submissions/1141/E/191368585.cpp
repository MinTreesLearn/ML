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

#define MAXV 150001
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
    if (Rank[rx] >= Rank[ry])
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h, n;
    cin >> h >> n;
    vi d(n);
    REP(i, 0, n)
    cin >> d[i];
    vi prefix(n + 1, 0);
    prefix[1] = d[0];
    REP(i, 1, n)
    prefix[i + 1] = d[i] + prefix[i];
    ll mi = INF;
    ll mi_idx = -1;
    REP(i, 1, n + 1)
    {
        if (mi > prefix[i] && prefix[i] < 0)
        {
            mi = prefix[i];
            mi_idx = i;
        }
    }
    if (mi_idx == (-1))
        cout << mi_idx << '\n';
    else
    {
        if (h <= (-1ll * mi))
        {
            ll ans = mi_idx;
            for (ll j = mi_idx - 1; j > 0; j--)
            {
                if (h <= (-1ll * prefix[j]))
                {
                    ans = j;
                }
            }
            cout << ans << '\n';
        }
        else if (prefix[n] >= 0)
            cout << "-1\n";
        else
        {
            h += mi;
            ll div = (h / abs(prefix[n]));
            ll rem = (h % abs(prefix[n]));
            ll ans = (div * 1ll * n) + mi_idx;
            if (rem == 0)
            {
                cout << ans << '\n';
            }
            else
            {
                ll i = (mi_idx) % (n);
                while (rem > 0)
                {
                    ans++;
                    rem += d[i];
                    i = (i + 1) % (n);
                }
                cout << ans << '\n';
            }
        }
    }
    return 0;
}