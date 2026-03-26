// LUOGU_RID: 98578627
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pair;
const int N=2e5+5;
#define F first
#define S second
#define ls now<<1
#define rs now<<1|1
int vis[N<<2],tag[N<<2]; Pair tr[N<<2];
int dep[N],used[N],siz[N],a[N]; ll su[N],sd[N],val[N];
int n,tot,rt,mn,u,v,R; ll ans;
vector<int> G[N],vec[N];
inline void pushdown(int now){
if (tag[now]){
tag[ls]=tag[rs]=1;
vis[ls]=vis[rs]=0;
tag[now]=0;
}
}
void update(int now, int l, int r, Pair p){
if (!vis[now]) return tr[now]=p,vis[now]=1,void();
int mid=(l+r)>>1;
if (mid*tr[now].F+tr[now].S<mid*p.F+p.S) swap(tr[now],p);
if (l==r) return;
pushdown(now);
p.F<tr[now].F?update(ls,l,mid,p):update(rs,mid+1,r,p);
}
ll query(int now, int l, int r, int x){
if (!vis[now]) return 0;
ll ret=tr[now].F*x+tr[now].S;
if (l==r) return ret;
int mid=(l+r)>>1; pushdown(now);
return max(ret,mid>=x?query(ls,l,mid,x):query(rs,mid+1,r,x));
}
void Getrt(int u, int f){
siz[u]=1; int mx=0;
for (int v:G[u])
if (v!=f && !used[v]){
Getrt(v,u); siz[u]+=siz[v];
mx=max(mx,siz[v]);
}
mx=max(mx,tot-siz[u]);
if (mx<mn) mn=mx,rt=u;
}
void dfs(int u, int f){
vec[R].push_back(u),siz[u]=1;
dep[u]=dep[f]+1,val[u]=val[f]+a[u];
sd[u]=sd[f]+val[u];
su[u]=su[f]+1ll*dep[f]*a[u];
for (int v:G[u])
if (v!=f && !used[v]) dfs(v,u),siz[u]+=siz[v];
}
inline void Ins(int v, int u){
for (int x:vec[v]) ans=max(ans,max(su[x]+val[x],sd[x]+query(1,1,n,dep[x])));
for (int x:vec[v]) update(1,1,n,{val[x]-a[u],su[x]});
}
void solve(int u){
used[u]=1; dep[u]=1,su[u]=0,val[u]=sd[u]=a[u];
for (int v:G[u])
if (!used[v]){
vec[v].clear(),R=v;
dfs(v,u),Ins(v,u);
}
tag[1]=1,vis[1]=0;
for (int i=G[u].size()-1; ~i; i--)
if (!used[G[u][i]]) Ins(G[u][i],u);
tag[1]=1,vis[1]=0;
for (int v:G[u])
if (!used[v]) tot=siz[v],mn=1e9,Getrt(v,u),solve(rt);
}
int main(){
scanf("%d",&n); tag[1]=1;
for (int i=1; i<n; i++){
scanf("%d%d",&u,&v);
G[u].push_back(v),G[v].push_back(u);
}
for (int i=1; i<=n; i++) scanf("%d",&a[i]);
tot=n,mn=1e9,Getrt(1,0),solve(rt);
printf("%lld\n",ans);
}