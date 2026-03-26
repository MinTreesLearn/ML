#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[55][20200];
int f[55][200200];
int tree[55][20200];
int lowbit(int x)
{
	return x&(-x);
}
int get(int x,int y,int i)
{
	if (x>y) return 0;
	int sum=0;
	while(y>=x)
	{
		sum=max(sum,f[i][y]);
		y--;
		for (;y-lowbit(y)>=x;y-=lowbit(y)) sum=max(sum,tree[i][y]);
	}
	
	return sum;
}
void push(int x,int i,int j)
{
	for (;j<=m;j+=lowbit(j)) tree[i][j]=max(tree[i][j],x);
}
int main()
{
	int x;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{	
			cin>>x;
			a[i][j]=a[i][j-1]+x;
		}
	for (int i=2;i<=n+1;i++)
	{
		for (int j=k;j<=m;j++)
		{
			f[i][j]=max(get(k,j-k,i-1),get(j+k,m,i-1));
			for (int ii=max(j-k+1,k);ii<=j+k-1;ii++)
			f[i][j]=max(f[i][j],f[i-1][ii]-(a[i-1][min(ii,j)]-a[i-1][max(j-k,ii-k)]));
			f[i][j]+=a[i-1][j]-a[i-1][j-k]+a[i][j]-a[i][j-k];
			push(f[i][j],i,j);
		}	
	}
	int ans=0;
	for (int j=k;j<=m;j++)
		ans=max(ans,f[n+1][j]);
	cout<<ans<<endl;
 } 
 