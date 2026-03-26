#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
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
    cout << md << endl;
    for (int i = 0; i < s.size(); i++)
        cout << col[i] << ' ';
}