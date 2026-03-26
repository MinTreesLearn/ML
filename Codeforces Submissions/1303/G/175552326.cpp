#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return f?x:-x;
}
const int N=150005;
int K[N],B[N],tot,n,a[N],ans;
vector<int> T[N];
int calc(int id,int x){
	return K[id]*x+B[id];
}
int newseg(int x,int y){
	++tot;
	K[tot]=x;
	B[tot]=y;
	return tot;
}
struct LichaoSegmentTree{
	int lc[N<<2],rc[N<<2],pool,val[N<<2],rt;
	#define mid (l+r>>1)
	void clear(){rt=pool=0;}
	int newnode(){
		int p=++pool;
		lc[p]=rc[p]=val[p]=0;
		return p;
	}
	void modify(int &p,int l,int r,int u){
		if(!p)p=newnode();
		int &v=val[p];
		if(calc(u,mid)>calc(v,mid))swap(u,v);
		if(calc(u,l)>calc(v,l))modify(lc[p],l,mid,u);
		if(calc(u,r)>calc(v,r))modify(rc[p],mid+1,r,v);
	}
	int query(int p,int l,int r,int x){
		if(!p)return 0;
		int ret=calc(val[p],x);
		if(l==r)return ret;
		if(x<=mid)ret=max(ret,query(lc[p],l,mid,x));
		else ret=max(ret,query(rc[p],mid+1,r,x));
		return ret;
	}
}Tr;
int sum,dep[N],siz[N],root,DP[N],vis[N],pre[N],ppre[N],gre[N],pgre[N];
void findsize(int u,int fa){
	siz[u]=1;
	for(int v:T[u])if(!vis[v]&&v!=fa){
		findsize(v,u);
		siz[u]+=siz[v];
	}
}
void findroot(int u,int fa){
	DP[u]=0;
	for(int v:T[u])if(!vis[v]&&v!=fa){
		findroot(v,u);
		DP[u]=max(DP[u],siz[v]);
	}
	DP[u]=max(DP[u],sum-siz[u]);
	if(DP[u]<DP[root])root=u;
}
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	gre[u]=gre[fa]+a[u];
	pgre[u]=pgre[fa]+gre[u];
	ans=max(ans,Tr.query(Tr.rt,0,n,dep[u]-1)+pgre[u]);
	ans=max(ans,pgre[u]+dep[u]*a[root]);
	for(int v:T[u])if(v!=fa&&!vis[v]){
		dfs1(v,u);
	}
}
void dfs2(int u,int fa){
	pre[u]=pre[fa]+a[u];
	ppre[u]=ppre[fa]+dep[u]*a[u];
	ans=max(ans,ppre[u]);
	Tr.modify(Tr.rt,0,n,newseg(pre[u],ppre[u]));
//	Tr.query(Tr.rt,0,n,0);
	for(int v:T[u])if(v!=fa&&!vis[v]){
		dfs2(v,u);
	}
}
void solve(int u){
	Tr.clear();
	tot=0;
	dep[u]=1;
	pre[u]=ppre[u]=a[u];
	ans=max(ans,ppre[u]);
	gre[u]=pgre[u]=0;
	for(int v:T[u])if(!vis[v]){
		dfs1(v,u);
		dfs2(v,u);
	}
	Tr.clear();
	tot=0;
	dep[u]=1;
	pre[u]=ppre[u]=a[u];
	gre[u]=pgre[u]=0;
	reverse(T[u].begin(),T[u].end());
	for(int v:T[u])if(!vis[v]){
		dfs1(v,u);
		dfs2(v,u);
	}
	vis[u]=1;
	for(int v:T[u])if(!vis[v]){
		findsize(v,u);
		sum=siz[v];
		root=0;
		DP[0]=n;
		findroot(v,u);
		solve(root);
	}
}
void work(){
	sum=n;
	root=0;
	DP[0]=n;
	findsize(1,0);
	findroot(1,0);
	solve(root);
}
signed main(){
	n=read();
	for(int i=1;i<n;++i){
		int x=read(),y=read();
		T[x].push_back(y);
		T[y].push_back(x);
	}
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	work();
	printf("%lld\n",ans);
	return 0;
}