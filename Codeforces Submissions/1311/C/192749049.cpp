#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vs = vector<string>;
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
#define SZ(v) int(v.size())

#ifdef DLOCAL
#include <local.h>
#else
#define deb(...);
#endif

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vi  queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i];
    }
    deb(queries)

    vector<vi> pref(n + 1, vi(26));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            pref[i][j] = pref[i - 1][j];
        }

        pref[i][s[i - 1] - 'a']++;
    }
    
    vll ans(26);
    for (int q : queries) {
        for (int j = 0; j < 26; ++j) {
            ans[j] += pref[q][j];
        }
    }
    for (int j = 0; j < 26; ++j) {
        ans[j] += pref[n][j];
    }
    
    for (ll v : ans) {
        cout << v << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    //ifstream cin ("puzzle_name.in");
    //ofstream cout ("puzzle_name.out");
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    

    return 0;
}
