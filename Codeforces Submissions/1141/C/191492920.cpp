#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
typedef long long ll;
#define int long long
#define mod7 1000000007
#define mod9 1000000009
#define endl "\n"
#define Endl "\n"
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define all(v) v.begin(), v.end()
#define f(i, a, b) for (ll i = a; i < b; ++i)
#define fr(i, a, b) for (ll i = a; i >= b; i--)
ll binary_expo(ll a, ll b, ll mod = 1)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % mod;
        }
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return ans;
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
ll moduloMultiplication(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}
/*input*/
template <typename T>
istream &operator>>(std::istream &in, vector<T> &a)
{
    for (auto &it : a)
        in >> it;
    return in;
}
template <typename T1, typename T2>
istream &operator>>(std::istream &in, pair<T1, T2> &a)
{
    in >> a.first >> a.second;
    return in;
}
/*output*/
template <typename T>
ostream &operator<<(std::ostream &out, vector<T> &a)
{
    for (auto it : a)
    {
        out << ' ' << it;
    }
    out << endl;
    return out;
}
template <typename T1, typename T2>
ostream &operator<<(std::ostream &out, pair<T1, T2> &a)
{
    out << a.first << ' ' << a.second;
    return out;
}
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
void _print(int t)
{
    cerr << t;
}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
const int N = 1e5 + 10;
const int INF = 1e9;
signed main()
{
    fast;
    int n;
    cin >> n;
    vector<int> visited(n + 1, 0);
    vector<int> brr(n - 1);
    cin >> brr;
    map<int, int> temp;
    for (auto child : brr)
        temp[child]++;
    long long sum = 0;
    long long min_val = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        cin >> brr[i];
        sum += brr[i];
        if (sum < min_val)
            min_val = sum;
    }
    vector<long long> p(n);
    p[0] = 1 - min_val;
    if (p[0] > n || p[0] < 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        p[i + 1] = p[i] + brr[i];
        if (p[i + 1] > n || p[i + 1] < 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if (set<int>(all(p)).size() == n)
        cout << p << endl;
    else
        cout << -1 << Endl;

    return 0;
}