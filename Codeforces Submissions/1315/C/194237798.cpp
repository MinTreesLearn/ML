#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    set<int> st;
    for(int i = 1; i <= n; i++) cin >> a[i], st.insert(i), st.insert(n + i);

    vector<int> ans(2 * n + 1);

    for(int i = 1; i <= n; i++) st.erase(a[i]);

    for(int i = 1; i <= n; i++)
    {
        ans[2 * i - 1] = a[i];
        auto pos = st.upper_bound(a[i]);
        if(pos == st.end())
        {
            cout << -1 << '\n';
            return ;
        }
        else ans[2 * i] = *pos, st.erase(pos);
    }

    for(int i = 1; i <= 2 * n; i++) cout << ans[i] << " ";

    cout << '\n';
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