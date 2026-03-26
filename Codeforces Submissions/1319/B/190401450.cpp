#include <bits/stdc++.h>

using namespace std;

const int inf = 1e15;

#define int long long

mt19937_64 rnd(441225); //ddly

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i] - i;
    }
    map<int, int> mp;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mp[b[i]] += a[i];
        mx = max(mx, mp[b[i]]);
    }
    cout << mx;
}
