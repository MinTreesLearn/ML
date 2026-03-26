#line 1 "/home/maspy/compro/library/my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'000'000'000;
template <>
constexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;
template <>
constexpr double infty<double> = infty<ll>;
template <>
constexpr long double infty<long double> = infty<ll>;

using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

// https://trap.jp/post/1224/
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define FOR_subset(t, s) \
  for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T, typename U>
T ceil(T x, U y) {
  return (x > 0 ? (x + y - 1) / y : x / y);
}
template <typename T, typename U>
T floor(T x, U y) {
  return (x > 0 ? x / y : (x - y + 1) / y);
}
template <typename T, typename U>
pair<T, T> divmod(T x, U y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

template <typename T, typename U>
T SUM(const vector<U> &A) {
  T sum = 0;
  for (auto &&a: A) sum += a;
  return sum;
}

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

template <typename T>
T POP(deque<T> &que) {
  T a = que.front();
  que.pop_front();
  return a;
}
template <typename T>
T POP(pq<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(pqg<T> &que) {
  assert(!que.empty());
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(vc<T> &que) {
  assert(!que.empty());
  T a = que.back();
  que.pop_back();
  return a;
}

template <typename F>
ll binary_search(F check, ll ok, ll ng) {
  assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));
  }
  return ok;
}
template <typename F>
double binary_search_real(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));
  }
  return (ok + ng) / 2;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

// ? は -1
vc<int> s_to_vi(const string &S, char first_char) {
  vc<int> A(S.size());
  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }
  return A;
}

template <typename T, typename U>
vector<T> cumsum(vector<U> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

// stable sort
template <typename T>
vector<int> argsort(const vector<T> &A) {
  vector<int> ids(len(A));
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
  return ids;
}

// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
  vc<T> B(len(I));
  FOR(i, len(I)) B[i] = A[I[i]];
  return B;
}
#endif
#line 1 "/home/maspy/compro/library/other/io.hpp"
// based on yosupo's fastio
#include <unistd.h>

namespace fastio {
#define FASTIO
// クラスが read(), print() を持っているかを判定するメタ関数
struct has_write_impl {
  template <class T>
  static auto check(T &&x) -> decltype(x.write(), std::true_type{});

  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_write : public decltype(has_write_impl::check<T>(std::declval<T>())) {
};

struct has_read_impl {
  template <class T>
  static auto check(T &&x) -> decltype(x.read(), std::true_type{});

  template <class T>
  static auto check(...) -> std::false_type;
};

template <class T>
class has_read : public decltype(has_read_impl::check<T>(std::declval<T>())) {};

struct Scanner {
  FILE *fp;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf); }
    if (neg) ref = -ref;
    return true;
  }
  template <typename T,
            typename enable_if<has_read<T>::value>::type * = nullptr>
  inline bool read_single(T &x) {
    x.read();
    return true;
  }
  bool read_single(double &ref) {
    string s;
    if (!read_single(s)) return false;
    ref = std::stod(s);
    return true;
  }
  bool read_single(char &ref) {
    string s;
    if (!read_single(s) || s.size() != 1) return false;
    ref = s[0];
    return true;
  }
  template <class T>
  bool read_single(vector<T> &ref) {
    for (auto &d: ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  template <class T, class U>
  bool read_single(pair<T, U> &p) {
    return (read_single(p.first) && read_single(p.second));
  }
  template <size_t N = 0, typename T>
  void read_single_tuple(T &t) {
    if constexpr (N < std::tuple_size<T>::value) {
      auto &x = std::get<N>(t);
      read_single(x);
      read_single_tuple<N + 1>(t);
    }
  }
  template <class... T>
  bool read_single(tuple<T...> &tpl) {
    read_single_tuple(tpl);
    return true;
  }
  void read() {}
  template <class H, class... T>
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE *fp) : fp(fp) {}
};

struct Printer {
  Printer(FILE *_fp) : fp(_fp) {}
  ~Printer() { flush(); }

  static constexpr size_t SIZE = 1 << 15;
  FILE *fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write(const char val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write('0');
      return;
    }
    if (val < 0) {
      write('-');
      val = -val; // todo min
    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 - i]; }
    pos += len;
  }
  void write(const string s) {
    for (char c: s) write(c);
  }
  void write(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write(s[i]);
  }
  void write(const double x) {
    ostringstream oss;
    oss << fixed << setprecision(15) << x;
    string s = oss.str();
    write(s);
  }
  void write(const long double x) {
    ostringstream oss;
    oss << fixed << setprecision(15) << x;
    string s = oss.str();
    write(s);
  }
  template <typename T,
            typename enable_if<has_write<T>::value>::type * = nullptr>
  inline void write(T x) {
    x.write();
  }
  template <class T>
  void write(const vector<T> val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  template <class T, class U>
  void write(const pair<T, U> val) {
    write(val.first);
    write(' ');
    write(val.second);
  }
  template <size_t N = 0, typename T>
  void write_tuple(const T t) {
    if constexpr (N < std::tuple_size<T>::value) {
      if constexpr (N > 0) { write(' '); }
      const auto x = std::get<N>(t);
      write(x);
      write_tuple<N + 1>(t);
    }
  }
  template <class... T>
  bool write(tuple<T...> tpl) {
    write_tuple(tpl);
    return true;
  }
  template <class T, size_t S>
  void write(const array<T, S> val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  void write(i128 val) {
    string s;
    bool negative = 0;
    if (val < 0) {
      negative = 1;
      val = -val;
    }
    while (val) {
      s += '0' + int(val % 10);
      val /= 10;
    }
    if (negative) s += "-";
    reverse(all(s));
    if (len(s) == 0) s = "0";
    write(s);
  }
};
Scanner scanner = Scanner(stdin);
Printer printer = Printer(stdout);
void flush() { printer.flush(); }
void print() { printer.write('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  printer.write(head);
  if (sizeof...(Tail)) printer.write(' ');
  print(forward<Tail>(tail)...);
}

void read() {}
template <class Head, class... Tail>
void read(Head &head, Tail &... tail) {
  scanner.read(head);
  read(tail...);
}
} // namespace fastio
using fastio::print;
using fastio::flush;
using fastio::read;

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define CHAR(...)   \
  char __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)      \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
#line 2 "/home/maspy/compro/library/flow/bflow.hpp"
enum Objective {
  MINIMIZE = 1,
  MAXIMIZE = -1,
};
enum class Status {
  OPTIMAL,
  INFEASIBLE,
};

template <class Flow = ll, class Cost = ll,
          Objective objective = Objective::MINIMIZE, Flow SCALING_FACTOR = 2>
struct MinCostFlow {
private:
  using V_id = uint32_t;
  using E_id = uint32_t;

  struct Edge {
    friend struct MinCostFlow;

  private:
    V_id frm, to;
    Flow flow, cap;
    Cost cost;
    E_id rev;

  public:
    Edge() = default;

    Edge(const V_id frm, const V_id to, const Flow cap, const Cost cost,
         const E_id rev)
        : frm(frm), to(to), flow(0), cap(cap), cost(cost), rev(rev) {}

    [[nodiscard]] Flow residual_cap() const { return cap - flow; }
  };

public:
  struct EdgePtr {
    friend struct MinCostFlow;

  private:
    const MinCostFlow *instance;
    const V_id v;
    const E_id e;

    EdgePtr(const MinCostFlow *instance, const V_id v, const E_id e)
        : instance(instance), v(v), e(e) {}

    [[nodiscard]] const Edge &edge() const { return instance->g[v][e]; }

    [[nodiscard]] const Edge &rev() const {
      const Edge &e = edge();
      return instance->g[e.to][e.rev];
    }

  public:
    [[nodiscard]] V_id frm() const { return rev().to; }

    [[nodiscard]] V_id to() const { return edge().to; }

    [[nodiscard]] Flow flow() const { return edge().flow; }

    [[nodiscard]] Flow lower() const { return -rev().cap; }

    [[nodiscard]] Flow upper() const { return edge().cap; }

    [[nodiscard]] Cost cost() const { return edge().cost; }

    [[nodiscard]] Cost gain() const { return -edge().cost; }
  };

private:
  V_id n;
  std::vector<std::vector<Edge>> g;
  std::vector<Flow> b;

public:
  MinCostFlow(int n) : n(n) {
    g.resize(n);
    b.resize(n);
  }

  V_id add_vertex() {
    ++n;
    g.resize(n);
    b.resize(n);
    return n - 1;
  }

  std::vector<V_id> add_vertices(const size_t size) {
    std::vector<V_id> ret;
    for (V_id i = 0; i < size; ++i) ret.emplace_back(n + i);
    n += size;
    g.resize(n);
    b.resize(n);
    return ret;
  }

  void add(const V_id frm, const V_id to, const Flow lo, const Flow hi,
           const Cost cost) {
    const E_id e = g[frm].size(), re = frm == to ? e + 1 : g[to].size();
    assert(lo <= hi);
    g[frm].emplace_back(Edge{frm, to, hi, cost * objective, re});
    g[to].emplace_back(Edge{to, frm, -lo, -cost * objective, e});
    edges.eb(EdgePtr{this, frm, e});
  }

  void add_source(const V_id v, const Flow amount) { b[v] += amount; }

  void add_sink(const V_id v, const Flow amount) { b[v] -= amount; }

private:
  static Cost constexpr unreachable = std::numeric_limits<Cost>::max();
  Cost farthest;
  std::vector<Cost> potential;
  std::vector<Cost> dist;
  std::vector<Edge *> parent;
  std::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost, int>>,
                      std::greater<>>
      pq;
  std::vector<V_id> excess_vs, deficit_vs;
  std::vector<EdgePtr> edges;
  Edge &rev(const Edge &e) { return g[e.to][e.rev]; }

  void push(Edge &e, const Flow amount) {
    e.flow += amount;
    g[e.to][e.rev].flow -= amount;
  }

  Cost residual_cost(const V_id frm, const V_id to, const Edge &e) {
    return e.cost + potential[frm] - potential[to];
  }

  bool dual(const Flow delta) {
    dist.assign(n, unreachable);
    parent.assign(n, nullptr);
    excess_vs.erase(std::remove_if(std::begin(excess_vs), std::end(excess_vs),
                                   [&](const V_id v) { return b[v] < delta; }),
                    std::end(excess_vs));
    deficit_vs.erase(
        std::remove_if(std::begin(deficit_vs), std::end(deficit_vs),
                       [&](const V_id v) { return b[v] > -delta; }),
        std::end(deficit_vs));
    for (const auto v: excess_vs) pq.emplace(dist[v] = 0, v);
    farthest = 0;
    std::size_t deficit_count = 0;
    while (!pq.empty()) {
      const auto [d, u] = pq.top();
      pq.pop();
      if (dist[u] < d) continue;
      farthest = d;
      if (b[u] <= -delta) ++deficit_count;
      if (deficit_count >= deficit_vs.size()) break;
      for (auto &e: g[u]) {
        if (e.residual_cap() < delta) continue;
        const auto v = e.to;
        const auto new_dist = d + residual_cost(u, v, e);
        if (new_dist >= dist[v]) continue;
        pq.emplace(dist[v] = new_dist, v);
        parent[v] = &e;
      }
    }
    pq = decltype(pq)();
    for (V_id v = 0; v < n; ++v) {
      potential[v] += std::min(dist[v], farthest);
    }
    return deficit_count > 0;
  }

  void primal(const Flow delta) {
    for (const auto t: deficit_vs) {
      if (dist[t] > farthest) continue;
      Flow f = -b[t];
      V_id v;
      for (v = t; parent[v] != nullptr && f >= delta; v = parent[v]->frm) {
        f = std::min(f, parent[v]->residual_cap());
      }
      f = std::min(f, b[v]);
      if (f < delta) continue;
      for (v = t; parent[v] != nullptr;) {
        auto &e = *parent[v];
        push(e, f);
        const size_t u = parent[v]->frm;
        parent[v] = nullptr;
        v = u;
      }
      b[t] += f;
      b[v] -= f;
    }
  }

  void saturate_negative(const Flow delta) {
    excess_vs.clear();
    deficit_vs.clear();
    for (auto &es: g)
      for (auto &e: es) {
        const Flow rcap = e.residual_cap();
        const Cost rcost = residual_cost(e.frm, e.to, e);
        if (rcost < 0 && rcap >= delta) {
          push(e, rcap);
          b[e.frm] -= rcap;
          b[e.to] += rcap;
        }
      }
    for (V_id v = 0; v < n; ++v)
      if (b[v] != 0) { (b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v); }
  }

public:
  std::pair<Status, i128> solve() {
    potential.resize(n);
    for (auto &es: g)
      for (auto &e: es) {
        const Flow rcap = e.residual_cap();
        if (rcap < 0) {
          push(e, rcap);
          b[e.frm] -= rcap;
          b[e.to] += rcap;
        }
      }

    Flow inf_flow = 1;
    for (const auto &es: g)
      for (const auto &e: es) inf_flow = std::max(inf_flow, e.residual_cap());
    Flow delta = 1;
    while (delta <= inf_flow) delta *= SCALING_FACTOR;

    for (delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR) {
      saturate_negative(delta);
      while (dual(delta)) primal(delta);
    }

    i128 value = 0;
    for (const auto &es: g)
      for (const auto &e: es) { value += e.flow * e.cost; }
    value /= 2;

    if (excess_vs.empty() && deficit_vs.empty()) {
      return {Status::OPTIMAL, value / objective};
    } else {
      return {Status::INFEASIBLE, value / objective};
    }
  }

  template <class T>
  T get_result_value() {
    T value = 0;
    for (const auto &es: g)
      for (const auto &e: es) { value += (T)(e.flow) * (T)(e.cost); }
    value /= (T)2;
    return value / objective;
  }

  std::vector<Cost> get_potential() {
    std::fill(potential.begin(), potential.end(), 0);
    for (int i = 0; i < (int)n; i++)
      for (const auto &es: g)
        for (const auto &e: es)
          if (e.residual_cap() > 0)
            potential[e.to]
                = std::min(potential[e.to], potential[e.frm] + e.cost);
    return potential;
  }

  std::vector<EdgePtr> get_edges() { return edges; }
};
#line 4 "main.cpp"

void solve() {
  LL(N1, N2, M, R, B);
  STR(S1, S2);
  VEC(pi, edge, M);
  for (auto&& [a, b]: edge) --a, --b;
  auto left = [&](int v) -> int { return v; };
  auto right = [&](int v) -> int { return N1 + v; };
  int source = N1 + N2;
  int sink = N1 + N2 + 1;
  MinCostFlow<ll, ll> G(sink + 1);

  FOR(i, M) {
    auto [a, b] = edge[i];
    G.add(left(a), right(b), 0, 1, R);
    G.add(right(b), left(a), 0, 1, B);
  }
  FOR(v, N1) {
    char c = S1[v];
    if (c == 'R') G.add(source, left(v), 1, infty<int>, 0);
    if (c == 'B') G.add(left(v), sink, 1, infty<int>, 0);
    if (c == 'U') G.add(source, left(v), 0, infty<int>, 0);
    if (c == 'U') G.add(left(v), sink, 0, infty<int>, 0);
  }
  FOR(v, N2) {
    char c = S2[v];
    if (c == 'B') G.add(source, right(v), 1, infty<int>, 0);
    if (c == 'R') G.add(right(v), sink, 1, infty<int>, 0);
    if (c == 'U') G.add(source, right(v), 0, infty<int>, 0);
    if (c == 'U') G.add(right(v), sink, 0, infty<int>, 0);
  }
  G.add(sink, source, 0, infty<int>, 0);
  auto [status, cost] = G.solve();
  if (status == Status::INFEASIBLE) return print(-1);
  auto edges = G.get_edges();
  vc<int> F(M + M);
  FOR(i, M + M) F[i] = edges[i].flow();
  string ANS;
  FOR(i, M) {
    int a = F[2 * i + 0], b = F[2 * i + 1];
    if (a) ANS += "R";
    elif (b) ANS += "B";
    else ANS += "U";
  }
  print(cost);
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
