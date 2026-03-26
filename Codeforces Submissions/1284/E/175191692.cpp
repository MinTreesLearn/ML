#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) 1
#endif

using ll = long long;
using db = long double;
using VS = vector<string>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using PLL = pair<ll, ll>;
using MLL = map<ll, ll>;
using SLL = set<ll>;
using QLL = queue<ll>;
using SS = stringstream;

#define rep(x, l, u) for (ll x = l; x < u; x++)
#define rrep(x, l, u) for (ll x = l; x >= u; x--)
#define fe(x, a) for (auto x : a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x, v) memset(x, v, sizeof(x))
#define sz(x) (ll) x.size()

#define umap unordered_map
#define uset unordered_set
#define mset multiset

// clang-format off

ll ob(ll i, ll n) { return i < 0 || i >= n; }
ll tp(ll x) { return ( 1LL << x ); }
ll rup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
ll sign(ll x) {	return x == 0 ? 0 : x / abs(x); }
void makemod(ll& x, ll m) { x %= m; if (x < 0) { x += m; } }
ll getmod(ll x, ll m) { makemod(x, m); return x; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1; ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
ll invmod(ll a, ll m) { return powmod(a, m - 2, m); }
void inll(ll& x) { scanf("%lld", &x); }

template <typename A, typename B> bool upmin(A& x, B v) { if (v >= x) return false; return x = v, true; }
template <typename A, typename B> bool upmax(A& x, B v) { if (v <= x) return false; return x = v, true; }

// clang-format on

const VLL di = {0, 0, 1, -1, 1, -1, 1, -1}, dj = {1, -1, 0, 0, -1, -1, 1, 1};
const ll mod = 1'000'000'007, mod2 = 998'244'353, inf = (ll)1e18 + 5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const double PI = atan(1) * 4;

struct Angle {
    ll x, y, revs;  // x, y of the coordinate
    // revs is the 0-indexed circle its on
    // by default 0
    Angle(ll x, ll y, ll r = 0) {
        ll g = gcd(x, y);
        assert(g > 0);

        this->x = x / g;
        this->y = y / g;
        this->revs = r;
    }

    ll quadrant() const {
        // * NOTE this is 0-indexed
        if (y >= 0 && x > 0) return 0 + revs * 4;
        if (x <= 0 && y > 0) return 1 + revs * 4;
        if (y <= 0 && x < 0) return 2 + revs * 4;
        if (x >= 0 && y < 0) return 3 + revs * 4;
        assert(false);
    }

    PLL bound(ll quad) const {
        return {quad * 90, (quad + 1) * 90};
    }

    double angle() const {
        // Return an angle from [0, 360)
        PLL b = bound(quadrant());

        double res = x == 0 ? 90 : atan(y / (double)x) / PI * 180;
        res += revs * 360;  // roughly get to the right angle

        while (res < b.first) res += 180;
        while (res >= b.second) res -= 180;
        assert(res >= b.first && res < b.second);
        return res;
    }

    ll compare(const Angle& rhs) const {
        // return -1 if self is smaller, 0 if same, 1 if self is bigger
        if (x == rhs.x && y == rhs.y) return 0;
        ll q = quadrant(), rhsq = rhs.quadrant();
        if (q < rhsq) return -1;
        if (q > rhsq) return 1;

        // same quadrant
        if (y * rhs.x < x * rhs.y) return -1;
        return 1;
    }
};

ostream& operator<<(ostream& os, const Angle& angle) {
    os << "{" << angle.x << ", " << angle.y << "}";
    return os;
}

namespace NCR {
ll ncr(ll n, ll r) {
    if (r > n) return 0;

    // n! / r! / (n-r)!
    // small r:
    ll ans = 1;
    rep(i, n - r + 1, n + 1) {
        ans *= i;
    }
    rep(i, 1, r + 1) {
        ans /= i;
    }
    return ans;
}
}  // namespace NCR

void solve() {
    ll n;
    cin >> n;
    vector<PLL> A(n);
    rep(i, 0, n) cin >> A[i].first >> A[i].second;

    // choose some point and fix as the center

    ll ans = 0;
    rep(i, 0, n) {
        // sort around this point
        vector<Angle> B;

        rep(j, 0, n) {
            if (i == j) continue;
            B.push_back({A[j].first - A[i].first, A[j].second - A[i].second});
        }

        sort(all(B), [](auto a, auto b) {
            // return 1 if a is smaller
            if (a.compare(b) <= 0) return 1;
            return 0;
        });

        rep(j, 0, n - 1) {
            B.push_back({B[j].x, B[j].y, B[j].revs + 1});
        }

        ll total = NCR::ncr(n - 1, 4);
        ll sub = 0;

        // count how many points are within the other half
        ll r = 0;  // right pointer
        rep(j, 0, n - 1) {
            Angle plusHalf = {-B[j].x, -B[j].y, (B[j].quadrant() + 2) / 4};

            while (B[r].compare(plusHalf) == -1) {
                r++;
            }

            ll amount = r - j;
            sub += NCR::ncr(amount - 1, 3);
        }

        ans += total - sub;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll t = 1;
    // cin >> t;
    rep(i, 0, t) solve();
    return 0;
}
