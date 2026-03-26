#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ", " : "{"), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 300005, M = 400005, logN = 20;

struct Dsu {
    int dsu[N << 1], cost[N << 1], ans;
    Dsu () {
        ans = 0;
        for (int i = 0; i < N; ++i) {
            dsu[i] = i, dsu[i + N] = i + N;
            cost[i + N] = 1;
        }
        cost[0 + N] = 1 << 30;
    }
    int calc(int x) {
        int y = x >= N ? x - N : x + N;
        return min(cost[x], cost[y]);
    }
    int Find(int x) {
        if (dsu[x] == x) {
            return x;
        }
        return dsu[x] = Find(dsu[x]);
    }
    void Union(int u, int v) {
        u = Find(u), v = Find(v);
        if (u == v) {
            return;
        }
        if (u % N > v % N) {
            swap(u, v);
        }
        ans -= calc(u), ans -= calc(v);
        cost[u] += cost[v];
        cost[v] = 0;
        dsu[v] = u;
        ans += calc(u);
    }
} dsu;

void solve() {
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    vector <vector <int>> pos(n);
    for (int i = 0, sz; i < m; ++i) {
        cin >> sz;
        for (int j = 0, x; j < sz; ++j) {
            cin >> x, --x;
            pos[x].pb(i + 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        int x, y;
        if (pos[i].empty()) {
            cout << dsu.ans << '\n';
            continue;
        }
        if (pos[i].size() == 1) {
            x = 0, y = pos[i][0];
        }
        if (pos[i].size() == 2) {
            x = pos[i][0], y = pos[i][1];
        }
        if (s[i] == '0') {
            dsu.Union(x, y + N);
            dsu.Union(x + N, y);
        } else {
            dsu.Union(x, y);
            dsu.Union(x + N, y + N);
        }
        cout << dsu.ans << '\n';
    }
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}