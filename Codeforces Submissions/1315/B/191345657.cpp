#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define vl vector<ll>
#define vp vector<pair<ll, ll>>
#define in(a)         \
    for (auto &x : a) \
        cin >> x;
#define out(a)            \
    for (auto x : a)      \
        cout << x << ' '; \
    cout << endl;
#define pr(a) cout << a << endl
const ll mod = 1e9 + 7;
const double pi = acos(-1);
void solve()
{
    ll i, a, b, p, ans;
    string s;
    cin >> a >> b >> p >> s;
    char c = 'X';
    for (i = s.size() - 2; i >= 0; i--)
    {
        if (c != s[i])
        {
            c = s[i];
            p -= (c == 'A' ? a : b);
            if (p < 0)
            {
                break;
            }
        }
    }
    pr(i + 2);
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}