#include<stdio.h>
#include<bits/stdc++.h>
#define fir first
#define sec second
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 int128;
typedef __uint128_t uint128;
typedef pair<int,int> pii;
template<typename type>
inline void chmin(type &x,const type &y)
{
	if(x>y)
		x=y;
}
template<typename type>
inline void chmax(type &x,const type &y)
{
	if(x<y)
		x=y;
}
constexpr int Max=2e5+100;
constexpr int dx[6]={1,-1,0,0,0,0},dy[6]={0,0,1,-1,0,0},dz[6]={0,0,0,0,1,-1};
int n,m,o,ans[Max];
vector<int>p[Max];
inline int ask_id(const int &x,const int &y,const int &z)
{
	return (x-1)*m*o+(y-1)*o+z;
}
void del(int x,int y,int z);
void dfs(int x,int y,int z,int d,int k)
{
	bool in=x>=1&&x<=n&&y>=1&&y<=m&&z>=1&&z<=o;
	if(!in&&k)
		cout<<"-1\n",exit(0);
	if(!in)
		return;
	int i=ask_id(x,y,z);
	if(!k)
	{
		if(ans[i]>0)
			del(x,y,z);
		ans[i]=0;
		dfs(x+dx[d],y+dy[d],z+dz[d],d,0);
		return;
	}
	if(!~ans[i])
	{
		ans[i]=k;
		p[i].push_back(d);
		return;
	}
	if(!ans[i])
		dfs(x+dx[d],y+dy[d],z+dz[d],d,k);
	else
		if(ans[i]!=k)
		{
			del(x,y,z),ans[i]=0;
			dfs(x+dx[d],y+dy[d],z+dz[d],d,k);
		}
		else
			p[i].push_back(d);
}
void del(int x,int y,int z)
{
	int i=ask_id(x,y,z);
	while(!p[i].empty())
	{
		int d=p[i].back();
		p[i].pop_back();
		dfs(x+dx[d],y+dy[d],z+dz[d],d,ans[i]);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>o;
	memset(ans,-1,sizeof(ans));
	int x;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=o;++j)
			cin>>x,dfs(1,i,j,0,x);
	for(int i=1;i<=m;++i)
		for(int j=1;j<=o;++j)
			cin>>x,dfs(n,i,j,1,x);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=o;++j)
			cin>>x,dfs(i,1,j,2,x);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=o;++j)
			cin>>x,dfs(i,m,j,3,x);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>x,dfs(i,j,1,4,x);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>x,dfs(i,j,o,5,x);
	for(int i=1;i<=n;cout<<"\n",++i)
		for(int j=1;j<=m;cout<<"\n",++j)
			for(int k=1,x;k<=o;++k)
				cout<<(~(x=ans[ask_id(i,j,k)])?x:0)<<" ";
	return 0;
}