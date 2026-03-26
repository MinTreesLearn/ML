#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const double PI = acos(-1);
const ll mod7 = 1e9 + 7;
const ll mod9 = 998244353;
const ll INF = 2 * 1024 * 1024 * 1023;
const char nl = '\n';
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(v) v.begin(),v.end()

#pragma GCC optimize("O2")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
ll l, r, k, n, m, p, q, u, v, w, x, y, z;
string s, t;

vi d4x = {1, 0, -1, 0};
vi d4y = {0, 1, 0, -1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1, 20)(rng)
 
////////////////////  LIBRARY CODE ////////////////////

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;

const ll MOD = mod9; //CHANGE MOD SETTING!!!
ll norm(ll x) { return (x + MOD) % MOD; }
template <class T>
T power(T a, ll b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
struct Mint {
  ll x;
  Mint(ll _x = 0) : x(norm(_x)) {}
  Mint operator-() const { return Mint(norm(MOD - x)); }
  Mint inv() const { return power(*this, MOD - 2); }
  Mint &operator*=(const Mint &rhs) { return x = x * rhs.x % MOD, *this; }
  Mint &operator+=(const Mint &rhs) { return x = norm(x + rhs.x), *this; }
  Mint &operator-=(const Mint &rhs) { return x = norm(x - rhs.x), *this; }
  Mint &operator/=(const Mint &rhs) { return *this *= rhs.inv(); }
  Mint &operator%=(const auto &_) { return *this; }
  friend Mint operator*(Mint lhs, const Mint &rhs) { return lhs *= rhs; }
  friend Mint operator+(Mint lhs, const Mint &rhs) { return lhs += rhs; }
  friend Mint operator-(Mint lhs, const Mint &rhs) { return lhs -= rhs; }
  friend Mint operator/(Mint lhs, const Mint &rhs) { return lhs /= rhs; }
  friend Mint operator%(Mint lhs, const auto &_) { return lhs; }
  friend istream &operator>>(istream &input, Mint &z) { return input >> z.x, input; }
};
ostream& operator<<(ostream& out, const Mint& x)
{
  return out << x.x;
}

///////////////////////////////////////////////////////

Mint calc(ll a, ll b) {
    Mint cur = 1;
    ll iter = b;
    forn(i, iter) {
        cur *= a;
        cur /= b;
        a--;
        b--;
    }

    return cur;
}

bool multiTest = 0;
void solve(int tt){

    cin >> n;

    set<int> startSet;
    startSet.insert(0);
    startSet.insert(998244352);

    vector<pii> segs(n);
    Mint divide = 1;

    forn(i, n) {
        cin >> segs[n-(i+1)].first >> segs[n-(i+1)].second;
    }

    forn(i, n) {
        startSet.insert(segs[i].first);
        startSet.insert(segs[i].second+1);
        divide *= segs[i].second + 1 - segs[i].first;
    }

    vi starts;
    for(int z : startSet) starts.push_back(z);

    m = starts.size();
    m--;
    vi sizes(m);
    int allowed[n][m];
    memset(allowed, 0, sizeof(allowed));
    forn(i, n) {
        u = segs[i].first;
        v = segs[i].second;
        forn(j, m) {
            l = starts[j];
            r = starts[j+1] - 1;
            sizes[j] = r + 1 - l;
            if(u <= l && v >= r) allowed[i][j] = 1;
        }
    }

    Mint dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    forn(i, n) {

        // forn(j, m+1) {
        //     cerr << i << ' ' << j << ' ' << dp[i][j] << nl;
        // }

        forn(j, m) {
            dp[i][j+1] += dp[i][j];
        }

        forn(j, m) {

            Mint cur = dp[i][j];

            for(int k = i; k < n; k++) {
                if(!allowed[k][j]) break;
                int sz = k + 1 - i;
                dp[k+1][j+1] += cur * calc(sz + sizes[j] - 1, sz);
            }
        }
    }

    Mint ans = 0;
    forn(i, m+1) ans += dp[n][i];

    cout << ans/divide << nl;

}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifdef yangster
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // #else 
    // freopen("cowpatibility.in", "r", stdin);
    // freopen("cowpatibility.out", "w", stdout);
    #endif

    cout << fixed << setprecision(14);

    int t = 1;
    if (multiTest) cin >> t;
    for (int ii = 0; ii < t; ii++) {
        solve(ii + 1);
    }
}