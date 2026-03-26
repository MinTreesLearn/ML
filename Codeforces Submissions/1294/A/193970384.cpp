#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int a, b, c, d;
        cin >> a >> b >> c >> d;
        long int x1 = max(a, b);
        long int x=max(x1,c);
        long int d1 = x - a;
        long int d2 = x - b;
        long int d3 = x - c;
        d = d - (d1 + d2 + d3);
        if (d % 3 == 0 && d>=0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}