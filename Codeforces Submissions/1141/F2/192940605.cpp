#include <bits/stdc++.h>
#define x first
#define y second
#define TLE ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef unsigned long long ULL;
const int N = 3e5 + 10, M = 2 * N, mod = 1e9 + 7;
const double eps = 1e-8;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int h[N], ne[M], e[M], w[M];
LL T, n, m, k;
int a[N], s[N];
int main()
{
    TLE;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i], s[i] = s[i - 1] + a[i];
    map<int, vector<PII>> hash;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ )
            hash[s[i] - s[j - 1]].push_back({j, i});
    //for (auto& c : hash[3]) cout << c.x << " " << c.y << endl;
    int st = -2e9, ed = -2e9;
    vector<PII> ans;
    for (auto& v : hash){
        st = -2e9, ed = -2e9;
        vector<PII> tmp;
        for (auto& c : v.y){
            if (c.x > ed){
                if (ed != -2e9) tmp.push_back({st, ed});
                st = c.x, ed = c.y;
            }
        }
        tmp.push_back({st, ed});
        if (tmp.size() > ans.size()) ans = tmp;
    }
    cout << ans.size() << "\n";
    for (auto& c : ans) cout << c.x << " " << c.y << "\n";
}
