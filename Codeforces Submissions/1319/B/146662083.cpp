//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

//#define LOCAL
//#define TASK "shut_up"

#define codeforces_is_shit yes

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repp(i, a, b) for(int i = a; i < b; ++i)
#define repv(i, v) for(auto i : v)
#define all(a) a.begin(), a.end()
#define yes "YES"
#define no "NO"
#define pb push_back
#define mp make_pair
#define ins insert
//#define endl "\n"

#define ll long long
#define ld long double
#define int ll

void fastios() {
    ios::sync_with_stdio(0);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
#ifdef TASK
    freopen(TASK ".in", 'r', stdin);
    freopen(TASK ".out", 'w', stdout);
#endif
}

template <typename T>
ostream& operator << (ostream& out, vector<T>& arr) {
    for (auto& i : arr) out << i << " ";
    return out;
}

template <typename T>
istream& operator >> (istream& in, vector<T>& arr) {
    for (auto& i : arr) in >> i;
    return in;
}

template <typename T>
T min(const vector <T> a) {
    return *min_element(all(a));
}

template <typename T>
T max(const vector <T> a) {
    return *max_element(all(a));
}

template <typename T>
T sum(const vector <T> a) {
    T res;
    for(auto i : a) res += i;
    return res;
}

template <typename T>
T gcd(T a, T b) {
    while(min(a, b) > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

const ll MOD = 1e9 + 7;
const ll MAXN = 1e7;
const ll INF = 1e18;
const ld EPS = 0.0000000001;

void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    map <int, int> d;
    rep(i, n) {
        d[a[i] - i] += a[i];
    }
    int mx = -INF;
    rep(i, n){
        if (d[a[i] - i] > mx) mx = d[a[i] - i];
    }
    cout << mx << endl;
}

signed main() {
    fastios();

    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}