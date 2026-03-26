#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>a(n);
    ll sm = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sm += a[i];
    }
    
    
    cout << min(1ll * m, sm) << "\n";
    
}
int main()
{
    int t;
cin >> t;
 while (t--)
{
    solve();
}

 return 0;
}
