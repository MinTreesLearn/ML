#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include <math.h>
#include <set>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define nl "\n"
#define fi first
#define se second
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define sz(s) s.size()
#define f0r(j, n) for (ll i = j; i < n; i++)
#define cin_2d(vec, n, m)                               \
    for (int i = 0; i < n; i++)                         \
        for (int j = 0; j < m && cin >> vec[i][j]; j++) \
            ;
#define ceil(w, m) (((w) / (m)) + ((w) % (m) ? 1 : 0)
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" \
                  << "\n";
template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << " ";
    return out;
}

void sherry()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
void solve()
{
    ll a, b;
    cin >> a >> b;
    vector<int> v(a), v2(a), pos(a);
    cin >> v;
    v2 = v;
    sort(all(v2));
    for (int i = 0; i < b; i++)
    {
        int num;
        cin >> num;
        pos[num - 1]++;
    }
    while (true)
    {
        bool flag = 0;
        for (int i = 0; i < a; i++)
        {
            if (pos[i] == 1 and v[i] > v[i + 1])
            {
                swap(v[i], v[i + 1]);
                flag = 1;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    if (v2 == v)
        cy;
    else
        cn;
}

int main()
{
    sherry();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    Time return 0;
}