#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N  = 1e6 + 3;

int main()
{
    cin.tie(0);cin.sync_with_stdio(0);
    cout.tie(0);cout.sync_with_stdio(0);

    int n;
    cin >> n;

    map<ll , ll > fr;

    ll ans =0 ;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        fr[x - i] += x;
        ans = max(ans , fr[x-i] ) ;
    }

    cout << ans ;

    return 0;
}