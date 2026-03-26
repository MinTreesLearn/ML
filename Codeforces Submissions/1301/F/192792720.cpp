#include<bits/stdc++.h>
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
const int N = 1005, mod = 1e9 + 7; // !
int t, a[N][N], n,m,k,f[N],d[44][N][N], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
vector<pii> c[44];
bool ok(int x,int y) {
if(min(x,y) < 1 || x > n || y > m) return 0;
return 1;
}
main() {
cin >> n >> m >> k;
for(int i = 1; i <= n; i++) {
for(int j = 1; j <= m; j++) {
cin >> a[i][j];
c[a[i][j]].push_back({i,j});
}
}
for(int cl = 1; cl <= k; cl++) {
queue<pii> q;
for(int j = 1; j <= k; j++) f[j] = 0;
for(int i = 1; i <= n; i++) {
for(int j = 1; j <= m; j++) {
if(a[i][j] == cl) d[cl][i][j] = 0, q.push({i,j});
else d[cl][i][j] = n + m + 5;
}
}
while(q.size()) {
int i = q.front().f;
int j = q.front().s;
q.pop();

if(!f[a[i][j]]) {
f[a[i][j]] = 1;
for(int k = 0; k < c[a[i][j]].size(); k++) {
int i_ = c[a[i][j]][k].f;
int j_ = c[a[i][j]][k].s;
if(d[cl][i_][j_] > n + m) {
d[cl][i_][j_] = d[cl][i][j] + 1;
q.push({i_,j_});
}
}
}
for(int k = 0; k < 4; k++) {
if(ok(i + dx[k], j + dy[k]) && d[cl][i + dx[k]][j + dy[k]] > n + m) {
d[cl][i + dx[k]][j + dy[k]] = d[cl][i][j] + 1;
q.push({i + dx[k], j + dy[k]});
}
}
}
}
int q;
cin >> q;
while(q--) {
int x,y,i,j;
cin >> x >> y >> i >> j;
int ans = abs(i - x) + abs(j - y);
for(int c = 1; c <= k; c++) ans = min(ans, d[c][x][y] + d[c][i][j] + 1);
cout << ans << endl;
}
}