#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
using LL = long long;
const int maxn = 105;
int g[maxn][maxn];
vector<pair<int, int> > d[maxn][maxn];
int n, k;
vector<int> v;
int s[maxn];
LL ans = 1e18;

void dfs(int u){
    if (u == k / 2 - 1){
        v.push_back(1);
        LL res = 0;
        for(int i = 1; i < v.size(); i++){
            int a = v[i - 1], b = v[i];
            LL t = 1e18;
            for(auto [x, j] : d[a][b]){
                if (!s[j]){
                    t = x;
                    break;
                }
            }
            res += t;
        }
        ans = min(ans, res);
        v.pop_back();
        return;
    }
    for(int i = 1; i <= n; i++){
        v.push_back(i);
        s[i]++;
        dfs(u + 1);
        s[i]--;
        v.pop_back();
    }
}

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> g[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if (k == i || k == j) continue;
                d[i][j].push_back({g[i][k] + g[k][j], k});
            }
            sort(d[i][j].begin(), d[i][j].end());
        }
    s[1] = 1;
    v.push_back(1);
    dfs(0);
    cout << ans << '\n';

}