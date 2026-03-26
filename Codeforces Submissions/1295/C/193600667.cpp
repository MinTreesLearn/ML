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
    string s;
    cin >> s;
    int n = s.length();
    map<char, vector<int>> pos;
    for (int i = 0; i < n; i++)
    {
        pos[s[i]].emplace_back(i);
    }
    string t;
    cin >> t;
    int m = t.length();
    int curr = -1;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        //找到第一个大于的数
        auto it = upper_bound(pos[t[i]].begin(), pos[t[i]].end(), curr);
        if (it == pos[t[i]].end())
        {
            if (curr == -1)
            {
                cout << "-1\n";
                return;
            }
            curr = -1;
            i--;
            continue;
        }
        if (curr == -1)
        {
            ans++;
        }
        curr = pos[t[i]][it - pos[t[i]].begin()];
    }
    cout << ans << "\n";
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