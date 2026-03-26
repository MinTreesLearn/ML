#line 1 "library/my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

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

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
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
#define FOR4_R(i, a, b, c) for (ll i = (b)-1; i >= ll(a); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) \
  overload4(__VA_ARGS__, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

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

template <typename T>
T pick(deque<T> &que) {
  T a = que.front();
  que.pop_front();
  return a;
}

template <typename T>
T pick(pq<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}

template <typename T>
T pick(pqg<T> &que) {
  assert(que.size());
  T a = que.top();
  que.pop();
  return a;
}

template <typename T>
T pick(vc<T> &que) {
  assert(que.size());
  T a = que.back();
  que.pop_back();
  return a;
}

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

vc<int> s_to_vi(const string &S, char first_char) {
  vc<int> A(S.size());
  FOR(i, S.size()) { A[i] = S[i] - first_char; }
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

template <typename CNT, typename T>
vc<CNT> bincount(const vc<T> &A, int size) {
  vc<CNT> C(size);
  for (auto &&x: A) { ++C[x]; }
  return C;
}

// stable
template <typename T>
vector<int> argsort(const vector<T> &A) {
  vector<int> ids(A.size());
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
}

// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
  int n = len(I);
  vc<T> B(n);
  FOR(i, n) B[i] = A[I[i]];
  return B;
}
#endif
#line 1 "library/other/io.hpp"
// based on yosupo's fastio
#include <unistd.h>

namespace fastio {
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
#line 2 "library/ds/unionfind/unionfind.hpp"

struct UnionFind {
  int n, n_comp;
  vc<int> dat; // par or (-size)
  UnionFind(int n = 0) { build(n); }

  void build(int m) {
    n = m, n_comp = m;
    dat.assign(n, -1);
  }

  int operator[](int x) {
    while (dat[x] >= 0) {
      int pp = dat[dat[x]];
      if (pp < 0) { return dat[x]; }
      x = dat[x] = pp;
    }
    return x;
  }

  int size(int x) {
    assert(dat[x] < 0);
    return -dat[x];
  }

  bool merge(int x, int y) {
    x = (*this)[x], y = (*this)[y];
    if (x == y) return false;
    if (-dat[x] < -dat[y]) swap(x, y);
    dat[x] += dat[y], dat[y] = x, n_comp--;
    return true;
  }
};
#line 4 "main.cpp"

void solve() {
  LL(N, M, Q);
  int H = N, W = M;
  const int LIM = max(1000, ceil(2'000'000, N * M)) + 5;
  // 色 0 ：単調減少
  // 色 k ：単調増加 → 単調減少
  // すべて、増加 → 減少 と見なせる
  // (t,x,y)
  using T3 = tuple<int, int, int>;
  vvc<T3> ADD(LIM), RM(LIM);

  vv(int, A, N, M);
  FOR(t, Q) {
    LL(a, b, c);
    --a, --b;
    if (A[a][b] == c) continue;
    RM[A[a][b]].eb(t, a, b);
    A[a][b] = c;
    ADD[A[a][b]].eb(t, a, b);
  }

  auto idx = [&](int x, int y) -> int { return M * x + y; };
  auto isin = [&](ll x, ll y) -> bool {
    return (0 <= x && x < H && 0 <= y && y < W);
  };
  ll dx[] = {1, 0, -1, 0};
  ll dy[] = {0, 1, 0, -1};

  UnionFind uf(N);
  vc<int> C(N * M);
  int comp = 0;
  auto reset = [&]() -> void {
    uf.build(N * M);
    fill(all(C), 0);
    comp = 0;
  };
  auto add = [&](int x, int y) -> void {
    int i = idx(x, y);
    assert(C[i] == 0);
    C[i] = 1;
    ++comp;
    FOR(d, 4) {
      int nx = x + dx[d], ny = y + dy[d];
      if (isin(nx, ny) && C[idx(nx, ny)] && uf.merge(i, idx(nx, ny))) --comp;
    }
  };

  vc<int> ANS(Q + 1);
  FOR(color, LIM) {
    if (ADD[color].empty() && RM[color].empty()) continue;
    // クエリ [0,p) の答を計算済
    int p = 0;
    reset();
    for (auto&& [t, a, b]: ADD[color]) {
      ANS[p] += comp, ANS[t] -= comp;
      add(a, b);
      p = t;
    }
    // クエリ [q, Q) の答を計算済
    int q = Q;
    reset();
    FOR(x, N) FOR(y, M) if (A[x][y] == color) add(x, y);
    reverse(all(RM[color]));
    for (auto&& [t, a, b]: RM[color]) {
      ANS[t] += comp, ANS[q] -= comp;
      q = t;
      add(a, b);
    }
    ANS[p] += comp, ANS[q] -= comp;
  }

  ANS = cumsum<int>(ANS, 0);
  FOR(q, Q) print(ANS[q]);
}

signed main() {
  solve();

  return 0;
}
