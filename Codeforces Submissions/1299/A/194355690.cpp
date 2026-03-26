#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> cnt(30, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (a[i] & (1LL << j))
            {
                cnt[j]++;
            }
        }
    }
    int pos = 0;
    for (int j = 29; j >= 0; j--)
    {
        if (cnt[j] == 1)
        {
            pos = j;
            j = -1;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]&(1LL<<pos)){
            swap(a[i],a[0]);
            i=n+2;
        }
    }
    for(auto u:a)cout<<u<<" ";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}