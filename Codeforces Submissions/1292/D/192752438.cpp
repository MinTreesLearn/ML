#include<bits/stdc++.h>
#define N 5000
#define M 5000005
using namespace std;
int tot,n,pr[N+5],cnt,s[N+5][705],son[M],a[M],v[N+5],p[N+5][705];
long long asw,sum[M];
bool vi[N+5];
struct nood {
	int to,next,v;
} g[M];
inline void add(int x,int y,int z) {
	g[++cnt].v=z,g[cnt].to=y,g[cnt].next=a[x],a[x]=cnt;
}
inline void dfs(int u) {
	for(int j,i=a[u]; i; i=g[i].next) {
		dfs(j=g[i].to),son[u]+=son[j],sum[u]+=sum[j]+1ll*son[j]*g[i].v;
	}
}
inline void Dfs(int u) {
	for(int j,i=a[u]; i; i=g[i].next) {
		if(son[j=g[i].to]*2>son[0]) {
			asw-=1ll*g[i].v*(son[j]*2-son[0]);
			return Dfs(j);
		}
	}
}
int main() {
	for(int i=2; i<=N; i++) {
		if(!vi[i]) pr[++pr[0]]=i;
		for(int j=1; j<=pr[0]; j++) {
			if(i*pr[j]>N) break;
			vi[i*pr[j]]=1;
			if(i%pr[j]==0) break;
		}
	}
	scanf("%d",&n);
	for(int x,i=1; i<=n; i++) scanf("%d",&x),v[max(x,1)]++;
	son[0]=v[1];
	for(int i=2; i<=N; i++) {
		int op=0;
		for(int j=pr[0]; j; j--) {
			if(pr[j]>i) continue;
			int k=i;
			while(k) s[i][j]+=k/pr[j],k/=pr[j];
			if(op) add(p[i][j+1],p[i][j]=++tot,s[i][j]);
			else if(s[i-1][j]!=s[i][j]) {
				add(p[i-1][j],p[i][j]=++tot,s[i][j]-s[i-1][j]),op=1;
			} else p[i][j]=p[i-1][j];
		}
		son[tot]=v[i];
	}
	dfs(0),asw=sum[0],Dfs(0),printf("%lld",asw);
}