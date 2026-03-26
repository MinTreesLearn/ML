#include <bits/stdc++.h>
#define st first
#define nd second
using lint = int64_t;
constexpr int mod = int(1e9) + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr int ninf = 0xcfcfcfcf;
constexpr lint linf = 0x3f3f3f3f3f3f3f3f;
const long double pi = acosl(-1.0);
// Returns -1 if a < b, 0 if a = b and 1 if a > b.
int cmp_double(double a, double b = 0, double eps = 1e-9) {
	return a + eps > b ? b + eps > a ? 0 : 1 : -1;
}
using namespace std;

template<class T> struct segtree_range {
    int H, N;
    vector<T> ts;
    segtree_range() {}
    explicit segtree_range(int N_) {
	for (H = 0, N = 1; N < N_; ++H, N *= 2) {}
        ts.resize(2*N);
    }
    template<class Q> explicit segtree_range(const vector<Q>& qs) {
        const int N_ = int(qs.size());
        for (H = 1, N = 1; N < N_; ++H, N *= 2) {}
        ts.resize(2*N);
        for (int i = 0; i < N_; ++i) at(i) = T(qs[i]);
        build();
    }
    T& at(int a) { return ts[a + N]; }
    void build() { for (int a = N; --a; ) merge(a); }
    inline void push(int a) { ts[a].push(ts[2 * a], ts[2 * a + 1]); }
    inline void merge(int a) { ts[a].merge(ts[2*a], ts[2*a+1]); }
    void for_parents_down(int a, int b) {
        for (int h = H; h; --h) {
            const int l = (a >> h), r = (b >> h);
            if (l == r) {
                if ((l << h) != a || (r << h) != b) push(l);
            } else {
                if ((l << h) != a) push(l);
                if ((r << h) != b) push(r);
            }
        }
    }
    void for_parents_up(int a, int b) {
        for (int h = 1; h <= H; ++h) {
            const int l = (a >> h), r = (b >> h);
            if (l == r) {
                if ((l << h) != a || (r << h) != b) merge(l);
            } else {
                if ((l << h) != a) merge(l);
                if ((r << h) != b) merge(r);
            }
        }
    }
    template<class F, class... Args> void update(int a, int b, F f, Args&&... args) {
        if (a == b) return;
        a += N; b += N;
        for_parents_down(a, b);
        for (int l = a, r = b; l < r; l /= 2, r /= 2) {
            if (l & 1) (ts[l++].*f)(args...);
            if (r & 1) (ts[--r].*f)(args...);
        }
        for_parents_up(a, b);
    }
    T query(int a, int b) {
        if (a == b) return T();
        a += N; b += N;
        for_parents_down(a, b);
        T lhs, rhs, t;
        for (int l = a, r = b; l < r; l /= 2, r /= 2) {
            if (l & 1) { t.merge(lhs, ts[l++]); lhs = t; }
            if (r & 1) { t.merge(ts[--r], rhs); rhs = t; }
        }
        t.merge(lhs, rhs); return t;
    }
    template<class Op, class E, class F, class... Args>
        auto query(int a, int b, Op op, E e, F f, Args&&... args) {
        if (a == b) return e();
        a += N; b += N;
        for_parents_down(a, b);
        auto lhs = e(), rhs = e();
        for (int l = a, r = b; l < r; l /= 2, r /= 2) {
            if (l & 1) lhs = op(lhs, (ts[l++].*f)(args...));
            if (r & 1) rhs = op((ts[--r].*f)(args...), rhs);
        }
        return op(lhs, rhs);
    }
    // find min i s.t. T::f(args...) returns true in [a, i) from left to right
    template<class F, class... Args> int find_right(int a, F f, Args &&... args) {
	assert(0 <= a && a <= N);
	if ((T().*f)(args...)) return a;
	if (a == N) return 1 + N;
	a += N;
        for (int h = H; h; --h) push(a >> h);
	for (; ; a /= 2) if (a & 1) {
	    if ((ts[a].*f)(args...)) {
		for (; a < N; ) {
                    push(a);
		    if (!(ts[a <<= 1].*f)(args...)) ++a;
		}
		return a - N + 1;
	    }
	    ++a;
	    if (!(a & (a - 1))) return N + 1;
	}
    }
    // find max i s.t. T::f(args...) returns true in [i, a) from right to left
    template<class F, class... Args> int find_left(int a, F f, Args &&... args) {
	assert(0 <= a && a <= N);
	if ((T().*f)(args...)) return a;
	if (a == 0) return -1;
	a += N;
        for (int h = H; h; --h) push((a - 1) >> h);
	for (; ; a /= 2) if ((a & 1) || a == 2) {
	    if ((ts[a - 1].*f)(args...)) {
		for (; a <= N; ) {
                    push(a - 1);
		    if (!(ts[(a <<= 1) - 1].*f)(args...)) --a;
		}
		return a - N - 1;
	    }
	    --a;
	    if (!(a & (a - 1))) return -1;
	}
    }
};

template<unsigned M_> struct modnum {
    static constexpr unsigned M = M_;
    using ll = long long; using ull = unsigned long long; unsigned x;
    constexpr modnum() : x(0U) {}
    constexpr modnum(unsigned x_) : x(x_ % M) {}
    constexpr modnum(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
    constexpr modnum(ull x_) : x(x_ % M) {}
    constexpr modnum(ll x_) : x(((x_ %= static_cast<ll>(M)) < 0) ? (x_ + static_cast<ll>(M)) : x_) {}
    explicit operator int() const { return x; }
    modnum& operator+=(const modnum& a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
    modnum& operator-=(const modnum& a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
    modnum& operator*=(const modnum& a) { x = unsigned((static_cast<ull>(x) * a.x) % M); return *this; }
    modnum& operator/=(const modnum& a) { return (*this *= a.inv()); }
    modnum operator+(const modnum& a) const { return (modnum(*this) += a); }
    modnum operator-(const modnum& a) const { return (modnum(*this) -= a); }
    modnum operator*(const modnum& a) const { return (modnum(*this) *= a); }
    modnum operator/(const modnum& a) const { return (modnum(*this) /= a); }
    modnum operator+() const { return *this; }
    modnum operator-() const { modnum a; a.x = x ? (M - x) : 0U; return a; }
    modnum pow(ll e) const {
        if (e < 0) return inv().pow(-e);
        modnum x2 = x, xe = 1U;
        for (; e; e >>= 1) {
            if (e & 1) xe *= x2;
            x2 *= x2;
        }
        return xe;
    }
    modnum inv() const {
        unsigned a = x, b = M; int y = 1, z = 0;
        while (a) {
            const unsigned q = (b/a), c = (b - q*a);
            b = a, a = c; const int w = z - static_cast<int>(q) * y;
            z = y, y = w;
        } assert(b == 1U); return modnum(z);
    }
    friend modnum inv(const modnum& a) { return a.inv(); }
    template<typename T> friend modnum operator+(T a, const modnum& b) { return (modnum(a) += b); }
    template<typename T> friend modnum operator-(T a, const modnum& b) { return (modnum(a) -= b); }
    template<typename T> friend modnum operator*(T a, const modnum& b) { return (modnum(a) *= b); }
    template<typename T> friend modnum operator/(T a, const modnum& b) { return (modnum(a) /= b); }
    friend bool operator==(const modnum& a, const modnum& b) { return a.x == b.x; }
    friend bool operator!=(const modnum& a, const modnum& b) { return a.x != b.x; }
    friend ostream &operator<<(ostream& os, const modnum& a) { return os << a.x; }
    friend istream &operator>>(istream& in, modnum& n) { ull v_; in >> v_; n = modnum(v_); return in; }
};

using mint = modnum<mod>;
vector<mint>inv2, p2;

struct seg_node{
	mint val, lo, hi;
	int sz;
	seg_node(mint p = 0, int c = 0): val(0), lo(p), hi(p*inv2[1]), sz(c) {}
	void push(seg_node& l, seg_node& r){}
	void merge(const seg_node& l, const seg_node& r){
		val = l.val + r.val + l.lo * r.hi * inv2[l.sz];
		lo = l.lo + r.lo * p2[l.sz];
		hi = l.hi + r.hi * inv2[l.sz];
		sz = l.sz + r.sz;
	}
	void rem(){
		val = lo = hi = 0;
		sz = 0;
	}
	void add(mint p){
		val = 0;
		lo = p;
		hi = p * inv2[1];
		sz = 1;
	}
	mint get_val() { return val; }
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	{
		p2 = inv2 = vector<mint>(1100000);
		p2[0] = inv2[0] = 1;
		mint inv = mint(1)/mint(2);
		for(int i=1;i<1100000;i++){
			p2[i] = 2 * p2[i-1];
			inv2[i] = inv * inv2[i-1];
		}
	}
	int n, q;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int>v = a;
	cin>>q;
	vector<pair<int, int>>qr(q);
	for(int i=0;i<q;i++){
		int j, x;
		cin>>j>>x; j--;
		qr[i] = {j, x};
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int m = n + q;
	vector<int>pos(m);
	segtree_range<seg_node>seg(m);
	for(int i=0;i<n;i++){
		a[i] = int(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
		a[i] += pos[a[i]]++;
		seg.at(a[i]) = seg_node(v[a[i]], 1);
	}
	seg.build();
	cout<<seg.query(0, m).get_val()<<"\n";

	for(int i=0;i<q;i++){
		auto [j, x] = qr[i];
		x = int(lower_bound(v.begin(), v.end(), x) - v.begin());
		x += pos[x]++;
		seg.update(a[j], a[j]+1, &seg_node::rem);
		a[j] = x;
		seg.update(a[j], a[j]+1, &seg_node::add, v[a[j]]);
		cout<<seg.query(0, m).get_val()<<"\n";
	}
	return 0;
}
/*
[  ]Leu o problema certo???
[  ]Ver se precisa de long long
[  ]Viu o limite dos fors (é n? é m?)
[  ]Tamanho do vetor, será que é 2e5 em vez de 1e5??
[  ]Testar sample
[  ]Testar casos de  borda
[  ]1LL no 1LL << i
[  ]Testar mod (é 1e9+7, mesmo?, será que o mod não ficou negativo?)
*/
