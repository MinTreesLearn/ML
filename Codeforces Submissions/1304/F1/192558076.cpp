// LUOGU_RID: 101625748
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
	int s=0; char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') s=s*10+c-'0',c=getchar();
	return s;
}
int n,m,k; int a[55][20010],b[55][20010];
int sum[55][20010];
int dp[55][20010];
struct Tree
{
	int ax1,ax2,ax3,ax4;
} tree[80010];
Tree merge(Tree x,Tree y)
{
	return {max(x.ax1,y.ax1),max(x.ax2,y.ax2),max(x.ax3,y.ax3),max(x.ax4,y.ax4)};
}
void build(int now,int qx,int l,int r)
{
	if(l==r)
	{
		tree[now]={dp[qx][l]+sum[qx][l+k-1]-sum[qx][l-1],dp[qx][l]-sum[qx][l-1],
		dp[qx][l]+sum[qx][l+k-1],dp[qx][l]+sum[qx][l+k-1]-sum[qx][l-1]};
		return;
	}
	int mid=(l+r)>>1;
	build(now<<1,qx,l,mid),build(now<<1|1,qx,mid+1,r);
	tree[now]=merge(tree[now<<1],tree[now<<1|1]);
}
int query(int now,int ql,int qr,int l,int r,int op)
{
	ql=max(ql,1ll),qr=min(qr,m-k+1);
	if(ql>qr) return -1e9;
	if(ql<=l && r<=qr) return op==1?tree[now].ax1:op==2?tree[now].ax2:op==3?tree[now].ax3:tree[now].ax4;
	int mid=(l+r)>>1,ans=-1e9;
	if(ql<=mid) ans=max(ans,query(now<<1,ql,qr,l,mid,op));
	if(qr>mid) ans=max(ans,query(now<<1|1,ql,qr,mid+1,r,op));
	return ans;
}
signed main()
{
	n=read(),m=read(),k=read();
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
		{
			a[i][j]=read();
		}
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
		{
			sum[i][j]=sum[i][j-1]+a[n-i+1][j];
		}
	}
	build(1,1,1,m-k+1);
	for(int i=2; i<=n; ++i)
	{
		for(int j=1; j<=m-k+1; ++j)
		{
			dp[i][j]=max(dp[i][j],query(1,1,j-k,1,m-k+1,1)+sum[i-1][j+k-1]-sum[i-1][j-1]);
			dp[i][j]=max(dp[i][j],query(1,j-k+1,j,1,m-k+1,2)+sum[i-1][j+k-1]);
			dp[i][j]=max(dp[i][j],query(1,j,j+k-1,1,m-k+1,3)-sum[i-1][j-1]);
			dp[i][j]=max(dp[i][j],query(1,j+k,m-k+1,1,m-k+1,4)+sum[i-1][j+k-1]-sum[i-1][j-1]);
		}
		build(1,i,1,m-k+1);
	}
	int ans=0;
	for(int i=1; i<=m-k+1; ++i) ans=max(ans,dp[n][i]+sum[n][i+k-1]-sum[n][i-1]);
	cout<<ans;
	return 0;
}