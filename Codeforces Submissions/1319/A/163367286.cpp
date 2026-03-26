#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif
using namespace std;

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> r(n), b(n);
    for (auto &v: r)
        cin >> v;

    for (auto &v: b)
        cin >> v;

    int good = 0;
    int cnt_r = 0, cnt_b = 0;
    for (int i = 0; i < n; i++) {
        good += r[i] && !b[i];
        cnt_r += r[i];
        cnt_b += b[i];
    }

    if (good)
        cout << (max(0, cnt_b - (cnt_r - good) + 1) + good - 1) / good << "\n";
    else
        cout << "-1\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve_testcase();
}