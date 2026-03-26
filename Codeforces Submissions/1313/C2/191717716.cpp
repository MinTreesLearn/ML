#include <bits/stdc++.h>
#define Zeoy std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define debug(x) cerr << #x << "=" << x << endl;
#define all(x) (x).begin(), (x).end()
#define int long long
#define mpk make_pair
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
const int N = 5e5 + 10;

int n;
int a[N];
int minl[N], minr[N];
int pre[N], suf[N];
int stk[N], tt;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        while (tt && a[stk[tt]] >= a[i])
            tt--;
        if (tt)
            minl[i] = stk[tt];
        else
            minl[i] = 0;
        stk[++tt] = i;
    }
    tt = 0;
    for (int i = n; i >= 1; --i)
    {
        while (tt && a[stk[tt]] >= a[i])
            tt--;
        if (tt)
            minr[i] = stk[tt];
        else
            minr[i] = n + 1;
        stk[++tt] = i;
    }
    for (int i = 1; i <= n; ++i)
        pre[i] += pre[minl[i]] + (i - minl[i]) * a[i];
    for (int i = n; i >= 1; i--)
        suf[i] = suf[minr[i]] + (minr[i] - i) * a[i];

    int ans = 0, pos = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (ans < pre[i] + suf[i] - a[i])
        {
            ans = pre[i] + suf[i] - a[i];
            pos = i;
        }
    }
    vector<int> res(n + 2);
    int p = pos;
    while (p != 0)
    {
        for (int i = minl[p] + 1; i <= p; ++i)
            res[i] = a[p];
        p = minl[p];
    }
    p = pos;
    while (p != n + 1)
    {
        for (int i = p; i <= minr[p] - 1; ++i)
            res[i] = a[p];
        p = minr[p];
    }
    for (int i = 1; i <= n; ++i)
        cout << res[i] << " ";
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
	 	     	 		 	 			  	  		  	  	