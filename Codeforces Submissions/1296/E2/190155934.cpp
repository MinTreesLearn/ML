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

int n;
string s;

void solve() {
    cin >> n >> s;
    vector<char> v;
    vector<int> res(n, 0);

    for (int i = 0; i < n; i++) {
        char x = s[i];
        auto it = lower_bound(rall(v), x + 1);

        //  assert(is_sorted(rall(v)));
        if (it == v.rbegin()) {
            v.push_back(x);
            it = v.rbegin();

            assert(*it == x);
        } else {
            if (it != v.rend()) assert(*it > x);
            it--;
            assert(*it <= x);
            *it = x;
        }

        assert(*it == x);

        //  assert(is_sorted(rall(v)));

        res[i] = v.size() - (it - v.rbegin());
    }

    cout << v.size() << endl;
    for (auto &x : res) cout << x << " ";
    cout << "\n";
    vector<vector<char>> check(v.size() + 1);
    for (int i = 0; i < n; i++) {
        check[res[i]].push_back(s[i]);
    }

    for (auto &x : check) assert(is_sorted(all(x)));
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
