#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int maxdp[26], ans[200001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, len, maxn;
	string s;
	cin>>n;
	cin>>s;
	len = s.length();
	for(int i=0;i<=len-1;++i)
	{
		ans[i] = 1;
		for(int j=25;j>(s[i]-'a');--j)
		{
			ans[i] = max(ans[i], maxdp[j]+1);
		}
		maxdp[s[i]-'a'] = ans[i];
		maxn = max(maxn, maxdp[s[i]-'a']);
	}
	cout<<maxn<<"\n";
	for(int i=0;i<=len-1;++i)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}