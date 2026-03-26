#include<bits/stdc++.h>
using namespace std;
#define X first
#define ll __int128
#define int long long
#define Y second
#define pii pair<int, int>
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define push emplace
#define lb(x, v) lower_bound(ALL(x), v)
#define ub(x, v) upper_bound(ALL(x), v)
#define re(x) reverse(ALL(x))
#define uni(x) x.resize(unique(ALL(x)) - x.begin())
#define inf 1000000000
#define INF 1000000000000000000
#define mod 1000000007
#define get_bit(x, y) ((x>>y)&1)
#define mkp make_pair
#define IO ios_base::sync_with_stdio(0); cin.tie(0);

#ifdef loli
void trace_() {cerr << "\n";}
template<typename T1, typename... T2> void trace_(T1 t1, T2... t2) {cerr << ' ' << t1; trace_(t2...); }
#define trace(...) cerr << "[" << #__VA_ARGS__ << "] :", trace_(__VA_ARGS__);
#else
#define trace(...) 49
#endif


#define x first
#define y second
#define point pii
point pt[2501];

point operator + (point a, point b) {
    return point(a.x + b.x, a.y + b.y); 
}
point operator - (point a, point b) {
    return point(a.x - b.x, a.y - b.y); 
}
inline int cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

int sgn(point a) {
    if (a.X >= 0 and a.Y >= 0) return 1;
    if (a.X <= 0 and a.Y >= 0) return 2;
    if (a.X <= 0 and a.Y <= 0) return 3;
    return 4;
}

point o;
bool cmp(point a, point b) {
    a = a - o;
    b = b - o;
    if (sgn(a) == sgn(b)) return cross(a, b) >= 0;
    return sgn(a) < sgn(b);
}

ll C4(ll x) {
    return (x * (x - 1) * (x - 2) * (x - 3) / 24);
}

int n;
inline void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pt[i].x >> pt[i].y;

    ll ans = 0;

    for (int c = 0; c < n; c++) {
        o = pt[c];
        vector<point> v;
        for (int i = 0; i < n; i++) if (i != c) v.eb(pt[i]);
        sort(ALL(v), cmp);
        for (int i = 0; i < n - 1; i++) v.eb(v[i]);

        int j = -1;
        ll add = 0, prv = 0, res = C4(n - 1);
        for (int i = 0; i < n - 1; i++) {
            j = max(j, i - 1);
            while (j + add + 1 < SZ(v) and (cross(v[j + add + 1] - v[i], o - v[i]) > 0 or (j + add + 1) == i)) add++;
            prv = j - i + 1;        
            ll sub = j - n + 2;
            if (sub < 0) sub = 0;
            j += add;

            if (add + prv >= 4) res -= C4(add + prv);
            if (prv >= 4) res += C4(prv);
            if (j - n + 2 >= 4) res += C4(j - n + 2);
            if (sub >= 4) res -= C4(sub);

            add = 0;
        }
        ans += res;
    }

    int out = ans;
    cout << out << '\n';
}

signed main() {
    IO; 
    solve();    
}