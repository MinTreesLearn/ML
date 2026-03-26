#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include "bits/stdc++.h"
using namespace std;


using ll = long long;
using ii = pair<int, int>;
using ull = unsigned long long;
using uint = unsigned int;
#define pb push_back
#define F first
#define S second
#define f(i, a, b)  for(int i = a; i < b; i++)
#define all(a)  a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) (int)(x).size()
#define mp(x,y) make_pair(x,y)
#define popCnt(x) (__builtin_popcountll(x))
#define int ll

//const int N = 2e5+5, A = 12, LG = 18, MOD = (119 << 23) + 1;
const long double PI = acos(-1);
const long double EPS = 1e-9;
const int BLK = 450;
void doWork() {
    int n, m, k;
    cin >> n >> m >> k;
    k = min(k, m - 1);
    vector<int> a(n);
    f(i,0,n)    cin >> a[i];
    int ans = 0;
    for(int i = 0; i <= k; i++) {
        int mn = INT_MAX;
        f(j,0,m-k)mn=min(mn,max(a[i+j],a[i+j+n-m]));
        ans = max(ans, mn);
    }
    cout << ans << '\n';

}
int32_t main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif // ONLINE_JUDGE
    int t = 1;
    cin >> t;
    while (t--) {
        doWork();
    }
    return 0;
}
