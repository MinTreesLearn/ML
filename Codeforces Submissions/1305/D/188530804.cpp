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
vector<set<int>> g;

void answer(int x) {
    cout << "! " << x << endl;
    exit(0);
}

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    cin >> n;
    g.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    set<int> res;

    for (int i = 1; i <= n; i++) res.insert(i);

    while (res.size() > 1) {
        vector<int> q;
        for (int i = 1; i <= n; i++) {
            if (g[i].size() == 1) q.push_back(i);
            if (q.size() >= 2) break;
        }
        if (q.size() == 1) {
            answer(q.front());
        } else {
            assert(q.size() == 2);
            int x = ask(q.front(), q.back());
            if (x == q.front() || x == q.back()) answer(x);
            for (auto y : q) {
                res.erase(y);
                g[y].clear();
                for (int i = 1; i <= n; i++) g[i].erase(y);
            }
        }
    }

    answer(*res.begin());
}

#undef int
int main() {
    ios::sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    cin.tie(0);
    int t = 1;
    //  cin >> t;
#ifdef DUPA
#endif
    for (int i = 0; i < t; i++) solve();
}
