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
    vector<int> fre(26), v;
    string s;
    cin >> s;
    v.assign(a, 0);
    while (b--)
    {
        int num;
        cin >> num;
        v[0]++;
        v[num]--;
        //cout << v << nl;
    }
    int sum = 1;
    for (int i = 0; i < a; i++)
    {
        sum += v[i];
        fre[s[i] - 'a'] += sum;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << fre[i] << " ";
    }
    cout << nl;
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