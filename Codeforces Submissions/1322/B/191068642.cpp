// LUOGU_RID: 100767713
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;
#define ll long long
#define pii pair<int,int>
//struct Edge {
//	int from, to, nex;
//}edge[400010];
//int tot, head[200010];
//void add(int u, int v) {
//	edge[++tot] = { u,v,head[u] };
//	head[u] = tot;
//}
ll n;
void solve()
{
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> b(n + 1);
    ll ans = 0;
    for (int k = 0; k <= 25; k++) {
        for (int i = 1; i <= n; i++) {
            b[i] = (a[i] % (1ll << (k+1)));
        }
        sort(b.begin() + 1, b.end());
        ll cnt = 0, cnt2 = 0;
        ll l = 1, r = 1;
        for (int i = n; i; i--) {
            /*ll tmp = (1ll << (k - 1));
            if (k == 0) tmp = 0;*/
            while ( l <= n&&b[l] + b[i] < (1ll<<k))  l++;
            while ( r <= n&&b[r] + b[i] <= ((1ll << (k+1)) - 1) ) r++;
            cnt += r - l - (i >= l && i < r);
        }
        l = r = 1;
        for (int i = n; i; i--) {
            while (l <= n&&b[l] + b[i] < ((1ll << (k + 1))+(1ll<<k)) ) l++;
            while (r <= n&&(b[r] + b[i] <= ((1ll << (k+2)) -1))) r++;
            cnt2 += r - l - (i >= l && i < r);
        }
        cnt = (cnt >> 1) & 1;
        cnt2 = (cnt2 >> 1) & 1;
        if (cnt ^ cnt2)
            ans += (1ll << k);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();

    return 0;
}
/*



*/