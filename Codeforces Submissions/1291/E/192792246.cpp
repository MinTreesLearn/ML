#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5 + 42, INF = 1e18 + 42;

bool b[N];
int n, k, ans = 0, id[N][2], par[N*2], nb[N*2];

int F(int i) {
if(par[i] == i)
return i;
return par[i] = F(par[i]);
}

inline int neg(int a) {
return F((a + k + 1) % (2*k+2));
}

void U(int a, int b, bool diff) {
a = F(a), b = F(b);
if(a == b || a == neg(b))
return;

if(a == F(0) || a == neg(0))
ans -= nb[F(0)];
else
ans -= min(nb[a], nb[neg(a)]);

if(b == F(0) || b == neg(0))
ans -= nb[F(0)];
else
ans -= min(nb[b], nb[neg(b)]);

if(diff) {
nb[neg(b)] += nb[a];
par[a] = neg(b);

nb[b] += nb[neg(a)];
par[neg(a)] = b;
} else {
nb[b] += nb[a];
par[a] = b;

nb[neg(b)] += nb[neg(a)];
par[neg(a)] = neg(b);
}

if(b == F(0) || b == neg(0))
ans += nb[F(0)];
else
ans += min(nb[F(b)], nb[neg(b)]);
}

signed main() {
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

cin >> n >> k;
for(int i = 0; i < N*2; i++)
par[i] = i;
for(int i = 1; i <= k; i++)
nb[i] = 1;
for(int i = 0; i < n; i++)
id[i][0] = id[i][1] = k+1;

for(int i = 0; i < n; i++) {
char c; cin >> c;
b[i] = (c == '1');
}
for(int i = 0; i < k; i++) {
int m; cin >> m;
for(int j = 0; j < m; j++) {
int a; cin >> a;
a--;
if(id[a][0] == k+1)
id[a][0] = i+1;
else
id[a][1] = i+1;
}
}
for(int i = 0; i < n; i++) {
U(id[i][0], id[i][1], !b[i]);
cout << ans << '\n';
}
}