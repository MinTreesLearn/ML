// time-limit: 5000
// problem-url: https://codeforces.com/problemset/problem/1288/D
// clang-format off
#include"bits/stdc++.h"
#define mod               1000000007
#define inf               1e18
#define pq                priority_queue
#define pqi               priority_queue<ll>
#define pqimn             priority_queue<ll,vi,greater<ll>>
#define pb                push_back
#define sz(v)             ((int)(v).size())
#define all(v)            (v).begin(),(v).end()
#define ss                second
#define ff                first
 
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
template<typename T>
ostream& operator <<(ostream& ostream, vector<T>& v) {for(auto& element : v) {cout << element << " ";}return ostream;}
template<typename T>
istream& operator >>(istream& istream, vector<T>& v) { for(auto& element : v) {cin >> element;}return istream;}
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }
 
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif
// clang-format on

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ai = 1, aj = 1;
    auto chk = [&](int k) -> bool {
        std::vector<int> sat(1 << m, -1);
        bool p = false;
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (int j = 0; j < m; j++) {
                if (a[i][j] >= k) {
                    mask |= (1 << j);
                }
            }
            if (sat[mask] == -1) {
                sat[mask] = i;
            }
        }
        for (int i = 0; i < sz(sat); i++) {
            for (int j = 0; j < sz(sat); j++) {
                if ((j | i) == (1 << m) - 1 and sat[i] != -1 and sat[j] != -1) {
                    ai = sat[i], aj = sat[j];
                    return true;
                }
            }
        }
        return false;
    };
    int l = -1, r = 2e9;
    while (l + 1 < r) {
        int m = (l & r) + ((l ^ r) >> 1);
        if (chk(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << ai + 1 << ' ' << aj + 1 << '\n';
    return 0;
}
