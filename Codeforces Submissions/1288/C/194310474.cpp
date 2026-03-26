#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e5+10, M = 1050, inf = 1e6, mod = 1e9+7;
ll add ( ll a , ll b)
{
    return (a + b) % mod;
}
ll mul ( ll a , ll b)
{
    return 1LL * a * b % mod;
}
ll fp( ll b , ll p)
{
    if(!p)
        return 1;
    ll temp = fp(b,p/2);
    temp = mul(temp,temp);
    if(p&1)
        temp = mul(temp,b);
    return temp;
}
ll fact[N], inv[N];
ll nCr( ll n , ll r)
{
    return mul(fact[n],mul(inv[n-r],inv[r]));
}

ll func(ll n, ll m)
{
    return nCr(n + m - 1, m - 1);
}

// long loooooooooooooooong;
void solve(ll kkkk, ll tttt)
{
    ll n, m; cin >> m >> n;

    ll ans = 0;

    for (ll i = 1; i <= m; i++)
    {
        ll current = func(n - 1, i) * func(n, m - i + 1) % mod;
        ans += current % mod;
        ans %= mod;
    }
    cout << ans << endl;
}

void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

int main()
{
    fact[0] = inv[0] = 1;
    for ( int i = 1 ; i < N ; i++)
    {
        fact[i] = mul(i,fact[i-1]);
        inv[i] = fp(fact[i],mod-2);
    }
    fast();

    int t = 0, i = 0;

//    int t; cin >> t;
//    for (int i = 1; i <= t; i++)
        solve(t, i);
    return 0;
}

