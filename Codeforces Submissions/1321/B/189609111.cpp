#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define x first
#define y second
const int N=1e5+10;

map<int,int>b;

void slove()
{
	int n;
	cin>>n;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		b[a-i]+=a;
		res=max(res,b[a-i]);
	}
	
	cout<<res<<endl;
	return;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	int T=1;
//	cin>>T;
	while(T--)
		slove();
	
	return 0;
}