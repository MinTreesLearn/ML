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
    vi  vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    int ans = 0;
    vb seen(n);
    for (int l = 0; l < n; l++) {
        if (vec[l] == 0) continue;
        if (seen[l]) continue;
        seen[l] = 1;
        int count = 1;
        int r = (l + 1) % n;
        for (; r != l; r = (r + 1) % n) {
            if (vec[r] == 0) break;
            seen[r] = 1;
            count++;
        }
        l = r;
        ans = max(ans, count);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    //ifstream cin ("puzzle_name.in");
    //ofstream cout ("puzzle_name.out");

    solve();

    return 0;
}
