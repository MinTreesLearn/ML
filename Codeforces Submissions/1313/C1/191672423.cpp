#include <bits/stdc++.h>
#define Zeoy std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define mp make_pair
#define endl '\n'
using namespace std;
typedef unsigned long long ULL;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-9;
const int N = 1e5 + 10;

int n;
int a[N];
int stk1[N], tt1, stk2[N], tt2;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = 0;
    int pos = -1;
    for (int i = 1; i <= n; ++i)
    {
        tt1 = tt2 = 0;
        int sum = 0;
        for (int j = i; j >= 1; --j)
        {
            if (tt1 && a[j] > stk1[tt1])
            {
                int t = stk1[tt1];
                stk1[++tt1] = t;
                sum += stk1[tt1];
            }
            else if (tt1 && a[j] <= stk1[tt1] || !tt1)
            {
                stk1[++tt1] = a[j];
                sum += stk1[tt1];
            }
        }
        for (int j = i; j <= n; ++j)
        {
            if (tt2 && a[j] > stk2[tt2])
            {
                int t = stk2[tt2];
                stk2[++tt2] = t;
                sum += stk2[tt2];
            }
            else if (tt2 && a[j] <= stk2[tt2] || !tt2)
            {
                stk2[++tt2] = a[j];
                sum += stk2[tt2];
            }
        }
        sum -= a[i];
        if (sum > ans)
        {
            ans = sum;
            pos = i;
        }
    }
    tt1 = tt2 = 0;
    for (int j = pos; j >= 1; --j)
    {
        if (tt1 && a[j] > stk1[tt1])
        {
            int t = stk1[tt1];
            stk1[++tt1] = t;
        }
        else if (tt1 && a[j] <= stk1[tt1] || !tt1)
            stk1[++tt1] = a[j];
    }
    for (int j = pos; j <= n; ++j)
    {
        if (tt2 && a[j] > stk2[tt2])
        {
            int t = stk2[tt2];
            stk2[++tt2] = t;
        }
        else if (tt2 && a[j] <= stk2[tt2] || !tt2)
            stk2[++tt2] = a[j];
    }
    while (tt1)
    {
        cout << stk1[tt1] << " ";
        tt1--;
    }
    for (int i = 2; i <= tt2; ++i)
        cout << stk2[i] << " ";
    cout << endl;
}
signed main(void)
{
    Zeoy;
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}