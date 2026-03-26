#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define x first
#define y second
const int N=1e5+10;



void solve()
{
	string s;
	int n;
	cin>>n>>s;
	int l=0,m=n;
	vector<int> res(n);
	for(int i=0;i<n;i++)
		if(i==n-1||s[i]=='>')
	{
		for(int j=i;j>=l;j--)
			res[j]=m--;
		l=i+1;
	}
	for(int i=0;i<n;i++)
		cout<<res[i]<<' ';
	cout<<endl;
	l=0,m=1;
	for(int i=0;i<n;i++)
		if(i==n-1||s[i]=='<')
	{
		for(int j=i;j>=l;j--)
			res[j]=m++;
		l=i+1;
	}
	for(int i=0;i<n;i++)
		cout<<res[i]<<' ';
	cout<<endl;
	
	return;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T=1;
	cin>>T;
	while(T--)
		solve();
	
	return 0;
}