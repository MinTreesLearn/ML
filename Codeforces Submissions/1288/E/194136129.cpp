// time-limit: 3000
// problem-url: https://codeforces.com/problemset/problem/1288/E
// clang-format off
#include"bits/stdc++.h"
#include <numeric>
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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order(0) -> k th element
// order_of_key(k) -> number of elements less than k

// clang-format on

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    std::vector<int> a;
    std::vector<int> pos(n, -1);
    o_set<int> s;
    std::vector<int> lans(n), rans(n);
    for (int i = 0; i < n; i++) {
        pos[i] = 0;
        rans[i] = i;
        lans[i] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        s.order_of_key(n - i - 1);
        pos[i] = n - i - 1;
        s.insert(n - i - 1);
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        k--, a.pb(k);
    }
    for (int i = 0; i < m; i++) {
        chmin(lans[a[i]], 0);
        int z = n - s.order_of_key(pos[a[i]]) - 1;
        s.erase(pos[a[i]]);
        chmax(rans[a[i]], z);
        pos[a[i]] = n + i;
        s.insert(n + i);
        dbg(pos);
    }
    for (int i = 0; i < n; i++) {
        int z = n - s.order_of_key(pos[i]) - 1;
        chmax(rans[i], z);
    }
    for (int i = 0; i < n; i++) {
        cout << lans[i] + 1 << ' ' << rans[i] + 1 << '\n';
    }
    return 0;
}
