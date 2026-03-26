// time-limit: 1000
// problem-url: https://codeforces.com/contest/1305/problem/E
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define forn(i, a) rep(i, 0, a)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define rofn(i, a) per(i, 0, a)
#define IOS                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define dbg(x) cout << #x << "=" << x << endl
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define dbg3(x, y, z)                                                          \
  cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z     \
       << endl
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define memf(a) memset(a, false, sizeof(a))
#define memt(a) memset(a, true, sizeof(a))
#define meminf(a) memset(a, 0x7f, sizeof(a))
#define nO                                                                     \
  {                                                                            \
    cout << "NO\n";                                                            \
    return;                                                                    \
  }
#define yES                                                                    \
  {                                                                            \
    cout << "YES\n";                                                           \
    return;                                                                    \
  }
#define neg                                                                    \
  {                                                                            \
    cout << "-1\n";                                                            \
    return;                                                                    \
  }
#define each(a, x) for (auto &a : x)
#define ar array
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define int             long long

template <typename T> using V = vector<T>;
template <typename T> bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
} // set a = min(a,b)
template <typename T> bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

using ll = long long;
using db = long double;
using vd = vector<db>;
using vs = vector<string>;
using pi = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vpi = vector<pi>;
template <class T> using MaxHeap = priority_queue<T>;

template <class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

template <class A> void read(V<A> &v);
template <class A, size_t S> void read(ar<A, S> &a);
template <class T> void read(T &x) { cin >> x; }
void read(double &d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double &d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T> void read(H &h, T &...t) {
  read(h);
  read(t...);
}
template <class A> void read(V<A> &x) { each(a, x) read(a); }
template <class A, size_t S> void read(ar<A, S> &x) { each(a, x) read(a); }

// bitwise ops
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(
    int x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
  return x == 0 ? 0 : 31 - __builtin_clz(x);
} // floor(log2(x))
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }

const ll INF = 1e18;
const db PI = acos((db)-1);
const int MOD = 1000000007;


vector<int>fac, inv, ifac;
void pre(int lim)
{
	fac.push_back(1); fac.push_back(1);
	ifac.push_back(1); ifac.push_back(1);
	inv.push_back(0); inv.push_back(1);
	for (int i = 2; i <= lim; i++)
	{
		fac.push_back(fac.back()*i % MOD);
		inv.push_back(MOD - (inv[MOD % i] * (MOD / i) % MOD));
		ifac.push_back(ifac.back()*inv.back() % MOD);
	}
}
int ncr(int n, int r)
{
	if (n < r || n < 0)
		return 0;
	if (r == 0)
		return 1;
	return (((fac[n] * ifac[r]) % MOD) * ifac[n - r]) % MOD;
}


void solve() {
  int n,m;
  cin >> n >> m;
  vi v(n), f(n);
  forn(i,n) v[i] = i + 1;
  int sum = 0;
  rep(i,2,n) f[i] = i / 2, sum += f[i];
  if(m > sum) neg;
  int X = 5005;
  int Y = 1e9;
  int idx = n-1;
  //debug(v,f);
  while(sum > m){
    int x = f[idx];
    int val = v[idx];
    if(m + x > sum){
      int rem = sum - m;
      if(val&1ll) v[idx] += rem * 2 - 1;
      else v[idx] += rem * 2;
      break;
    }
    else{
      v[idx] = Y;
      sum -= x;
      Y -= X;
    }
    idx--;
  }
  forn(i,n) cout << v[i] << " ";
  cout << endl;
}

signed main() {
  IOS;
	//pre(5e5+10);
  int tt = 1;
  // cin >> tt;
  for (int ii = 1; ii <= tt; ii++)
    solve();
}
