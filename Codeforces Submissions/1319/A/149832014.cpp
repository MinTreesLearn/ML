#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;
const int X = 1e6 + 1;
int mac[X];
signed main()
{
    int a, b;
    cin >> a ;
    int k = 0, k1 = 0;
    for (int i = 0;i < a;i++)
    {
        cin >> mac[i];
    }
    for (int i = 0;i < a;i++)
    {
        int x;
        cin >> x;
        if (x == 0 && mac[i] == 1)
        {
            k++;
        }
        if (x == 1 && mac[i] == 0)
        {
            k1++;
        }
    }
    if (k == 0)
    {
        cout << -1;
        return 0;
    }
    cout << k1 / k + 1;
}
