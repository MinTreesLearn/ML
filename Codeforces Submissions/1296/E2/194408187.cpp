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
    int n; cin >> n;
    string s; cin >> s;

    vi ans(n);
    vi positions(27, 0);
    map<char, bool> seen;
    for (int i = 0; i < n; ++i) {
        if (seen.upper_bound(s[i]) != seen.end()) {
            positions[s[i] - 'a'] = *max_element(positions.begin() + (s[i] - 'a') + 1, positions.end()) + 1;
            ans[i] = positions[s[i] - 'a'];
        }
        else {
            positions[s[i] - 'a'] = 1;
            ans[i] = positions[s[i] - 'a'];
        }
        seen[s[i]] = 1;
    }

    cout << *max_element(ALL(ans)) << "\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    //ifstream cin ("puzzle_name.in");
    //ofstream cout ("puzzle_name.out");

    solve();

    return 0;
}
