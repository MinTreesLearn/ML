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

typedef long long LL;
// HMMMM
#define int LL

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

const int INF = 1e18 + 1;

int n;
vector<int> p, c;
vector<vector<int>> g;
vector<int> a;

bool no;

void h(int u, int from, int d) {
    if (a[u] >= from) {
        a[u] += d;
    }
    for (auto v : g[u]) {
        h(v, from, d);
    }
}

int f(int u) {
    int res = 0;
    for (auto v : g[u]) {
        int curr = f(v);
        h(v, 0, res);
        res += curr;
    }

    if (res < c[u]) {
        no = true;
    } else {
        h(u, c[u], 1);
    }

    a[u] = c[u];

    return res + 1;
}

void solve() {
    cin >> n;
    p.resize(n + 1);
    c.resize(n + 1);

    g.resize(n + 1);
    for (auto &x : g) x.clear();
    a.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> p[i] >> c[i];

    int root = -1;
    for (int i = 1; i <= n; i++) {
        g[p[i]].push_back(i);
        if (p[i] == 0) root = i;
    }

    no = false;
    f(root);

    if (no)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) cout << a[i] + 1 << " ";
        cout << endl;
    }
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
