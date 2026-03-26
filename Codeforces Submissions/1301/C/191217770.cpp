#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
ll n,m;
inline ll cal(ll x)
{
	return x * (x+1) / 2;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		n -= m;
		ll k = n/(m+1),r = n % (m+1);
		ll ans = cal(n+m) - cal(k+1) * r - cal(k) *(m+1-r);
		printf("%lld\n",ans);
	}
	return 0;
}
