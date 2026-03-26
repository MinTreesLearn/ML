#pragma GCC optimaze(3)
#pragma GCC optimaze(2)
#pragma GCC optimaze("Ofast")
#pragma GCC optimaze("inline")
#pragma GCC optimaze("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define int long long
#define ll long long
#define N 5010
using namespace std;
const ll md=1e9+7;

int ss[N][N],s1[N],s2[N],a[N];
int n,m;
ll r1=1,r2=0;

inline void add(ll &x,ll y)
{
	x+=y;
	if (x>=md) x-=md;
}

signed main()
{
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s2[a[i]]++;
	}
	for (int i=1,x,y;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		ss[x][y]++;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			ss[i][j]+=ss[i][j-1];
		}
	}
	for (int i=0;i<=n;i++)
	{
		if (i)
		{
			s1[a[i]]++;
			s2[a[i]]--;
		}
		ll sum=1,num=0;
		int t1,t2;
		if (i)
		{
			t1=s1[a[i]],t2=s2[a[i]];
			t2=ss[a[i]][t2]-(t2>=t1);
			t1=ss[a[i]][t1]-ss[a[i]][t1-1];
			if (!t1) continue;
			if (t2)
			{
				sum=sum*t1*t2%md;
				num+=2;
			}
			else
			{
				sum=sum*t1%md;
				num++;
			}
		}
//		cout<<r1<<"   "<<r2<<endl;
		for (int j=1;j<=n;j++)
		{
			if (j==a[i]) continue;
			t1=s1[j],t2=s2[j];
			t1=ss[j][t1],t2=ss[j][t2];
//			cout<<t1<<"   "<<t2<<endl;
			if (!t1&&!t2) 
				continue;
			if (!t1||!t2) 
			{
				sum=sum*(t1+t2)%md;
				num++;
			}
			else if (t1==1&&t2==1)
			{
				sum=sum*2%md;
				num++;
			}
			else
			{
				sum=sum*(t1*t2-min(t1,t2))%md;
				num+=2;
			}
		}
//		cout<<i<<"   "<<num<<"   "<<sum<<endl;
		if (num>r2)
			r2=num,r1=sum;
		else if (num==r2)
			add(r1,sum);
//		cout<<i<<"   "<<r1<<"   "<<r2<<endl;
	}
	if (!r2) r1=1;
	printf("%lld %lld",r2,r1);
	return 0;
}