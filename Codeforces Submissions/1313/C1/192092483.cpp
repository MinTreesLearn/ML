#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    //pick max
    
    vector<int> c(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        //max is i
        int sm = a[i];
        int mn = a[i];
        
        vector<int> b(n);
        b[i] = a[i];
        for (int j = i-1; j >= 0; j--)
        {
            mn = min(mn, a[j]);
            b[j] = mn;
            sm += mn;
        }
        
        
        mn = a[i];
        
        for (int j = i + 1; j < n; j++)
        {
            mn = min(mn, a[j]);
            b[j] = mn;
            sm += mn;
        }
        
        if (sm > ans)
        {
            ans = sm;
            c = b;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    cout << "\n";
    
 return 0;
}
