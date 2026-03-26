#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve()
{
    LL n, a, b;
    cin >> n >> a >> b;
    LL t = (n + 1) / 2;
    if(t <= a)
    {
        cout << n << '\n';
    }
    else 
    {
        LL tmp = t / a;
        LL ans = tmp * (a + b);
        if(t % a) ans += t % a;
        else ans -= b;
        if(ans < n) cout << n << '\n';
        else cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}