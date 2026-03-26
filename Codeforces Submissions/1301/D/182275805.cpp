#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;

void cutExcessMoves(vector<pair<string, int>>& path, int k) {
    int tot = 0, idx = 0;
    for (auto& instr : path) {
        if (instr.second + tot >= k) {
            instr.second = k - tot;
            idx++;
            break;
        }
        tot += instr.second;
        idx++;
    }
    while ((int) path.size() > idx) {
        path.pop_back();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // Respect the plan !!!
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<string, int>> path;
    if (k > 4 * n * m - 2 * n - 2 * m) {
        return cout << "NO\n", 0;
    }
    if (n == 1) {
        path.push_back({"R", m - 1});
        path.push_back({"L", m - 1});
    } else if (m == 1) {
        path.push_back({"D", n - 1});
        path.push_back({"U", n - 1});
    } else {
        path.push_back({"R", m - 1});
        path.push_back({"D", n - 1});
        path.push_back({"L", m - 1});
        path.push_back({"U", n - 1});
        path.push_back({"D", n - 1});
        path.push_back({"R", m - 1});
        for (int i = n; i > 2; --i) {
            path.push_back({"U", 1});
            path.push_back({"L", m - 1});
            path.push_back({"R", m - 1});
        }
        path.push_back({"U", 1});
        for (int i = m; i > 2; --i) {
            path.push_back({"L", 1});
            path.push_back({"D", n - 1});
            path.push_back({"U", n - 1});
        }
        path.push_back({"L", 1});
    }
    cutExcessMoves(path, k);
    cout << "YES\n" << path.size() << '\n';
    for (auto instr : path) {
        cout << instr.second << ' ' << instr.first << '\n';
    }
    // Respect the plan !!!
    return 0;
}
