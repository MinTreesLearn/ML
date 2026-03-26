#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int M = 805;
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int n,p[M],id[M],rd[M];
int ask(vector<int> v)
{
	printf("? %d",v.size());
	for(int x:v) printf(" %d",x);
	puts("");fflush(stdout);
	return read();
}
int qry(int x)
{
	vector<int> v;
	for(int i=1;i<=n;i++)
		if(i!=x && !p[i]) v.push_back(i);
	return ask(v);
}
void get(int x,int a,int y,int b)
{
	for(int i=1;i<=n;i++)
	{
		if(!p[i] && !id[x] && rd[i]==a)
			{if(qry(i)) id[x]=i;}
		else if(!p[i] && !id[y] && rd[i]==b)
			{if(qry(i)) id[y]=i;}
	}
	p[id[x]]=x;p[id[y]]=y;
}
signed main()
{
	n=read();get(1,0,n,0);
	for(int t=2,l=2,r=n-1;l<=r;t<<=1)
	{
		//calc the remainder
		for(int i=1;i<=n;i++) if(!p[i])
		{
			vector<int> v;
			for(int j=1;j<=t;j++)
				if(j%t!=rd[i]) v.push_back(id[j]);
			v.push_back(i);
			if(ask(v)) rd[i]+=t>>1;
		}
		while(l<=2*t && l<=r)
			get(l,l%t,r,r%t),l++,r--;
	}
	if(p[1]>n/2) for(int i=1;i<=n;i++)
		p[i]=n-p[i]+1;
	printf("!");
	for(int i=1;i<=n;i++) printf(" %d",p[i]);
	puts("");fflush(stdout);
}