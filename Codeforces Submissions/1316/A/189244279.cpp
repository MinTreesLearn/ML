///Moba8ta gya mn el 2alb
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define popCnt(x) (__builtin_popcountll(x))
#define int ll

using ll = long long;
using ull = unsigned long long;
using uint = uint32_t;
using ii = pair<int, int>;

const int N = 2e5 + 5, A = 12, LG = 18, MOD = 1e9 + 7;
const long double PI = acos(-1);
const long double EPS = 1e-9;
const int INF = 1e18;
void doWork()
{
    int n, m;
    cin >> n >> m;
    int sum = 0;
    f(i,0,n) {
        int x;
        cin >> x;
        sum += x;
    }
    cout << min(sum,m) << endl;

}
int32_t main()
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif // ONLINE_JUDGE
    int t = 1;
    cin >> t;
    while (t--)
    {
        doWork();
    }
    return 0;
}
