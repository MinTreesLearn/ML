/*
わんわん……わんだほーいっ☆
Wonderhoy!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9')	f=(c=='-'?-1:f),c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
void write(LL x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
LL n,a[20];
LL sum[1<<20],cnt[1<<20];
inline LL Abs(LL x){return x<0?-x:x;}
inline LL lowbit(LL x){return x&(-x);}
bool f[1<<20];
LL g[1<<20];
int main(){
	n=read();
	for(LL i=0;i<n;++i)
	{
		a[i]=read();
		if(!a[i])	--i,--n;
	}
	for(LL S=1;S<(1<<n);++S)	cnt[S]=cnt[S^lowbit(S)]+1;
	for(LL S=0;S<(1<<n);++S)
	{
		for(LL i=0;i<n;++i)
		{
			if((S>>i)&1)
			{
				sum[S]=sum[S^(1<<i)]+a[i];
				break;
			}
		}
	}
	for(LL S=1;S<(1<<n);++S)	if((cnt[S]^sum[S])&1)	for(LL T=S&(S-1);T && !f[S];T=S&(T-1))	if(Abs(sum[T]-sum[T^S])<cnt[S])	f[S]=true;
	for(LL S=1;S<(1<<n);++S)
	{
		if(f[S] && !g[S])
		{
			g[S]=1;
			LL U=((1<<n)-1)^S;
			for(LL T=U;T;T=U&(T-1))	g[S|T]=max(g[S|T],g[T]+1);
		}
	}
	write(n-g[(1<<n)-1]),puts("");
	return 0;
}