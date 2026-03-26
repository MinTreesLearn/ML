#include <bits/stdc++.h>

using namespace std;

#define i64 long long
#define db double
#define INF INT_MAX
#define endl "\n"
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define lc (node << 1)
#define rc (lc | 1)
#define pii pair<int, int>
#define pdd pair<db, db>

using namespace std;
const int N = 1e5 + 10;
const int mod = 998244353;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        vector<bool> vis(N);
        for (int i = 0; i < 5000; i++)
            vis[i] = 1;
        int n, s, k;
        cin >> n >> s >> k;
        for (int i = 1; i <= k; i++)
        {
            int x;
            cin >> x;
            if (x >= s - 2000 && x <= s + 2000)
                vis[x - s + 2000] = 0;
        }
        if (vis[2000])
            cout << "0\n";
        else
        {
            int R = min(4000, n - s + 2000);
            int L = max(1, 1 - s + 2000);

            int idx = 2000;
            int sum = 0;
            while (!vis[idx] && idx <= R)
            {
                sum++;
                idx++;
            }

            if (!vis[R] && idx == R + 1)
                sum = INF;

            int idx_1 = 2000;
            int sum_1 = 0;
            while (!vis[idx_1] && idx_1 >= L)
            {
                sum_1++;
                idx_1--;
            }
            if (idx_1 == L - 1 && !vis[L])
                sum_1 = INF;

            cout << min(sum, sum_1) << endl;
        }
    }
    return 0;
}