#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
//const int mod = 998244353;
#define PII pair<long long, long long>
#define x first
#define y second
#define pi 3.14159265359
int qpow(int a, int b)
{
    int res = 1;
    while (b != 0)
    {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int _qpow(int a, int b)
{
    int res = 1;
    while (b != 0)
    {
        if (b & 1)res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int inv(int a)
{
    return qpow(a, mod - 2);
}

int exgcd(int ai, int bi, int& xi, int& yi)
{
    if (bi == 0)
    {
        xi = 1, yi = 0;
        return ai;
    }
    int d = exgcd(bi, ai % bi, yi, xi);
    yi -= ai / bi * xi;
    return d;
}
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
/*----------------------------------------------------------------------*/

bool st[200005];
int cnt;
int primes[200005];
int phi[200005];

void getPrime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])primes[cnt++] = i, phi[i] = i - 1;
        for (int j = 0; primes[j] * i <= n; j++)
        {
            st[primes[j] * i] = 1;
            if (i % primes[j])phi[primes[j] * i] = phi[i] * primes[j] * (primes[j] - 1) * primes[j];
            else
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
        }
    }
}

void solve()
{
    int a, m;
    cin >> a >> m;
    int d = gcd(a, m);
    int tmp = m / d;
    int res = tmp;
    for (int i = 0; i < cnt; i++)
    {
        if (tmp % primes[i] == 0)
        {
            res = res / primes[i] * (primes[i] - 1);
            while (tmp % primes[i] == 0)
            {
                tmp /= primes[i];
            }
        }
    }
    if (tmp != 1)res = res / tmp * (tmp - 1);
    cout << res << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    getPrime(2e5);
    cin >> tt;
    while (tt--)solve();
    return 0;
}