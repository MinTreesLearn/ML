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

    vi vals(n);
    map<char, int> target;
    for (int i = 0; i < 26; ++i) {
        if (indexes[i].first == indexes[i].second) continue;
        target[char('a' + i)] = indexes[i].first;
    }
    //deb(target)
    map<char, int> temp;
    for (int i = 0; i < n; ++i) {
        if (i > indexes[s[i] - 'a'].first + temp[s[i]]) {
            vals[i] = 1;
        }
        temp[s[i]]++;
    }
    vi og = vals;
    //deb(vals)

    for (int i = 0; i < n; ++i) {
        map<char, int> seen;
        char lowest_char = 'z' + 1;
        int  char_index = -1;
        int  target_index = -1;
        for (int j = 0; j < n; ++j) {
            if (j > indexes[s[j] - 'a'].first + seen[s[j]] && s[j] < lowest_char) {
                lowest_char = s[j];
                char_index = j;
                target_index = seen[s[j]] + indexes[s[j] - 'a'].first;
                //deb(j)
            }
            seen[s[j]]++;
        }
        if (target_index == -1) break;
        //deb(lowest_char, char_index, target_index);

        for (int j = char_index; j != target_index; --j) {
            if (vals[j] == vals[j - 1]) {
                cout << "NO\n";
                return;
            }
            swap(s[j], s[j - 1]);
            swap(vals[j], vals[j - 1]);
        }
        //deb(s)
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << og[i];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    //ifstream cin ("puzzle_name.in");
    //ofstream cout ("puzzle_name.out");

    solve();

    return 0;
}
