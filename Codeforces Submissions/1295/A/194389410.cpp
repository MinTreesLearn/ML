#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cout.tie(nullptr);            \
    cin.tie(nullptr);
#define precision cout << fixed << setprecision(12);
#define done cout << "Successful\n";
#define input(gggg, n)             \
    for (int xd = 0; xd < n; xd++) \
        cin >> gggg[xd];
#define print(x) cout << #x << " = " << x << "\n";
#define nl "\n"
#define sp " "

void solve()
{
    ll n, c = 0;
    cin >> n;
    string a;
    if (n % 2 == 0)
    {
        ll d = n / 2;
        for (int i = 0; i < d; ++i)
        {
            cout << 1;
        }
    }
    else
    {
        cout << 7;
        ll d = (n - 3) / 2;
        for (int i = 0; i < d; ++i)
        {
            cout << 1;
        }
    }
    cout << nl;
}

int main()
{

    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
    // solve();
    return 0;
}
