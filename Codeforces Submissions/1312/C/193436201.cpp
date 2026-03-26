#include <bits/stdc++.h>

#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define endl '\n'
using namespace std;

void DuckMyKofta() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e5 + 5;
const long long BASE = 1e9 + 7;
const int INV_2 = 5e8 + 4;
const int LOG = 20;
const long double PI = 3.14159265358979323846;
int dx[] = {+0, +0, -1, +1, +1, -1, +1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, -1, +1};


void solve(int testcase) {
    int n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m = (int) (log(LONG_LONG_MAX) / log(k));
    vector<vector<int>> bits(n, vector<int>(m+1));

    for (int i = 0; i < n; ++i) {
        ll tmp = a[i];
        int cnt = 0;
        while (tmp) {
            bits[i][cnt] = tmp % k;
            tmp /= k;
            cnt++;
        }
    }
    set<int> st;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (bits[i][j] == 1) {
                if (st.contains(j)) {
                    cout << "NO" << endl;
                    return;
                }
                st.insert(j);
            } else if (bits[i][j] != 0) {
                cout << "NO" << endl;
                return;
            }

        }
    }
    cout << "YES" << endl;
}


signed main() {
    DuckMyKofta();
    int t = 1, cnt = 1;
    cin >> t;
    while (t--) {
        solve(cnt++);
    }
}
