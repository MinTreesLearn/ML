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
const ll N = 1500, LOG = 20;
const ld pi = acos(-1);
const ll mod = 1e9 + 7;
int dx[] = {0, -1, 0, 1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};
ll n, m, k, x, y;
int a[N];

int solve(vector<pair<int, int>> &v) {
    int cnt = 1;
    int idx;
    sort(v.begin(), v.end());
    pair<int, int> p = {v[0].second, 1e9};
    for (auto j: v) {
        if (p.second > j.second) {
            p = j;
        }
    }
    p = {p.second + 1, 0};
    idx = upper_bound(v.begin(), v.end(), p) - v.begin();
    while (idx < v.size()) {
        p = v[idx];
        p = {p.second + 1, 0};
        idx = upper_bound(v.begin(), v.end(), p) - v.begin();
        cnt++;
    }
    return cnt;
}

void dowork() {
    map<int, vector<pair<int, int>>> mp;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sum;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++) {
        sum = 0;
        for (int j = i; j > 0; j--) {
            sum += a[j];
            if (mp[sum].size() == 0 || mp[sum].back().second < j) {
                mp[sum].push_back({j, i});
            }
            if (mp[sum].size() > ans.size()) {
                ans = mp[sum];
            }
        }
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