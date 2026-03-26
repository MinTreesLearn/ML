///KoJa
#include<bits/stdc++.h>
using namespace std;
#define task "test"
#define vec vector
#define fi first
#define se second
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(n) (1LL << (n))
#define MASK(x, i) (((x) >> (i))&1)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;

template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b, 1) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b, 1) : 0); }
struct Points
{
    ll x, y;
    Points(){}
    Points(ll _x, ll _y)
    {
        x = _x;
        y = _y;
    }
    Points operator - (const Points &other) const { return Points(x - other.x, y - other.y);}
    ll operator * (const Points &other) const { return x * other.y - y * other.x;}
    ll triangle(const Points &b, const Points &c)
    {
        return (*this - b) * (*this - c);
    }
};
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if(fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    else if(fopen(task ".in", "r"))
    {
        freopen(task ".in", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}
const int N = 50 + 10;
const int M = int(2e4) + 10;
const int INF = int(1e9);
int n, m, k;
int a[N][M], dp[N][M], pref[N][M];
void init()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];
}
class SegmentTree
{
private:
    int n;
    vec<int> st;
    void update(int pos, int val, int l, int r, int id)
    {
        if((l > r)||(l > pos)||(pos > r)) return;
        if(l == r)
        {
            st[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(pos, val, l, mid, 2 * id);
        update(pos, val, mid + 1, r, 2 * id + 1);
        st[id] = max(st[2 * id], st[2 * id + 1]);
    }
    int getMax(int u, int v, int l, int r, int id)
    {
        if((u > v)||(l > r)||(u > r)||(l > v)) return -INF;
        if((u <= l)&&(r <= v)) return st[id];
        int mid = (l + r) >> 1;
        return max(getMax(u, v, l, mid, 2 * id), getMax(u, v, mid + 1, r, 2 * id + 1));
    }
public:
    SegmentTree(int _n = 0)
    {
        this->n = _n;
        st.assign(4 * n + 10, -INF);
    }
    void update(int pos, int val) { return update(pos, val, 1, n, 1);}
    int getMax(int l, int r) { return getMax(l, r, 1, n, 1);}
} it1, it2, it3;
void process(int tc = 0)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++) pref[i][j] = pref[i][j - 1] + a[i][j];
    }
    for(int i = 1; i + k - 1 <= m; i++)
        dp[1][i] = pref[1][i + k - 1] - pref[1][i - 1] + pref[2][i + k - 1] - pref[2][i - 1];
    for(int i = 2; i <= n + 1; i++)
    {
        it1 = it2 = it3 = SegmentTree(m);
        /**
            cost = sum(i->i+1, j->j+k-1)
            dp(i, j) = dp(i - 1, x) + cost x = 1->j-k
            dp(i, j) = dp(i - 1, y) + cost y = j+k->m
            dp(i, j) = dp(i - 1, z1) + cost - sum(i, z1->j+k-1) z1=j->j+k-1
            dp(i, j) = dp(i - 1, z2) + cost - sum(i, j->z2+k-1) z2=j-k+1->j
        */
        for(int j = 1; j + k - 1 <= m; j++)
        {
            it1.update(j, dp[i - 1][j]);
            //cout << i - 1 << " " << j << " " << dp[i - 1][j] << '\n';
        }
        for(int j = 1; j + k - 1 <= m; j++) it2.update(j, dp[i - 1][j] + pref[i][j - 1]);
        for(int j = 1; j + k - 1 <= m; j++) it3.update(j, dp[i - 1][j] - pref[i][j + k - 1]);
        for(int j = 1; j + k - 1 <= m; j++)
        {
            int cost = pref[i][j + k - 1] - pref[i][j - 1] + pref[i + 1][j + k - 1] - pref[i + 1][j - 1];
            if(j - k >= 1) dp[i][j] = max(dp[i][j], it1.getMax(1, j - k));
            if(j + k <= m - k + 1) dp[i][j] = max(dp[i][j], it1.getMax(j + k, m));
            dp[i][j] = max(dp[i][j], it3.getMax(max(j - k + 1, 1), j) + pref[i][j - 1]);
            dp[i][j] = max(dp[i][j], it2.getMax(j, min(j + k - 1, m)) - pref[i][min(j + k - 1, m)]);
            dp[i][j] += cost;
            //cout << i << " " << j << " " << dp[i][j] << '\n';
        }
    }
    int res = 0;
    for(int i = 1; i + k - 1 <= m; i++) res = max(res, dp[n + 1][i]);
    cout << res;
}

int main()
{
    fastio();
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++)
    {
        init();
        process(i);
    }
    return 0;
}
