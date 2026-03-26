#include <bits/stdc++.h>

using namespace std;
#define sz(s) (int)(s.size())
#define all(v) v.begin(),v.end()
#define clr(d, v) memset(d,v,sizeof(d))
#define ll long long


void file() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    file();
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it: v)cin >> it;
    map<ll, vector<pair<int, int>>> mp;
    for (int r = 0; r < n; r++) {
        ll sum = 0;
        for (int l = r; l >= 0; l--) {
            sum += v[l];
            mp[sum].emplace_back(l, r);
        }
    }
    vector<pair<int, int>> ans;
    for (auto it: mp) {
        int last = -1;
        vector<pair<int, int>> temp;
        for (auto it2: it.second) {
            if (it2.first > last) {
                temp.push_back(it2);
                last = it2.second;
            }
        }
        if (temp.size() > ans.size()) {
            ans = temp;
        }

    }
    cout << ans.size() << "\n";
    for (auto it: ans)cout << it.first + 1 << " " << it.second + 1 << "\n";

}