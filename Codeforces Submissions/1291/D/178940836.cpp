#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
typedef unsigned long long ull;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;

string s;
int pre[34][N];

void run()
{
    int n, q, l, r, cnt;

    cin >> s;
    cin >> q;
    n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 26; j++)
            if (s[i] - 'a' == j - 1)
                pre[j][i] = pre[j][i - 1] + 1;
            else
                pre[j][i] = pre[j][i - 1];
    while (q--)
    {
        cin >> l >> r;
        if (l == r || s[l] != s[r])
            cout << "Yes";
        else
        {
            cnt = 0;
            for (int i = 1; i <= 26; i++)
                if (pre[i][r] - pre[i][l - 1] > 0)
                    cnt++;
            if (cnt >= 3)
                cout << "Yes";
            else
                cout << "No";
        }
        cout << endl;
    }
}

signed main()
{
    int T = 1;

    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // cin >> T;
    while (T--)
        run();

    return 0;
}