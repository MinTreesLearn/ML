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

///////////////////////////////////////////////////////

bool multiTest = 0;
void solve(int tt){

    cin >> n;

    map<int, vi> val;

    vector<pii> pubs(n);

    forn(i, n) cin>> pubs[i].first;
    forn(i, n) cin >> pubs[i].second;

    forn(i, n) {
        val[pubs[i].first].push_back(pubs[i].second);
    }

    ll ans = 0;
    priority_queue<int> nums;
    ll cur = 0;
    ll lastVal = -1e9;

    for(auto [y,z] : val) {
        while(nums.size() && lastVal != y) {
            cur -= nums.top();
            ans += cur;
            nums.pop();
            lastVal++;
        }
        for(auto z1 : z) {
            nums.push(z1);
            cur += z1;
        }
        lastVal = y;
    }

    while(nums.size()) {
        cur -= nums.top();
        ans += cur;
        nums.pop();
        lastVal++;
    } 

    cout << ans << nl;

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