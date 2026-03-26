#include <bits/stdc++.h>

//#include <ext/pb_ds/detail/standard_policies.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

using namespace std;

//using namespace __gnu_pbds;
//template <typename T> using ordered_set = tree <T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 gen(time(0));

#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define sz(a) int32_t(a.size())
//#define endl '\n'
//#define int long long

const int N = 1100;
const int M = 30;
const int mod = 1e9 + 7;
const int inf = 2e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int a[n], b[n], sum1 = 0, sum2 = 0;
    for (int i = 0;i < n;i++)
        cin >> a[i];
    for (int i = 0;i < n;i++)
        cin >> b[i];
    for (int i = 0;i < n;i++)
    {
        if (a[i] == b[i]) continue;
        if (a[i] == 1) sum1++;
            else sum2++;
    }
    sum2++;
    if (sum1 == 0) cout << -1 << endl;
        else cout << ((sum2 % sum1) > 0) + sum2 / sum1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while (t--)
        solve();
}
