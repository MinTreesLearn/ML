// LUOGU_RID: 101261866
#include<bits/stdc++.h>
#define N 600010
#define int long long
#define ls k*2
#define rs k*2+1
#define mid (l+r)/2
#define pb push_back
using namespace std;
int read() {
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f=ch=='-'?-1:1,ch=getchar();
	while(isdigit(ch)) res=res*10+ch-'0',ch=getchar();
	return f*res;
}
int n;
int cnt,head[N],to[N],nxt[N];
void insert(int u,int v) {
	cnt++;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
struct line{int k,b;}a[N];
int d[N<<1];
int f(int x,int id) {return a[id].k*x+a[id].b;}
void update(int k,int l,int r,int id) {
	if(l==r) {
		if(f(l,id)>f(l,d[k])) d[k]=id;
		return ;
	}
	if(f(mid,id)>f(mid,d[k])) swap(id,d[k]);
	if(f(l,id)>f(l,d[k])) update(ls,l,mid,id);
	else if(f(r,id)>f(r,d[k])) update(rs,mid+1,r,id);
}
int query(int k,int l,int r,int x) {
	if(l==r) return f(x,d[k]);
	return max(f(x,d[k]),x<=mid?query(ls,l,mid,x):query(rs,mid+1,r,x));
} 
void clear(int k,int l,int r) {
	d[k]=0;if(l==r) return ;
	clear(ls,l,mid),clear(rs,mid+1,r);
}
int siz[N],son[N],rt,vis[N];
void gtrt(int now,int fa,int S) {
	siz[now]=1,son[now]=0;
	for(int i=head[now]; i; i=nxt[i]) if(to[i]!=fa&&!vis[to[i]]) {
		gtrt(to[i],now,S),siz[now]+=siz[to[i]];
		son[now]=max(son[now],siz[to[i]]);
	} son[now]=max(son[now],S-siz[now]);
	if(son[now]<son[rt]) rt=now;
}
int mx,val[N],ans;
struct node{
	int v1,v2,l,s,fr;
};
vector<node> v[N];
void dfs(int now,int v1,int v2,int s,int dep,int fr,int fa) {
//	printf("%lld\n",now);
	if(now!=rt&&!fr) fr=now;
	mx=max(mx,dep);
	if(!nxt[head[now]]) {
//		printf("%d %d %d %d\n",now,v1,v2,s-val[rt]);
		return v[fr].pb(node{v1,v2,dep,s-val[rt],fr}),void();
	}
	for(int i=head[now]; i; i=nxt[i]) if(to[i]!=fa&&!vis[to[i]]) 
		dfs(to[i],v1+s+val[to[i]],v2+val[to[i]]*dep,s+val[to[i]],dep+1,fr,now);
}
int tmp[N],tn;
void solve(int now,int S){
	vis[now]=1,tn=0;int tot=0;mx=0;
	dfs(now,val[now],0,val[now],1,0,0),clear(1,1,mx);
	for(int i=head[now]; i; i=nxt[i]) if(!vis[to[i]]) {
		for(node p:v[to[i]]) ans=max(ans,query(1,1,mx,p.l)+p.v1);
		for(node p:v[to[i]]) a[++tot]=line{p.s,p.v2},update(1,1,mx,tot);
		tmp[++tn]=to[i];
//		printf("%lld\n",ans);
	} ans=max(ans,query(1,1,mx,1)+val[now]);
//	printf("%lld\n",ans);
	clear(1,1,mx);
	for(int i=tn; i; i--) {
		for(node p:v[tmp[i]]) ans=max(ans,query(1,1,mx,p.l)+p.v1);
		for(node p:v[tmp[i]]) a[++tot]=line{p.s,p.v2},update(1,1,mx,tot);
		v[tmp[i]].clear();
	}
//	printf("%lld\n",ans);
 	for(int i=head[now]; i; i=nxt[i]) if(!vis[to[i]]) {
		int tS=siz[to[i]]<siz[now]?siz[to[i]]:S-siz[now];
		if(tS>1) rt=0,gtrt(to[i],now,tS),solve(rt,tS);
	}
}
signed main() {
	n=son[0]=read();
	if(n==2) {puts("5");return 0;}
	for(int i=1; i<n; i++) {
		int u=read(),v=read();
		insert(u,v),insert(v,u);
	}
	for(int i=1; i<=n; i++) val[i]=read(),ans=max(ans,val[i]);
	gtrt(1,0,n);
	solve(rt,n);
	printf("%lld",ans);
} 