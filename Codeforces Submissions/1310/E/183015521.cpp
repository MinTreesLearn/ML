// LUOGU_RID: 95985746
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define eb emplace_back
#define ef emplace_front
#define lowbit(x) (x & (-x))
#define ti chrono::system_clock::now().time_since_epoch().count()
#define Fin(x) freopen(x, "r", stdin)
#define Fout(x) freopen(x, "w", stdout)
#define Fio(x) Fin(x".in"), Fout(x".out");
// #define SGT
// #define int long long // int main() -> signed
// #define PAIR
#define ll long long
#ifdef PAIR
#define fi first
#define se second
#endif
#ifdef SGT
#define lson (p << 1)
#define rson (p << 1 | 1)
#define mid ((l + r) >> 1)
#endif
const int maxn = 2022, mod = 998244353;
int n, k, f[maxn], ans;
vector<int> cur, a, b;
bool check(){
    a = cur;
    // printf("checking ");
    // for(int i : a) printf("%d ", i);
    // puts("");
    for(int _ = 1; _ < k; _++){
        reverse(a.begin(), a.end()); ll sum = 0;
        for(int i = 0; i < (int)a.size(); i++) sum += 1ll * (i + 1) * a[i];
        if(sum > n) return  0;
        if(_ == k - 1) break;
        b.clear();
        for(int i = 0; i < (int)a.size(); i++) for(int j = 1; j <= a[i]; j++) b.pb(i + 1);
        a = b;
    }
    return 1;
}
void dfs(int dep, int x){
    // printf("dfs %d %d\n", dep, x);
    for(int i = x; ; i++){
        cur.pb(i);
        int res = check();
        // printf("%d - %d\n", i, res);
        if(res) ans++, dfs(dep + 1, i);
        cur.ppb();
        if(!res) return;
    }
}
signed main(){
    scanf("%d%d", &n, &k), f[0] = 1;
    if(k == 1){
        for(int i = 1; i <= n; i++) for(int j = i; j <= n; j++) f[j] = (f[j] + f[j - i]) % mod;
        for(int i = 1; i <= n; i++) ans = (ans + f[i]) % mod;
    }else if(k == 2){
        for(int i = 1; i * (i + 1) / 2 <= n; i++) for(int j = i * (i + 1) / 2; j <= n; j++) f[j] = (f[j] + f[j - i * (i + 1) / 2]) % mod;
        for(int i = 1; i <= n; i++) ans = (ans + f[i]) % mod;
    }else dfs(1, 1);
    printf("%d\n", ans);
    return 0;
}