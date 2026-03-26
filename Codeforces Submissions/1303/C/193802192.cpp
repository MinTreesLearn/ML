#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

bool dfs(int vertex, v64 graph[], vector <bool> &visited, int parent) {
    bool isLoopExists = false;
    // cout<<vertex<<" ";
    visited[vertex] = true;
    for(auto child : graph[vertex]) {
        if((visited[child]) && (child == parent)) continue;
        if(visited[child]) return true;
        isLoopExists |= dfs(child, graph, visited, vertex);
    }

    return isLoopExists;
}

void dfs1(ll node, ll par, v64 g[], v64 &ans) {
    ans.pb(node);
    for(auto child : g[node]) {
        if(child == par) continue;
        dfs1(child, node, g, ans);
    }
}

void solve()
{
    string s;
    cin>>s;
    ll n = sz(s);
    if(n == 1) {
        cout<<"YES\n";
        cout<<"abcdefghijklmnopqrstuvwxyz\n";
        return;
    }
    set <p64> st;
    v64 g[26];
    forn(i, n-1) {
        p64 p = {(s[i] - 'a'), (s[i+1] - 'a')};
        p64 p1 = {p.se, p.fi};
        if(st.find(p) == st.end()) {
            st.insert(p);
            st.insert(p1);
            g[p.fi].pb(p.se);
            g[p.se].pb(p.fi);
        }
    }
    vector <bool> vis(26, false);
    if(dfs((s[0] - 'a'), g, vis, -1)) {
        cout<<"NO\n";
        return;
    }
    ll flag = 0;
    for(ll i = 0; i < 26; i++) {
        if(g[i].size() > 2) {
            flag = 1;
            break;
        }
    }
    if(flag) {
        cout<<"NO\n";
        return;
    }
    else {
        cout<<"YES\n";
        ll x = 1;
        for(ll i = 0; i < 26; i++) {
            if(g[i].size() == 1) {
                x = i;
                break;
            }
        }
        v64 ans;
        dfs1(x, -1, g, ans);
        for(auto it : ans) {
            cout<<(char)('a' + it);
        }
        for(ll i = 0; i < 26; i++) {
            if(vis[i] == 0) cout<<(char)('a' + i);
        }
        cout<<ln;
    }

}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        // 		cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}