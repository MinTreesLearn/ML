/**
 * Created by megurine on 2023/02/09 09:14:06.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define fastIO() ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define itr(it) begin(it), end(it)
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
typedef long double ld;
typedef unsigned uint;
typedef unsigned long long ull;
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

template<typename T>
void chmax(T &a, T b) { if (b > a) a = b; }

template<typename T>
void chmin(T &a, T b) { if (b < a) a = b; }

void elysia() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    map<int, int> g;
    vector<map<int, int>> f(n);
    for (int j = n - 1; j >= 0; --j) {
        for (int i = j, p = 0; i >= 0; --i) {
            p += a[i];
            chmax(f[i][p], g.count(p) ? g[p] + 1 : 1);
        }
        for (auto &[x, y]: f[j]) chmax(g[x], y);
    }
    int mx = 0, mv = 0;
    for (auto &[x, y]: g) {
        if (y > mx) mx = y, mv = x;
    }
    cout << mx << endl;
    map<int, int> mp;
    mp[0] = 0;
    vector<int> f1(n + 1);
    for (int i = 0, p = 0; i < n; ++i) {
        p += a[i];
        f1[i + 1] = f1[i];
        if (mp.count(p - mv)) {
            int cur = mp[p - mv] ? f1[mp[p - mv]] + 1 : 1;
            if (cur > f1[i + 1]) {
                f1[i + 1] = cur;
                cout << mp[p - mv] + 1 << ' ' << i + 1 << endl;
            }
        }
        mp[p] = i + 1;
    }
}

int main() {
#ifdef MEGURINE
#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
    fr("../input.txt");
    fw("../output.txt");
    clock_t start = clock();
#endif
    fastIO();
    int T = 1;
//    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) {
        elysia();
    }
    cout.flush();
#ifdef MEGURINE
    clock_t end = clock();
    cout << "\n\nRunning Time : " << (double) (end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}