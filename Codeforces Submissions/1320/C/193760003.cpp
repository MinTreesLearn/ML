#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifdef DUPA
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x, ...)
#endif

typedef long long LL;
// HMMMM
#define int LL

int sum(vector<int> &tree, int k) {
    k++;
    int s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k & -k;
    }
    return s;
}

void add(vector<int> &tree, int k, int x) {
    k++;
    while (k < tree.size()) {
        tree[k] += x;
        k += k & -k;
    }
}

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

const int INF = 1e18 + 1;

vector<PII> clean(vector<PII> a) {
    sort(all(a), [](PII i, PII j) { return i.second < j.second; });

    vector<PII> res;
    for (auto [x, y] : a) {
        if (res.empty())
            res.push_back({x, y});
        else {
            assert(res.back().second <= y);
            if (res.back().second == y) {
                if (res.back().first <= x) {
                    res.pop_back();
                    res.push_back({x, y});
                }
            } else {
                assert(res.back().second < y);
                if (res.back().first < x) {
                    res.push_back({x, y});
                }
            }
        }
    }

    for (int i = 1; i < res.size(); i++) {
        assert(res[i - 1].first < res[i].first);
        assert(res[i - 1].second < res[i].second);
    }

    return res;
}

const int inf = INF;

typedef vector<int> vi;

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = -inf, madd = 0, val = -inf;

    ~Node() {
        if (!l) return;
        delete l;
        delete r;
    }
    Node(int _lo, int _hi) : lo(_lo), hi(_hi) {}  // Large interva l of −in f
    Node(vi &v, int _lo, int _hi) : lo(_lo), hi(_hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = max(l->val, r->val);

        } else
            val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return inf;
        if (L <= lo && hi <= R) return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R)
            mset = val = x, madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != -inf)
                mset += x;
            else
                madd += x;
            val += x;
        } else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != -inf)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = -inf;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};

const int MAXN = 1e6 + 100;
int solve(vector<PII> a, vector<PII> b, vector<tuple<int, int, int>> c) {
    a = clean(a);
    b = clean(b);
    sort(rall(c));
    int res = -INF;
    // vector<int> d(MAXN + 1, -INF);
    Node *tr = new Node(0, MAXN + 1);

    for (auto [j, bj] : b) {
        // d[j] = -bj;
        tr->set(j, j + 1, -bj);
    }

    for (auto [i, ci] : a) {
        while (!c.empty() && get<0>(c.back()) < i) {
            auto x = get<1>(c.back());
            auto y = get<2>(c.back());
            // for (int j = x + 1; j < d.size(); j++) d[j] += y;
            tr->add(x + 1, MAXN + 1, y);
            c.pop_back();
        }
        //   int curr = -INF;
        // for (auto j : d) curr = max(curr, j);
        //  assert(curr == tr->query(0, MAXN + 1));
        int curr = tr->query(0, MAXN + 1);
        res = max(res, curr - ci);
    }
    delete tr;

    return res;
}

int solve2() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<PII> a(n), b(m);
    vector<tuple<int, int, int>> c(p);
    for (auto &[x, y] : a) cin >> x >> y;
    for (auto &[x, y] : b) cin >> x >> y;
    for (auto &[x, y, z] : c) cin >> x >> y >> z;
    return solve(a, b, c);
}

#undef int
int main() {
    ios::sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    cin.tie(0);
    int t = 1;
#ifdef DUPA
#endif
    for (int i = 0; i < t; i++) cout << solve2() << "\n";
}
