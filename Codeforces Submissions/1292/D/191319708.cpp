#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vp = vector <pii>;
using vl = vector<ll>;

const int inf = INT_MAX;
const ll linf = LLONG_MAX;

const int PI = 669;
const int MX = 5000;

int main() {
    int n;
    scanf("%d", &n);

    array <int, PI> primes;
    vi spf(MX+1), w(MX+1);
    vector <array<int, PI>> info(MX+1);
    int ptr = 0;

    for(int i = 2; i <= MX; i++) {
        if(!spf[i]) {
            primes[ptr++] = i;
            for(int j = i; j <= MX; j += i)
                spf[j] = i;
        }
    }

    vi rel, a(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] == 0) a[i] = 1;
        if(!w[a[i]])
            rel.pb(a[i]);
        w[a[i]]++;
    }

    reverse(all(primes));
    for(int v : rel) {
        ptr = 0;
        for(int p : primes) {
            int x = v;
            int r = 0;
            while(x) {
                r += x / p;
                x /= p;
           }
           info[v][ptr++] = r;
        }
    }

    vector <array<int, PI>> ancestor_info;
    sort(all(rel), [&](int u, int v) {
            return info[u] < info[v];
         });

    for(int v : rel) {
        ancestor_info.pb(info[v]);
    }

    auto lca = [&](array <int, PI> &u, array <int, PI> &v) -> array<int, PI> {
        array <int, PI> ret;
        for(int j = 0; j < PI; j++) ret[j] = 0;
        for(int i = 0; i < PI; i++) {
            if(u[i] == v[i]) {
                ret[i] = u[i];
            }
            else {
                ret[i] = min(u[i], v[i]);
                break;
            }
        }
        return ret;
    };
    for(int i = 1; i < sz(rel); i++) {
        auto lca_info = lca(info[rel[i - 1]], info[rel[i]]);
        ancestor_info.pb(lca_info);
    }

    sort(all(ancestor_info));
    ancestor_info.resize(unique(all(ancestor_info)) - begin(ancestor_info));

    vi sub(sz(ancestor_info));
    vector <vp> adj(sz(ancestor_info));

    auto lb = [&](array <int, PI> &v_info) -> int {
        return lower_bound(all(ancestor_info), v_info) - begin(ancestor_info);
    };

    for(int v : rel) {
        sub[lb(info[v])] += w[v];
    }

    for(int i = 1; i < sz(ancestor_info); i++) {
        auto lca_info = lca(ancestor_info[i - 1], ancestor_info[i]);
        int w = 0;
        for(int j = 0; j < PI; j++) {
            w += ancestor_info[i][j] - lca_info[j];
        }
        int idx = lb(lca_info);
        adj[idx].pb({i, w});
    }

    vl below(sz(ancestor_info));
    ll ans = linf;
    auto dfs1 = [&](auto &&self, int u) -> void {
        for(auto [v, w] : adj[u]) {
            self(self, v);
            sub[u] += sub[v];
            below[u] += below[v] + 1ll * sub[v] * 1ll * w;
        }
    };
    dfs1(dfs1, 0);
    auto dfs2 = [&](auto &&self, int u, ll above) -> void {
        for(auto [v, w] : adj[u]) {
            self(self, v, above + below[u] - (below[v] + 1ll * sub[v] * 1ll * w)
                    + 1ll * (n - sub[v]) * 1ll * w);
        }
        ans = min(ans, below[u] + above);

    };
    dfs2(dfs2, 0, 0);
    printf("%lld\n", ans);



    return 0;
}
