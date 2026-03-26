// LUOGU_RID: 93070834
#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,m,t=0,t1=0;
LL res,ans=1;
int l[52],r[52],id[102],val[102],len[102];
LL inv[52];
LL f[102][52];
inline LL Pow(int a,int b)
{
	if(!b)return 1;
	LL c=Pow(a,b>>1);
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline bool cmp(int x,int y)
{
	return val[x]<val[y];
}
inline void init()
{
	inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=(-inv[mod%i]*(mod/i))%mod;
}
int main()
{
	scanf("%d",&n),init(),f[0][0]=1;
	for(int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]),++t,val[id[t]=t]=-r[i],++t,val[id[t]=t]=-l[i]+1,(ans*=r[i]-l[i]+1)%=mod;
	sort(id+1,id+t+1,cmp);
	for(int i=1;i<=t;++i)
	{
		if(i==1 || val[id[i]]^val[id[i-1]])len[t1]=val[id[i]]-val[id[i-1]],++t1;
		(id[i]&1? l[(id[i]+1)>>1]:r[id[i]>>1])=t1;
	}
	for(int i=1;i<t1;++i)
	{
		for(int j=1;j<=n;++j)
		{
			res=1;
			for(int k=j-1;~k && l[k+1]<=i && i<r[k+1];--k)(f[i][j]+=f[i-1][k]*((((res*=(len[i]+(j-k)-1))%=mod)*=inv[j-k])%=mod))%=mod;
		}
		for(int j=0;j<=n;++j)(f[i][j]+=f[i-1][j])%=mod;
	}
	return 0&printf("%lld",(((Pow(ans,mod-2)*f[t1-1][n])%mod)+mod)%mod);
}