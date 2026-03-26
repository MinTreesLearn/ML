#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vvvvll = vector<vvvll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vvvvb = vector<vvvb>;
using vd = vector<double>;
using vvd = vector<vd>;
using vvvd = vector<vvd>;
#define all(A) A.begin(),A.end()
#define ALL(A) A.begin(),A.end()
#define rep(i, n) for (ll i = 0; i < (ll) (n); i++)
using pqr = priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>;

template<class T>
bool chmax(T& p, T q, bool C = 1) {
    if (C == 0 && p == q) {
        return 1;
    }
    if (p < q) {
        p = q;
        return 1;
    }
    else {
        return 0;
    }
}

template<class T>
bool chmin(T& p, T q, bool C = 1) {
    if (C == 0 && p == q) {
        return 1;
    }
    if (p > q) {
        p = q;
        return 1;
    }
    else {
        return 0;
    }
}

ll gcd(ll(a), ll(b)) {
    if (b == 0)return a;
    ll c = a;
    while (a % b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return b;
}
template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }
    
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    void set(int p, S x) {
        //assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        //assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        //assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        //assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        //assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        //assert(0 <= l && l <= _n);
        //assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        //assert(0 <= r && r <= _n);
        //assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};
struct S {
    ll a;
    ll size;
};

struct F {
    ll a, b;
};

S op(S l, S r) { return S{max(l.a,r.a), max(l.size,r.size)}; }

S e() { return S{-ll(1e18), 0}; }

S mapping(F l, S r) { return S{r.a * l.a + r.size * l.b, r.size}; }

F composition(F l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }

F id() { return F{1, 0}; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll N,M,P;
    cin>>N>>M>>P;
    ll MAX=0;
    vector<pair<ll,ll>> W(N),B(M);
    vector<tuple<ll,ll,ll>> MON(P);
    rep(i,N){
        cin>>W[i].first>>W[i].second;

    }
    rep(i,M){
        cin>>B[i].first>>B[i].second;
        chmax(MAX,B[i].first);
    }
    rep(p,P){
        ll X,Y,Z;
        cin>>X>>Y>>Z;
        MON[p]={X,Y,Z};
        chmax(MAX,Y);
    }
    MAX+=10;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(MAX);
    
    rep(i,MAX){
        seg.set(i,S{-ll(1e18),1});
    }
    rep(i,M){
        ll p=seg.get(B[i].first).a;
        chmax(p,-B[i].second);
        seg.set(B[i].first,S{p,1});
    }
    rep(i,MAX){
        ll p=seg.prod(i,MAX).a;
        seg.set(i,S{p,1});
    }
    //rep(i,MAX)cout<<i<<":"<<seg.get(i).a<<" ";
    cout<<endl;
    sort(all(W));
    sort(all(MON));
    ll an=-1e18;
    ll mo=0;
    rep(i,N){
        ll A=W[i].first;
        ll cost=W[i].second;

        while(mo<P&&get<0>(MON[mo])<A){
            ll b=get<1>(MON[mo]);
            ll c=get<2>(MON[mo]);
            seg.apply(b+1,MAX,F{1,c});
            //rep(i,MAX)cout<<i<<":"<<seg.get(i).a<<" ";
            mo++;
        }

        ll g=seg.all_prod().a;
        chmax(an,g-cost);
    }
    cout<<an<<endl;
}