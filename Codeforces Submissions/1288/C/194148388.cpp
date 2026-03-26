#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define vec vector
#define ar array
#define UNIQUE(c) (c).resize(unique(all(c)) - (c).begin())
#define dbg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__<<" "; ((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl; }(__VA_ARGS__);
const ld PI = 2 * acos(0.0);
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, -1, 1, 1, -1 };
// function<returnType(args) name = [&]

// work smart not hard
// self reflect


const ll mod = 1e9 + 7;
const int N = 1e5 + 5;

ll fact[N];
ll invfact[N];

ll fpow(ll x, ll n) {
    if (n == 0) return 1;
    ll u = fpow(x, n / 2);
    (u *= u) %= mod;
    if (n & 1) u = u * x % mod;
    return u;
}

void calc() {
    fact[0] = 1;
    for (ll i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    invfact[N - 1] = fpow(fact[N - 1], mod - 2);
    for (ll i = N - 2; i >= 0; i--) {
        invfact[i] = (i + 1) * invfact[i + 1] % mod;
    }
}

ll ncr(ll n, ll r) {
    if (r > n) return 0;
    return (fact[n] % mod * invfact[r] % mod * invfact[n - r] % mod) % mod;
}

void solve() {
    calc();
    ll n, m;
    cin >> n >> m;
    cout << ncr(2 * m + n - 1, n - 1) << '\n';
}


int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    //cout << setprecision(6) << fixed;

    int T = 1; //cin >> T;
    int x = T;

    while (T--) {
        //cout << "Case #" << x - T << ": ";
        solve();
    }
}
