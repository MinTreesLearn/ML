/*************************************
*    author: marvinthang             *
*    created: 10.01.2023 21:53:11    *
*************************************/

#include <bits/stdc++.h>

using namespace std;

#define                  fi  first
#define                  se  second
#define                left  ___left
#define               right  ___right
#define                TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define             MASK(i)  (1LL << (i))
#define             FULL(i)  (MASK(i) - 1)
#define           BIT(x, i)  ((x) >> (i) & 1)
#define  __builtin_popcount  __builtin_popcountll
#define              ALL(v)  (v).begin(), (v).end()
#define           REP(i, n)  for (int i = 0, _n = (n); i < _n; ++i)
#define        FOR(i, a, b)  for (int i = (a), _b = (b); i <= _b; ++i) 
#define       FORD(i, b, a)  for (int i = (b), _a = (a); i >= _a; --i) 
#define        scan_op(...)  istream & operator >> (istream &in, __VA_ARGS__ &u)
#define       print_op(...)  ostream & operator << (ostream &out, const __VA_ARGS__ &u)
#ifdef LOCAL
    #include "debug.h"
#else
    #define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
    #define DB(...) 23
    #define db(...) 23
    #define debug(...) 23
#endif

template <class T> scan_op(vector <T>)  { for (size_t i = 0; i < u.size(); ++i) in >> u[i]; return in; }
template <class U, class V> scan_op(pair <U, V>)  { return in >> u.fi >> u.se; }
template <class U, class V> print_op(pair <U, V>)  { return out << '(' << u.first << ", " << u.second << ')'; }
template <class Con, class = decltype(begin(declval<Con>()))> typename enable_if <!is_same<Con, string>::value, ostream&>::type operator << (ostream &out, const Con &con) { out << '{'; for (__typeof(con.begin()) it = con.begin(); it != con.end(); ++it) out << (it == con.begin() ? "" : ", ") << *it; return out << '}'; }
template <size_t i, class T> ostream & print_tuple_utils(ostream &out, const T &tup) { if constexpr(i == tuple_size<T>::value) return out << ")";  else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); }
template <class ...U> print_op(tuple<U...>) { return print_tuple_utils<0, tuple<U...>>(out, u); }

// end of template

const double PI = 3.1415926535897932384626433832795; // acos(-1.0); atan(-1.0);
const int dir[] = {1, 0, -1, 0, 1, 1, -1, -1, 1}; // {2, 1, -2, -1, -2, 1, 2, -1, 2};

void process(void) {
    int n, k; string s;
    cin >> n >> k >> s;
    vector <vector <int>> in_subset(n);
    REP(i, k) {
        int c; cin >> c;
        while (c--) {
            int x; cin >> x;
            in_subset[x - 1].push_back(i);
        }
    }
    vector <int> lab(2 * k, -1), cnt(2 * k);
    REP(i, k) cnt[i * 2 + 1] = 1;
    vector <bool> active(2 * k, true);
    function <int(int)> find = [&] (int u) {
        return lab[u] < 0 ? u : lab[u] = find(lab[u]);
    };
    function <bool(int, int)> join = [&] (int u, int v) {
        if ((u = find(u)) == (v = find(v))) return false;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        cnt[u] += cnt[v];
        if (!active[v]) active[u] = false;
        return true;
    };
    int cur = 0;
    auto get_min = [&] (int u) {
        int x = find(u * 2), y = find(u * 2 + 1);
        if (x == y) return 0;
        int mi = k;
        if (active[x] && mi > cnt[x]) mi = cnt[x];
        if (active[y] && mi > cnt[y]) mi = cnt[y];
        return mi;
    };
    REP(i, n) {
        int c = s[i] - '0';
        if (in_subset[i].size() == 1) {
            int u = in_subset[i][0];
            int x = find(u * 2 + c);
            int y = find(u * 2 + !c);
            if (cnt[x] < cnt[y] && active[x]) cur += cnt[y] - cnt[x];
            active[x] = false;
        } else if (in_subset[i].size() == 2) {
            int u = in_subset[i][0], v = in_subset[i][1];
            if (!c) {
                if (find(u * 2) != find(v * 2 + 1)) {
                    cur -= get_min(u) + get_min(v);
                    join(u * 2, v * 2 + 1);
                    join(u * 2 + 1, v * 2);
                    cur += get_min(u);
                }
            } else {
                if (find(u * 2) != find(v * 2)) {
                    cur -= get_min(u) + get_min(v);
                    join(u * 2, v * 2);
                    join(u * 2 + 1, v * 2 + 1);
                    cur += get_min(u);
                }
            }
        }
        cout << cur << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); // cout.tie(nullptr);
    file("test");
    process();
    cerr << "Time elapsed: " << TIME << " s.\n";
    return (0^0);
}