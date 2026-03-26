#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define x first
#define y second
const int N=1e5+10;



void solve()
{
	int n,x,y;
	cin>>n>>x>>y;
	int t=(x+y+1)-n;
	int a=min(max(t,1ll),n);
	int b=min(x+y-1,n);
	cout<<a<<' '<<b<<endl;
	
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