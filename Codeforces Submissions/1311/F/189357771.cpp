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

int g(deque<PII> left, deque<PII> right) {
    sort(all(left));
    sort(all(right));
    int res = 0;

    int sum = 0;
    for (auto [y, _] : right) sum += y;
    for (auto [x, d1] : left) {
        assert(d1 <= 0);

        while (!right.empty()) {
            auto [y, d2] = right.front();
            if (d1 == 0 && d2 == 0) {
                sum -= y;
                right.pop_front();
            } else if (!(y > x)) {
                sum -= y;
                right.pop_front();
            } else
                break;
        }

        res += sum - right.size() * x;
    }

    return res;
}

void add(vector<int> &tree, int k, int x) {
    int n = tree.size() - 1;
    k = n - k;
    assert(k >= 1);
    while (k <= n) {
        tree[k] += x;
        k += k & -k;
    }
}

int get(vector<int> &tree, int k) {
    int n = tree.size() - 1;
    k = n - k;
    assert(k >= 1);
    int s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k & -k;
    }
    return s;
}
int f(deque<PII> right) {
    sort(all(right));

    map<int, int> re_map;
    for (auto [_, y] : right) re_map[y] = 0;
    int idx = 0;
    for (auto &[_, y] : re_map) y = idx++;
    for (auto &[_, y] : right) y = re_map[y];

    int sz = re_map.size() + 2;

    vector<int> sum(sz, 0);
    vector<int> cnt(sz, 0);

    for (auto [y, d2] : right) {
        add(sum, d2, y);
        add(cnt, d2, 1);
    }

    int res = 0;

    for (auto [x, d1] : right) {
        add(sum, d1, -x);
        add(cnt, d1, -1);
        res += get(sum, d1) - x * get(cnt, d1);
    }
    return res;
}

int solve() {
    int n;
    vector<PII> dupa;
    cin >> n;
    dupa.resize(n);

    for (int i = 0; i < n; i++) cin >> dupa[i].first;
    for (int i = 0; i < n; i++) cin >> dupa[i].second;

    deque<PII> left, right;
    for (auto x : dupa) {
        if (x.second < 0) left.push_back(x);
        if (x.second >= 0) right.push_back(x);
    }

    int res = g(left, right);
    for (auto &[x, y] : left) {
        x *= -1;
        y *= -1;
    }
    res += f(left);
    res += f(right);
    return res;
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
    for (int i = 0; i < t; i++) cout << solve() << endl;
}