/* | In The Name Of Allah | */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename key>
using ordered_set = tree<key, null_type, less<key>, rb_tree_tag, tree_order_statistics_node_update>; // less_equal

/////////////////////////////////////////////////////////////////////////////////////////////////////////
#define LL                              __int128
#define ll                              long long
#define int                             long long
#define ld                              long double
#define all(v)                          ((v).begin()), ((v).end())
#define sz(v)                           ((int)((v).size()))
#define dpp(v, d)                       memset(v, d, sizeof(v))
#define MP                              make_pair
#define ceil(n, m)                      (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define rep(i, f, t)                    for (int i = f; i < t; i++)
#define lep(i, f, t)                    for (int i = f; i >= t; i--)
#define cin(vec)                        for (auto &i : vec) cin >> i
#define cin_2d(vec, n, m)               for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout(vec)                       for(auto& i : vec) cout << i << " "; cout << "\n";
#define cout_2d(vec, n, m)              for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j] << " "; j++);
#define TC                              int tt; cin >> tt; while (tt--)
#define count1(n)                       __builtin_popcount(n)  // count 1s in Binary number
#define count0(n)                       __builtin_ctz(n)      // trailing 0s in the begin from right
#define countb0(n)                      __builtin_clz(n)     // trailing 0s in the begin from left (LOL)
int setBit(int num, int idx, int val)   { return val ? (num | (1 << idx)) : (num & (~(1 << idx))); }
int getBit(int num, int idx)            { return (((1 << idx) & num) >= 1); }
int addt(int x, int y, int mod)         { return ((x % mod) + (y % mod)) % mod; }
int mult(int x, int y, int mod)         { return ((x % mod) * (y % mod)) % mod; }
int subt(int x, int y, int mod)         { return ((x % mod) - (y % mod) + mod) % mod; }
/////////////////////////////////////////////////////////////////////////////////////////////////////////

const int inf = (int)(1e18);
const int mod = (int)(1e9 + 7);

int a[200], p[200];

void Test_Case() {
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;

    int prf[n + 1] = {};

    for (int i = 0, x; i < m; i++) {
        cin >> x;
        prf[0] += 1, prf[x] -= 1;
    }
    prf[0]++;
    for (int i = 0; i < n; i++) {
        if (i)
            prf[i] += prf[i - 1];
    }

    vector<int> frq(26, 0);
    for (int i = 0; i < n; i++) {
        frq[str[i] - 'a'] += prf[i];
    }

    cout(frq);
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(3);   
    //////////////////////////////////////////////////////
    int tt = 1;
    cin >> tt;

    while (tt--) { Test_Case(); }
    return 0;
}