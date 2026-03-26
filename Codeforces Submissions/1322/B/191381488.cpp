// prod by mdolchik

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, int> pli;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
#define int ll
#define E '\n'
#define fi first
#define se second
#define ins insert
#define pb push_back
#define pob pop_back
#define pof pop_front
#define umap unordered_map
#define gp gp_hash_table
#define uset unordered_set
#define all(a) a.begin(),a.end()
#define fbo find_by_order
#define ork order_of_key
mt19937 gen (time (0));

const int MAXI = INT_MAX / 2;
const ll LMAXI = LLONG_MAX / 2;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

const ll MD = 1e9 + 7;
ll bp(ll a, int b) {
    ll st = 1;
    while(b > 0) {
        if (b & 1) {
            st *= a;
            st %= MD;
            --b;
        } else {
            a *= a;
            a %= MD;
            b >>= 1;
        }
    }
    return st;
}

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 4e5 + 12;
int a[N], b[N];
int n;
int get(int L, int R) {
    if(L > R)
        return 0;
    int l = 1, r = 0;
    int kol = 0;
    for(int i = n; i >= 1; --i) {
        while(l <= n && b[l] + b[i] < L)
            l++;
        while(r + 1 <= n && b[r+1] + b[i] <= R)
            r++;
        kol += r - l + 1 - (l <= i && i < r);
//        cout << i << ' ' << r << E;
    }
    return kol / 2;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#else
//    freopen ("bridges.in", "r", stdin);
//    freopen ("bridges.out", "w", stdout);
#endif // LOCAL
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for(int st = 0; st <= 25; st++) {
        for(int i = 1; i <= n; ++i) {
            b[i] = (a[i] % ((1 << (st + 1))));
//            cout << b[i] << ' ';
        }
        sort (b + 1, b + n + 1);
//        cout << E;
        int cnt = get((1 << st), (1 << (st + 1)) - 1);
        cnt += get((1 << (st + 1)) + (1 << st), (1 << (st + 2)) - 1);
        if(cnt % 2 == 1) {
//            cout << st << E;
            ans += (1 << st);
        }
    }
    cout << ans;
    return 0;
}
