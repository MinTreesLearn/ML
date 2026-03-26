#include<bits/stdc++.h>
using namespace std;
namespace my_std
{
	typedef long long ll;
	const ll inf=0x3f3f3f3f;
	#define fr(i,x,y) for(ll i=(x);i<=(y);++i)
	#define pfr(i,x,y) for(ll i=(x);i>=(y);--i)
	#define space putchar(' ')
	#define enter putchar('\n')
	inline ll read()
	{
		ll sum=0,f=1;char ch=0;
		while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
		while(isdigit(ch)) sum=sum*10+(ch^48),ch=getchar();
		return sum*f;
	}
	inline void write(ll x)
	{
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	inline void writesp(ll x){write(x),space;}
	inline void writeln(ll x){write(x),enter;}
}
using namespace my_std;
const ll N=1050;
ll n,m,k,tot,lcp[N][N],f[N][N],sum[N][N];char s[N];
struct sub{ll l,r,len;}a[N*N];
inline bool cmp(sub a,sub b)
{
	ll len=lcp[a.l][b.l];
	if(min(a.len,b.len)<=len) return a.len<b.len;
	return s[a.l+len]<s[b.l+len];
}
inline ll solve(sub t)
{
	f[n+1][0]=sum[n+1][0]=1;
	pfr(i,n,1) sum[i][0]=1;
	fr(j,1,m) pfr(i,n,1) 
	{
		ll len=min(lcp[t.l][i],t.len),lim=i+len-1;
		if(t.len<=len||s[lim+1]>s[t.l+len])
		{
			if(len<t.len) ++lim;
			f[i][j]=sum[lim+1][j-1];
		}
		else f[i][j]=0;
		sum[i][j]=min(k,sum[i+1][j]+f[i][j]);
	}
	return f[1][m];
}
int main(void)
{
	n=read(),m=read(),k=read(),scanf("%s",s+1);
	pfr(i,n,1) pfr(j,n,1) lcp[i][j]=(s[i]==s[j])?(lcp[i+1][j+1]+1):0;
	fr(i,1,n) fr(j,i,n) a[++tot]=(sub){i,j,j-i+1};
	sort(a+1,a+tot+1,cmp);ll l=1,r=tot,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(solve(a[mid])>=k) ans=mid,l=mid+1;
		else r=mid-1;
	}
	fr(i,a[ans].l,a[ans].r) putchar(s[i]);
	return 0;
}////
 	 			 		 	 	 					 	 	    	  	