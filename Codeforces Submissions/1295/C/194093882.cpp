/* iamujj15 */

#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;

#define fstio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 5e18
#define nline "\n"
#define pb emplace_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define FIXED_FLOAT(x) std::fixed << std::setprecision(15) << (x)
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vcin(a) for (auto &i : a) cin >> i
#define vcout(a) for (auto i : a) cout << i << " "

#ifndef iamujj15
#define debug(x) cerr << #x << " "; _print(x); cerr << nline;
#else
#define debug(x);
#endif

typedef unsigned long long ull;
typedef long double lld;
typedef pair<long long, long long> pll;
typedef vector<long long> vll;
typedef long long ll;
typedef unsigned long long ull;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(float t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*---------------------------------------------------------------------------------------------------------------------------*/
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b >>= 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll pow2(ll k) {ll i = 1; if (k == 0) return 1; while (k--) i *= 2; return i;}
ll pow10(ll k) {ll i = 1; if (k == 0) return 1; while (k--) i *= 10; return i;}
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b;}
ll mx(ll a, ll b) {return a > b ? a : b;}
ll mn(ll a, ll b) {return a < b ? a : b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
void sieve(vector<bool>& prime) {for (int p = 2; p * p <= prime.size(); p++) {if (prime[p] == true) {for (int i = p * p; i <= prime.size(); i += p) prime[i] = false;}}}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
ll modInverse(ll A, ll M) {ll m0 = M; ll y = 0, x = 1; if (M == 1)return 0; while (A > 1) {ll q = A / M; ll t = M; M = A % M, A = t; t = y; y = x - q * y; x = t;} if (x < 0)x += m0; return x;}
void preclc(vll &fact, vll &invf) {fact[0] = 1; fact[1] = 1; invf[0] = 1; invf[1] = 1; for (ll i = 2; i < (ll)fact.size(); i++) {fact[i] = (fact[i - 1] * i) % MOD; invf[i] = modInverse(fact[i], MOD);}}
ll ncr(ll n, ll r, vll &fact, vll &invf) {return ((fact[n] * invf[r] % MOD) * invf[n - r]) % MOD;}
/*--------------------------------------------------------------------------------------------------------------------------*/

string spi = "3141592653589793238462643383279";

class DSU {
public:
    vector<pll> parent;
    vll size;
    DSU(ll n) {
        size.resize(n, 1);
        for (ll i = 0; i < n; i++) parent.pb(i, 0);
    }

    ll find_set(ll x) {
        if (parent[x].ff == x) return x;
        return parent[x].ff = find_set(parent[x].ff);
    }
    bool same_set(ll x, ll y) {
        return find_set(x) == find_set(y);
    }
    void union_set(ll x, ll y) {
        ll xroot = find_set(x);
        ll yroot = find_set(y);
        if (xroot == yroot) return;
        if (parent[xroot].ss > parent[yroot].ss) {
            parent[yroot].ff = xroot;
            size[xroot] += size[yroot];
        }
        else if (parent[yroot].ss > parent[xroot].ss) {
            parent[xroot].ff = yroot;
            size[yroot] += size[xroot];
        }
        else {
            parent[xroot].ss++;
            parent[yroot].ff = xroot;
            size[xroot] += size[yroot];
        }
    }
    ll size_set(ll x) {
        return size[find_set(x)];
    }
};

/*
----------------------------------Errors to be taken care of----------------------------------

⬥ Initialised a variable, with some other variable (say n), before cin >> n?
⬥ Checked for the domain of the answer, & what extreme values your solution could get?
⬥ In C++, comparator should return false if its arguments are equal
⬥ Use custom sqrt function

*/

void solution()
{
    //vector<bool> prime(4e6, true);
    //sieve(prime);

    ll t;
    cin >> t;
    for (ll i = 1; i <= t; ++i)
    {
        string s, t;
        cin >> s >> t;
        bool flg = true;
        set<char> ss;
        for (auto i : s)
            ss.insert(i);
        for (auto i : t)
        {
            if (ss.find(i) == ss.end())
            {
                flg = false;
                break;
            }
        }

        if (!flg)
            cout << -1 << nline;
        else
        {
            ll cnt = 0, cr = -1, id = 0;
            vector<set<ll>> pos(26);
            for (ll i = 0; i < s.length(); ++i)
                pos[s[i] - 'a'].insert(i);

            while (id < t.size())
            {
                if (pos[t[id] - 'a'].lower_bound(cr + 1) != pos[t[id] - 'a'].end())
                {
                    cr = *pos[t[id] - 'a'].lower_bound(cr + 1);
                    id++;
                }
                else
                {
                    cr = -1;
                    cnt++;
                }
            }
            cout << cnt + 1 << nline;
        }
    }
}

int main()
{
#ifndef iamujj15
    freopen("error.txt", "w", stderr);
#endif
    fstio();
    auto start1 = high_resolution_clock::now();
    solution();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef iamujj15
    cerr << "Time: " << duration . count() / 1000 << nline;
#endif
}