#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    int lo = 1, hi = 27;
    int md = 0;
    vector<int> col(n + 3);
    vector<char> seg(29);
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        for (int i = 0; i <= mid; i++)
            seg[i] = 'a';
        bool flag = 1;
        for (int i = 0; i < n; i++)
        {
            int u = -1;
            for (int j = 1; j <= mid; j++)
            {
                if (s[i] < seg[j])
                    continue;
                if (u == -1 or seg[j] > seg[u])
                    u = j;
            }
            if (u == -1)
            {
                flag = 0;
                break;
            }
            col[i] = u;
            seg[u] = s[i];
        }
        if (flag)
        {
            hi = mid - 1;
            md = mid;
        }
        else
            lo = mid + 1;
    }
    if (md > 2)
    {
        cout << "NO" << endl;
        exit(0);
    }
    cout << "YES" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        if (col[i] == 1)
            col[i] = 0;
        else
            col[i] = 1;
        cout << col[i];
    }
}