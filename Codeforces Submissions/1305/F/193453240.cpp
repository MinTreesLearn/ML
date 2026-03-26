// LUOGU_RID: 102089595
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
#define int long long // int main() -> signed
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
const int maxn = 2e5 + 10;
int n, a[maxn], ans;
set<int> st;
mt19937 rnd(ti);
void solve(int x){
    for(int i = 2; i * i <= x; i++) if(x % i == 0){
        st.insert(i); 
        while(x % i == 0) x /= i;
    }
    if(x > 1) st.insert(x);
}
int calc(int x){
    int ret = 0;
    for(int i = 1; i <= n; i++){
        int k = a[i] / x * x;
        ret += min(k ? a[i] - k : n, k + x - a[i]);
    }
    return ret;
}
signed main(){
    scanf("%lld", &n), ans = n;
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for(int _ = 1; _ <= 50; _++){
        int i = rnd() % n + 1;
        solve(a[i]), solve(a[i] + 1), solve(a[i] - 1);
    }
    for(int i : st) ans = min(ans, calc(i));
    printf("%lld\n", ans);
    return 0;
}