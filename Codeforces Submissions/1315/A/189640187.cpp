#include <bits/stdc++.h>
using namespace std;
#define ll long lon

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        cout << max({x * b, a * y, (a - x - 1) * b, a * (b - y - 1)}) << endl;
    }

    return 0;
}
