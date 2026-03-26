#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
using LL = long long;
const int maxn = 2e5 + 5;
pair<int, int> op[maxn];
int f[maxn][1 << 8];
int a[8];

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        op[++cnt] = {l, i};
        op[++cnt] = {r + 1, -i};
    }
    sort(op + 1, op + cnt + 1);
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for(int i = 1; i <= cnt; i++){
        auto [x, id] = op[i];
        int len = (i + 1 <= cnt ? op[i + 1].first - op[i].first : 0);
        int t;
        if (id > 0){
            for(int j = 0; j < k; j++)
                if (!a[j]){
                    a[j] = id;
                    t = j;
                    break;
                }
            for(int j = 0; j < 1 << k; j++){
                int par = __builtin_parity(j);
                if (j >> t & 1)
                    f[i][j] = f[i - 1][j ^ (1 << t)] + par * len;
                else 
                    f[i][j] = f[i - 1][j] + par * len;
            }
        }
        else{
            for(int j = 0; j < k; j++)
                if (a[j] == -id){
                    t = j;
                    a[j] = 0;
                    break;
                }
            for(int j = 0; j < 1 << k; j++){
                if (j >> t & 1) continue;
                int par = __builtin_parity(j);
                f[i][j] = max(f[i - 1][j], f[i - 1][j | (1 << t)]) + par * len;
            }
        }
    }
    cout << f[cnt][0] << '\n';

}