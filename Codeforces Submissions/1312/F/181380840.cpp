#include<bits/stdc++.h>
#define ll long long
#define ls u<<1
#define rs u<<1|1
#define mm(x) memset(x,0,sizeof(x))
using namespace std;
ll read()
{
	ll a=0;ll f=0;char p=getchar();
	while(!isdigit(p)){f|=p=='-';p=getchar();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=getchar();}
	return f?-a:a;
}
const int INF=998244353;
const int P=998244353;
const int N=1e6+5;
int T;
int n,m;
int x,y,z;
int ans;
ll val[N];
int SG[N][3];
int t[N],top;
int att[3];
int r;
int find(ll u)
{
	if(u<=100)	return u;
	return (u-100)%r+100;
}
void solve()
{
	n=read();	ans=0;	t[0]=-1;
	for(int i=0;i<3;++i)	att[i]=read();
	for(int i=1;i<=300;++i)
	{
		for(int j=0;j<3;++j)
		{
			top=0;
			for(int k=0;k<3;++k)
			{
				if(j==1&&k==1)	continue;
				if(j==2&&k==2)	continue;
				t[++top]=SG[max(0,i-att[k])][k];
			}
			sort(t+1,t+top+1);
			SG[i][j]=t[top]+1;
			for(int k=0;k<top;++k)
				if(t[k]+1<t[k+1])
				{
					SG[i][j]=t[k]+1;
					break;
				}
		}
	}
	for(int i=1;i<=100;++i)
	{
		bool flag=true;
		for(int j=1;j<=200;++j)
			for(int k=0;k<3;++k)
				if(SG[100+j][k]!=SG[100+j%i][k])	flag=false;
		if(flag)	{r=i;break;}
	}
	int sum=0;
	for(int i=1;i<=n;++i)	val[i]=read();
	for(int i=1;i<=n;++i)
	{
		int now=SG[find(val[i])][0];
		sum^=now;
	}
	for(int i=1;i<=n;++i)
	{
		int now=SG[find(val[i])][0];
		for(int j=0;j<3;++j)
		{
			int ts=SG[find(max(0ll,val[i]-att[j]))][j];
			if((sum^now^ts)==0)	ans++;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	T=read();
	while(T--)	solve();
	return 0;
}