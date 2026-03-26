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

vector<pair<int, int>> ans;

void solve(set<pair<int, int>> &st1, set<pair<int, int>> &st2, bool ok = false) {
    vector<pair<int, int>> temp;
    for (auto it: st1)temp.push_back(it);
    for (auto it: temp) {
        auto it2 = st2.lower_bound({it.first, -1});
        if (it2 != st2.end() && it2->first == it.first) {
            if (ok)
                ans.emplace_back(it.second + 1, it2->second + 1);
            else ans.emplace_back(it2->second + 1, it.second + 1);
            st1.erase(it);
            st2.erase(it2);
        }
    }
}

int main() {
    file();
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> q1, q2;
    set<pair<int, int>> st1, st2;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?')q1.push_back(i);
        else st1.insert({s[i], i});
    }


    for (int i = 0; i < n; i++) {
        if (t[i] == '?')q2.push_back(i);
        else st2.insert({t[i], i});
    }

    solve(st1, st2, true);
    solve(st2, st1, false);
    vector<pair<int, int>> rem1, rem2;
    for (auto it: st1)rem1.push_back(it);
    for (auto it: st2)rem2.push_back(it);
    for (int i = 0; i < rem1.size() && (!q2.empty()); i++) {
        ans.emplace_back(rem1[i].second + 1, 1 + q2.back());
        q2.pop_back();
    }

    for (int i = 0; i < rem2.size() && (!q1.empty()); i++) {
        ans.emplace_back(q1.back() + 1, rem2[i].second + 1);
        q1.pop_back();
    }
    for (int i = 0; i < min(q1.size(), q2.size()); i++) {
        ans.emplace_back(q1[i] + 1, q2[i] + 1);
    }
    cout << ans.size() << "\n";
    for (auto it: ans)cout << it.first << " " << it.second << "\n";
}