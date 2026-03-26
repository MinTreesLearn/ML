/// IN THE NAME OF ALLAH
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    int a, b, c, n;
    while(t--)
    {
        cin >> a >> b >> c >> n;
        int mx = max (a, max(b, c));
        int tr = mx - a;
        a += tr;
        n -= tr;
        
        tr = mx - b;
        b += tr;
        n -= tr;
        
        tr = mx - c;
        c += tr;
        n -= tr;
        if ((a == b && b == c) && (n%3 == 0 && n >= 0)) cout<< "YES" << endl;
        else cout << "NO" << endl;
    }
}