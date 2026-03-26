#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define watch(x) cout << (#x) << " : " << x << '\n'

using namespace std;

const int N = 3e3 + 128;

vector <int> g[N];
ll dp[N][N];
ll pr[N][N];
ll sb[N][N];

int root;

void dfs(int v) {
    sb[root][v] = 1;
    for (auto nxt : g[v]) {
        if (nxt == pr[root][v])
            continue;
        pr[root][nxt] = v;
        dfs(nxt);
        sb[root][v] += sb[root][nxt];
    }
}

int n;

ll calc(int i, int j) {
    if (i == j)
        dp[i][j] = 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = sb[i][j] * sb[j][i] + max(calc(pr[j][i], j), calc(i, pr[i][j]));
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = pr[i][j] = sb[i][j] = -1;

    for (int i = 0; i < n; i++, root = i) {
        dfs(i);
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            calc(i, j);

    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, dp[i][j]);

    cout << ans << '\n';
}

main () {
    srand(time(NULL));
    boost;
    int t = 1;
//    cin >> t;
    while (t--)
        solve();
    return 0;
}
