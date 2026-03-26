//  ↘ ⬇ ⬇ ⬇ ⬇ ⬇ ↙
//  ➡ @roadfromroi ⬅
//  ↗ ⬆ ⬆ ⬆ ⬆ ⬆ ↖
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
void solve() {
    multiset<pair<int, int>> a;
    int n;
    cin >> n;
    vector<int> aa(n), bb(n);
    for (int i = 0; i < n; ++i) {
        cin >> aa[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> bb[i];
        a.insert({aa[i], bb[i]});
    }
    int res = 0;
    multiset<int> ls;
    int lssm = 0;
    int lsvl = -3;
    while (!a.empty()) {
        int vl = a.begin()->first;
        //cout << ls.size() << ' ' << lsvl << '\n';
        while (!ls.empty() and lsvl != vl) {
            lsvl++;
            lssm -= *ls.rbegin();
            ls.erase(--ls.end());
            res += lssm;
        }
        lsvl = vl;
        ls.insert(a.begin()->second);
        lssm += a.begin()->second;
        a.erase(a.begin());
    }
    while (!ls.empty()) {
        lssm -= *ls.rbegin();
        ls.erase(--ls.end());
        res += lssm;
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}
