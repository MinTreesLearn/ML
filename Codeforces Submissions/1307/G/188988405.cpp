// LUOGU_RID: 99528311
#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<queue>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(x) ((x)&-(x))
#define popcount(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define umap unordered_map
#define all(x) x.begin(),x.end()
#define mk make_pair
#define pb push_back
#define ckmax(x,y) x=max(x,y)
#define ckmin(x,y) x=min(x,y)
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define N 55
using namespace std;
inline int read(){
	int x=0,f=0; char ch=getchar();
	while(!isdigit(ch)) f|=(ch==45),ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
struct edge{
	int b,c,f,n;
}e[N*N*4];
int n,m,h[N],tot=1;
inline void charu(int a,int b,int f,int c){
	e[++tot].b=b,e[tot].f=f,e[tot].c=c,e[tot].n=h[a],h[a]=tot;
	e[++tot].b=a,e[tot].f=0,e[tot].c=-c,e[tot].n=h[b],h[b]=tot;
}
int S,T,dis[N],flow[N],vis[N],pre[N];
queue <int> q;
inline bool spfa(){
	memset(dis,0x3f,sizeof(dis));
	memset(flow,0,sizeof(flow));
	flow[S]=inf,dis[S]=0,vis[S]=1,q.push(S);
	while(!q.empty()){
		int u=q.front();q.pop();vis[u]=0;
		for(int i=h[u];i;i=e[i].n){
			int v=e[i].b;
			if(e[i].f && dis[v]>dis[u]+e[i].c){
				dis[v]=dis[u]+e[i].c;
				flow[v]=min(flow[u],e[i].f),pre[v]=i;
				if(!vis[v]) vis[v]=1,q.push(v);
			}
		}
	}
	return flow[T];
}
int cnt;
double C[N*N];
inline pair<int,int> EK(){
	int maxflow=0,mincost=0;
	while(spfa()){
		C[++cnt]=dis[T],C[cnt]+=C[cnt-1];
		maxflow+=flow[T],mincost+=flow[T]*dis[T];
		for(int x=T;x!=S;x=e[pre[x]^1].b)
			e[pre[x]].f-=flow[T],e[pre[x]^1].f+=flow[T];
	}
	return {maxflow,mincost};
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read(),z=read();
		charu(x,y,1,z);
	}
	S=1,T=n;
	EK();
	for(int q=read();q--;){
		double x=read();
		double ans=1e9;
		for(int i=1;i<=cnt;++i){
			ckmin(ans,(C[i]+x)/(double)i);
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}
