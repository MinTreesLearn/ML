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
    vi  vec(2);
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        vec[v % 2]++;
    }

    if (vec[1] % 2 || (vec[1] && vec[0])) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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
