#include <bits/stdc++.h>
using namespace std;
#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(0)
#define ll long long int
#define minfun(a, b) ((a) < (b) ? (a) : (b))
#define maxfun(a, b) ((a) > (b) ? (a) : (b))
#define MOD 1000000007
#define rep(i, n) for (i = 0; i < n; i++)
#define repp(i, a, n) for (i = a; i < n; i++)
#define repr(i, a, n) for (i = a; i >= n; i--)
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair
#define fi first
#define se second
ll fact[15];
vector<bool> isprime(100007, true);
map<ll, ll> sfact;
long long int gcd(long long int a, long long int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll binpowmod(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll absfun(ll a)
{
    if (a < 0)
        return -a;
    return a;
}
ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll x, ll mod)
{
    return binpowmod(x, mod - 2, mod);
}

void pre()
{
    fact[0] = 1;
    fact[1] = 1;
    ll modulo = 998244353;
    for (ll i = 2; i < 2005; i++)
    {
        fact[i] = (fact[i - 1] * i) % modulo;
    }
}
const int MAX_SIEVE = 1005;
vector<int> P(MAX_SIEVE, 1);
void sieve()
{
    P[1] = 0;
    for (ll i = 2; i < MAX_SIEVE; i++)
    {
        if (P[i] == 1)
        {
            P[i] = i;
            for (int j = 2 * i; j < MAX_SIEVE; j += i)
            {
                P[j] = i;
            }
        }
    }
}
ll nckmod(ll n, ll k, ll p)
{
    return ((fact[n] * modInverse(fact[k], p) % p) * modInverse(fact[n - k], p)) % p;
}
map<ll, ll> factors_prime;
void primeFactors(ll n)
{
    while (n % 2 == 0)
    {
        factors_prime[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            factors_prime[i]++;
            n = n / i;
        }
    }
    if (n > 1)
        factors_prime[n]++;
}

bool isvowel(char x)
{
    return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

void solve()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    map<char,vector<int>> m;
    for(int i=0;i<n;i++) m[a[i]].pb(i);
    vector<pair<int,int>> ans;
    vector<int> h;
    for(int i=0;i<n;i++)
    {
        if(b[i]=='?'){
            h.pb(i);
            continue;
        }
        if(m[b[i]].size()>0)
        {
            ans.pb({m[b[i]].back()+1,i+1});
            m[b[i]].pop_back();
        }
        else if(m['?'].size()>0)
        {
            ans.pb({m['?'].back()+1,i+1});
            m['?'].pop_back();
        }
    }
    for(auto it:m)
    {
        while(h.size()>0&&it.se.size()>0)
        {
            ans.pb({it.se.back()+1,h.back()+1});
            it.se.pop_back();h.pop_back();
        }
    }
    cout<<ans.size()<<'\n';
    for(auto it:ans) cout<<it.fi<<' '<<it.se<<'\n';
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);

#endif
    SPEED;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}