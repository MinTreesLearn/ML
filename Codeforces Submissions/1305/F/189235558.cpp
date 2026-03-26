#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")

#define all(x) x.begin(),x.end()
#define pb push_back
#define m_p make_pair

#define fi first
#define se second
#define sz(x) (int)x.size()

#define fr(i, l, r) for(ll i = l; i <= r; i ++)
#define fe(x, y)    for(auto& x : y)
#define rf(x, l, r) for(int x = l; x >= r; x--)

#define sq(x) ((x)*(x))
#define pw(x) (1ll << x)

#define ook order_of_key
#define fbo find_by_order

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

template <typename T>
using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
bool umx(T& a, T b)
{
    return a < b ? a = b, 1 : 0;
}

template <typename T>
bool umn(T& a, T b)
{
    return a > b ? a = b, 1 : 0;
}

const ll INF = 3e18;
const int INTF = 1e9;
const ll mod = 32768;
const ld eps = 0.00000001;
const ll N = 2e5 + 22;
const bool TEST = 0;
ll mn = 1e18;
int n;
ll a[N];
gp_hash_table<ll, bool> s;

bool TL() {
    return (double)clock() / CLOCKS_PER_SEC > 2.2;
}

void check(ll x) {
    if (s.find(x) != s.end()) return;
    s[x] = 1;

    if (TL()) return;
    if(x == 0 || x == 1)return;
    ll sum = 0;
    assert(x != 0);
    for(int i = 0;i < n;i ++) {
        if(a[i] >= x)sum += min(a[i] % x, x - (a[i] % x));
        else sum += x - a[i];
    }
    mn = min(mn, sum);
}
void f(ll x) {
    for(int i = 2;1LL * i * i <= x;i ++) {

        assert(x != 0);
        if(x % i == 0) {
            if (TL()) break;
            check(i);
            while(x % i == 0) {
                // if (TL()) return;
                x /= i;
                assert(x != 0);
            }
        }
    }
    if(x > 1)check(x);

}
void solve() {
    cin >> n;
    mn = n;
    for(int i = 0;i < n;i ++)cin >> a[i];
    shuffle(a, a + n, rng);
    int i = 0;
    while(!TL()) {
        f(a[i]);
        if (TL()) break;
        f(a[i] + 1);
        if (TL()) break;
        f(a[i] - 1);
        i++;

        if (i == n) break;
    }
    cout << mn << endl;
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else // LOCAL
//    freopen("half.in", "r", stdin);
//    freopen("half.out", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;

    if(TEST)cin >> q;
    while(q--)
    {
        solve();
    }

    return 0;
}
