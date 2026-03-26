// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include "complex"

using namespace std;
using namespace __gnu_pbds;
template <class T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define int long long
typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define si(n) scanf("%d", &n)
#define dout(n) printf("%d\n", n)
#define sll(n) scanf("%lld", &n)
#define lldout(n) printf("%lld\n", n)
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
const long long mod = 1e9 + 7;

void prec() {
}

const int N = 5001;
int cnt[N];
int prime[N];
int curr = 0;
void solve() {
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            x = 1;
        }
        cnt[x]++;
    }
    vector<int> primes;
    map<int, int> id;
    vector<pair<int, int>> s[N];
    for (int i = 0; i < N; i++)
        prime[i] = i;
    for (int i = 2; i < 5001; i++) {
        if (prime[i] == i) {
            id[i] = curr++;
            primes.PB(i);
            for (int j = 2 * i; j < 5001; j += i) {
                prime[j] = i;
            }
        }
    }
    map<int, int> mm;

    int ans = 0;
    for (int i = 1; i < N; i++) {
        int v = i;
        while (v != 1) {
            int x = prime[v];
            mm[x]++;
            v /= prime[x];
        }
        vector<pair<int, int>> x;
        int y = 0;
        for (auto &v : mm) {
            y += v.second;
            x.PB({v.first, v.second});
        }
        s[i] = (x);
        ans += cnt[i] * y;
    }
    int sz = primes.size();
    vector<int> occur(sz);  // how many are there for each of these primes
    for (int i = 2; i < N; i++) {
        if (cnt[i] > 0) {
            occur[id[s[i].back().first]] += cnt[i];
        }
    }
    while (1) {
        int maxi_s = 0;
        int maxi_p = 0;
        for (int i = 0; i < sz; i++) {
            if (occur[i] >= maxi_s) {
                maxi_s = occur[i];
                maxi_p = primes[i];
            }
        }
        // answer decreses by n - maxi_s and increases by maxi_s
        // so decreses by n-
        if (n - 2 * maxi_s >= 0) {
            break;
        }
        ans = ans + (n - 2 * maxi_s);
        // now update occur
        occur = vector<int>(sz, 0);
        for (int i = 2; i < N; i++) {
            if (!cnt[i]) {
                continue;
            }
            int p = maxi_p;
            if (s[i].back().first != maxi_p) {
                cnt[i] = 0;
                continue;
            }
            s[i].back().second--;
            if (s[i].back().second == 0) {
                s[i].pop_back();
            }
            if (!s[i].size()) {
                cnt[i] = 0;
                continue;
            }
            occur[id[s[i].back().first]] += cnt[i];
        }
    }

    cout
        << ans << endl;
}

signed main() {
    fast_io;
    prec();
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    int totalTests = 1;
    // cin >> totalTests;
    for (int testNo = 1; testNo <= totalTests; testNo++) {
        // cout << "Case #" << testNo << ": ";
        solve();
    }
    return 0;
}
