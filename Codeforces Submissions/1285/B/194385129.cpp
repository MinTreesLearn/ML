#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5, MOD = 1e9+7;
const long long INF = 1e18;
const double EPS = 1e-6, PI_Val = 3.141592653589793238;
                    /* --- YOU SHOULD HAVE A VISION --- */
bool flag;
int n;
long long sum;
int a[N];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int _ts; cin >> _ts;
    while (_ts--)
    {
        cin >> n;
        sum = 0;
        flag = true;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (sum <= 0) flag = false;
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += a[i];
            if (sum <= 0) flag = false;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}
