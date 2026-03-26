#include "bits/stdc++.h"

using namespace std;



// #define MULTI_TESTS
// #define FLOAT_PRECISION 13

void solve() {
    int n;
    cin >> n;

    vector p(n + 1, 0), c(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> p[i] >> c[i];
    
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i)
        adj[p[i]].push_back(i);
    
    int rt = -1;
    for (int i = 1; i <= n; ++i)
        if (p[i] == 0)
            rt = i;
    
    vector<int> sz(n + 1);

    auto dfs = [&] (auto &f, int cur) -> int {
        int s = 1;
        for (auto &e : adj[cur]) {
            s += f(f, e);
        }
        return sz[cur] = s;
    };
    dfs(dfs, rt);

    for (int i = 1; i <= n; ++i) {
        if (c[i] >= sz[i]) {
            cout << "NO\n";
            return;
        }
    }

    vector<int> ans(n + 1, -1);
    auto dfs2 = [&] (auto &f, int cur, vector<int> &av) -> void {
        ans[cur] = av[c[cur]];
        int i = 0;
        for (auto &e : adj[cur]) {
            vector<int> cv;
            for (int j = 0; j < sz[e]; ++j) {
                if (i == c[cur])
                    i++;
                cv.push_back(av[i]);
                i++;
            }
            f(f, e, cv);
        }
    };
    vector<int> av(n);
    iota(begin(av), end(av), 1);
    dfs2(dfs2, rt, av);

    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
};

void init() {
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.exceptions(cin.failbit);
    
    #ifdef FLOAT_PRECISION
        cout << fixed;
        cout.precision(FLOAT_PRECISION);
    #endif
    
    init();
    
    int numTests = 1;
    #ifdef MULTI_TESTS
        cin >> numTests;
    #endif
    for (int testNo = 1; testNo <= numTests; testNo++) {
        solve();
    }
    
    return 0;
}