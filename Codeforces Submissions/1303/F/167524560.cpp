#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <queue>
#include <cmath>
#include <numeric>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <deque>
#include <iomanip>
#include <unordered_set>
#include <limits>
#include <list>
#include <bitset>
#include <random>
#include <cstring>
#include <cassert>
#include <chrono>
#include <array>

#define ff first
#define err(x) cerr << "["#x"]  " << (x) << "\n"
#define errv(x) {cerr << "["#x"]  ["; for (const auto& ___ : (x)) cerr << ___ << ", "; cerr << "]\n";}
#define errvn(x, n) {cerr << "["#x"]  ["; for (auto ___ = 0; ___ < (n); ++___) cerr << (x)[___] << ", "; cerr << "]\n";}
#define ss second
#define pb push_back
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
using namespace std;
const int MOD = 1000000007;
mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());

template<typename T1, typename T2>
inline bool relaxmi(T1 &a, const T2 &b) {
    return a > b ? a = b, true : false;
}

template<typename T1, typename T2>
inline bool relaxma(T1 &a, const T2 &b) {
    return a < b ? a = b, true : false;
}

double GetTime() { return clock() / (double) CLOCKS_PER_SEC; };
/// Actual code starts here
const int N = 305, Q = 2e6 + 5;

int p[N * N + 5];
int table[N][N];
int n, m;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int get(int v) {
    if (p[v] == v) return v;
    return p[v] = get(p[v]);
}

bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    p[a] = b;
    return true;
}

int gv[Q];

void Fill(vector<pair<int, int>> &bebra, int delta) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            table[i][j] = -1;
    for (int i = 0; i < n * m; i++) p[i] = i;
    for (auto[v, id]: bebra) {
        int x = v / m, y = v % m;
        table[x][y] = 228;
        int cnt = 1;
        for (int k = 0; k < 4; k++) {
            int x2 = x + dx[k], y2 = y + dy[k];
            if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && table[x2][y2] == 228)
                cnt -= join(x * m + y, x2 * m + y2);
        }
//        err(cnt);
        gv[id] += delta * cnt;
    }
}


struct bebra {
    int x, y, c;
};

bebra qv[Q];

vector<pair<int, int>> add[Q], sub[Q];

void solve() {
    int q;
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        cin >> qv[i].x >> qv[i].y >> qv[i].c;
        qv[i].x--, qv[i].y--;
        if (qv[i].c == table[qv[i].x][qv[i].y]) continue;
        sub[table[qv[i].x][qv[i].y]].pb({qv[i].x * m + qv[i].y, i});
        table[qv[i].x][qv[i].y] = qv[i].c;
        add[qv[i].c].pb({qv[i].x * m + qv[i].y, i});
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sub[table[i][j]].pb({i * m + j, Q - 1});
    for (int j = 0; j < Q; j++) {
        if (add[j].empty()) continue;
        Fill(add[j], 1);
    }
    for (int j = 0; j < Q; j++) {
        if (sub[j].empty()) continue;
        reverse(all(sub[j]));
        Fill(sub[j], -1);
    }
    int res = 1;
//    errvn(gv, q);
    for (int i = 0; i < q; i++) {
        res += gv[i];
        cout << res << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--)
        solve();
}
