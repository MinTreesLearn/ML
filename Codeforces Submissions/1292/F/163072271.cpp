#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
int n, a[65], f[65], ind[65], nidx[65], imsk[65], pfxs[65536];
long long dp[65536][65], fac[65], ifac[65];
vector <int> wcc[65], nod;

inline int GetRoot(int v) {
    if (f[v] == v) return v;
    return f[v] = GetRoot(f[v]);
}

inline void Merge(int x, int y) {
    int u = GetRoot(x), v = GetRoot(y);
    if (u != v) f[v] = u;
}

inline void Read() {
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
}

inline void Prefix() {
    for (int i = 1;i <= n;i++) f[i] = i;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (a[i] % a[j] == 0) Merge(i, j);
        }
    }
    for (int i = 1;i <= n;i++) wcc[GetRoot(i)].push_back(a[i]);
    ifac[1] = ifac[0] = fac[1] = fac[0] = 1;
    for (int i = 2;i <= n;i++) ifac[i] = (mod - mod / i) * ifac[mod % i] % mod;
    for (int i = 2;i <= n;i++) {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = ifac[i - 1] * ifac[i] % mod;
    }
}

inline pair <int, long long> Work(int idx) {
    nod.clear(); nod.shrink_to_fit();
    sort(wcc[idx].begin(), wcc[idx].end());
    for (int i = 0;i < wcc[idx].size();i++) {
        for (int j = i + 1;j < wcc[idx].size();j++) {
            if (wcc[idx][j] % wcc[idx][i] == 0) ind[wcc[idx][j]]++;
        }
    }
    for (int x : wcc[idx]) {
        if (!ind[x]) {
            nidx[x] = nod.size();
            nod.push_back(x);
            // cout << x << " no indgr\n";
        }
    }
    memset(imsk, 0, sizeof(imsk));
    //cout << nod.size() << endl;
    memset(pfxs, 0, sizeof(pfxs));
    for (int x : wcc[idx]) {
        for (int y : nod) {
            if (x % y == 0) imsk[x] |= (1 << nidx[y]); 
        }
        if (ind[x]) pfxs[imsk[x]]++;
    }
    for (int i = 0;i < nod.size();i++) {
        for (int j = 0;j < (1 << nod.size());j++) {
            if (j & (1 << i)) pfxs[j] += pfxs[j ^ (1 << i)];
        }
    }
    memset(dp, 0, sizeof(dp));
    for (int x : wcc[idx]) {
        if (ind[x]) dp[imsk[x]][1]++;
    }
    //cout << (1 << nod.size()) << endl;
    for (int i = 1;i < (1 << nod.size());i++) {
        //cout << i << " " << pfxs[i] << endl;
        for (int j = 1;j <= n;j++) {
            //cout << i << " " << j << " " << dp[i][j] << endl;
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * (pfxs[i] - j)) % mod;
            for (int k = 1;k <= n;k++) {
                if ((imsk[a[k]] & i) != 0 && (imsk[a[k]] & i) != imsk[a[k]]) {
                    dp[i | imsk[a[k]]][j + 1] = (dp[i | imsk[a[k]]][j + 1] + dp[i][j]) % mod;
                }
            }
        }
    }
    return make_pair(pfxs[(1 << nod.size()) - 1] - 1, dp[(1 << nod.size()) - 1][pfxs[(1 << nod.size()) - 1]]);
}

inline void Solve() {
    long long ans = 1;
    int fcnt = 0;
    for (int i = 1;i <= 60;i++) {
        if (wcc[i].size() > 1) {
            // for (int x : wcc[i]) cout << x << " "; cout << endl;
            pair <int, long long> res = Work(i);
            //cout << res.first << " " << res.second << endl;
            ans = ans * res.second % mod * ifac[res.first] % mod;
            fcnt += res.first;
        }
    }
    cout << ans * fac[fcnt] % mod << endl;
}

int main() {
    std::ios::sync_with_stdio(0);
    Read();
    Prefix();
    Solve();
    return 0;
}