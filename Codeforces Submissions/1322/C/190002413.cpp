// LUOGU_RID: 100364926
#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m;
int a[500005];
int b[500005];
int mod=1e18;
struct node
{
	int num,xb;
}c[500005];
bool cmp(node aa,node bb)
{
	return aa.num<bb.num;
}
signed main()
{
	ios::sync_with_stdio(0);
	srand(time(0));
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) c[i].num=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) b[i]=(1ll*rand()*rand()*rand()+rand())%mod;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin>>u>>v;
			c[v].num^=b[u];
			c[v].xb=v;
		}
		sort(c+1,c+n+1,cmp);
		int now=-1,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(!c[i].num) continue;
			if(c[i].num==c[i-1].num) sum+=a[c[i].xb];
			else
			{
				if(now<0) now=sum;
				else now=__gcd(now,sum);
				sum=a[c[i].xb];
			}
		}
		if(now<0) now=sum;
		else now=__gcd(now,sum);
		cout<<now<<endl;
	}
}