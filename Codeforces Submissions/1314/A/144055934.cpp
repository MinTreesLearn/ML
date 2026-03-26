
#include <bits/stdc++.h>
#define fore(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define fort(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ford(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;

template<class A, class B> bool maxi(A &a, const B &b) {return (a < b) ? (a = b, true):false;};
template<class A, class B> bool mini(A &a, const B &b) {return (a > b) ? (a = b, true):false;};

typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int maxN = 200005;

int n;
ll res;
vector<pair<ll, ll> > p;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("main.INP", "r", stdin);
//        freopen("main.OUT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<pair<ll, ll> > pq;
    cin >> n;
    p.resize(n);
    for (auto &[a, t] : p)
        cin >> a;
    for (auto &[a, t] : p)
        cin >> t;
    sort(all(p));
    for (int l, r = 0; r < n;) {
        for (l = r; r < n && p[r].fi <= p[l].fi + r - l; ++r);
        fore(h, p[l].fi, p[l].fi + r - l) {
            for (; l < r && p[l].fi <= h; ++l)
                pq.push({p[l].se, p[l].fi});
            const auto &[t, a] = pq.top();
            res += (h - a) * t;
            pq.pop();
        }
    }
    cout << res << '\n';
    return 0;
}
