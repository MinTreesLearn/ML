// Lynkcat.
// Problem: E. Cow and Treats
// Contest: Codeforces - Codeforces Round #621 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1307/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 1000000007
#define int ll
#define N 5005
using namespace std;
int cnt[N][4];
int tot,nowans;
poly L[N],R[N];
int stat[N];
int s[N],f[N],h[N],l[N],r[N];
int n,m;
int mx,ans;
inline int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void del(int x,int y)
{
	int o=0;
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			if ((i&1)&&((j>>1)&1))
			{
				if (i==j) o=max(o,min(2ll,cnt[f[x]][i]));
				else
					o=max(o,(int)(cnt[f[x]][i]>0)+(cnt[f[x]][j]>0));
			}
	tot-=o;
	int nowans=0;
	if (o==2)
	{
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
				if ((i&1)&&((j>>1)&1))
				{
					int now=0;
					if (i==j) now=min(2ll,cnt[f[x]][i]);
					else
						now=(cnt[f[x]][i]>0)+(cnt[f[x]][j]>0);
					if (now==o)
					{
						if (i==j)
						{
							nowans=(nowans+cnt[f[x]][i]*(cnt[f[x]][i]-1+mod)%mod)%mod;
						}
						else
						{
							nowans=(nowans+cnt[f[x]][i]*cnt[f[x]][j]%mod)%mod;
						}
					}
				}
	} else
	if (o==1)
	{
		for (int i=0;i<4;i++)
			if (i&1) nowans=(nowans+cnt[f[x]][i])%mod;
		for (int i=0;i<4;i++)
			if ((i>>1)&1) nowans=(nowans+cnt[f[x]][i])%mod;
	} else nowans=1;
	::nowans=::nowans*quickPower(nowans,mod-2)%mod;
}
void add(int x,int y)
{
	int o=0;
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			if ((i&1)&&((j>>1)&1))
			{
				if (i==j) o=max(o,min(2ll,cnt[f[x]][i]));
				else
					o=max(o,(int)(cnt[f[x]][i]>0)+(cnt[f[x]][j]>0));
			}
	tot+=o;
	int nowans=0;
	if (o==2)
	{
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
				if ((i&1)&&((j>>1)&1))
				{
					int now=0;
					if (i==j) now=min(2ll,cnt[f[x]][i]);
					else
						now=(cnt[f[x]][i]>0)+(cnt[f[x]][j]>0);
					if (now==o)
					{
						if (i==j)
						{
							nowans=(nowans+cnt[f[x]][i]*(cnt[f[x]][i]-1+mod)%mod)%mod;
						}
						else
						{
							nowans=(nowans+cnt[f[x]][i]*cnt[f[x]][j]%mod)%mod;
						}
					}
				}
	} else
	if (o==1)
	{
		for (int i=0;i<4;i++)
			if (i&1) nowans=(nowans+cnt[f[x]][i])%mod;
		for (int i=0;i<4;i++)
			if ((i>>1)&1) nowans=(nowans+cnt[f[x]][i])%mod;
	} else nowans=1;
	::nowans=::nowans*nowans%mod;
}
void ers(int x,int y)
{
	del(x,y);
	cnt[f[x]][stat[x]]--;
	stat[x]-=(1<<y);
	cnt[f[x]][stat[x]]++;
	add(x,y);
}
void ins(int x,int y)
{
	del(x,y);
	cnt[f[x]][stat[x]]--;
	stat[x]+=(1<<y);
	cnt[f[x]][stat[x]]++;
	add(x,y);
}
int qry(int x,int o)
{
	int nowans=0;
	if (o==2)
	{
		for (int i=0;i<4;i++)
			if ((i>>1)&1) nowans=(nowans+cnt[f[x]][i])%mod;
	} else
	if (o==1)
	{
		for (int i=0;i<4;i++)
			if (i&1) nowans=(nowans+cnt[f[x]][i])%mod;
	} else nowans=1;
	return nowans;
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>s[i];
	for (int i=1;i<=m;i++)
	{
		cin>>f[i]>>h[i];
		int x=0;
		for (int j=1;j<=n;j++)
		{
			x+=(s[j]==f[i]);
			if (x==h[i]) 
			{
				l[i]=j;
				break;
			}
		}
		if (!l[i]) l[i]=n+1;
		x=0;
		for (int j=n;j>=1;j--)
		{
			x+=(s[j]==f[i]);
			if (x==h[i])
			{
				r[i]=j;
				break;
			}
		}
		L[l[i]].push_back(i);
		R[r[i]].push_back(i);
	}
	nowans=1;
	for (int i=1;i<=n;i++) cnt[f[i]][stat[i]]++;
	for (int i=1;i<=n;i++)
		for (auto u:R[i])
			ins(u,1);
	if (tot>mx)
	{
		mx=tot;
		ans=nowans;
	}
	for (int i=1;i<=n;i++)
	{
		for (auto u:L[i])
			ins(u,0);
		for (auto u:R[i])
			ers(u,1);
		int x=tot,y=nowans;
				for (auto u:L[i])
				{
					if (tot>mx)
					{
						mx=tot;
						ers(u,0);
						int oo=0;
						if (stat[u]>1)
							ers(u,1),oo=1;
						del(u,0);
						if (mx-tot==2)
							ans=(nowans*qry(u,2)%mod)%mod;
						else ans=(nowans)%mod;
							
						add(u,0);
						ins(u,0);
						if (oo) ins(u,1);
					} else
					if (tot==mx) 
					{
						mx=tot;
						ers(u,0);
						int oo=0;
						if (stat[u]>1)
							ers(u,1),oo=1;
						del(u,0);
						if (mx-tot==2)
							ans=(ans+nowans*qry(u,2)%mod)%mod;
						else ans=(ans+nowans)%mod;
						
						add(u,0);
						ins(u,0);
						if (oo) ins(u,1);
					}
				}
	}
	if (mx==0) return cout<<"0 1\n",void();
	cout<<mx<<" "<<ans<<'\n';
		
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
