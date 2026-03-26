#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int dp[MAXN][MAXN][MAXN][2], a[MAXN], n, oddCount = 0, evenCount = 0;

int f(int index, int odd, int even, int previousParity)
{
    if(index == n) return 0;

    if(dp[index][odd][even][previousParity] != -1) return dp[index][odd][even][previousParity];

    if(a[index]) return (index && previousParity != a[index] % 2) + f(index + 1, odd, even, a[index] % 2);

    int takeOdd = MAXN, takeEven = MAXN;

    if(odd) takeOdd = (index && !previousParity) + f(index + 1, odd - 1, even, 1);
    if(even) takeEven = (index && previousParity) + f(index + 1, odd, even - 1, 0);

    return dp[index][odd][even][previousParity] = min(takeOdd, takeEven);
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
        if(a[i] && a[i] % 2) oddCount++;
        if(a[i] && a[i] % 2 == 0) evenCount++;
    }

    cout << f(0, (n + 1) / 2 - oddCount, n / 2 - evenCount, 0) << "\n";
}