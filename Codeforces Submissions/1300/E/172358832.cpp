#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        int s = a[i];
        int cnt = 1;
        while (q.size() && (s + q.back().first) * cnt >= s * (q.back().second + cnt)) {
            s += q.back().first;
            cnt += q.back().second;
            q.pop_back();
        }
        q.push_back({s, cnt});
    }
    cout.precision(20);
    for (auto i: q) {
        for (int j = 0; j < i.second; ++j) {
            cout << (double) i.first / i.second << "\n";
        }
    }
}