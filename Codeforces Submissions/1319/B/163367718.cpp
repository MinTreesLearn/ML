#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif
using namespace std;

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto &v: b)
        cin >> v;

    map<int, long long> sum;
    for (int i = 0; i < n; i++)
        sum[b[i] - i] += b[i];

    long long ans = 0;
    for (auto [k, v]: sum) 
        ans = max(ans, v);

    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve_testcase();
}