/// Do the solution on the paper
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0;i < n;++i)
#define FOR(i, l, r) for(int i = l; i <= r; ++i)
#define FOD(i, r, l) for(int i = r; i >= l; --i)
#define dem(x) __builtin_popcount(x)
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define pb emplace_back
#define SZ(x) (int)((x).size())
#define fi first
#define se second
typedef pair<int,int> ii;
//const int dx[4] = {-1, 0, 0, 1};
//const int dy[4] = {0, -1, 1, 0};
//const int base = 311;
const int mod = 1e9 + 7;
const int N = 5e3 + 5;
int n, m, s[N], l[N], r[N], cntL[N], cntR[N];
int f[N], h[N], cntB[N], ans1, ans2 = 1;
vector<int> pos[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    if(fopen("c.inp", "r")){
        freopen("c.inp", "r", stdin);
//        freopen("c.out", "w", stdout);
    }
    cin >> n >> m;
    FOR(i, 1, n)cin >> s[i], pos[s[i]].pb(i);
    FOR(i, 1, m){
        cin >> f[i] >> h[i];
        if(SZ(pos[f[i]]) >= h[i]){
            l[i] = pos[f[i]][h[i]-1];
            r[i] = pos[f[i]][SZ(pos[f[i]])-h[i]];
        }
    }
    FOR(t, 0, n){
        int res1 = 0, res2 = 1;
        if(t){
            int id = -1;
            FOR(i, 1, m)if(l[i] == t)id = f[i];
            if(id == -1)continue;
            int cnt = 0;
            FOR(i, 1, m)if(f[i] == id && l[i] != t && r[i] > t)cnt++;
            res1++;
            if(cnt){
                res1++;
                res2 = cnt;
            }
        }
        memset(cntL, 0, sizeof cntL);
        memset(cntR, 0, sizeof cntR);
        memset(cntB, 0, sizeof cntB);
        FOR(i, 1, m)if(l[i]){
            if(l[i] <= t)cntL[f[i]]++;
            if(r[i] > t)cntR[f[i]]++;
            if(l[i] <= t && r[i] > t)cntB[f[i]]++;
        }
        FOR(i, 1, n){
            if(t && s[t] == i)continue;
            int cnt = cntL[i] * cntR[i] - cntB[i];
            if(cnt){
                res1 += 2;
                (res2 *= cnt) %= mod;
            }
            else if(cntL[i] + cntR[i]){
                res1++;
                (res2 *= cntL[i] + cntR[i]) %= mod;
            }
        }
        if(res1 > ans1)
            ans1 = res1, ans2 = res2;
        else if(res1 == ans1)(ans2 += res2) %= mod;
    }
    if(ans1 == 0)ans2 = 1;
    cout << ans1 << ' ' << ans2;
}
