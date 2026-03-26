#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using vi = vc<int>;
using vl = vc<ll>;
using vvi = vc<vi>;
using vvl = vc<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define rev(x) reverse(ALL(x))
#define srt(x) sort(ALL(x))
#define rsrt(x) sort(rALL(x))
#define rb(_, l, r) for(int _= l; _ <= r; ++_)
#define rep(_, l, r) for(int _ = l; _ < r; ++_)
#define br(_, r, l) for(int _ = r; _ >= l; _--)
#define sz(x) (int)(x.size())
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
template<typename T> void in(vector<T>&a) {for(auto& e: a) cin>> e;}
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

void p(int x) { if (x) cout << "YES" << '\n'; else cout << "NO" << '\n'; }

template<class t> void printv(t x, char delimiter = ',', bool needBrace = true) {
    needBrace && cout << "{"; 
    for(auto it = x.begin(); it != x.end(); ) {
        cout << *it;
        it = next(it);
        if (it != x.end()) {
            cout << delimiter;
        } else {
            needBrace && cout << "}";
        }
    }
    cout << "\n";
}

#define TEST
#ifdef TEST
    #define pr(...) printf(__VA_ARGS__);
    #define db(x, ...)      debug##x(__VA_ARGS__)
    #define ldb(parm...)    do {cout << "Line:" << __LINE__ << "  "; db(parm);} while(0)
    #define debugv(v...)    do {printv(v);} while(0)
    #define debug1(a)       cout << #a << " = " << a << ' ';
    #define debug2(a,b)     do {debug1(a); debug1(b); cout << '\n';} while(0)
    #define debug3(a,b,c)   do {debug1(a); debug2(b, c);} while(0)
    #define debug4(a,b,c,d) do {debug1(a); debug3(b, c, d);} while(0)
#else
    #define db(...) "Your attitude towards suffering is the melody of life."; 
#endif
/*
str -> str.c_str()
db(v, a) -> printv()
db(1, x) -> print x
db(2, x, y) -> print x, y
*/


const char nl = '\n';
#define SINGLE
void solve() {
    int n;
    cin >> n;
    vi a(n);
    map<int, vc<pii>> mp;
    rep (i, 0, n) {
        cin >> a[i];
        int cur = 0;
        br (j, i, 0) {
            cur += a[j];
            mp[cur].push_back({j + 1, i + 1});
        }
    }
    int mxv = -1, mx = 0;
    for (auto&[k, v]: mp) {
        int m = sz(v), cur = 1, pre = v[0].second;
        rep (i, 1, m) {
            if (v[i].first > pre) {
                cur ++;
                pre = v[i].second;
            } 
        }
        if (chmax(mx, cur)) mxv = k;
    }
    auto v = mp[mxv];
    cout << mx << nl;
    auto [l, r] =  v.front();
    cout << l << ' ' << r << nl;

    int m = sz(v), cur = 1, pre = v[0].second;
    rep (i, 1, m) {
        if (v[i].first > pre) {
            cout << v[i].first << ' ' << v[i].second << nl;
            pre = v[i].second;
        } 
    }
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
#ifdef SINGLE
    solve();
#else
    int T; cin >> T; while (T--) solve();
#endif
    return 0;
}