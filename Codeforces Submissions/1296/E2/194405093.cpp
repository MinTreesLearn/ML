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

    vi count(26);
    for (int i = 0; i < n; ++i) {
        count[s[i] - 'a']++;
    }
    int pos = 0;
    vector<pii> indexes(26); // start, end
    for (int i = 0; i < 26; ++i) {
        indexes[i].first = pos;
        pos += count[i];
        indexes[i].second = pos;
    }
    deb(count);

    for (int i = 0; i < 26; ++i) {
        if (indexes[i].first == indexes[i].second) continue;
        char c = char('a' + i);
        deb(c, indexes[i])
    }
    
    vi ans;
    vi positions(27, 0);
    
    map<char, int> temp;
    for (int i = 0; i < n; ++i) {
        if (temp.upper_bound(s[i]) != temp.end()) {
            positions[s[i] - 'a'] = *max_element(positions.begin() + (s[i] - 'a') + 1, positions.end()) + 1;
            ans.emplace_back(positions[s[i] - 'a']);
        }
        else {
            positions[s[i] - 'a'] = 1;
            ans.emplace_back(positions[s[i] - 'a']);
        }
        temp[s[i]]++;
    }
    deb(positions)
    deb(ans);

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
