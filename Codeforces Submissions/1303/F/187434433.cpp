#include<bits/stdc++.h>
using namespace std;
int const N=2000200,M=303,dx[]={-1,1,0,0},dy[]={0,0,-1,1};
struct node{int u,v,id;};vector<node> g1[N],g2[N];
int i,j,n,m,k,u,v,w,f[M*M],mp[M][M],Ans[N];
int read(){
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x;
}
int idx(int x,int y){return (x-1)*m+y;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int merg(int u,int v){
	u=find(u);v=find(v);
	if (u==v) return 0;
	f[u]=v;return 1;
}
void solve(int u,int v,int id,int type){
	if (mp[u][v]) return ;
	Ans[id]+=type;mp[u][v]=1;
	for (int U,V,k=0;k<4;k++)
		if (mp[U=u+dx[k]][V=v+dy[k]])
			Ans[id]-=type*merg(idx(u,v),idx(U,V));
}
void clear(){
	for (int i=1;i<=n*m;i++) f[i]=i;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			mp[i][j]=0;	
}
int main(){
	n=read();m=read();k=read();
	for (i=1;i<=n;i++) for (j=1;j<=m;j++)
		g2[0].push_back({i,j,0});
	for (i=1;i<=k;i++){
		u=read();v=read();w=read();
		g1[mp[u][v]].push_back({u,v,i});
		g2[mp[u][v]=w].push_back({u,v,i});
	}
	for (i=1;i<=n;i++) for (j=1;j<=m;j++)
		g1[mp[i][j]].push_back({i,j,k+1}),mp[i][j]=0;
	for (i=0;i<=w;i++){ reverse(g1[i].begin(),g1[i].end());
		clear();for (j=0;j<g1[i].size();j++) solve(g1[i][j].u,g1[i][j].v,g1[i][j].id,-1);
		clear();for (j=0;j<g2[i].size();j++) solve(g2[i][j].u,g2[i][j].v,g2[i][j].id,1);
	}
	for (i=1;i<=k;i++) printf("%d\n",Ans[i]+=Ans[i-1]);
	return 0;
}