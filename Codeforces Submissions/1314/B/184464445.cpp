//  ↘ ⬇ ⬇ ⬇ ⬇ ⬇ ↙
//  ➡ @roadfromroi ⬅
//  ↗ ⬆ ⬆ ⬆ ⬆ ⬆ ↖
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
vector<int> gd;
int vlm = -1e9;
void mxr(int &a, int b) {
    a = max(a, b);
}
array<int, 4> recslv(int l, int r) {
    if (l + 2 == r) {
        int v1 = gd[l], v2 = gd[l + 1];
        if (v1 == 1 and v2 == 1) {
            return {0, 1, 1, 1};
        }
        if (v1 == 1 or v2 == 1) {
            return {0, 1, 1, vlm};
        }
        return {0, vlm, vlm, vlm};
    }
    int m = l + r >> 1;
    array<int, 4> a = recslv(l, m), b = recslv(m, r);
    array<int, 4> c = {0, vlm, vlm, vlm};
    mxr(c[2], a[1] + 2); // 1 0
    mxr(c[1], a[1] + 1); // 1 0
    mxr(c[2], a[2] + 2); // 2 0
    mxr(c[3], a[3] + 3); // 3 0
    mxr(c[3], a[1] + b[1] + 2); // 1 1
    mxr(c[3], a[2] + b[1] + 3); // 2 1
    mxr(c[3], a[3] + b[1] + 3); // 3 1
    mxr(c[2], a[2] + b[2] + 2); // 2 2
    mxr(c[3], a[3] + b[2] + 3); // 3 2
    mxr(c[3], a[3] + b[3] + 3); // 3 3
    swap(a, b);
    mxr(c[2], a[1] + 2); // 1 0
    mxr(c[1], a[1] + 1); // 1 0
    mxr(c[2], a[2] + 2); // 2 0
    mxr(c[3], a[3] + 3); // 3 0
    mxr(c[3], a[1] + b[1] + 2); // 1 1
    mxr(c[3], a[2] + b[1] + 3); // 2 1
    mxr(c[3], a[3] + b[1] + 3); // 3 1
    mxr(c[2], a[2] + b[2] + 2); // 2 2
    mxr(c[3], a[3] + b[2] + 3); // 3 2
    mxr(c[3], a[3] + b[3] + 3); // 3 3
    return c;
}
void solve() {
    int n, k;
    cin >> n >> k;
    n = (1 << n);
    gd.assign(n, 0);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        x--;
        gd[x] = 1;
    }
    array<int, 4> t = recslv(0, n);
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        res = max(res, (i != 0) + t[i]);
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}
