#include<iostream>
#include<cstring>
using namespace std;
using LL = long long;
const int maxn = 505;
int s1[4][maxn][maxn], a[maxn][maxn];
int s2[255][maxn][maxn];

int sum(int s[maxn][maxn], int l1, int r1, int l2, int r2){
    return s[l2][r2] - s[l2][r1 - 1] - s[l1 - 1][r2] + s[l1 - 1][r1 - 1];
}

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
                s1[x][i][j] = (a[i][j] == x) + s1[x][i - 1][j] + s1[x][i][j - 1] - s1[x][i - 1][j - 1];
    int up = min(n, m) / 2;
    for(int len = 1; len <= up; len++){
        for(int i = 1; i + 2 * len - 1 <= n; i++){
            for(int j = 1; j + 2 * len - 1 <= m; j++){
                int t = 0;
                if (sum(s1[0], i, j, i + len - 1, j + len - 1) == len * len && 
                    sum(s1[1], i, j + len, i + len - 1, j + 2 * len - 1) == len * len &&
                    sum(s1[2], i + len, j, i + 2 * len - 1, j + len - 1) == len * len &&
                    sum(s1[3], i + len, j + len, i + 2 * len - 1, j + 2 * len - 1) == len * len)
                        t = 1;
                s2[len][i][j] = t + s2[len][i - 1][j] + s2[len][i][j - 1] - s2[len][i - 1][j - 1];
            }
        }
    }

    while(q--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int mx = min(l2 - l1 + 1, r2 - r1 + 1) / 2;
        while(mx && !sum(s2[mx], l1, r1, l2 - 2 * mx + 1, r2 - 2 * mx + 1)) mx--;
        cout << 4 * mx * mx << '\n';
    }

}