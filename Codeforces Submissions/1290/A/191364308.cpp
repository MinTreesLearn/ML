#include<iostream>
#include<algorithm>
#include<string>
#define int long long
#define endl '\n'
using namespace std;
int t, n, m, k;
int x, y;
int a[100010];
int l, r;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        k = min(k, m-1);
        for (int i = 0; i <= k; i++) {
            l = i + 1;
            r = n - k + i;
            int res = 1e9;
            for (int j = 0; j <= m - k - 1; j++) {
                res = min(res, max(a[l + j], a[r - (m - k - 1) + j]));
            }
            ans = max(ans, res);
        }
        cout << ans << endl;
    }
    return 0;
}

     		 		 	 						   	 		 		 	