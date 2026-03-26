#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int a[n], s = 0, k = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            s += a[j];
        }
        for (int j = 0; j < n; j++)
        {
            if (a[j] == 0)
            {
                a[j] = 1;
                k = k + 1;
            }
        }
        if (k == 0 && s == 0)
            k = 1;
        if ((k + s) == 0)
            k++;
        cout << k << endl;
    }
return 0;
}
