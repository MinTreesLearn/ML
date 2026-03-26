/**
 *    author: Pratham_Shah10
 *    date: 10.02.2023
**/

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((ll)(x).size())
#define all(x) x.begin(),x.end()
#define set_bits __builtin_popcountll
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<": "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
void google(int t) {cout << "Case #" << t << ": ";}
ll binexpo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll min(ll a, ll b) {if (a > b) return b; return a;}
ll max(ll a, ll b) {if (a > b) return a; return b;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return ((a * b) / (gcd(a, b)));}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    while (1) {
        n = s.length();
        char mx = 'a';
        mx--;
        for (int i = 0; i < n; i++) {
            int t1 = (i + 1 < n) ? s[i] - s[i + 1] : 0;
            int t2 = (i - 1 >= 0) ? s[i] - s[i - 1] : 0;
            if (t1 == 1 || t2 == 1) {
                if (s[i] > mx) {
                    mx = s[i];
                }
            }
        }
        if (mx < 'a') {
            break;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == mx) {
                if (i + 1 < n && ((s[i] - s[i + 1]) == 1)) {
                    s[i] = '-';
                    cnt++;
                }
                else if (i - 1 >= 0 && ((s[i] - s[i - 1]) == 1)) {
                    s[i] = '-';
                    cnt++;
                }
            }
        }
        string ss;
        for (int i = 0; i < n; i++) {
            if (s[i] != '-') ss += s[i];
        }
        s = ss;
    }
    cout << cnt << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    solve();
}