#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define x first
#define y second
const int N=1e5+10;

int a[N];

void solve()
{
	int n,d;
	cin>>n>>d;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int res=a[0];
	for(int i=1;i<n&&d>=i;i++)
	{
		if(d>a[i]*i)
			res+=a[i],d-=a[i]*i;
		else
			res+=d/i,d-=i*d/i;
	}	
	cout<<res<<endl;
	
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