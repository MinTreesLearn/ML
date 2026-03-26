#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector,Ofast")
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define pb push_back 
#define mp make_pair
#define fi first
#define se second
#define lwb lower_bound
#define setp setprecision
#define SZ(_a) (ll)(_a).size()
#define SQ(_a) ((_a)*(_a))
#define all(_a) (_a).begin(), (_a).end()
#define chmax(_a, _b) _a = max(_a, _b)
#define chmin(_a, _b) _a = min(_a, _b)
template <class T> inline ostream& operator << (ostream& out, vector<T> v) {
    for (int i = 0;i < SZ(v); ++i) out << v[i] << (i == SZ(v)-1 ? "" : " ");
    return out;
}

template <class T> inline ostream& operator << (ostream& out, pair<T, T> p) {
    out << "(" << p.fi << ", " << p.se << ")";
    return out;
}

template <class A, class B> inline pair<A, B> operator + (pair<A, B> pA, pair<A, B> pB) {
    return make_pair(pA.fi+pB.fi, pA.se+pB.se);
}

template <class A, class B> inline pair<A, B> operator - (pair<A, B> pA, pair<A, B> pB) {
    return make_pair(pA.fi-pB.fi, pA.se-pB.se);
}

template <class A, class B, class C> inline pair<A, B> operator * (pair<A, B> pA, C pB) {
    return make_pair(pA.fi*pB, pA.se*pB);
}



const ll N = 4e2 + 5;
const ll MOD = 1e9 + 7;
const ld pi = acos(-1);
const ll INF = 1e9;

struct edge {
    ll y, c, f, cost;
    edge() {};
    edge(ll y, ll c, ll f, ll cost): y(y), c(c), f(f), cost(cost) {};
};

ll bal[N][N], u[N], v[N];
ll s, t, os, ot, V;
vector<ll> g[N];
vector<edge> e;

ll n1, n2, r, b, m;
string s1, s2;

void add(ll x, ll y, ll cap, ll cost) {
    g[x].pb(SZ(e));
    e.pb(edge(y, cap, 0, cost));
    g[y].pb(SZ(e));
    e.pb(edge(x, 0, 0, -cost));
}

void add_LR(ll x, ll y, ll lcap, ll rcap, ll cost) {
    ll last = rcap - lcap;
    if (lcap > 0) {
        add(s, y, lcap, cost);
        add(x, t, lcap, cost);
    }
    if (last > 0) add(x, y, last, cost);
}

void ins_l(ll x) {
    if (s1[x] == 'R') {
        add_LR(os, x, 1, m, 0);
    } else if (s1[x] == 'B') {
        add_LR(x, ot, 1, m, 0);
    } else {
        add(os, x, m, 0);
        add(x, ot,  m, 0);
    }
}

void ins_r(ll x) {
    if (s2[x] == 'R') {
        add_LR(x+n1, ot, 1, m, 0);
    } else if (s2[x] == 'B') {
        add_LR(os, x+n1, 1, m, 0);
    } else {
        add(os, x+n1, m, 0);
        add(x+n1, ot, m, 0);
    }
}

ll rem(ll id) {
    return e[id].c - e[id].f;
}

ll d[N], p[N], pe[N], inq[N];

ll enlarge() {
    for (int i = 0; i < V; ++i) {
        d[i] = INF;
        p[i] = -1;
        pe[i] = -1;
        inq[i] = 0;
    }
    d[s] = 0;
    queue<ll> q;
    q.push(s);
    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        inq[now] = 0;
        for (auto i : g[now]) {
            if (!rem(i)) continue;
            if (d[e[i].y] > d[now] + e[i].cost) {
                p[e[i].y] = now;
                pe[e[i].y] = i;
                d[e[i].y] = d[now]+e[i].cost;
                if (!inq[e[i].y]) {
                    q.push(e[i].y);
                    inq[e[i].y] = 1;
                }
            }
        }
    }
    if (p[t] == -1) {
        return 0;
    }
    ll cur = t;
    while (cur != s) {
        ++e[pe[cur]].f;
        --e[pe[cur]^1].f;
        cur = p[cur];
    }
    return 1;
}

void construct_bal() {
    for (ll i = 0;i < n1; ++i) {
        for (auto j : g[i]) {
            if (e[j].y >= n1 && e[j].y < n1 + n2) {
                bal[i][e[j].y-n1] += e[j].f;
            }
        }
    }
}

void find_ans() {
    ll res = 0;
    string w = "";
    for (auto i : g[s]) {
        if (rem(i)) {
            cout << "-1\n";
            return ;
        }
    }
    for (ll i = 0;i < m; ++i) {
        if (bal[u[i]][v[i]] > 0) {
            --bal[u[i]][v[i]];
            res += r;
            w += "R";
        } else if (bal[u[i]][v[i]] < 0) {
            ++bal[u[i]][v[i]];
            res += b;
            w += "B";
        } else w += "U";
    }
    cout << res << "\n" << w << "\n";
}

void solve() {
    cin >> n1 >> n2 >> m >> r >> b;
    cin >> s1 >> s2;
    for (ll i = 0;i < m; ++i) {
        cin >> u[i] >> v[i];
        --u[i], --v[i];
    }
    os = n1 + n2;
    ot = os + 1;
    s = ot + 1;
    t = s + 1;
    V = t + 1;
    for (ll i = 0;i < n1; ++i) {
        ins_l(i);
    }
    for (ll i = 0;i < n2; ++i) {
        ins_r(i);
    }
    for (ll i = 0;i < m; ++i) {
        add(u[i], v[i]+n1, 1, r);
        add(v[i]+n1, u[i], 1, b);
    }
    add(ot, os, INF, 0);
    while (enlarge());
    construct_bal();
    find_ans();
    return ;
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}

/* Don't forget to check:
 * special case (n=1?)
 * array bounds.
 * hash collision
 * MOD in every step
*/



