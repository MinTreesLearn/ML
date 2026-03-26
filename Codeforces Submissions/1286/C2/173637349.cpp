#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<assert.h>
#include<vector>
struct edge
{
	int to;std::pair<int,int> s;
	edge(int to=0,std::pair<int,int> s=std::make_pair(0,0)){this->to=to,this->s=s;}
};
int n,f[105][30],p[105],q[105],ans[105];
char st[105];
std::vector<edge> a[105];
void print()
{
	printf("! ");
	for (int i=1;i<=n;i++) printf("%c",ans[i]+96);
	puts("");
	fflush(stdout);
}
void add(int x,int y,std::pair<int,int> s){/*printf("%d %d (%c,%c)\n",x,y,s.first+96,s.second+96);*/a[x].push_back(edge(y,s));a[y].push_back(edge(x,s));}
void solve(int x,int y)
{
	int len=(y-x+1),ss=len*(len+1)/2;
//	printf("ss = %d\n",len);
	assert(1<=x&&x<=y&&y<=n);
	printf("? %d %d\n",x,y);
	fflush(stdout);
	for (int i=0;i<=len+1;i++) for (int ch=1;ch<=26;ch++) f[i][ch]=0;
	for (int i=0;i<=len+1;i++) p[i]=q[i]=0;
	for (int i=1;i<=ss;i++)
	{
		scanf("%s",st+1);
		if (st[1]=='-') exit(0);
		int m=std::strlen(st+1);
		if (m>(len+1)/2) continue;
		for (int k=1;k<=m;k++) ++f[m][st[k]-96];
	}
	for (int s=(len+1)/2;s>=1;s--)
		for (int ch=1;ch<=26;ch++)
			f[s][ch]=f[s][ch]-f[s-1][ch];
	for (int s=1;s<=(len+1)/2;s++)
		for (int ch=1;ch<=26;ch++)
			f[s][ch]=f[s][ch]-f[s+1][ch];
//	for (int s=1;s<=(len+1)/2;s++)
//	{
//		for (int ch=1;ch<=26;ch++) printf("%d ",f[s][ch]);
//		puts("");
//	}
	for (int s=1;s<=(len+1)/1;s++)
		for (int ch=1;ch<=26;ch++)
		{
			if (!f[s][ch]) continue;
			if (f[s][ch]>1){p[s]=q[s]=ch;continue;}
//			printf("%d:%d\n",s,ch);
			if (p[s]) q[s]=ch;else p[s]=ch;
		}
	fflush(stdout);
}
void dfs(int v)
{
//	printf("dfs %d\n",v);
	for (int i=0;i<(int)a[v].size();i++)
	{
		int u=a[v][i].to;
		std::pair<int,int> pp=a[v][i].s;
		if (ans[u]!=-1) continue;
		if (ans[v]==pp.first) ans[u]=pp.second;
		else ans[u]=pp.first;
		dfs(u);
	}
}
int main()
{
	scanf("%d",&n);
	if (n==1)
	{
		printf("? 1 1\n");
		fflush(stdout);
		char st[10];
		scanf("%s",st+1);
		if (st[1]=='-') exit(0);
		printf("! %c\n",st[1]);
		fflush(stdout);
		return 0;
	}
	if (n==2)
	{
		printf("? 1 1\n");
		fflush(stdout);
		char st[10];
		scanf("%s",st+1);
		if (st[1]=='-') exit(0);
		printf("? 2 2\n");
		fflush(stdout);
		scanf("%s",st+2);
		if (st[2]=='-') exit(0);
		printf("! %c%c\n",st[1],st[2]);
		fflush(stdout);
		return 0;
	}
	if (n==3)
	{
		printf("? 1 1\n");
		fflush(stdout);
		char st[10];
		scanf("%s",st+1);
		if (st[1]=='-') exit(0);
		printf("? 2 2\n");
		fflush(stdout);
		scanf("%s",st+2);
		if (st[2]=='-') exit(0);
		printf("? 3 3\n");
		fflush(stdout);
		scanf("%s",st+3);
		if (st[2]=='-') exit(0);
		printf("! %c%c%c\n",st[1],st[2],st[3]);
		fflush(stdout);
		return 0;
	}
	int kk=n-n/3;
	if (n<=5) kk=n;
	if (n==6) kk=5;
	int l1=kk-(n-kk),r1=n;
//	printf("%d %d\n",l1,r1);
	int l2=l1-1,r2=n;
	int l3=1,r3=(n>2?2*(l2-2)+1:1);
	if (r3>n) r3=n;
	int pt=0;
	solve(l1,r1);
	for (int i=1;i<=n;i++) ans[i]=-1;
	for (int i=1;i<=(r1-l1)/2+1;i++)
	{
		int x=l1+i-1,y=r1-i+1;
		if (x!=y) add(x,y,std::make_pair(p[i],q[i]));
		else if (x==y) ans[x]=p[i],pt=x;
	}
	solve(l2,r2);
	for (int i=1;i<=(r2-l2)/2+1;i++)
	{
		int x=l2+i-1,y=r2-i+1;
		if (x!=y) add(x,y,std::make_pair(p[i],q[i]));
		else if (x==y) ans[x]=p[i];
	}
	solve(l3,r3);
	for (int i=1;i<=(r3-l3)/2+1;i++)
	{
		int x=l3+i-1,y=r3-i+1;
		if (x!=y) add(x,y,std::make_pair(p[i],q[i]));
		else if (x==y) ans[x]=p[i];
	}
//	printf("%d\n",pt);
	assert(pt);
	dfs(pt);
	print();
	return 0;
}