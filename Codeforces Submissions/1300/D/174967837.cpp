#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}
#define DEBUG_VLL(vec) REP(sz, vec.size()) cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

constexpr ll MOD = 1000000007;
constexpr ll HIGHINF = (ll)1e18;
constexpr int INF = 1e9;

using PI = P<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    if (n & 1) {
        cout << "NO\n";
        return 0;
    }

    V<PI> points(n);
    for (int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;
    V<PI> vecs(n);
    for (int i = 0; i < n; i++) {
        vecs[i] = PI(abs(points[i].first - points[(i + 1) % n].first), 
                abs(points[i].second - points[(i + 1) % n].second));
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        ok = ok && (vecs[i].first == vecs[(i + n / 2) % n].first && vecs[i].second == vecs[(i + n / 2) % n].second);
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
