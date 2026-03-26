#include<bits/stdc++.h>
#define ll long long
#define f(i,a,b) for (ll i=a;i<=b;i++)
#define fx(i,a,b) for (ll i=a;i>=b;i--)
using namespace std;
const ll maxn=2e5+5;
inline ll read()
{
	ll l=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9')
	{
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9') l=(l<<3)+(l<<1)+(c-'0'),c=getchar();
	return l*f;
}
ll n,m,k,t;
inline ll id(ll x,ll y,ll z)
{
	return (x-1)*m*k+(y-1)*k+z;
}
ll a[maxn];
vector<ll> tag[maxn];
ll dx[6]={1,-1,0,0,0,0},dy[6]={0,0,1,-1,0,0},dz[6]={0,0,0,0,1,-1};
inline bool chk(ll x,ll y,ll z)
{
	return 1<=x && x<=n && 1<=y && y<=m && 1<=z && z<=k;
}
void ins(ll,ll,ll,ll,ll);
void del(ll,ll,ll);
void ins(ll x,ll y,ll z,ll d,ll t)
{
	ll i=id(x,y,z);
	if (!chk(x,y,z))
	{
		if (!t) return;
		puts("-1");
		exit(0);
	}
	if (!t)
	{ 
		if (a[i]>0) del(x,y,z);
		a[i]=0;
		ins(x+dx[d],y+dy[d],z+dz[d],d,t);
	}
	else if (a[i]==-1 || a[i]==t) a[i]=t,tag[i].push_back(d);
	else if (!a[i]) ins(x+dx[d],y+dy[d],z+dz[d],d,t);
	else del(x,y,z),a[i]=0,ins(x+dx[d],y+dy[d],z+dz[d],d,t);
}
inline void del(ll x,ll y,ll z)
{
	ll i=id(x,y,z);
	while (!tag[i].empty())
	{
		ll d=tag[i].back();
		tag[i].pop_back();
		if (chk(x+dx[d],y+dy[d],z+dz[d]))
		{
			ins(x+dx[d],y+dy[d],z+dz[d],d,a[i]);
		}
	}
}
signed main()
{
	n=read();
	m=read();
	k=read();
	memset(a,-1,sizeof(a));
	f(i,1,m) f(j,1,k) t=read(),ins(1,i,j,0,t);
	f(i,1,m) f(j,1,k) t=read(),ins(n,i,j,1,t);
	f(i,1,n) f(j,1,k) t=read(),ins(i,1,j,2,t);
	f(i,1,n) f(j,1,k) t=read(),ins(i,m,j,3,t);
	f(i,1,n) f(j,1,m) t=read(),ins(i,j,1,4,t);
	f(i,1,n) f(j,1,m) t=read(),ins(i,j,k,5,t);
	f(i,1,n*m*k) if (a[i]==-1) cout<<"1 ";else cout<<a[i]<<" ";cout<<endl;
}