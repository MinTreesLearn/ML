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
    string a;
    cin >> a;
    vl ob, cb;
    ll l = 0, r = a.size() - 1;
    while (l < r)
    {
        while (l < a.size() and a[l] == ')')
        {
            l++;
        }
        while (r >= 0 and a[r] == '(')
        {
            r--;
        }
        if (l < a.size() and r >= 0 and l < r)
        {
            ob.push_back(l + 1);
            cb.push_back(r + 1);
            l++;
            r--;
        }
    }
    if (ob.empty())
    {
        pr(0);
        return;
    }
    reverse(all(cb));
    pr(1);
    pr(2 * ob.size());
    for (ll x : ob)
    {
        cout << x << " ";
    }
    for (auto x : cb)
    {
        cout << x << " ";
    }
    pr("");
}
int main()
{
    fast;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}