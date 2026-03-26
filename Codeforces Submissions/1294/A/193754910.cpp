#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int val = a;
        val = max(val, b);
        val = max(val, c);
        a = val - a;
        b = val - b;
        c = val - c;
        if ((a + b + c) > n)
        {
            cout << "NO" << endl;
        }
        else if (a == 0)
        {
            n -= b;
            n -= c;
            if ((n % 3) == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else if (b == 0)
        {
            n -= a;
            n -= c;
            if ((n % 3) == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else if (c == 0)
        {
            n -= a;
            n -= b;
            if ((n % 3) == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}