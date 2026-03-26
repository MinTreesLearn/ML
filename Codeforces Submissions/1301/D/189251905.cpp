#include <bits/stdc++.h>
using namespace std;
int main() {
    vector <pair<int, string>> way, ans;
    int n, m, k, cur = 0;
    cin >> n >> m >> k;
    if (k > 4 * n * m - 2 * (n + m)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n - 1; ++i) {
        if(m != 1) {
            way.push_back({m - 1, "R"});
            way.push_back({m - 1, "L"});
        }
        way.push_back({1, "D"});
    }
    if(m != 1) way.push_back({m - 1, "R"});
    for (int i = m - 1; i >= 0; --i) {
        if( n != 1) way.push_back({n - 1, "U"});
        if (i != 0) {
            if(n != 1) way.push_back({n - 1, "D"});
            way.push_back({1, "L"});
        }
    }
    for (auto i : way) {
        if (cur + i.first >= k) {
            ans.push_back({k - cur, i.second});
            break;
        } else {
            cur += i.first;
            ans.push_back({i.first, i.second});
        }
    }
    cout << (int) ans.size() << "\n";
    for (auto i : ans) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}