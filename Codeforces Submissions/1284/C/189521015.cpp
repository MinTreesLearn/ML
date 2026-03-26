#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define r_all(x) x.rbegin(), x.rend()
#define sz(x)(ll) x.size()
#define g_max(x, y) x = max(x, y)
#define g_min(x, y) x = min(x, y)
#define rsz(a, n) a.resize(n)
#define ass(a, n) a.assign(n, 0)
#define YES() cout << "YES\n"
#define Yes cout << "Yes\n"
#define NO() cout << "NO\n"
#define No() cout << "No\n"
#define n_line() cout << "\n"

using namespace std;

using ll = long long;
using ld = long double;

using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using stkll = stack<ll>;
using qll = queue<ll>;
using dqll = deque<ll>;
using sll = set<ll>;
using sc = set<char>;
using msll = multiset<ll>;
using mll = map<ll, ll>;

using vsll = vector<sll>;

using pcll = pair<char, ll>;

template<class T>
vector<T> operator+(vector<T> a, vector<T> b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

pll operator+(pll a, pll b) {
    pll ans = {a.first + b.first, a.second + b.second};
    return ans;
}

template<class A, class B>
ostream &operator<<(ostream &os,
                    const pair<A, B> &p) {
    os << p.first << " " << p.second;
    return os;
}

template<class A, class B>
istream &operator>>(istream &is, pair<A, B> &p) {
    is >> p.first >> p.second;
    return is;
}

template<class T>
ostream &operator<<(ostream &os,
                    const vector<T> &vec) {
    for (auto &x: vec) {
        os << x << " ";
    }

    return os;
}

template<class T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (auto &x: vec) {
        is >> x;
    }

    return is;
}


template<class T>
ostream &operator<<(ostream &os,
                    const set<T> &vec) {
    for (auto &x: vec) {
        os << x << " ";
    }

    return os;
}

template<class A, class B>
ostream &operator<<(ostream &os,
                    const map<A, B> d) {
    for (auto &x: d) {
        os << "(" << x.first << " " << x.second << ") ";
    }

    return os;
}

template<class A>
void read_arr(A a[], ll from, ll to) {
    for (ll i = from; i <= to; i++) {
        cin >> a[i];
    }
}

template<class A>
void print_arr(A a[], ll from, ll to) {
    for (ll i = from; i <= to; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

template<class A>
void set_arr(A a[], A val, ll from, ll to) {
    for (ll i = from; i <= to; i++) {
        a[i] = val;
    }
}

ll dr[] = {0, 1, 0, -1}, dc[] = {-1, 0, 1, 0};

//ll dr[] = {1, 0}, dc[] = {0, 1};

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ll M = 13010;

struct Dsu {
    ll n;
    vll par;

    void init(ll n_sz) {
        n = n_sz;
        par.assign(n, 0);

        for (ll i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    ll find_st(ll v) {
        return (par[v] == v) ? par[v] : par[v] = find_st(par[v]);
    }

    ll union_st(ll u, ll v) {
        u = find_st(u), v = find_st(v);

        if (u == v) {
            return 0;
        }

        par[v] = u;
        return 1;
    }
};

struct Smt {
    ll n;
    vll tree;

    void init(ll _n) {
        n = _n;
        tree.assign(4 * n + 10, 0);
    }

    void build(ll left, ll right, ll node, vll &v) {
        if (left == right) {
            tree[node] = v[left];
            return;
        }

        ll mid = (left + right) >> 1;
        build(left, mid, 2 * node + 1, v);
        build(mid + 1, right, 2 * node + 2, v);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        return;
    }

    ll query(ll left, ll right, ll node, ll from, ll to) {
        if (left > to || right < from) {
            return -INF;
        }

        if (left >= from && right <= to) {
            return tree[node];
        }

        ll mid = (left + right) >> 1;
        ll q1 = query(left, mid, 2 * node + 1, from, to);
        ll q2 = query(mid + 1, right, 2 * node + 2, from, to);
        return max(q1, q2);
    }

    void update(ll left, ll right, ll node, ll id, ll val) {

        if (left > id || right < id) {
            return;
        }

        if (left == right) {
            tree[node] = val;
            return;
        }

        ll mid = (left + right) >> 1;

        update(left, mid, 2 * node + 1, id, val);
        update(mid + 1, right, 2 * node + 2, id, val);

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }
};

void memset64(ll dest[], ll val, ll sz) {
    for (ll i = 0; i < sz; i++) {
        dest[i] = val;
    }
}


void print(ll a[], ll from, ll to) {
    for (ll i = from; i <= to; i++) {
        cout << a[i] << " ";
    }

    cout << "\n";
}


ll gcd_extended(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0LL, *y = 1LL;
        return b;
    }

    ll x1, y1;
    ll g = gcd_extended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return g;
}

ll mod_pow(ll p, ll n) {
    ll res = 1;

    while (n) {
        if (n & 1) {
            res = (res * p) % MOD;
        }

        p = (p * p) % MOD;
        n >>= 1;
    }

    return res;
}

ll mod_inverse(ll b) {
    ll x, y;
    ll g = gcd_extended(b, MOD, &x, &y);

    if (g != 1) {
        return -1;
    }

    return (x % MOD + MOD) % MOD;
}

ll mod_divide(ll a, ll b) {
    a %= MOD;
    ll inv = mod_inverse(b) % MOD;
    if (inv == -1) {
        return -1;
    }

    return (a * inv) % MOD;
}

ll mod_fact(ll n) {
    if (n < 0) {
        return 0;
    }

    ll ans = 1;
    for (ll i = 2; i <= n; i++) {
        ans *= i;
        ans %= MOD;
    }

    return ans;

}


ll nPr(ll n, ll r) {

    if (n < r) {
        return 0;
    }

    if (r == 0) {
        return 1;
    }

    ll ans = mod_fact(n) * mod_inverse(mod_fact(n - r));
    ans %= MOD;
    return ans;
}

ll nCr(ll n, ll r) {
    if (n < r) {
        return 0;
    }

    ll ans = mod_fact(n) * (mod_inverse(mod_fact(n - r)) % MOD);
    ans %= MOD;
    ans = (ans * mod_inverse(mod_fact(r)));
    return ans;
}

mll factorize(ll x) {
    mll dict;
    ll tmp = x;
    while (x % 2 == 0) {
        dict[2]++;
        x /= 2;
    }

    for (ll i = 3; i * i <= tmp; i++) {
        while (x % i == 0) {
            x /= i;
            dict[i]++;
        }
    }

    if (x > 1) {
        dict[x]++;
    }

    return dict;
};

ll is_palindrome(string &str) {
    string rev = str;
    reverse(all(str));
    return rev == str;
}


const ll N = 3e5 + 100;

ll n, m, k, q;
ll a[N], b[N];
vvll grid;
string s, s1, s2;

ll fact[N];

void init() {
}


ll get_ans() {
    fact[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % m;
    }

    ll ans = 0;
    for (ll len = 0; len <= n; len++) {
        ll cur = (fact[n - len + 1] * fact[len]) % m;
        cur = (cur * (n - len + 1)) % m;
        ans = (ans + cur) % m;
    }

    return ans;
}



void single(ll t_id = 0) {
    cin >> n >> m;

    cout << get_ans() << "\n";

}

void multiple() {
    init();

    ll t;
    cin >> t;

    for (ll i = 0; i < t; i++) {
        single(i);
    }

}

//#endif

#if 0

void multiple() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }

        single();
    }

#endif

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

//    freopen("../input.txt", "r", stdin);
//    multiple();
    single();



    return 0;


}