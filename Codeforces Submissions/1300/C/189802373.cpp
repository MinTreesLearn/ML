#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int> z(30);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < 30; j++)
        {
            if (a[i] & (1 << j))
            {
                z[j]++;
            }
        }
    }
    
    int q = -1;
    
    for (int i = 29; i >= 0; i--)
    {
        if (z[i] == 1)
        {
            for (int j = 0; j < n; j++)
            {
                if (q == -1 && a[j] & (1 << i))
                {
                    q = j;
                }
            }
        }
    }
    
    
    if (q != -1)
    {
        cout << a[q] << " ";
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i != q)
        {
            cout << a[i] << " ";
        }
    }
    cout << "\n";
 return 0;
}
