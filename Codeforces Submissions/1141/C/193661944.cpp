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
    vi vec(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> vec[i];
    }

    vi ans(n);
    for (int i = 1; i < n; ++i) {
        ans[i] = ans[i - 1] + vec[i - 1];
    }

    int lowest = *min_element(ALL(ans));
    int inc = abs(lowest - 1);
    for (int i = 0; i < n; ++i) {
        ans[i] += inc;
    }
    vi sorted = ans;
    SORT(sorted);
    for (int i = 0; i < n; ++i) {
        if (sorted[i] != i + 1) {
            cout << -1;
            return;
        }
    }
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
