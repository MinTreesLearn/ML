#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int32_t test; cin >> test;
    int32_t m, n;
    while (test--)
    {
        cin >> m >> n;
        if (m%n == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}