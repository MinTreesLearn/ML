/////////////////////include/////////////////////
//#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip>
#include <bitset>
#include <stdio.h>
#include <climits>
#include <numeric>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <typename T>
//using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/////////////////////define/////////////////////
#define ci(x) if(x) cout << "YES" << '\n'; else cout << "NO" << '\n';
#define cii(x) if(check(x))
#define MOD 1000000007
#define MOD2 998244353
#define oo 1e9
#define ool 1e18L
#define pii pair<int, int>
#define pll pair<long long, long long>
#define mii map<int, int>
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vll vector <ll>
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define pob pop_back
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define alll(x) (x), (x) + n
#define clr(x) (x).clear();
#define fri(x) for(int i = 0; i < x; ++i)
#define frj(x) for(int j = 0; j < x; ++j)
#define frp(x) for(int p = 0; p < x; ++p)
#define frr(a, b) for(int i = a; i < b; ++i)
#define frrj(a, b) for(int j = a; j < b; ++j)
#define fra(x) for(int i = 0; i < x; ++i) cin >> a[i];
#define frb(x) for(int i = 0; i < x; ++i) cin >> b[i];
#define frs(x) for(auto it = x.begin(); it != x.end(); ++it)
#define fr(x) for(auto it : x) //el
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define dbg(x) cerr << #x << ": " << x << endl;
#define ce(x) cout << x << endl;
#define uniq(x) x.resize(unique(all(x)) - x.begin()); //make all one after sorting
#define blt __builtin_popcount
/////////////////////print array, vector, deque, set, multiset, pair, map /////////////////////
void print(long long t) {cerr << t;}
void print(int t) {cerr << t;}
void print(string t) {cerr << t;}
void print(char t) {cerr << t;}
void print(double t) {cerr << t;}
void print(long double t) {cerr << t;}
void print(unsigned long long t) {cerr << t;}
template <class T, class V> void print(pair <T, V> p) {cerr << "{"; print(p.first); cerr << ","; print(p.second); cerr << "}";}
template <class T, class V> void print(T v[],V n) {cerr << "["; for(int i = 0; i < n; i++) {print(v[i]); cerr << " "; } cerr << "]"; cout << endl;}
template <class T> void print(vector <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]"; cout << endl;}
template <class T> void print(set <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]"; cout << endl;}
template <class T> void print(multiset <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]"; cout << endl;}
template <class T> void print(stack <T> v) {cerr << "[ "; stack<T> s = v; while(s.size()) {T i = s.top(); print(i); s.pop(); cerr << " ";} cerr << "]"; cout << endl;}
template <class T> void print(queue <T> v) {cerr << "[ "; queue<T> s = v; while(s.size()) {T i = s.front(); print(i); s.pop(); cerr << " ";} cerr << "]"; cout << endl;}
template <class T> void print(deque <T> v) {cerr << "[ "; deque<T> s = v; while(s.size()) {T i = s.front(); print(i); s.pop_front(); cerr << " ";} cerr << "]"; cout << endl;}
template <class T, class V> void print(map <T, V> v) {cerr << "[ "; for (auto i : v) {print(i); cerr << " ";} cerr << "]"; cout << endl;}
template <class T, class V> void print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {print(i); cerr << " ";} cerr << "]"; cout << endl;}
/////////////////////code/////////////////////
struct segtree {
    int size;
    struct node{
        long long val, maxi; // = -1e10;
    };
    vector<node> tree;
    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size - 1);
    }
    void propogade(int x, int lx, int rx) { 
        if(tree[x].val == 0 || rx - lx == 1) return;
        int m = (lx + rx) / 2;
        tree[2 * x + 1].val += tree[x].val;
        tree[2 * x + 1].maxi += tree[x].val;
        tree[2 * x + 2].val += tree[x].val;
        tree[2 * x + 2].maxi += tree[x].val;
        tree[x].val = 0;
    }
    void upd(int l, int r, int v, int x, int lx, int rx) {
        propogade(x, lx, rx);
        if(l >= rx || r <= lx) return;
        if(lx >= l && rx <= r) {
            tree[x].val += v;
            tree[x].maxi += v;
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m);
        upd(l, r, v, 2 * x + 2, m, rx);
        tree[x].maxi = max(tree[2 * x + 2].maxi, tree[2 * x + 1].maxi);
    }
    void upd(int l, int r, int v) {
        upd(l, r, v, 0, 0, size);
    }
    long long qry(int l, int r, int x, int lx, int rx) {
        propogade(x, lx, rx);
        if(l >= rx || r <= lx) return -1e10;
        if(lx >= l && rx <= r) return tree[x].maxi;
        int m = (lx + rx) / 2;
        long long s1 = qry(l, r, 2 * x + 1, lx, m);
        long long s2 = qry(l, r, 2 * x + 2, m, rx);
        return max(s1, s2);
    }
    long long qry(int l, int r) {
        return qry(l, r, 0, 0, size);
    }
};
 
pll a[200005], b[200005];
pair<pll, ll> t[200005];

void solve() {
    int n, m, p; cin >> n >> m >> p;
    fri(n) cin >> a[i].ff >> a[i].ss;
    fri(m) cin >> b[i].ff >> b[i].ss;
    fri(p) cin >> t[i].ff.ff >> t[i].ff.ss >> t[i].ss;
    sort(a, a + n);
    sort(b, b + m);
    sort(t, t + p);
    int id = 0;
    ll ans = -1e18;
    segtree st; st.init(m + 1);
    fri(m) st.upd(i, i + 1, -b[i].ss);
    fri(n) {
        while(id < p && t[id].ff.ff < a[i].ff) {
            pll pa = {t[id].ff.ss, 1e9};
            auto it = ub(b, b + m, pa) - b;
            if(it != m) 
                st.upd(it, m, t[id].ss);
            id++;
        }
        ans = max(ans, -a[i].ss + st.qry(0, m));
    }
    cout << ans;
}

int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

//	           ♥ ♥ ♥  ♥  ♥    ♥   ♥    ♥
//	           ♥      ♥  ♥     ♥ ♥    ♥ ♥
//	           ♥ ♥ ♥  ♥  ♥      ♥    ♥   ♥
//	           ♥      ♥  ♥      ♥   ♥ ♥ ♥ ♥
//	           ♥      ♥  ♥ ♥ ♥  ♥  ♥       ♥
//
//        God loves Fil, Fil accepts God's will
