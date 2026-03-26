#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10;
const long long mod = 998244353;
inline long long solve(void);
int x[maxn], y[maxn], n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
    printf("%lld\n", solve());
    return 0;
}

const int maxl = 35, maxs = 25;
long long dp[maxl][maxs][maxs][maxs][maxs][2][2];
int len;

long long dfs(const int p, const int px, const int nx, const int py, const int ny, const bool fx,
              const bool fy) {
    if (p == len)
        return !px && !nx && !py && !ny && !fx && !fy;
    if (dp[p][px][nx][py][ny][fx][fy] != -1)
        return dp[p][px][nx][py][ny][fx][fy];
    int lim = 1 << n;
    long long ret = 0;
    for (int i = 0; i < lim; i++) {
        int Px = px, Nx = nx, Py = py, Ny = ny;
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1) {
                if (x[j] > 0)
                    Px += x[j];
                else
                    Nx -= x[j];
                if (y[j] > 0)
                    Py += y[j];
                else
                    Ny -= y[j];
            }
        if ((Px & 1) == (Nx & 1) && (Py & 1) == (Ny & 1)) {
            bool Fx = ((m >> p) & 1) != (Px & 1) ? (Px & 1) : fx;
            bool Fy = ((m >> p) & 1) != (Py & 1) ? (Py & 1) : fy;
            ret += dfs(p + 1, Px >> 1, Nx >> 1, Py >> 1, Ny >> 1, Fx, Fy);
        }
    }
    return dp[p][px][nx][py][ny][fx][fy] = ret % mod;
}

inline long long solve(void) {
    int M = m;
    while (M) len++, M >>= 1;
    memset(dp, -1, sizeof(dp));
    return (dfs(0, 0, 0, 0, 0, false, false) + mod - 1) % mod;
}
