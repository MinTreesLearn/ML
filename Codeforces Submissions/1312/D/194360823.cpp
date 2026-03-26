#include<bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
#define vt vector
#define pb push_back
#define eb emplace_back
#define INF 0x3f3f3f3f3f3f3f3f
#define PI pair<int, int>
#define rep(i, from, to) for (int i = from; i <= to; ++i)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("avx,avx2,fma")
const int mxn = 2e5 + 5, MOD = 998244353;

//枚舉最大的數
//最大的數為i 有Ci - 1取n - 2
//每種會有n - 2種
//1 1 2 3 => 1231 1321 n - 2?
//1 2 2 3 4 => 12342 12432 24321 13421

int n, m, fac[mxn];
int fast_power(int a, int b, int MOD = MOD){
    int res = 1;
    while (b){
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void init() {
    fac[0] = 1;
    rep(i, 1, 2e5) fac[i] = fac[i - 1] * i % MOD;
}
int C(int n, int r) {
    if (n < r) return 0;
    return fac[n] * fast_power(fac[r], MOD - 2) % MOD * fast_power(fac[n - r], MOD - 2) % MOD;
}
signed main(void){
    #ifndef ONLINE_JUDGE
    freopen("C:\\Code\\C\\input.txt","r",stdin);
    freopen("C:\\Code\\C\\output.txt","w",stdout);
    #endif
    fio
    cin >> n >> m;
    init();
    int ans = 0;
    rep(i, 1, m) {
        ans = (ans + C(i - 1, n - 2) * fast_power(2, n - 2) % MOD * (n - 2) % MOD) % MOD;
    }
    cout << ans * fast_power(2, MOD - 2) % MOD << '\n';
}