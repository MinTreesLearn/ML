// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include "complex"

using namespace std;
using namespace __gnu_pbds;
// template <class T>
// using o_set = tree<T, int_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void prec() {
}
const int N = (int)2e5 + 1;
int A[N];
int n;
int ans = mod * mod;
int calc(int x) {
    int fans = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] <= x)
            fans += x - A[i];
        else {
            int y = A[i] % x;
            fans += min(y, x - y);
        }
        if (fans >= ans) return ans;
    }
    return fans;
}
int modpow(long long x, unsigned int y, int p) {
    // calculates x^y
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int modmul(int x, int y, int p) {
    x = x % p, y = y % p;
    return (__int128)x * y % p;
}
bool isPrime(int n) {
    if (n < 2 || n % 6 % 4 != 1) return (n |
                                         1) == 3;
    int A[] = {2, 325, 9375, 28178, 450775,
               9780504, 1795265022},
        s = __builtin_ctzll(n - 1), d = n >> s;
    for (int a : A) {  // ^ count trailing
        int p = modpow(a % n, d, n),
            i = s;
        while (p != 1 && p != n - 1 && a % n &&
               i--)
            p = modmul(p, p, n);
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
}
int pollard(int n) {
    auto f = [n](int x) { return modmul(x, x,
                                        n) +
                                 1; };
    int x = 0, y = 0, t = 30, prd = 2, i = 1,
        q;
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
vector<int> factor(int n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    int x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), ALL(r));
    return l;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    ans = calc(2);
    for (int i = 0; i < 40; i++) {
        int id = rng() % n;
        for (int j = 1; j > -2 && A[id] + j > 1; j--) {
            int x = A[id] + j;
            // for this x, do something
            // vector<int> p = factor(x);
            for (int y = 2; y * y <= x; y++) {
                if (x % y == 0) {
                    ans = min(ans, calc(y));
                    while (x % y == 0) {
                        x /= y;
                    }
                }
            }
            if (x > 1)
                ans = min(ans, calc(x));
        }
    }

    cout << ans << endl;
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
