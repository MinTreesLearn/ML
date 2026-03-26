#include "bits/stdc++.h"

using namespace std;

signed main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> a(n);
    for (auto &i: a) cin >> i;
    int cnt = 0;
    map<string, int> mp;
    for (auto i: a)
        mp[i]++;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string tmp;
            for (int k = 0; k < m; k++) {
                if (a[i][k] == a[j][k])
                    tmp += a[i][k];
                else {
                    for (auto e: {'S', 'T', 'E'})
                        if (a[i][k] != e and a[j][k] != e)
                            tmp += e;
                }
            }
            cnt += mp[tmp];
        }
    }
    cout << cnt / 3 << '\n';

}
