// LUOGU_RID: 102066497
#include <bits/stdc++.h>
using namespace std;
int f[200005],ff[200005],n,a[200005],u,v;
vector<int> g[200005];
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return f*x;
}
void dfs(int x,int fa){
	f[x]=a[x];
	for(int i=0;i<g[x].size();i++)
		if(g[x][i]^fa)
			dfs(g[x][i],x),f[x]+=max(0,f[g[x][i]]);
}
void dfs2(int x,int fa){
	for(int i=0;i<g[x].size();i++)
		if(g[x][i]^fa)
			ff[g[x][i]]=a[g[x][i]]+max(ff[x]+f[x]-max(f[g[x][i]],0)-a[x],0),dfs2(g[x][i],x);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=(read()?1:-1);
	for(int i=1;i<n;i++)
		u=read(),v=read(),g[u].push_back(v),g[v].push_back(u);
	dfs(1,0),ff[1]=a[1];
	dfs2(1,0);
	for(int i=1;i<=n;i++)
		printf("%d ",f[i]+max(0,ff[i]-a[i]));
	putchar(10);
	return 0;
}