#include<cstdio>
#include<cstdlib>
#include<utility>
#include<vector>
#include<random>
#define mod 998244353
std::mt19937 seed(*new int);
std::pair<long long,int> operator +(std::pair<long long,int> x,std::pair<long long,int> y)
{return std::make_pair(x.first+y.first,x.second+y.second);}
struct tree
{
	std::pair<long long,int> s[2100005];
	void pushup(int k){s[k]=s[k*2]+s[k*2+1];}
	void update(int k,int l,int r,int x)
	{
		if (l==r) return s[k]=s[k]+std::make_pair(1ll*x,1),void();
		int mid=(l+r)/2;
		if (x<=mid) update(k*2,l,mid,x);
		if (mid<x) update(k*2+1,mid+1,r,x);
		pushup(k);
	}
	long long ask(int k,int l,int r,int x)
	{
		if (x<=l) return s[k].first-1ll*s[k].second*(x-1);
		int mid=(l+r)/2;
		long long ans=0;
		if (x<=mid) ans=ans+ask(k*2,l,mid,x);
		ans=ans+ask(k*2+1,mid+1,r,x);
		return ans;
	}
};
tree tt;
int n,m;
char s[500005],t[500005],p[1000005];
int f[500005],g[500005];
long long sh[500005],th[500005],ph[1000005],pw[1000005],base,ans=0;
std::vector<long long> add[1000005],del[1000005];
int getrd(int l,int r){std::uniform_int_distribution<int> rd(l,r);return rd(seed);}
long long getph(int l,int r){return ((ph[r]-ph[l-1]*pw[r-l+1])%mod+mod)%mod;}
long long getsh(int l,int r){return ((sh[r]-sh[l-1]*pw[r-l+1])%mod+mod)%mod;}
long long getth(int l,int r){return ((th[r]-th[l-1]*pw[r-l+1])%mod+mod)%mod;}
int lcp(int k,int l,int r)
{
	if (l==r) return l;
	int mid=(l+r+1)/2;
	if (getph(1,mid)==getsh(k,k+mid-1)) return lcp(k,mid,r);
	return lcp(k,l,mid-1); 
}
int lcs(int k,int l,int r)
{
	if (l==r) return l;
	int mid=(l+r+1)/2;
	if (getph(m-mid+1,m)==getth(k-mid+1,k)) return lcs(k,mid,r);
	return lcs(k,l,mid-1); 
}
int main()
{
	base=getrd(10000,20000);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	scanf("%s",t+1);
	scanf("%s",p+1);
	pw[0]=1;for (int i=1;i<=n;i++) pw[i]=pw[i-1]*base%mod;
	for (int i=1;i<=n;i++) sh[i]=(sh[i-1]*base+s[i])%mod,th[i]=(th[i-1]*base+t[i])%mod;
	for (int i=1;i<=m;i++) ph[i]=(ph[i-1]*base+p[i])%mod;
	for (int i=1;i<=n;i++)
	{
		f[i]=(s[i]!=p[1]?0:lcp(i,1,n-i+1));
		g[i]=(t[i]!=p[m]?0:lcs(i,1,i));
	}
	for (int i=1;i<=n;i++)
	{
		add[i].push_back(std::max(m-f[i],1));
		if (i+m-1<=n) del[i+m-1].push_back(std::max(m-f[i],1));
	}
	for (int i=n;i>=1;i--)
	{
		tt.update(1,0,m,std::min(g[i],m-1));
		for (int d=0;d<(int)add[i].size();d++) ans=ans+tt.ask(1,0,m,add[i][d]);
		for (int d=0;d<(int)del[i].size();d++) ans=ans-tt.ask(1,0,m,del[i][d]);
	}
	printf("%lld\n",ans);
	return 0;
}