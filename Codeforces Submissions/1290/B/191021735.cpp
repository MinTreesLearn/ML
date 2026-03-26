#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int pre[N][30];
string s;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
		{
			pre[i][j]=pre[i-1][j]+(s[i]==j+'a');
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		int l,r,cnt=0;
		cin>>l>>r;
		if(l==r||s[l]!=s[r]) 
		{
			cout<<"YES\n";
			continue;
		}
		else
		{
			for(int i=0;i<26;i++)
			{
				if(pre[r][i]-pre[l][i]) cnt++;//这个区间有字符i+'a'
				if(cnt>=3) break;
			}
		}
		if(cnt>=3) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}