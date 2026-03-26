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

const int N = 1e5 + 5, A = 12, LG = 18, MOD = 1e9 + 7, INV = (MOD + 1) / 2;
const long double PI = acos(-1);
const long double EPS = 1e-9;
const int INF = 1e18;
string DIC = "UDRLX";
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
struct Nd
{
    int cnt;
    ll sumL, sumR, ans;
} t[1 << 21];
vector<ii> ord;
int n, q, p[300005], cur[300005];
int pwr[300005];
void update(int node, int s, int e, int index, int val)
{
    if (s == e)
    {
        t[node].cnt = val;
        t[node].ans = 0;
        t[node].sumL = t[node].sumR = val * ord[index].F * INV % MOD;
        return;
    }
    int md = (s + e) >> 1;
    if (index <= md)
        update(node << 1, s, md, index, val);
    else
        update(node << 1 | 1, md + 1, e, index, val);
    t[node].cnt = t[node << 1].cnt + t[node << 1 | 1].cnt;
    t[node].ans = (t[node << 1].ans + t[node << 1 | 1].ans + t[node << 1].sumL * t[node << 1 | 1].sumR) % MOD;
    t[node].sumL = (t[node << 1 | 1].sumL + t[node << 1].sumL * pwr[t[node << 1 | 1].cnt]) % MOD;
    t[node].sumR = (t[node << 1].sumR + t[node << 1 | 1].sumR * pwr[t[node << 1].cnt]) % MOD;
}
int qrI[300005], qrX[300005];
int getIndex(ii p)
{
    return lower_bound(all(ord), p) - begin(ord);
}
void doWork()
{
    cin >> n;
    pwr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pwr[i] = pwr[i - 1] * INV % MOD;
        cin >> p[i];
        ord.push_back(mp(p[i], i));
        cur[i] = i;
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> qrI[i] >> qrX[i];
        ord.push_back(mp(qrX[i], n + i));
    }
    sort(all(ord));
    for (int i = 1; i <= n; i++)
    {
        int index = getIndex(mp(p[i], i));
        update(1, 0, ord.size() - 1, index, 1);
    }
    cout << t[1].ans << endl;
    for (int i = 1; i <= q; i++)
    {
        int prvIndex = getIndex(mp(p[qrI[i]], cur[qrI[i]]));
        update(1, 0, ord.size() - 1, prvIndex, 0);
        p[qrI[i]] = qrX[i];
        cur[qrI[i]] = n + i;
        int index = getIndex(mp(p[qrI[i]], cur[qrI[i]]));
        update(1, 0, ord.size() - 1, index, +1);
        cout << t[1].ans << endl;
    }
}
int32_t main()
{
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif // ONLINE_JUDGE
    int t = 1;
    // cin >> t;
    while (t--)
    {
        doWork();
    }
    return 0;
}