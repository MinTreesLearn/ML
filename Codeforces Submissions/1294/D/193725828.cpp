#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q, x, y, ans;
	map<int, int>mp;
	cin>>q>>x;
	ans = 0;
	for(int i=1;i<=q;++i)
	{
		cin>>y;
		++mp[y%x];
		while(mp[ans%x])
		{
			--mp[ans%x];
			++ans;
		}
		cout<<ans<<"\n";
	}
	return 0;
}