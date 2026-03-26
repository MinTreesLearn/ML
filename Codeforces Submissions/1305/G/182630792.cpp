#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 18;

ll n, ans, a[1 << N], cnt[1 << N];

struct dsu
{
    vector < int > link, rang;

    dsu(int sz)
    {
        link.resize(sz + 1);
        rang.resize(sz + 1, 1);
        for (int i = 0; i <= sz; i++) link[i] = i;
    }

    int get(int v)
    {
        return (v == link[v] ? v : link[v] = get(link[v]));
    }

    int unite(int v, int u)
    {
        int lv = v, lu = u;
        v = get(v); u = get(u);
        if (v == u) return 0;
        if (rang[v] > rang[u]) swap(v, u);
        link[v] = u; rang[u] += v;
        cnt[lv] = cnt[lu] = 1;
        return 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    cnt[0] = 1;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans -= a[i];
        cnt[a[i]]++;
    }

    dsu G(1 << N);
    for (int i = (1 << N) - 1; i >= 0; i--) {
        int j = i;
        do {
            if (cnt[j] && cnt[i ^ j]) ans += (cnt[j] + cnt[i ^ j] - 1) * (ll)i * G.unite(j, i ^ j);
            j = (j - 1) & i;
        } while (j);
    }

    cout << ans;
}

