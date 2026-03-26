#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long;

#ifdef LOCAL
#include "algo/debug.h"
#define TASK "inp1"
#else
#define debug(...) 42
#define TASK "printer"
#define debugArr(...) 42
#endif

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fi first
#define se second

const ll MOD = 1e9+7;
const ll maxn = 1e5+5;
const ll inf = 1e18;
const ll BASE = 31;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

//random
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int a, int b)
{
    return uniform_int_distribution<int>(a, b)(rng);
}

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s = '$' + s;
    vector <int> v(k), ans(26);
    vector <vector <int>> cnt(n + 1, vector <int> (26));
    for(int &x : v) cin >> x;
    v.push_back(n);
    for(int i = 1; i <= n; i++)
    {
        int x = s[i] - 'a';
        for(int j = 0; j < 26; j++) cnt[i][j] = cnt[i - 1][j] + (x == j);
    }

    for(int x : v)
    {
        for(int i = 0; i < 26; i++)
        {
            ans[i] += cnt[x][i];
        }
    }

    for(int x : ans) cout << x << ' ';
    cout << '\n';
}

signed main()
{
    faster();

    if (fopen(TASK ".inp", "r")) freopen(TASK ".inp", "r", stdin);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
