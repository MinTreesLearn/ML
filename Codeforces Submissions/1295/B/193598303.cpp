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



void solve()
{
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int sum = 0;
    for (char c : s)
    {
        if (c == '0')sum++;
        else sum--;
    }
    int curr = 0;
    set<int> ss;
    int cnt = 0;
    if (curr == x && sum == 0)
    {
        cout << "-1\n";
        return;
    }
    if (sum != 0 && x % sum == 0 && x / sum >= 0)ss.insert(x / sum * n);
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == '0')curr++;
        else curr--;
        if (curr == x && sum == 0)
        {
            cout << "-1\n";
            return;
        }
        if (sum != 0 && (x - curr) % sum == 0 && (x - curr) / sum >= 0)
        {
            ss.insert((x - curr) / sum * n + i + 1);
        }
    }
    cout << ss.size() << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)solve();
    return 0;
}