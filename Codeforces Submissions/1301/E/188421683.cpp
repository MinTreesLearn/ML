#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
using LL = long long;
const int maxn = 505;
int s[4][maxn][maxn], a[maxn][maxn];

int sum(int s[maxn][maxn], int l1, int r1, int l2, int r2){
    return s[l2][r2] - s[l2][r1 - 1] - s[l1 - 1][r2] + s[l1 - 1][r1 - 1];
}

template<typename T, bool isMin>
struct SparseTable2D{
#define v1 vector<T> 
#define v2 vector<v1> 
#define v3 vector<v2> 
#define v4 vector<v3>

    int n, m, N, M;
    v4 f;

    SparseTable2D(int n, int m) : n(n), m(m), N(__lg(n)), M(__lg(m)) {
        f = v4(N + 1, v3(M + 1, v2(n + 1, v1(m + 1))));
    }

    SparseTable2D(v2 init) : SparseTable2D((int)init.size(), (int)init[0].size()){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                f[0][0][i][j] = init[i - 1][j - 1];
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= M; j++){
                if (i + j){
                    for(int a = 1; a + (1 << i) - 1 <= n; a++){
                        for(int b = 1; b + (1 << j) - 1 <= m; b++){
                            if (isMin){
                                if (i) f[i][j][a][b] = min(f[i - 1][j][a][b], f[i - 1][j][a + (1 << (i - 1))][b]);
                                else f[i][j][a][b] = min(f[i][j - 1][a][b], f[i][j - 1][a][b + (1 << (j - 1))]);  
                            }
                            else{
                                if (i) f[i][j][a][b] = max(f[i - 1][j][a][b], f[i - 1][j][a + (1 << (i - 1))][b]);
                                else f[i][j][a][b] = max(f[i][j - 1][a][b], f[i][j - 1][a][b + (1 << (j - 1))]);  
                            }                            
                        }
                    }
                } 
            }
        }
    }

    T query(int x1, int y1, int x2, int y2){
        int k1 = __lg(x2 - x1 + 1);
        int k2 = __lg(y2 - y1 + 1);
        x2 = x2 - (1 << k1) + 1;
        y2 = y2 - (1 << k2) + 1;
        if (isMin) return min(min(f[k1][k2][x1][y1], f[k1][k2][x1][y2]), min(f[k1][k2][x2][y1], f[k1][k2][x2][y2]));
        else return max(max(f[k1][k2][x1][y1], f[k1][k2][x1][y2]), max(f[k1][k2][x2][y1], f[k1][k2][x2][y2]));
    }

#undef v1
#undef v2
#undef v3
#undef v4
};

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    auto get = [](char c){
        if (c == 'R') return 0;
        if (c == 'G') return 1;
        if (c == 'Y') return 2;
        return 3;
    };

    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            a[i][j] = get(c);
        }
    for(int x = 0; x < 4; x++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                s[x][i][j] = (a[i][j] == x) + s[x][i - 1][j] + s[x][i][j - 1] - s[x][i - 1][j - 1];
    
    auto check = [&](int x, int y, int mid){
        if (sum(s[0], x - mid + 1, y - mid + 1, x, y) != mid * mid) return false;
        if (sum(s[1], x - mid + 1, y + 1, x, y + mid) != mid * mid) return false;
        if (sum(s[2], x + 1, y - mid + 1, x + mid, y) != mid * mid) return false;
        if (sum(s[3], x + 1, y + 1, x + mid, y + mid) != mid * mid) return false;
        return true;
    };
    
    vector<vector<int> > init(n, vector<int>(m));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int l = 0, r = min({i, j, n - i, m - j});
            while(l < r){
                int mid = (l + r + 1) / 2;
                if (check(i, j, mid)) l = mid;
                else r = mid - 1;
            }
            init[i - 1][j - 1] = r;
        }

    SparseTable2D<int, false> st(init);

    while(q--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int l = 0, r = min(l2 - l1 + 1, r2 - r1 + 1) / 2;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if (st.query(l1 + mid - 1, r1 + mid - 1, l2 - mid, r2 - mid) >= mid) l = mid;
            else r = mid - 1;
        }
        cout << 4 * r * r << '\n';
    }

}