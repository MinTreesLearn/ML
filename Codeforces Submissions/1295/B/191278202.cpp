/// endless ?

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll                       long long
#define F                        first
#define S                        second
#define pii                      pair<int, int>
#define all(x)                   x.begin(), x.end()
#define vi                       vector<int>
#define vii                      vector<pii>
#define pb                       push_back
#define pf                       push_front
#define wall                     cout <<'\n'<< "-------------------------------------" <<'\n';
#define fast                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define int ll
const ll MAXN = 2e5 + 43;
const ll MOD  = 1e9  + 7; ///998244353;
const ll INF  = 1e18 + 19763;
const ll LG   = 19;
ll pw(ll a, ll b){return b == 0 ? 1LL : (pw(a * a%MOD , b / 2)%MOD * (b % 2 == 0 ? 1LL : a))%MOD;}
int pref[MAXN];

void solve()
{
    fast
    int n, bl, flg = 0; cin >> n >> bl;
    string s; cin >> s;
    pref[0] = (s[0] == '0' ? 1 : -1);
    if (pref[0] == bl)flg = 1;
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + (s[i] == '0' ? 1 : -1);
        if (pref[i] == bl)flg = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int xbal = bl - pref[i];

        if (pref[n - 1] == 0)continue;
        else if (pref[n - 1] < 0)
            {
                if (xbal <= 0)
                {
                    ans += (-xbal % -pref[n - 1] == 0);
                }
            }
        else
            {
                if (xbal >= 0)
                {
                    ans += (xbal % pref[n - 1] == 0);
                }
            }
    }
    if (bl == 0)ans ++;
    cout << (pref[n - 1] == 0 && flg ? -1 : ans) << '\n';
}

int32_t main ()
{
    fast
    int t = 1; cin >> t;
    while (t --)
    {
        solve();
    }
}
/// Thanks GOD :)

