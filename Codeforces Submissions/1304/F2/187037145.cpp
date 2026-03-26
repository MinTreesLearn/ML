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
		priority_queue<pair<int,int> >q,q2;
		for (int j=1;j<k;j++)
			q2.push(make_pair(f[i-1][j+k-1]-(a[i-1][m]-a[i-1][j-1]),j+k-1));
		for (int j=k;j<=m;j++)
		{
			f[i][j]=max(get(k,j-k,i-1),get(j+k,m,i-1));
			while(!q.empty()&&q.top().second<j-k+1) q.pop();
			q.push(make_pair(f[i-1][j]-a[i-1][j],j));
			f[i][j]=max(f[i][j],q.top().first+a[i-1][j-k]);
			while(!q2.empty()&&q2.top().second<j) q2.pop();
			q2.push(make_pair(f[i-1][j+k-1]-(a[i-1][m]-a[i-1][j-1]),j+k-1));
			f[i][j]=max(f[i][j],q2.top().first+a[i-1][m]-a[i-1][j]);
			f[i][j]+=a[i-1][j]-a[i-1][j-k]+a[i][j]-a[i][j-k];
			push(f[i][j],i,j);
			
		}	
	}
	int ans=0;
	for (int j=k;j<=m;j++)
		ans=max(ans,f[n+1][j]);
	cout<<ans<<endl;
 } 
 