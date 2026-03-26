#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
template <typename T> inline void read(T &F) {
    int R = 1; F = 0; char CH = getchar();
    for(; !isdigit(CH); CH = getchar()) if(CH == '-') R = -1;
    for(; isdigit(CH); CH = getchar()) F = F * 10 + CH - 48;
    F *= R;
}
inline void file(string str) {
    freopen((str + ".in").c_str(), "r", stdin);
    freopen((str + ".out").c_str(), "w", stdout);
}
const int N = 5e3 + 10;
const LL mod = 1e9 + 7;
int n, m, ai[N]; vector<int> pos[N], f[N]; int g[N][N];
int main() {
    //file("test");
    read(n), read(m);
    for(int i = 1; i <= n; i++) {
        int x; read(x); pos[x].emplace_back(i);
        ai[i] = x;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            g[i][j] = g[i - 1][j];
        g[i][ai[i]]++;
    }
    vector<int> c;
    for(int i = 1; i <= m; i++) {
        int x, y; read(x), read(y);
        f[x].emplace_back(y);
        if(pos[x].size() >= y)
            c.emplace_back(pos[x][y - 1]);
    }
    int ans = 0; LL res = 1;
    for(int i = 1; i <= n; i++) sort(f[i].begin(), f[i].end());
    for(int i = 1; i <= n; i++) {
        int p = 0;
        for(int j : f[i])
            if(pos[i].size() >= j) p++;
        if(p) ans++, res = res * p % mod;
    }
    for(int i : c) {
        LL p = 1; int cnt = 1;
        for(int j = 1; j <= n; j++) {
            int a = g[i][j], b = pos[j].size() - g[i][j];
            int x = upper_bound(f[j].begin(), f[j].end(), a) - f[j].begin();
            int y = upper_bound(f[j].begin(), f[j].end(), b) - f[j].begin();
             
            if(ai[i] == j) {
                if(b >= a) y--;
                if(y) cnt++, p = p * y % mod;
                continue;
            }
            a = x, b = y;
            if(a > b) swap(a, b);
            if(!b) continue;
            else if(b == 1 || a == 0) {
                cnt++;
                if(a) p = p * 2 % mod;
                else p = p * b % mod;
            }
            else {
                b -= a; cnt += 2;
                p = p * (1LL * a * (a - 1) % mod + 1LL * a * b % mod) % mod;
            }
        }
        if(cnt > ans) {
            ans = cnt, res = p;
        }
        else if(cnt == ans) res = (res + p) % mod;
    }
    cout << ans << " " << res << '\n';
    #ifdef _MagicDuck
        fprintf(stderr, "# Time: %.3lf s", (double)clock() / CLOCKS_PER_SEC);
    #endif
    return 0;
}