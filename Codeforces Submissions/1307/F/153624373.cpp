#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int dep[N],f[N][21],head[N],nxt[N],vet[N],edgenum,que[N],fa[N],K,r,n;
void Add(int u,int v) { vet[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum; }
int find(int x) { if (x!=fa[x]) fa[x]=find(fa[x]); return fa[x]; }
void bfs() {
	for (int i=1; i<=n; i++) fa[i]=i,dep[i]=-1;
	int Head=1,Tail=0;
	for (int i=1; i<=r; i++) {
		int x; scanf("%d",&x);
		que[++Tail]=x; dep[x]=0;
	}
	while (Head<=Tail) {
		int x=que[Head++];
		if (dep[x]>=K/2) break;
		for (int e=head[x]; e; e=nxt[e]) {
			int v=vet[e];
			if (find(x)!=find(v)) fa[find(v)]=find(x);
			if (dep[v]!=-1) continue;
			dep[v]=dep[x]+1,que[++Tail]=v;
		}
	}
}
void dfs(int x,int fa) {
	f[x][0]=fa; dep[x]=dep[fa]+1;
	for (int i=1; i<=20; i++) f[x][i]=f[f[x][i-1]][i-1];
	for (int e=head[x]; e; e=nxt[e]) {
		int v=vet[e]; if (v==fa) continue;
		dfs(v,x);
	}
}
int LCA(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20; i>=0; i--) if (dep[f[x][i]]>=dep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=20; i>=0; i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int Jump(int x,int d) {
	for (int i=20; i>=0; i--) if (d>=(1<<i)) x=f[x][i],d-=(1<<i);
	return x;
}
int Dis(int x,int y,int lca) { return dep[x]+dep[y]-2*dep[lca]; }
int main() {
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d%d%d",&n,&K,&r);
	K<<=1; int num=n;
	for (int i=1; i<n; i++) {
		int u,v; scanf("%d%d",&u,&v);
		Add(u,++num),Add(num,u);
		Add(v,num),Add(num,v);
	}
	n=num;
	bfs(),dfs(1,0);
	int q; scanf("%d",&q);
	while (q--) {
		int u,v; scanf("%d%d",&u,&v);
		int lca=LCA(u,v),d=Dis(u,v,lca);
//		cerr<<u<<' '<<v<<' '<<d<<endl;
		if (d<=K) { puts("YES"); continue; }
		int fu,fv;
		if (dep[u]-dep[lca]>=K/2) fu=Jump(u,K/2);
		else fu=Jump(v,d-K/2);
		if (dep[v]-dep[lca]>=K/2) fv=Jump(v,K/2);
		else fv=Jump(u,d-K/2);
		if (find(fu)==find(fv)) puts("YES");
		else puts("NO");
	}
	return 0;
}
