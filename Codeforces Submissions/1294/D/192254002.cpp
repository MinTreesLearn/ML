#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (long long i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define endl '\n'
const int MOD = 1000000007;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll q, x;
    cin >> q >> x;
    multiset<ll> st;
    ll qt = 0;
    ll ct = 0;
    while (q--)
    {
        ll y;
        cin >> y;
        y = (y % x);
        st.insert(y);
        while (st.count(ct) > 0)
        {
            st.erase(st.find(ct));
            ct++;
            if (ct == x)
            {
                qt++;
                ct = 0;
            }
        }
        cout << ct + x * qt << endl;
    }
    return 0;
}