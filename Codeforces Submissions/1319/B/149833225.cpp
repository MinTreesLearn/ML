#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;
const int X = 1e6 + 1;
int mac[3*X];
int cnt[3*X];
signed main()
{
    int a, b;
    cin >> a ;
    for (int i = 0;i < a;i++)
    {
        cin >> mac[i];
    }
    int mx = 0;
    for (int i = 0;i < a;i++)
    {
        cnt[mac[i] - i + X] += mac[i];
        mx = max(mx, cnt[mac[i] - i + X]);
    }
    cout << mx;
}
