#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FIO                     ios::sync_with_stdio(false); cin.tie(nullptr)
#define TC(t)                   int t; cin >> t; for(int i = 1; i <= t; i++)
#define ll                      int
#define ull                     unsigned long long int
#define lll                     __int128
#define lld                     long double
#define loop(i, a, b)           for(ll i = a; i <= b; i++)
#define loop2(i, b, a)          for(ll i = b; i >= a; i--)
#define ini(x, y)               memset(x, y, sizeof(x))
#define all(x)                  x.begin(), x.end()
#define all2(x)                 x.rbegin(), x.rend()
#define sz(x)                   (ll)x.size()
#define pb                      push_back
#define ppb                     pop_back
#define mp                      make_pair
#define ff                      first
#define ss                      second
#define M                       1000000007
#define endl                    '\n'
#define bits(x)                 __builtin_popcountll(x)
#define zrbits(x)               __builtin_ctzll(x)
#define vl                      vector<ll>
#define pll                     pair<ll,ll>
#define vpll                    vector<pll>
#define uni(x)                  x.erase(unique(all(x)), x.end())
#define ordered_set             tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define multi_ordered_set       tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define mxheap                  priority_queue<ll>
#define mnheap                  priority_queue<ll, vector<ll>, greater<ll>>
#define mxheap2                 priority_queue<pair<ll,ll>>
#define mnheap2                 priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>

const int N = 1e6 + 5;
const int L = 20;
const int MX = 1e9 + 10;
const ll INF = 1e18;

const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

using namespace std;
using namespace __gnu_pbds;

inline ll uceil(ll a,ll b) {return (a % b ? a / b + 1 : a / b);}
inline ll mod(ll x) {return ( (x % M + M) % M );}
ll ulog(ll val, ll base) {ll cnt = 0; val /= base; while(val) {cnt++; val /= base;} return cnt;}
ll power(ll a, ll b) {ll res = 1; while (b) {if (b & 1) res = res * a; a = a * a; b >>= 1;} return res;}
ll modpow(ll a, ll b) {ll res = 1; while (b) {if (b & 1) res = res * a % M; a = a * a % M; b >>= 1;} return res;}

#ifdef FARHAN
#define deb(x)                  cerr << #x << " = " << x << endl;
#define deb2(x, y)              cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define deb3(x, y, z)           cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define deb4()                  cerr << endl;
#define done                    cerr << "Line " << __LINE__ << " is done" << endl;
#else
#define deb(x)
#define deb2(x, y)
#define deb3(x, y, z)
#define deb4()
#define done
#endif

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for(auto& x : v) os << x << " "; return os;}
template<typename T> ostream& operator<<(ostream& os, const set<T>& v) {for(auto& x : v) os << x << " "; return os;}
template<typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S>& p) {os << p.first << ' ' << p.second; return os;}
template<typename... T> void in(T&... args) {((cin >> args), ...);}
template<typename... T> void out(T&&... args) {((cout << args << endl), ...);}
template<typename... T> void out2(T&&... args) {((cout << args << " "), ...);}
template<typename... T> void out3(T&&... args) {((cout << args << " "), ...); cout << endl;}

vector<ll> g[N], vis(N);

bool valid(ll i, ll j, ll n) {
        return (i >= 0 && i < n && j >= 0 && j < n);
}

ll create(ll i, ll j, ll n) {
        return (i * n + j);
}

pll decode(ll node, ll n) {
        return {node / n, node % n};
}

char findchar(pll prev, pll cur) {
        if(prev.ff == cur.ff) {
                if(prev.ss < cur.ss) return 'L';
                else return 'R';
        } else {
                if(prev.ff < cur.ff) return 'U';
                else return 'D';
        }
}

void fillans(vector<ll>& cycle, vector<vector<char>>& ans) {
        int len = cycle.size();
        ll n = sz(ans);
        for(int i = 1; i < len; i++) {
                pll cur = decode(cycle[i], n);
                pll prev = decode(cycle[i - 1], n);
                char ch = findchar(prev, cur);
                ans[cur.ff][cur.ss] = ch;
        }
}

vector<ll> cycle;

void dfs(ll node, ll par, ll n, vector<vector<char>>& ans) {
        vis[node] = 1;
        for(auto child : g[node]) {
                if(!vis[child]) {
                        pll cur = decode(child, n);
                        pll prev = decode(node, n);
                        char ch = findchar(prev, cur);
                        ans[cur.ff][cur.ss] = ch;
                        dfs(child, node, n, ans);
                }
        }
}

void dfs2(ll node, vector<vector<char>>& ans, pll tar, vector<vector<pll>>& a) {
        vis[node] = 1;
        loop(k, 0, 3) {
                ll i, j;
                tie(i, j) = decode(node, sz(ans));
                ll ii = i + dx[k];
                ll jj = j + dy[k];
                if(valid(ii, jj, sz(ans))) {
                        ll child = create(ii, jj, sz(ans));
                        if(!vis[child]) {
                                pll cur = decode(child, sz(ans));
                                pll prev = decode(node, sz(ans));
                                if(a[cur.ff][cur.ss] == tar) {
                                        char ch = findchar(prev, cur);
                                        ans[cur.ff][cur.ss] = ch;
                                        dfs2(child, ans, tar, a);
                                }
                        }
                }
        }
}

void solve() {
        ll n;
        cin >> n;
        vector<vector<pll>> a(n, vector<pll>(n));
        for(ll i = 0; i < n; i++) {
                for(ll j = 0; j < n; j++) {
                        cin >> a[i][j].ff >> a[i][j].ss;
                }
        }

        // id ... 1 = cycle, 2 = fix, 3 = general
        vector<vector<ll>> info(n, vector<ll>(n));
        loop(i, 0, n - 1) {
                loop(j, 0, n - 1) {
                        if(a[i][j].ff == -1) info[i][j] = 1;
                        else if(a[i][j].ff - 1 == i && a[i][j].ss - 1 == j) info[i][j] = 2;
                        else info[i][j] = 3;
                }
        }

        // checking for cycle, id = 1
        loop(i, 0, n - 1) {
                loop(j, 0, n - 1) {
                        loop(k, 0, 3) {
                                ll ii = i + dx[k], jj = j + dy[k];
                                if(valid(ii, jj, n) && info[i][j] == 1 && info[ii][jj] == 1) {
                                        ll u = create(i, j, n);
                                        ll v = create(ii, jj, n);
                                        g[u].pb(v);
                                        g[v].pb(u);
                                }
                        }
                }
        }

        vector<vector<char>> ans(n, vector<char>(n, '#'));
        loop(p, 0, n - 1) {
                loop(q, 0, n - 1) {
                        ll node = create(p, q, n);
                        if(!vis[node] && info[p][q] == 1) {
                                loop(k, 0, 3) {
                                        ll pp = p + dx[k];
                                        ll qq = q + dy[k];
                                        if(valid(pp, qq, n) && info[pp][qq] == 1) {
                                                ll child = create(pp, qq, n);
                                                vis[child] = 1;
                                                vis[node] = 1;
                                                ans[p][q] = findchar({pp, qq}, {p, q});
                                                ans[pp][qq] = findchar({p, q}, {pp, qq});
                                                dfs(node, -1, n, ans);
                                                dfs(child, -1, n, ans);
                                        }
                                }
                        }
                }
        }

        loop(i, 0, n - 1) {
                loop(j, 0, n - 1) {
                        if(info[i][j] == 2) {
                                ans[i][j] = 'X';
                                ll node = create(i, j, n);
                                vis[node] = 1;
                                dfs2(node, ans, {i + 1, j + 1}, a);
                        }
                }
        }

        loop(i, 0, n - 1) {
                loop(j, 0, n - 1) {
                        if(ans[i][j] == '#') {
                                cout << "INVALID" << endl;
                                return;
                        }
                }
        }

        cout << "VALID" << endl;
        loop(i, 0, n - 1) {
                loop(j, 0, n - 1) {
                        cout << ans[i][j];
                }
                cout << endl;
        }
}

signed main () {
        #ifdef FARHAN
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
        FIO;
        // TC(t)
        solve();
        return 0;
}