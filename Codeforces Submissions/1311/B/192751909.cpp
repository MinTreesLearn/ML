#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define all(x) x.begin(),x.end()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

vector<int> dx8 = {0, 1, -1, 0, 1, -1, -1, 1},
        dy8 = {1, 0, 0, -1, 1, -1, 1, -1},
        dx4 = {0, 1, -1, 0},
        dy4 = {1, 0, 0, -1};


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<bool> vis(101);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            vis[b[i] - 1] = 1;
        }
        sort(all(b));
        for (int i = 0; i < m; ++i) {
            int j = b[i];
            while (1) {
                if (a[b[i] - 1] > a[j]) {
                    swap(a[b[i] - 1], a[j]);
                }
                if (vis[j]) {
                    j++;
                } else {
                    break;
                }
            }
        }
        if (is_sorted(all(a))) {
            yes
        } else {
            no
        }
    }

    return 0;
}