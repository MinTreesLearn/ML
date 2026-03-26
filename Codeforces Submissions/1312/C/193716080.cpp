#include <bits/stdc++.h>
using namespace std;
#define int long long int

int bs(int k, int x)
{
    int l = 0, h;
    int p = 1;
    for (int i = 1; i < 60; i++)
    {
        if (p * k < 0)
            break;
        h = i;
        p = p * k;
    }
    int ans = -1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int key = 1;
        for (int i = 1; i <= mid; i++)
        {
            key = key * k;
        }
        if (key <= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    return ans;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {

        while (a[i] > 0)
        {
            int x = bs(k, a[i]);
            if (x == -1)
            {
                cout << "NO";
                return;
            }
            mp[x]++;
            if (mp[x] > 1)
            {
                cout << "NO";
                return;
            }
            int p = 1;
            //cout<<x<<" hehe\n";
            for (int j = 1; j <= x; j++)
                p = p * k;

            a[i] -= p;
        }
    }
    cout << "YES";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}