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
const int N = 2e3 + 10;
int f[N << 1][N], n, m, num[N], s[N], c[N << 1];
int main() {
    //file("");
    read(n), read(m);
    for(int i = 1; i <= n; i++) read(num[i]);
    for(int i = 1; i <= n; i++) read(s[i]);
    for(int i = 1; i <= n + m; i++) read(c[i]);
    for(int i = 1; i <= n + m; i++) {
        f[i][0] = 0;
        for(int j = 1; j <= n; j++)
            f[i][j] = INT_MIN / 2;
    }
    for(int i = n; i >= 1; i--) {
        for(int j = n; j >= 1; j--)
            f[num[i]][j] = max(f[num[i]][j], f[num[i]][j - 1] - s[i] + c[num[i]]);
        int len = n;
        for(int j = num[i]; j < n + m; j++, len >>= 1)
            for(int k = 0; k <= len; k++)
                f[j + 1][k / 2] = max(f[j + 1][k / 2], f[j][k] + c[j + 1] * (k / 2));
    }
    cout << f[n + m][0] << endl;
    #ifdef _MagicDuck
        fprintf(stderr, "# Time: %.3lf s", (double)clock() / CLOCKS_PER_SEC);
    #endif
    return 0;
}