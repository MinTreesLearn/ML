/**
 *    author:  longvu
 *    created: 01/20/23 12:44:55
**/
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
const int INF = numeric_limits<int>::max();
const int nax = (int)(2009);
const int mod = 1e9 + 7;

template<class X, class Y>
bool maximize(X& x, const Y y) {
    if (y > x) {x = y; return true;}
    return false;
}
template<class X, class Y>
bool minimize(X& x, const Y y) {
    if (y < x) {x = y; return true;}
    return false;
}

int ans[nax], par[nax], h[nax], c[nax];
vector<int> adj[nax];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> par[i] >> c[i];
        if (par[i]) {
            adj[i].push_back(par[i]);
            adj[par[i]].push_back(i);
        } else {
            root = i;
        }
    }
    function<void(int, int)> dfs = [&](int u, int pa) {
        for (auto v : adj[u]) {
            if (v == pa) {
                continue;
            }
            h[v] = 1 + h[u];
            dfs(v, u);
        }
    };
    assert(root != -1);
    dfs(root, -1);
    memset(ans, -1, sizeof ans);
    vector<int> st;
    for (int i  = 1; i <= n; ++i) {
        if (!c[i]) {
            st.push_back(i);
        }
    }
    sort(all(st), [&](int x, int y) {
        return h[x] > h[y];
    });
    int d = 0;
    while (!st.empty()) {
        int u = st.back();
        st.pop_back();
        ans[u] = ++d;
        while (u) {
            c[u]--;
            if (!c[u]) {
                st.push_back(u);
            }
            u = par[u];
        }
    }
    bool flag = 1;
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == -1) {
            flag = 0;
        }
    }
    if (!flag) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}