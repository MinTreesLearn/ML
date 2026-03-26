#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v(n);
        vector<pair<int, int>> edg;
        for (int i = 0; i < n - 1; i++) {
                int a, b;
                cin >> a >> b;
                --a; --b;
                v[a].push_back(b);
                v[b].push_back(a);
                edg.push_back({a, b});
        }
        int lf = 1;
        int rg = n;
        int pos = -1;
        vector<int> ans;
        vector<int> dep(n);
        while (lf <= rg) {
                int md = (lf + rg)/2;
                vector<int> c(n);
                function<int(int, int)> dfs = [&](int x, int p) {
                        int col = 0;
                        int res = 0;
                        int cnt = 0;
                        dep[x] = dep[p] + 1 - (x == 0);
                        for (auto z : v[x]) {
                                if (z == p) continue;
                                cnt++;
                                col++;
                                if (col > md) col = 1;
                                if (col == c[x]) col++;
                                if (col > md) col = 1;
                                c[z] = col;
                                res += dfs(z, x);
                        }
                        if (x != 0) cnt++;
                        if (cnt > md) res++;
                        return res;
                };
                c[0] = 0;
                if (dfs(0, 0) <= k) {
                        pos = md;
                        ans = c;
                        rg = md - 1;
                } else {
                        lf = md + 1;
                }
        }
        assert(pos != -1);
        cout << pos << '\n';
        for (auto [a, b] : edg) {
                if (dep[a] < dep[b]) swap(a, b);
                cout << ans[a] << " ";
        }
        cout << '\n';
        return 0;
}