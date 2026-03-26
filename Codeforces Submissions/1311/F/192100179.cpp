#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rrep(i, a, b) for(ll i = a; i >= b; i--)
const ll inf = 4e18;
template <typename T>
struct fenwick_tree {
    int n;
    vector<T> data;
    fenwick_tree(int N)
        : n(N), data(N) {}
    void add(int p, T x) {
        assert(0 <= p && p < n);
        p++;
        while(p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }
    T sum(int r) {
        T s = 0;
        while(r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        return sum(r) - sum(l);
    }
    T operator[](int x) const {
        assert(0 <= x && x < n);
        return sum(x, x + 1);
    }
};
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<ll> x(n), v(n);
    rep(i, 0, n) {
        cin >> x[i];
    }
    rep(i, 0, n) {
        cin >> v[i];
    }
    vector<ll> res = v;
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    vector<P> p(n);
    rep(i, 0, n) {
        p[i].first = x[i];
        p[i].second = lower_bound(res.begin(), res.end(), v[i]) - res.begin();
        // cout << p[i].first << " " << p[i].second << '\n';
    }
    sort(p.begin(), p.end());
    fenwick_tree<ll> fw1(n), fw2(n), fw3(n), fw4(n);
    rep(i, 0, n) {
        fw3.add(p[i].second, p[i].first);
        fw4.add(p[i].second, 1);
    }
    ll ans = 0;
    rep(i, 0, n) {
        ll cnt = 0;
        cnt = fw2.sum(0, p[i].second + 1);
        ans += (cnt * p[i].first - fw1.sum(0, p[i].second + 1));
        cnt = fw4.sum(p[i].second, n);
        ans += (fw3.sum(p[i].second, n) - cnt * p[i].first);
        fw1.add(p[i].second, p[i].first);
        fw2.add(p[i].second, 1);
        fw3.add(p[i].second, -p[i].first);
        fw4.add(p[i].second, -1);
    }
    cout << ans / 2 << '\n';
}