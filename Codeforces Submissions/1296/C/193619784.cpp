#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll base = 1000000;
ll num[200001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T, n, len, ans, l, r, tmp;
	string s;
	cin>>T;
	while(T--)
	{//
		map<ll, ll>mp;
		cin>>n;
		cin>>s;
		len = s.length();
		ans = 1e9;
		//两个标准, x, y, 找两个标准都相同高度位置记录
		mp[0] = -1;
		for(ll i=0;i<=len-1;++i)
		{
			if(s[i]=='L')
			{
				num[i+1] = num[i] + base;					
			}
			else if(s[i]=='R')
			{
				num[i+1] = num[i] - base;
			}
			else if(s[i]=='U')
			{
				num[i+1] = num[i] + 1;
			}
			else if(s[i]=='D')
			{
				num[i+1] = num[i] - 1;
			}
			tmp = mp[num[i+1]];
			if(tmp==0)
			{
				mp[num[i+1]] = i+1;
			}
			else
			{
				if(tmp==-1)
				{
					tmp = 0;
				}
				if(ans>i+1-tmp)
				{
					ans = (i+1)-tmp;
					l = tmp+1;
					r = i+1;
				}
				mp[num[i+1]] = i+1;
			}
		}
		if(ans==1e9)
		{
			cout<<-1<<"\n";
		}
		else
		{
			cout<<l<<" "<<r<<"\n";
		}
	}
	return 0;
}