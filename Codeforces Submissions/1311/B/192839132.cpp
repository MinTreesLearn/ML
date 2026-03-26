#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = n; j > i; j--)
        {
            if(a[i] > a[j])
            {
                b[i]++, b[j]--;
                // cout << i << " " << j << endl;
                break;
            } 
        }
    }

    set<int> st;
    for(int i = 0; i < m; i++) 
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    for(int i = 1; i <= n; i++) b[i] += b[i - 1];

    for(int i = 1; i <= n; i++)
    {
        if(b[i])
        {
            if(!st.count(i))
            {
                cout << "NO\n";
                return ;
            }
        }
    }

    cout << "YES\n";
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