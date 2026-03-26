#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//long long may cause TLE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#define int ll

const int MAXN = 5e3 + 2;
vector<int> g[MAXN];
int par[MAXN],d[MAXN];

int mp[MAXN][MAXN];

void dfs(int v, int pr)
{
    par[v] = pr;
    for (auto to : g[v]) {
        if (to!=pr) {
            d[to] = d[v] + 1;
            dfs(to,v);
        }
    }
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> edges;
    for (int i=1,a,b;i<n;i++) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back({a,b});
    }
    dfs(0,0);
    vector<tuple<int,int,int>> Q;
    int TT;
    cin >> TT;
    while (TT--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        Q.push_back({a,b,c});
        while (a!=b) {
            if (d[a] > d[b]) mp[a][par[a]] = mp[par[a]][a] = max(mp[a][par[a]],c),  a = par[a];
            else mp[b][par[b]] = mp[par[b]][b] = max(mp[b][par[b]],c) , b = par[b];
        }
    }
    for (auto &[a,b]:edges) {
        if (mp[a][b] == 0) mp[a][b] = mp[b][a] = 1e6;
    }
    int ok = 1;
    for (auto [a,b,c] : Q) {
        int is = 0;
        while (a!=b) {
            if (d[a] > d[b]) {
                if (mp[a][par[a]] < c) ok = 0;
                if (mp[a][par[a]] == c) is = 1;
                a = par[a];
            }
            else {
                if (mp[b][par[b]] < c) ok = 0;
                if (mp[b][par[b]] == c) is = 1;
                b = par[b];
            }
        }
        ok&=is;
    }
    if (!ok) {
        cout << -1;
        return 0;
    }
    for (auto [a,b]:edges) cout << mp[a][b] << " ";


}
