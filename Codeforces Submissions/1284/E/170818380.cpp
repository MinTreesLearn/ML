#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
 
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
using i64 = long long;
using i128 = __int128;
#define MAXN 100005
#define MAXM 100005
#define M 1000000
#define K 17
#define MAXP 25
#define MAXK 55
//#define MAXC 255
#define MAXERR 105
#define MAXLEN 105
#define MDIR 10
#define MAXR 705
#define BASE 102240
#define MAXA 28
#define MAXT 100005
#define LIMIT 86400
#define MAXV 305
#define LEQ 1
#define EQ 0
#define OP 0
#define CLO 1
#define DIG 1
#define C1 0
#define C2 1
#define PLUS 0
#define MINUS 1
#define MUL 2
#define CLO 1
#define VERT 1
//#define B 31
#define B2 1007
#define W 1
#define H 30
#define SPEC 1
#define MUL 2
#define CNT 3
#define ITER 1000
#define INF 1e9
#define EPS 1e-10
#define MOD 998244353
#define FACT 100000000000000
#define PI 3.1415926535897932384626433832795014
#define SRC 0
#define SCALE 1e16
typedef long long ll;
typedef ll hash_t;
typedef __int128_t lint;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<double,int> ip;
typedef pair<ll,ii> pl;
typedef pair<ll, ll> pll;
typedef pair<ll,int> ppll;
typedef pair<ll,int> li;
typedef pair<ll,ll> iv;
typedef pair<double,int> ip;
typedef tuple<int,int,int> iii;
typedef tuple<int, int, int> tll;
typedef tuple<ld, int, int> iit;
typedef vector<vector<int>> vv;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<vector<ll>> vll;
typedef complex<ld> cd;
#define pb push_back
#define eb emplace_back
#define ins insert
#define er erase
#define sc second
#define fr first
#define mp make_pair
#define mt make_tuple
#define repl(i,x,y) for (int i = (x); i <= (y); ++i)
#define rep(i,x,y) for (int i = (x); i < (y); ++i)
#define rev(i,x,y) for (int i = (x); i >= (y); --i)
#define LSOne(S) (S & (-S))
#define trav(i,v) for (auto &i : v)
#define foreach(it,v) for (auto it = begin(v); it != end(v); ++it)
#define bend(v) (v).begin(), (v).end()
#define rbend(v) (v).rbegin(), (v).rend()
#define sortarr(v) sort(bend(v))
#define rsortarr(v) sort(rbend(v))
#define unique(v) v.er(unique(bend(v)), end(v))
#define extend(A,B) A.insert(end(A), bend(B))
#define sz(A) (int)(A.size())
#define fill(V) iota(bend(V), (0))
#define vfill(V, st) iota(bend(V), st)
template<class T> bool ckmin(T &a, T b) { return a > b ? a = b, 1 : 0; };
template<class T> bool ckmax(T &a, T b) { return a < b ? a = b, 1 : 0; };
template<class T> void amax(T &a, T b, T c) { a = max(b, c); };
template<class T> void amin(T &a, T b, T c) { a = min(b, c); };
template<class T> T getmax(vector<T> &v) { return *max_element(bend(v)); };
template<class T> T getmin(vector<T> &v) { return *min_element(bend(v)); };
template<class T> int compress(vector<T> &v, T &val) { return (int)(lower_bound(bend(v), val) - begin(v)); };
template<class T> auto vfind(vector<T> &v, T val) {
    return find(bend(v), val);
}
template<class T> auto verase(vector<T> &v, T val) {
    return v.er(vfind(v, val));
}
template<class T> void revarr(vector<T> &v) { reverse(bend(v)); };

struct pt {
    ll x, y;
    public : pt() {};
    public : pt(ll _x,  ll _y) : x(_x), y(_y) {};
};

struct vec {
    ll x,y;
    public : vec(pt a, pt b) { x = b.x - a.x, y = b.y - a.y; };
    public : vec(ll _x, ll _y) : x(_x), y(_y) {};
    bool operator<(const vec &p) {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

vec toVec(pt &p, pt &q) {
    return vec(p, q);
}

ll dot (vec &p, vec &q) {
    return p.x * q.x + p.y * q.y;
}

ll sqrmag(vec &p) {
    return p.x * p.x + p.y * p.y;
}

pt translate(pt &p, vec q) {
    ll x = p.x + q.x, y = p.y + q.y;
    pt r(x,y); return r;
}

vec scale(ll u, vec p) {
    return vec(p.x * u, p.y * u);
}

ll cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

bool onseg(pt &p, pt &q, pt &r) {
    return (min(p.x, r.x) <= q.x && max(r.x, p.x) >= q.x && q.y >= min(p.y, r.y)  && max(r.y, p.y) >= q.y);
}

ll orien(pt &p, pt &q, pt &r) {
    ll res = cross(toVec(p,q), toVec(p,r));
    if (!res) return 0; //Collinear
    return (res < 0) ? 1 : 2; //1 is CW, 2 is CCW
}

ll choose3(int n) {
    if (n < 3) return 0;
    ll ans = 1;
    repl(i,n-2,n) ans *= i;
    repl(i,2,3) ans /= i;
    return ans;
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

//xi denotes the number of subsets of 5 points here exactly i points form its convex hull
//we want to find 2x3 + x4
//idea: if we cannot find the exact form properly, we can try to calculate other closed forms, do some addition/subtraction to get the exact form
//in this case x3 + x4 + x5 = nC5
//5x3 + 5x4 + 5x5 - 3x3 - 4x4 - 5x5 = 2x3 + x4 which is what we desire
int main() {
    fast_io();
    int n;
    cin >> n;
    vector<pt> pts;
    rep(i,0,n) {
        int a,b; cin >> a >> b;
        pts.pb(pt(a,b));
    }
    //5 * x3 + 5 * x4 + 5 * x5 = 5 * (nC5)
    ll ans = 1;
    repl(i,n-4,n) ans = (ans * i);
    repl(i,2,4) ans /= i;
    //this is equal to 3x3 + 4x4 + 5x5
    ll sub = 0;
    //calculate the contribution of every edge to the total sum
    rep(i,0,n) {
        vector<vec> v;
        //get all vectors w.r.t point i
        rep(j,0,n) {
            if (j != i) v.pb(vec(pts[i], pts[j]));
        }
        sort(bend(v),[](vec &a, vec &b) {
            //check where the point lies on the left or right of point i w.r.t the x-axis
            bool ba = a < vec(0,0);
            bool bb = b < vec(0,0); //no duplicates so vector can never be (0,0)
            if (ba != bb) return ba > bb;
            //ccw walk from point i to point a to point b
            return cross(a,b) > 0;
        });
        int ptr = 0;
        rep(j,0,n-1) {
            while (ptr < j + n - 1 && cross(v[j], v[ptr % (n - 1)]) >= 0)ptr++;
            sub += choose3(ptr - j - 1);
        }
    }
    cout << ans - sub;
}