/*
DavitMarg
In a honky-tonk,
Down in Mexico
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <random>
#include <bitset>
#include <stack>
#include <cassert>
#include <iterator>
#define mod 1000000007ll
#define LL long long
#define LD long double
#define MP make_pair    
#define PB push_back
#define all(v) v.begin(), v.end()
#define fastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 500005;

LL binpow(LL a, LL n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return binpow((a * a) % mod, n / 2);
    return (a * binpow(a, n - 1)) % mod;
}

LL prm = 13, p[N], ip[N];

int n,pr[N];
string s;
int q;
pair<pair<LL, LL>, pair<char, char>> t[N * 4];

LL val(char x)
{
    return (x - '0' + 1ll);
}

pair<pair<LL, LL>,  pair<char,char>> merge(pair<pair<LL, LL>,  pair<char,char>> a, pair<pair<LL, LL>,  pair<char,char>> b)
{
    if (a.second.second == '1' && b.second.first == '1')
    {
        a.first.first += (mod - ((val(a.second.second) * p[a.first.second]) % mod)) % mod;
        
        a.first.first %= mod;
        a.first.second--;
        a.second.second = '0';


        b.first.first += (mod - ((val(b.second.first) * p[1]) % mod)) % mod;
        b.first.first %= mod;
        
        b.first.first *= ip[1];
        b.first.first %= mod;

        b.first.second--;
        b.second.first = '0';
        
    }

    if (a.first.second == 0 && b.first.second == 0)
        return MP(MP(0, 0), MP('0', '0'));
    if (b.first.second == 0)
        return a;
    if (a.first.second == 0)
        return b;
    
    a.first.first += (b.first.first * p[a.first.second]) % mod;
    a.first.first %= mod;
    a.first.second += b.first.second;
    a.second.second = b.second.second;
    return a;
}

void build(int v, int l, int r)
{
    int k = 0;
    if (l == r)
    {
        t[v].first.first = p[1] * val(s[l]);
        t[v].first.second = 1;
        t[v].second = MP(s[l], s[r]);
        return;
    }
    int m = (l + r) / 2;
    build(v * 2, l, m);
    build(v * 2 + 1, m + 1, r);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

pair<pair<LL, LL>,  pair<char,char>>  get(int v, int l, int r, int i, int j)
{
    if (l == i && r == j)
        return t[v];
    int m = (l + r) / 2;

    if (j <= m)
        return get(v * 2, l, m, i, j);
    else if (i >= m + 1)
        return get(v * 2 + 1, m + 1, r, i, j);

    return merge(
        get(v * 2, l, m, i, min(j, m)),
        get(v * 2 + 1, m + 1, r, max(i, m + 1), j)
    );

}


void solve()
{
    cin >> n >> s >> q;

    s = "#" + s;
    p[0] = ip[0] = 1;
    for (int i = 1; i <= n;i++)
    {
        pr[i] = pr[i - 1] + s[i] - '0';
        p[i] = (p[i - 1] * prm) % mod;
        ip[i] = binpow(p[i], mod - 2);
    }

    build(1, 1, n);

    while (q--)
    {
        int l, r, len;
        cin >> l >> r >> len;
        
        if (get(1, 1, n, l, l + len - 1).first.first == get(1, 1, n, r, r + len - 1).first.first && (pr[l + len - 1] - pr[l - 1]) == (pr[r + len - 1] - pr[r - 1]))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

}

int main()
{
    //fastIO;

    int T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

/*



*/