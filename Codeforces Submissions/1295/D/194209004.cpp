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
#define endl "\n"
#define print(a) for (auto &x: a) cout << x << " "; cout << endl
#define print_pair(a)
#define FOR(i, fr, to) for (long long i = fr; i <= to; i++)
#define RFOR(i, fr, to) for (long long i = fr; i >= to; i--)
#define pb push_back
#define eb emplace_back
#define is insert
#define F first
#define S second

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
using msll = multiset<ll>;
using mll = map<ll, ll>;
using vsll = vector<sll>;
using sc = set<char>;
using pcll = pair<char, ll>;

ll dr[] = {0, 1, 0, -1}, dc[] = {-1, 0, 1, 0};

const ll INF = 1e18;
ll MOD = 1e9 + 7;

ll mod_add(ll u, ll v, ll mod = MOD) {
    u %= mod, v %= mod;
    return (u + v) % mod;
}

ll mod_sub(ll u, ll v, ll mod = MOD) {
    u %= mod, v %= mod;
    return (u - v + mod) % mod;
}

ll mod_mul(ll u, ll v, ll mod = MOD) {
    u %= mod, v %= mod;
    return (u * v) % mod;
}

ll mod_pow(ll u, ll p, ll mod = MOD) {
    ll res = 1;
    u %= mod;

    if (u == 0) {
        return 0;
    }

    while (p > 0) {
        if (p & 1) {
            res = (res * u) % mod;
        }

        p >>= 1;
        u = (u * u) % mod;
    }

    return res;


}

ll mod_inv(ll u, ll mod = MOD) {
    u %= mod;
    ll g = __gcd(u, mod);
    if (g != 1) {
        return -1;
    }

    return mod_pow(u, mod - 2, mod);
}

ll mod_div(ll u, ll v, ll mod = MOD) {
    u %= mod, v %= mod;
    return mod_mul(u, mod_inv(v), mod);
}


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
void print_arr(A a[], ll n) {
    print_arr(a, 0, n - 1);
}

template<class A>
void set_arr(A a[], A val, ll from, ll to) {
    for (ll i = from; i <= to; i++) {
        a[i] = val;
    }
}

template<class A>
void set_arr(A a[], A val, ll n) {
    set_arr(a, val, 0, n - 1);
}


const ll N = 1e6 + 10;



ll n, k, q, m;
ll a[N];
string s, s1, s2, s3;




void init() {
}



ll get_ans() {
}


void single(ll t_id = 0) {
    cin >> n >> m;

    ll g = __gcd(m, n);
    ll ans = (n + m - 1) / g - (n - 1) / g;

    ll rem = m / g;
    ll tmp = rem;
    vll vec;
    for (ll i = 2; i * i <= rem; i++) {
        if (tmp % i == 0) {
            vec.pb(i);
        }

        while (tmp % i == 0) {
            tmp /= i;
        }
    }

//    cout << vec << "\n";

    if (tmp > 1) {
        vec.pb(tmp);
    }

//    sll st;
//    cout << ans << "\n";

    for (ll mask = 1; mask < (1 << sz(vec)); mask++) {
        ll fac = 1;
        ll sign = __builtin_popcount(mask) & 1 ? -1 : 1;
        for (ll i = 0; i < sz(vec); i++) {
            if (mask >> i & 1) {
                fac *= vec[i];
            }
        }

//        if (st.count(fac)) {
//            continue;
//        }

        ans += sign * ((n + m - 1) / (g * fac) - (n - 1) / (g *fac));
//        cout << fac << "\n";
//        cout << ans << "\n";
//        st.is(fac);
    }

    cout << ans << "\n";





}

void multiple() {

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
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);

    init();


//    freopen("feast.in", "r", stdin);
//    freopen("feast.out", "w", stdout);

//    freopen("../input.txt", "r", stdin);
    multiple();
//    single();


    return 0;


}


			 					  	     	  					   	