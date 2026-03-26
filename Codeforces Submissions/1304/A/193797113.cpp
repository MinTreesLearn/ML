#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int32_t test; cin >> test;
    int64_t x, y, a, b, d;
    while (test--)
    {
        cin >> x >> y >> a >> b;
        d = y-x;
        if ((d/(a+b))*a+(d/(a+b))*b == d)
            cout << d/(a+b) << '\n';
        else cout << "-1\n";
    }
    return 0;
}