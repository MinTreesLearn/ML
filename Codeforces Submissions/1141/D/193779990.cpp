#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define el "\n"
#define matrix vector<vector<int>>
#define pt complex<ld>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll, null_type,less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
const ll N = 2e5 + 7, LOG = 20;
const ld pi = acos(-1);
const ll mod = 1e9 + 7;
int dx[] = {0, -1, 0, 1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};
ll n, m, k, x, y;

void dowork() {
    string a, b;
    cin >> n >> a >> b;
    set<int> sta[30], stb[30];
    n = a.size();
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == '?') {
            sta[26].insert(i + 1);
        } else {
            sta[a[i] - 'a'].insert(i + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == '?') {
            stb[26].insert(i + 1);
        } else {
            stb[b[i] - 'a'].insert(i + 1);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (sta[i].size() < stb[i].size()) {
            for (auto j: sta[i]) {
                ans.push_back({j, *stb[i].begin()});
                stb[i].erase(stb[i].begin());
            }
            sta[i].clear();
        } else {
            for (auto j: stb[i]) {
                ans.push_back({*sta[i].begin(), j});
                sta[i].erase(sta[i].begin());
            }
            stb[i].clear();
        }
    }
    for (int i = 0; i < 26; i++) {
        if (sta[26].size() < stb[i].size()) {
            for (auto j: sta[26]) {
                ans.push_back({j, *stb[i].begin()});
                stb[i].erase(stb[i].begin());
            }
            sta[26].clear();
        } else {
            for (auto j: stb[i]) {
                ans.push_back({*sta[26].begin(), j});
                sta[26].erase(sta[26].begin());
            }
            stb[i].clear();
        }
    }
    for (int i = 0; i < 26; i++) {
        if (sta[i].size() < stb[26].size()) {
            for (auto j: sta[i]) {
                ans.push_back({j, *stb[26].begin()});
                stb[26].erase(stb[26].begin());
            }
            sta[i].clear();
        } else {
            for (auto j: stb[26]) {
                ans.push_back({*sta[i].begin(), j});
                sta[i].erase(sta[i].begin());
            }
            stb[26].clear();
        }
    }
    if (sta[26].size() < stb[26].size()) {
        for (auto j: sta[26]) {
            ans.push_back({j, *stb[26].begin()});
            stb[26].erase(stb[26].begin());
        }
        sta[26].clear();
    } else {
        for (auto j: stb[26]) {
            ans.push_back({*sta[26].begin(), j});
            sta[26].erase(sta[26].begin());
        }
        stb[26].clear();
    }
    cout << ans.size() << el;
    for (auto j: ans) {
        cout << j.first << " " << j.second << el;
    }
}

int main() {
    fast
    //freopen("cowland.in", "r", stdin);
    //freopen("cowland.out", "w", stdout);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        dowork();
    }
}