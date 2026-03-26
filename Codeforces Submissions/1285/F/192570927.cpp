// LUOGU_RID: 101638026
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m,ans;
ll mark[N],miu[N],v[N],cnt[N];
vector<ll> factors[N],primes;
inline void Mobius(ll n)
{
	miu[1]=1;
	for(ll i=2; i<=n; i++)
	{
		if(!v[i])
		{
			primes.push_back(i);
			miu[i]=-1;
		}
		for(ll j=0; i*primes[j]<=n; j++)
		{
			ll t=i*primes[j];
			v[t]=1;
			if(i%primes[j]==0) 
			{
				miu[t]=0;
				break;
			}
			miu[t]=-miu[i];
		}
	}
}
inline ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}
inline ll sum(ll x)
{
	ll res=0;
	for(ll i=0; i<factors[x].size(); i++)
	    res+=cnt[factors[x][i]]*miu[factors[x][i]];
	return res;
}
inline void add(ll x,ll y)
{
	for(ll i=0; i<factors[x].size(); i++)
	    cnt[factors[x][i]]+=y;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1; i<=n; i++)
	{
		ll x; scanf("%lld",&x);
		mark[x]=1;
		m=max(m,x);
	}
	ans=m;
	for(ll i=1; i<=m; i++)
		for(ll j=i; j<=m; j+=i)
		    factors[j].push_back(i);
	Mobius(m);
	for(ll r=1; r<=m; r++)
	{
		stack<ll> used;
		for(ll x=m/r; x>0; x--)
		{
			if(!mark[x*r]) continue;
			ll nums=sum(x);
			while(nums)
			{
				if(gcd(x,used.top())==1)
				{
					ans=max(ans,x*used.top()*r);
					nums--;
				}
				add(used.top(),-1);
				used.pop();
			}
			used.push(x);
			add(used.top(),1);
		}
		while(!used.empty())
		{
			add(used.top(),-1);
			used.pop();
		}
	}
	printf("%lld\n",ans);
	return 0;
}
