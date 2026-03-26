#include<bits/stdc++.h>
#define f first
#define s second
#define prev prv
#define pii pair<int,int>
using namespace std;
const int N = 300 + 5, M = 2e6 + 5, mod = 1e9 + 7; // !
int t, n, m, a[N][N], p[N * N], l[M], r[M], ans[M], prev[M];
int X[N][N];
int cn = 0;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
struct query{
    int x, y, v;
} qry[M];
int find(int x) {
    return (p[x] == x ? x : p[x] = find(p[x]));
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    p[x] = y; --cn;
}
void add(int x, int y) {
    for(int k = 0; k < 4; k++) {
        int xn = x + dx[k], yn = y + dy[k];
        if(a[x][y] == a[xn][yn] && xn && yn && xn <= n && yn <= m) merge(X[x][y], X[xn][yn]);
    }
}

main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int q;
    cin >> n >> m >> q;
    for(int i = 1; i <= q; i++) {
        cin >> qry[i].x >> qry[i].y >> qry[i].v;
        if(qry[i].v != qry[i - 1].v) l[qry[i].v] = i;
        r[qry[i].v] = i;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) X[i][j] = m * (i - 1) + j;
    }

    for(int i = 1; i <= q; i++) {
        for(int x = 1; x <= n; x++) {
            for(int y = 1; y <= m; y++) {
                p[X[x][y]] = X[x][y];
            }
        }
        cn = 0;
        for(int x = 1; x <= n; x++) {
            for(int y = 1; y <= m; y++) {
                if(a[x][y] == qry[i].v) add(x, y);
            }
        }
        for(int j = l[qry[i].v]; j <= r[qry[i].v]; ++j) {
            prev[j] = a[qry[j].x][qry[j].y];
            a[qry[j].x][qry[j].y] = qry[i].v;
            add(qry[j].x, qry[j].y);
            ans[j] = cn;
        }
        cn = n * m;
        for(int x = 1; x <= n; x++) {
            for(int y = 1; y <= m; y++) {
                p[X[x][y]] = X[x][y];
            }
        }
        for(int x = 1; x <= n; x++) {
            for(int y = 1; y <= m; y++) {
                if(a[x][y] != qry[i].v) add(x, y);
            }
        }
        for(int j = r[qry[i].v]; j >= l[qry[i].v]; --j) {
            ans[j] += cn;
            a[qry[j].x][qry[j].y] = prev[j];
            if(prev[j] != qry[i].v)
            add(qry[j].x, qry[j].y);

        }
        for(int j = l[qry[i].v]; j <= r[qry[i].v]; ++j) a[qry[j].x][qry[j].y] = qry[i].v;
        i = r[qry[i].v];
    }

    for(int i = 1; i <= q; i++) cout << ans[i] << " ";
 }
