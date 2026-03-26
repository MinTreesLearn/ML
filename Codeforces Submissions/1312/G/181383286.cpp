
#include<bits/stdc++.h>
#define ll long long
#define ls u<<1
#define rs u<<1|1
#define mm(x) memset(x,0,sizeof(x))
using namespace std;
int read()
{
	int a=0;int f=0;char p=getchar();
	while(!isdigit(p)){f|=p=='-';p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=getchar();}
	return f?-a:a;
}
const int INF=998244353;
const int P=998244353;
const int N=1e6+5;
int T;
int n,m;
char s[N];
int trip[N][26];
int pos[N];
int tot;
int dp[N];
int t[N],top;
int cnt;
int q[N];
bool col[N];
void dfs(int u)
{
	++top;	t[top]=min(t[top-1],dp[u]-cnt);
	if(col[u])
	{
		++cnt;
		dp[u]=min(dp[u],t[top]+cnt);
	}
	for(int i=0;i<26;++i)
	{
		int v=trip[u][i];
		if(!v)	continue;
		dp[v]=dp[u]+1;
		dfs(v);
	}
	top--;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		int fa=read();	scanf("%s",s+1);
		int ch=s[1]-'a';
		if(!trip[fa][ch])	trip[fa][ch]=++tot;
		pos[i]=trip[fa][ch];
	}
	m=read();
	for(int i=1;i<=m;++i)	q[i]=pos[read()];
	for(int i=1;i<=m;++i)	col[q[i]]=true;
	dfs(0);
	for(int i=1;i<=m;++i)	printf("%d\n",dp[q[i]]);
	return 0;
}