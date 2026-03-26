#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = x; i < y; i++)

const int mx = 2e5 + 5;

int n, m, k, A[mx], dst[mx], cnt[mx]; vector<int> adj[mx];

int main(){
cin >> n >> m;
FOR(i, 1, m + 1){
int u, v; cin >> u >> v;
adj[v].push_back(u);
}
cin >> k;
FOR(i, 1, k + 1) cin >> A[i];

queue<int> q; memset(dst, 0x3f, sizeof(dst));
q.push(A[k]); dst[A[k]] = 0;

while (!q.empty()){
int cur = q.front(); q.pop();
for (int nxt : adj[cur]){
if (dst[cur] + 1 < dst[nxt]){
dst[nxt] = dst[cur] + 1;
cnt[nxt] = 0;
q.push(nxt);
}
if (dst[cur] + 1 == dst[nxt]) cnt[nxt]++;
}
}
int bstMn = 0, bstMx = 0;
FOR(i, 1, k){
if (dst[A[i]] - 1 != dst[A[i + 1]]) bstMn++, bstMx++;
else if (cnt[A[i]] > 1) bstMx++;
}
cout<<bstMn<<" "<<bstMx<<"\n";
}