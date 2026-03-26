#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
//#include <unordered_set>
#include <deque>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <ctime>
#include <numeric>
#include <string>
#include <chrono>
#include <random>

using namespace std;

typedef long long ll;
//typedef __int128_t ll;
typedef long long ld;
#define all(x) x.begin(), x.end()
//#define break_(x) {x; return;}
//const ll MOD = 1000000007;
const ll inf = 1e18;
const ld eps = 1e-10;
const ll MOD = 998244353;
ld pi = asin(0.5) * (ld)6;

std::mt19937 rnd(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());

vector<int> a, bt, ans, bt3, treesm, tree2;
int mx = 0;

void st0(int i, int l, int r, int lq, int rq, int wh) {
    if (r <= lq || rq <= l || treesm[i] == 0) {
        return;
    }
    if (l + 1 == r) {
        treesm[i] = 0;
        ans[l] = wh;
        return;
    }
    int mid = (l + r) / 2;
    st0(2 * i + 1, l, mid, lq, rq, wh);
    st0(2 * i + 2, mid, r, lq, rq, wh);
    treesm[i] = (treesm[2 * i + 1] + treesm[2 * i + 2]);
}

void st(int i, int l, int r, int q, int wh) {
    if (l + 1 == r) {
        tree2[i] = wh;
        return;
    }
    int mid = (l + r) / 2;
    if (mid <= q) {
        st(2 * i + 2, mid, r, q, wh);
    } else {
        st(2 * i + 1, l, mid, q, wh);
    }
    tree2[i] = tree2[2 * i + 1] + tree2[2 * i + 2];
}

int gtp(int i, int l, int r, int rq) {
    if (rq <= l || tree2[i] == 0) {
        return -1;
    }
    if (l + 1 == r) {
        return l;
    }
    int mid = (l + r) / 2;
    int ns = gtp(2 * i + 2, mid, r, rq);
    if (ns == -1) {
        return gtp(2 * i + 1, l, mid, rq);
    }
    return ns;
}

int gtn(int i, int l, int r, int lq) {
    if (r <= lq || tree2[i] == 0) {
        return -1;
    }
    if (l + 1 == r) {
        return l;
    }
    int mid = (l + r) / 2;
    int ns = gtn(2 * i + 1, l, mid, lq);
    if (ns == -1) {
        return gtn(2 * i + 2, mid, r, lq);
    }
    return ns;
}

void dl(int i, int n) {
    bt3[i] = 0;
    st(0, 0, n, i, 0);
}

void dd(int i, int n) {
    bt3[i] = 1;
    st(0, 0, n, i, 1);
}

void check(int i, int n) {
    if (i > 0 && i + 1 < n && (bt[i] == bt[i - 1] || bt[i] == bt[i + 1])) {
        dd(i, n);
    } else if (i > 0 && i + 1 < n) {
        dl(i, n);
    }
}

int gtprf(int i, int n) {
    if (i == -1) {
        return -1;
    }
    return gtp(0, 0, n, i);
}

int gtnxt(int i, int n) {
    if (i == -1) {
        return -1;
    }
    return gtn(0, 0, n, i + 1);
}

void turn_off(int n, int i) {
    bt[i] = 0;
    check(i - 1, n);
    check(i, n);
    check(i + 1, n);
}

void obr(int n, int i, int wh) {
    int pr = gtprf(i, n);
    int prpr = gtprf(pr, n);
    int nx = gtnxt(i, n);
    int nxnx = gtnxt(nx, n);
    vector<int> st;
    if (prpr != -1) {
        st.push_back(prpr);
    }
    if (pr != -1) {
        st.push_back(pr);
    }
    if (bt3[i]) {
        st.push_back(i);
    }
    if (nx != -1) {
        st.push_back(nx);
    }
    if (nxnx != -1) {
        st.push_back(nxnx);
    }
    for (int i = 0; i + 1 < (int)st.size(); ++i) {
        mx = max(mx, (st[i + 1] - st[i]) / 2);
        if (bt[st[i]] == bt[st[i + 1]]) {
            if (bt[st[i]] == 0) {
                st0(0, 0, n, st[i], st[i + 1] + 1, wh);
            }
        } else {
            if (bt[st[i]] == 0) {
                st0(0, 0, n, st[i], (st[i] + st[i + 1]) / 2 + 1, wh);
            } else {
                st0(0, 0, n, (st[i] + st[i + 1]) / 2 + 1, st[i + 1] + 1, wh);
            }
        }
    }
}

void build(int i, int l, int r) {
    treesm[i] = r - l;
    if (l + 1 == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
}

inline void solve(void) {
    int n, t = 1; cin >> n;// >> t;
    a.resize(n);
    treesm.resize(4 * n);
    tree2.resize(4 * n, 0);
    build(0, 0, n);
    vector<pair<int, int>> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b.push_back({ a[i], i });
    }
    ans = a;
    sort(all(b));
    bt.resize(n, 1);
    bt3.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        dd(i, n);
    }
    int lst = 0;
    for (int i = 1; i < n; ++i) {
        if (b[i].first != b[lst].first) {
            for (int j = lst; j < i; ++j) {
                turn_off(n, b[j].second);
            }
            for (int j = lst; j < i; ++j) {
                obr(n, b[j].second, b[j].first);
            }
            lst = i;
        }
    }
    st0(0, 0, n, 0, n, b.back().first);
    cout << mx << '\n';
    if (t) {
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}

signed main(void) {
    //freopen("censored.in", "r", stdin);
    //freopen("C://temp//example.csv", "w", stdout);
    //cout << fixed << setprecision(20);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; srand(time(0)); //cin >> t;
    //std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    while (t--) solve();
    //::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
    return 0;
}
