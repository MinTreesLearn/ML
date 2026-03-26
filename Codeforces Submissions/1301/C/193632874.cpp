#include <bits/stdc++.h>
using namespace std;
#define oo 1000000010
#define mod 1000000007
const int N = 1010;

void solve()
{
    int n, m;
    cin>>n>>m;
    long long ans = (long long)n * (long long)(n + 1) / 2LL;
    int z = n - m;
    int k = z / (m + 1);
    ans -= (long long)(m + 1) * (long long)k * (long long)(k + 1) / 2LL;
    ans -= (long long)(z % (m + 1)) * (long long)(k + 1);
    cout<<ans<<endl;
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