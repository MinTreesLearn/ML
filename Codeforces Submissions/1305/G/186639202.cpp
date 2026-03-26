// LUOGU_RID: 97972407
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
constexpr int Max=262144+100,Log=18,Lim=262144;
int n,a[Max],b[Max],fa[Max];
int find(int i)
{
	return i==fa[i]?i:fa[i]=find(fa[i]);
}
inline bool unite(int x,int y)
{
	x=find(x),y=find(y);
	if(x!=y)
	{
		fa[x]=y;
		return true;
	}
	return false;
}
struct node
{
	int x1,y1,x2,y2;
	inline node(const int &x,const int &y)
	{
		x1=x,y1=y,x2=0,y2=0;
	}
	inline node()
	{
		x1=y1=x2=y2=0;
	}
};
node f[Max];
inline void clear()
{
	for(int i=0;i<Lim;++i)
		f[i]=node();
}
inline void update(node &a,const node &b)
{
	if(b.x1>a.x1)
	{
		if(a.y1!=b.y1)
			a.x2=a.x1,a.y2=a.y1;
		a.x1=b.x1,a.y1=b.y1;
	}
	if(b.x1>a.x2&&b.y1!=a.y1)
		a.x2=b.x1,a.y2=b.y1;
	if(b.x2>a.x2&&b.y2!=a.y1)
		a.x2=b.x2,a.y2=b.y2;
}
inline void solve()
{
	for(int j=0;j<Log;++j)
		for(int i=0;i<Lim;++i)
			if(!(i>>j&1))
				update(f[i],f[i|1<<j]);
}
int val[Max],pos[Max];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i],b[i]=a[i]^(Lim-1);
	for(int i=0;i<=n;++i)
		fa[i]=i;
	ll ans=0;
	int cnt=n+1;
	while(cnt>1)
	{
		clear();
		for(int i=0;i<=n;++i)
			update(f[b[i]],node(a[i],find(i)));
		solve();
		for(int i=0;i<=n;++i)
			val[i]=-1,pos[i]=0;
		for(int i=0;i<=n;++i)
		{
			const int x=find(i),k=a[i];
			int u,v;
			if(f[k].y1==x)
				u=f[k].x2,v=f[k].y2;
			else
				u=f[k].x1,v=f[k].y1;
			u+=a[i];
			if(val[x]<u)
				val[x]=u,pos[x]=v;
		}
		for(int i=0;i<=n;++i)
			if(find(i)==i&&unite(i,pos[i]))
				ans+=val[i],--cnt;
	}
	for(int i=1;i<=n;++i)
		ans-=a[i];
	cout<<ans<<"\n";
	return 0;
}