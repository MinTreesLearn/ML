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
#define endl '\n'
#define int long long

const int N = 1100;
const int M = 30;
const int mod = 1e9 + 7;
const int inf = 2e9 + 7;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 25;i >= 1;i--)
    {
        for (int j = 0;j < s.size();j++)
            if (s[j] - 'a' == i && ((j > 0 && s[j - 1] == s[j] - 1) || (j + 1 < s.size() && s[j + 1] == s[j] - 1)))
            {
                s.erase(j, 1);
                j = max((int)-1, j - 2);
            }
    }
    cout << n - s.size();
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
