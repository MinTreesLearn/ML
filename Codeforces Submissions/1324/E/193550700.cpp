#include <bits/stdc++.h>
#pragma GCC optimize(0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline ll read()
{
    ll X = 0, w = 0; char ch = 0;
    while (!isdigit(ch)) { w |= ch == '-'; ch = getchar(); }
    while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return w ? -X : X;
}

inline void write(ll x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;

using namespace std;

void solve() {
    int n = read(), h = read(), l = read(), r = read();
    int dp[n + 1][h];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    int pres[n + 1];
    pres[0] = 0;
    for (int i = 1; i <= n; i++) {
        pres[i] = (pres[i - 1] + read()) % h;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            if (dp[i][j] >= 0) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (l <= (pres[i + 1] - j + h) % h && (pres[i + 1] - j + h) % h <= r));
                dp[i + 1][(j + 1) % h] = max(dp[i + 1][(j + 1) % h], dp[i][j] + (l <= (pres[i + 1] - j - 1 + h + h) % h && (pres[i + 1] - j - 1 + h + h) % h <= r));
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < h; j++) {
        if (dp[n][j] > ans) ans = dp[n][j];
    }
    write(ans); putchar('\n');
}

int main() {
    int t = 1;
    while (t--) solve();
}
