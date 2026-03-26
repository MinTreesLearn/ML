#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifdef DUPA
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x, ...)
#endif

typedef long long LL;
// HMMMM
#define int LL

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

const int INF = 1e18 + 1;
int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<pair<char, int>> res;

    if (n == 1) {
        res.push_back({'R', m - 1});
        res.push_back({'L', m - 1});
    } else if (m == 1) {
        res.push_back({'D', n - 1});
        res.push_back({'U', n - 1});
    } else {
        for (int i = 0; i < n - 1; i++) {
            res.push_back({'R', m - 1});
            res.push_back({'L', m - 1});
            res.push_back({'D', 1});
        }
        res.push_back({'R', m - 1});
        for (int j = m - 1; j > 0; j--) {
            res.push_back({'U', n - 1});
            res.push_back({'D', n - 1});
            res.push_back({'L', 1});
        }
        res.push_back({'U', n - 1});
    }
    int sum = 0;

    for (auto [_, x] : res) {
        sum += x;
    }
    assert(sum == 4 * n * m - 2 * n - 2 * m);
    if (k > sum) {
        cout << "NO " << endl;
        return;
    }

    while (sum != k) {
        res.back().second--;
        sum--;
        if (res.back().second == 0) res.pop_back();
    }

    assert(res.size() <= 3000);
    cout << "YES" << endl;
    cout << res.size() << endl;
    for (auto [y, x] : res) cout << x << " " << y << endl;
}

#undef int
int main() {
    ios::sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    cin.tie(0);
    int t = 1;
#ifdef DUPA
    cin >> t;
#endif
    for (int i = 0; i < t; i++) solve();
}
