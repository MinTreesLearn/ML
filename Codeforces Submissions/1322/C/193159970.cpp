#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
int bm(int b, int p) {
  if(p==0) return 1;
  int r=bm(b,p>>1);
  if(p&1) return (((r*r)%MOD)*b)%MOD;
  return (r*r)%MOD;
}
mt19937_64 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
  return uniform_int_distribution<int>(x,y)(rng);
}
const int MAXN = 5e5+10;
int a[MAXN];
int dsu[MAXN];
int set_of(int u) {
  if(dsu[u]==u) return u;
  return dsu[u]=set_of(dsu[u]);
}
void union_(int u,int v) {
  dsu[set_of(u)]=set_of(v);
}
void solve() {
  int n, m;
  scanf("%lld %lld", &n, &m);
  for(int i=1; i<=n; i++)dsu[i]=i;
  int c[n+1];
  for(int i=1; i<=n; i++) scanf("%lld", &c[i]);
  int h[n+1]; for(int i=1; i<=n; i++)h[i]=0;
  int deg[n+1];
  for(int i=1;i<=n;i++)deg[i]=0;
  for(int i=1; i<=m; i++) {
    int32_t u,v; scanf("%d %d", &u, &v);
    h[v]^=a[u];
    deg[v]++;
  }
  map<int,int32_t>ok;
  for(int i=1; i<=n; i++) {
    if(ok.count(h[i])) {
      union_(ok[h[i]],i);
    }
    else ok[h[i]]=i;
  }
  int sum[n+1];
  for(int i=1;i<=n; i++)sum[i]=0;
  for(int i=1; i<=n; i++) {
    sum[set_of(i)] += c[i];
  }
  int g = 0;
  for(int i=1; i<=n; i++) {
    if(deg[i]==0)continue;
    if(sum[i]>0) {
      g = (g==0 ? sum[i] : gcd(g, sum[i]));
    }
  }
  cout<<g<<"\n";
}
int32_t main() {
  for(int i=1; i<MAXN; i++) a[i] = rnd(0, LLONG_MAX);
  int32_t t;
  scanf("%d", &t);
  while(t--)solve();
}