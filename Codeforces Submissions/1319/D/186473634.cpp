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
vi g[200005], tg[200005];
int a[200005], dt[200005];
bool vt[200005];

void solve() {
    int n, m, k, x, y; 
    cin >> n >> m;
    fri(m) {
        cin >> x >> y;
        g[x].pb(y);
        tg[y].pb(x);
    }
    cin >> k; fra(k)
    int s = a[0], t = a[k - 1];
    queue<int> q;
    q.push(t); vt[t] = 1;
    while(!q.empty()) {
        x = q.front(); q.pop();
        for(int y : tg[x]) {
            if(vt[y]) continue;
            q.push(y); vt[y] = 1;
            dt[y] = dt[x] + 1;
        }
    }
    // print(dt, n + 1);
    int mini = 0, maxi;
    fri(k - 1) {
        if(dt[a[i]] < dt[a[i + 1]] + 1) {
            // dbg(i)
            mini++, maxi++;
        } else {
            for(int v : g[a[i]]) {
                if(v != a[i + 1] && dt[v] + 1 == dt[a[i]]) {
                    maxi++;
                    break;
                }
            }
        }
    }
    cout << mini << ' ' << maxi << endl;
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
