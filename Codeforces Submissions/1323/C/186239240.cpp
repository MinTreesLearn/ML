#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
//#pragma comment (linker, "/STACK: 268435456")

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define int long long

using namespace std;
using namespace __gnu_pbds;

template <typename T> inline bool umin (T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> inline bool umax (T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;
template <typename T> using oset = tree<T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll mod = 1e9 + 7;
const ll m1 = 1e9 + 7;
const ll m2 = 1e9 + 21;
const ll base = 1e6 + 9;
const ll inf = 1e9;
const int MAX = 5e6 + 1;
const int lg = 20;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<ll> dis(1, inf);

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += s[i] == '(';
    }
    if(2 * cnt != n) {
        cout << "-1\n";
        return;
    }
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = (s[i] == '('? 1 : -1);
    }
    int b = 0;
    int l = 0;
    for(int i = 0; i < n; i++) {
        b += a[i];
        if(b < 0) {
            break;
        }
        if(b == 0) {
            l = i + 1;
        }
    }
    int r = n - 1;
    b = 0;
    for(int i = n - 1; ~i; i--) {
        b += a[i];
        if(b > 0) {
            break;
        }
        if(b == 0) {
            r = i - 1;
        }
    }
    if(l == n) {
        cout << "0\n";
        return;
    }
    while(n - 1 > r) {
        a.pop_back();
        n--;
    }
    reverse(all(a));
    while(l) {
        a.pop_back();
        n--;
        l--;
    }
    reverse(all(a));
    int ans = 0;
    bool flag = 0;
    b = 0;
    int lst = 0;
    for(int i = 0; i < n; i++) {
        b += a[i];
        if(b == 0) {
            if(flag) {
                ans += i - lst + 1;
            }
            lst = i + 1;
            flag = 0;
        }
        if(b < 0) {
            flag = 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ttt = 1;
    //cin >> ttt;
    int ttt0 = ttt;
    while(ttt--) {
        solve();
    }
    return 0;
}
