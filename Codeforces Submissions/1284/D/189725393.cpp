#include <bits/stdc++.h>
#include "stdio.h"

using namespace std;

#define SZ(s) ((int)s.size())
#define all(x) (x).begin(), (x).end()
#define lla(x) (x).rbegin(), (x).rend()
#define bpc(x) __builtin_popcount(x)
#define bpcll(x) __builtin_popcountll(x)
#define MP make_pair
#define endl '\n'

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
const int MOD = 1e9 + 7;
const int N = 1e6 + 3e2;

#define pll pair<ll, ll>

vector<pll> get_hash(vector<int> a, vector<int> b){
    int n = (int)a.size();

    vector<int> pl(n), pr(n);
    iota(all(pl), 0);
    iota(all(pr), 0);

    sort(all(pl), [&](int i, int j){
        return a[i] > a[j];
    });

    sort(all(pr), [&](int i, int j){
        return b[i] < b[j];
    });

    vector<ll> val{100003, 1000000007};
    vector<ll> mod{998244353, 1000678447};
    vector<vector<ll>> pw(2, vector<ll>(n));
    pw[0][0] = pw[1][0] = 1;
    for (int i = 1; i < n; i++){
        pw[0][i] = pw[0][i - 1] * val[0] % mod[0];
        pw[1][i] = pw[1][i - 1] * val[1] % mod[1];
    }

    function<void(pll&, pll)> add = [&](pll &x, pll y){
        (x.first += y.first) %= mod[0];
        (x.second += y.second) %= mod[1];
    };

    vector<pll> lf(n), rg(n);
    for (int i = 0; i < n; i++){
        int j = pl[i];
        lf[i] = MP(pw[0][j], pw[1][j]);
        if (i > 0) add(lf[i], lf[i - 1]);
    }

    for (int i = 0; i < n; i++){
        int j = pr[i];
        rg[i] = MP(pw[0][j], pw[1][j]);
        if (i > 0) add(rg[i], rg[i - 1]);
    }

    vector<pll> res(n);
    for (int i = 0; i < n; i++){
        int l, r;
        l = 0, r = n - 1;
        int ind1 = -1;
        while (l <= r){
            int m = (l + r) >> 1;
            if (a[pl[m]] > b[i]){
                ind1 = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        if (ind1 != -1) add(res[i], lf[ind1]);

        l = 0, r = n - 1;
        int ind2 = -1;
        while (l <= r){
            int m = (l + r) >> 1;
            if (b[pr[m]] < a[i]){
                ind2 = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        if (ind2 != -1) add(res[i], rg[ind2]);
    }

    return res;
}

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<pll> h1 = get_hash(a, b);
    vector<pll> h2 = get_hash(c, d);

    // for (int i = 0; i < n; i++){
    //     cout << h1[i].first << ' ' << h1[i].second << ' ';
    //     cout << h2[i].first << ' ' << h2[i].second << ' ';
    //     cout << endl;
    // }

    cout << (h1 == h2 ? "YES" : "NO") << endl;

}

int main(){
    clock_t startTime = clock();
    ios_base::sync_with_stdio(false);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int test_cases = 1;
    // cin >> test_cases;

    for (int test = 1; test <= test_cases; test++){
        solve();
    }

    cerr << "Time: " << int((double) (clock() - startTime) / CLOCKS_PER_SEC * 1000) << " ms" << endl;

    return 0;
}
