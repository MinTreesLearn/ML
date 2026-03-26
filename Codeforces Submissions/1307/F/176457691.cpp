// LUOGU_RID: 90198724
#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
const int M=N*2;

int n,m,k;
int tot;
int head[N],ver[M],ne[M];
void add(int x,int y)
{
	ver[++tot]=y;
	ne[tot]=head[x];
	head[x]=tot;
}

int d[N];
int f[N][25];

void dfs(int x,int fath)
{
	d[x]=d[fath]+1;
	for(int i=1;i<=20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=ne[i])
	{
		int y=ver[i];
		if(y==fath) continue;
		f[y][0]=x;
		dfs(y,x);
	}
}

int lca(int x,int y)
{
	if(d[x]<d[y]) swap(x,y);
	for(int i=20;i>=0;i--)
	{
		if(d[f[x][i]]>=d[y])
			x=f[x][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--)
	{
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}

int dis[N];
int fa[N];
int get(int x)
{
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
void vacation()
{
	queue<int>q;
	memset(dis,-1,sizeof(dis));
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		dis[x]=0;
		q.push(x);
	}
	
	while(q.size())
	{
		int x=q.front();q.pop();
		if(dis[x]==m) break;
		for(int i=head[x];i;i=ne[i])
		{
			int y=ver[i];
			fa[get(y)]=get(x);
			if(dis[y]==-1)
			{
				dis[y]=dis[x]+1;
				q.push(y);
			}
		}
	}
}

int move(int x,int len)
{
	for(int i=20;i>=0;i--)
	{
		if((1<<i)<=len)
		{
			len-=(1<<i);
			x=f[x][i];
		}
	}
	return x;
}

int main(){
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n*2;i++) fa[i]=i;	
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,n+i);
		add(y,n+i);
		add(n+i,x);
		add(n+i,y);
	}

	dfs(1,0);
	vacation();
	
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int z=lca(x,y);
		int len=d[x]+d[y]-2*d[z];
		if(len<=2*m) printf("YES\n");
		else
		{
			int ans1=(m<=(d[x]-d[z]))?get(move(x,m)):get(move(y,len-m));
			int ans2=(m<=(d[y]-d[z]))?get(move(y,m)):get(move(x,len-m));
			if(ans1==ans2) printf("YES\n");
			else printf("NO\n");
		}
	}
	
	return 0;
}