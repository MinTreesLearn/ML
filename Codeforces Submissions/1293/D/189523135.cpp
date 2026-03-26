#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

int read() {
    int op = 1, a = 0; char c = getchar();
    for (; c < '0' || c > '9'; c = getchar()) if (c == '-') op = -1;
    for (; c >= '0' && c <= '9'; c = getchar()) a = a * 10 + c - '0';
    return op * a;
}

int sx, sy, n;
int x, y, a, b, c, d;

void solve() {
    x = read(), y = read(), a = read(), b = read(), c = read(), d = read();
    sx = read(), sy = read(), n = read();
    int ans = 0;
    int res = n;
    int tx, ty, pox, poy, cos;
    for (int i = 1, tmp; ; i++) {
        tmp = 0;
        res = n;
        tx = x, ty = y;
        pox = sx, poy = sy;
        // if (pox == tx && poy == ty) tmp = 1;
        for (int j = i; ; j++) {
            cos = abs(pox - tx) + abs(poy - ty);
            if (cos <= res) {
                res -= cos;
                tmp++;
                pox = tx, poy = ty;
            }
            else break;
            tx = a * tx + c;
            ty = b * ty + d;
        }
        ans = max(ans, tmp);
        tmp = 0;
        res = n;
        tx = x, ty = y;
        pox = sx, poy = sy;
        for (int j = i; j; j--) {
            cos = abs(pox - tx) + abs(poy - ty);
            if (cos <= res) {
                res -= cos;
                tmp++;
                pox = tx, poy = ty;
            }
            else break;
            tx = (tx - c) / a;
            ty = (ty - d) / b;
        }
        ans = max(ans, tmp);
        if (x >= sx && y >= sy && !tmp) break;
        x = a * x + c;
        y = b * y + d;
    }
    cout << ans << '\n';
}

signed main() {
    int T = 1;
    for (; T; T--) solve();
    return 0;
}