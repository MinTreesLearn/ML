#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
vector<int> p[5005];
int lst[5005],cnt[5005],w[5005];
vector<int> s[5005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=2;i<=5000;i++)
	{
		if(p[i].empty())
		{
			for(int j=i;j<=5000;j+=i)
			{
				int x=j;
				while(x%i==0)
				{
					p[j].push_back(i);
					x/=i;
				}
			}
			for(int j=i;j<=5000;j++) lst[j]=i;
		}
	}
	for(int i=2;i<=5000;i++) w[i]=p[i].size()+w[i-1];
	int sum=0,L=0,R=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		++cnt[x];
		ans+=w[x];
	}
	for(int i=2;i<=5000;i++)
	{
		if(lst[i]!=lst[i-1]) sum=0;
		sum+=cnt[i];
		if(sum>n/2)
		{
			for(int j=1;j<=5000;j++)
				if(lst[j]==lst[i]){if(!L) L=j;R=j;}
			break;
		}
	}
	for(int i=L;i<=R;i++)
	{
		for(int j=1;j<=i;j++)
			for(auto t:p[j]) s[i].push_back(t);
		sort(s[i].begin(),s[i].end());
		reverse(s[i].begin(),s[i].end());
	}
	int nowl=L,nowr=R;
	for(int len=1;len<=20000;len++)
	{
		if(!nowl) break;
		int sum=0;
		for(int i=nowl;i<=nowr;i++) sum+=cnt[i];
		ans-=sum,ans+=n-sum;
		map<int,int> mp;
		int pos=-1;
		for(int j=nowl;j<=nowr;j++)
		{
			if(s[j].size()<=len) continue;
			if((mp[s[j][len]]+=cnt[j])>n/2)
			{
				pos=s[j][len];
				break;
			}
		}
		int L=0,R=0;
		for(int j=nowl;j<=nowr;j++)
		{
			if(s[j].size()<=len) continue;
			if(s[j][len]==pos)
			{
				if(!L) L=j;
				R=j;
			}
		}
		nowl=L,nowr=R;
	}
	cout << ans;
	return 0;
}