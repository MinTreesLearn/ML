#include <bits/stdc++.h>
using namespace std;

#define FOR(i, x, y) for (int i = x; i < y; i++)

const int mx = 1e6 + 5;

int n, m, p, ans = -2e9, A[mx], B[mx]; long long seg[mx * 4], lz[mx * 4];

void push(int l, int r, int i){
seg[i] += lz[i];
if (l != r) lz[2 * i] += lz[i], lz[2 * i + 1] += lz[i];
lz[i] = {};
}
void upd(int x, int y, int v, int l = 0, int r = mx - 1, int i = 1){
push(l, r, i);
if (l > y or r < x) return;
if (l >= x and r <= y){ lz[i] += v; push(l, r, i); return; }
int mid = (l + r) / 2;
upd(x, y, v, l, mid, i * 2); upd(x, y, v, mid + 1, r, i * 2 + 1);
seg[i] = max(seg[i * 2], seg[i * 2 + 1]);
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0);
cin >> n >> m >> p;
FOR(i, 0, mx) A[i] = B[i] = 2e9;

FOR(i, 0, n){ int a, c; cin >> a >> c; A[a] = min(A[a], c); }
FOR(i, 0, m){ int b, c; cin >> b >> c; B[b] = min(B[b], c); }

for (int i = mx - 2; ~i; i--) A[i] = min(A[i], A[i + 1]);
FOR(i, 0, mx) upd(i, i, -B[i]);

vector<array<int, 3>> V(p);
for (auto &[x, y, z] : V) cin >> x >> y >> z;
V.push_back({0, 0, 0}); sort(V.begin(), V.end());

for (auto [x, y, z] : V){
upd(y + 1, mx - 1, z);
ans = max(1LL*ans, seg[1] - A[x + 1]);
}
cout<<ans<<"\n";
}