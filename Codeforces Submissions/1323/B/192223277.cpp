#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "debug.h"
#endif
// abbreviations
using chr = char;     using ll = long long;     using pll = pair<ll, ll>;
using str = string;   using ld = long double;   using pii = pair<int, int>;
template<class T> using MaxHeap = priority_queue<T, vector<T>,    less<T>>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename T1> T amax(T &a, T1 b) { if (b > a) a = b; return a; }
template<typename T, typename T1> T amin(T &a, T1 b) { if (b < a) a = b; return a; }
// definitons
#define fi first
#define se second
#define all(a)   (a).begin(),  (a).end()
#define rall(a) (a).rbegin(), (a).rend()
// constants
const int maxN = 1e6 + 2;
const int Mod = 1e9 + 7, Modd = 998244353;
const int inf = 0x3f3f3f3f;
const ll linf = 1e18;

void aine() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    vector<int> div;
    for (int i = 1; i <= sqrt(k); ++i) {
        if (k % i == 0) {
            div.push_back(i);
        }
    }
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    vector<int> suba, subb;
    vector<int> nums(n + 1), Nums(m + 1);
    a.push_back(0); b.push_back(0);
    int len = 0;
    for (int i = 0; i <= n;  ++i) {
        if (a[i] == 0) {
            suba.push_back(len);
            len = 0;
        }
        else len++;
    }
    len = 0;
    for (int i = 0; i <= m;  ++i) {
        if (b[i] == 0) {
            subb.push_back(len);
            len = 0;
        }
        else len++;
    }
    for (auto i : suba) {
        for (int j = 1; j <= i; ++j) {
            nums[j] += i - j + 1;
        }
    }
    for (auto i : subb) {
        for (int j = 1; j <= i; ++j) {
            Nums[j] += i - j + 1;
        }
    }
    // debug(nums, Nums, div);
    ll ans = 0;
    for (auto i : div) {
        int p = i, q = k / i;
        if (p <= n && q <= m) ans += 1ll * nums[p] * Nums[q];
        if (p != q && p <= m && q <= n) ans += 1ll * nums[q] * Nums[p];
    }
    cout << ans << '\n';
}
signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) { aine(); } cout << '\n';
    return 0;
}