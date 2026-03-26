#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=50+5;
const int Mod=998244353;
int n,m,ans,a[N],b[N],c[N<<1],f[N],g[N];
int qpow(int x,int k)
{	int res=1;
	while(k)
	{	if(k&1)res=1ll*res*x%Mod;
		x=1ll*x*x%Mod,k>>=1;
	}
	return res;
}
int main()
{	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{	scanf("%d%d",&a[i],&b[i]);
		c[++m]=a[i],c[++m]=++b[i];
	}
	sort(c+1,c+1+m);
	m=unique(c+1,c+1+m)-c-1;
	for(int i=1;i<=n;i++)
	{	a[i]=lower_bound(c+1,c+1+m,a[i])-c;
		b[i]=lower_bound(c+1,c+1+m,b[i])-c;
	}
	f[0]=1;
	for(int j=m-1;j>=1;j--)
	{	int l=c[j+1]-c[j];
		g[0]=1;
		for(int i=1;i<=n;i++)g[i]=1ll*g[i-1]*(l+i-1)%Mod*qpow(i,Mod-2)%Mod;
		for(int i=n;i>=1;i--)
			if(a[i]<=j&&j<b[i])for(int o=1,k=i-1;k>=0;k--,o++)
			{	f[i]=(f[i]+1ll*g[o]*f[k]%Mod)%Mod;
				if(a[k]>j||j>=b[k])break;
			}
	}
	ans=f[n];
	for(int i=1;i<=n;i++)ans=1ll*ans*qpow(c[b[i]]-c[a[i]],Mod-2)%Mod;
	printf("%d\n",ans);
	return 0;
}