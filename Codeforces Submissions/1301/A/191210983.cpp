#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define x first
#define y second
const int N=1e5+10;

string a,b,c;

void solve()
{
	cin>>a>>b>>c;
	bool f=0;
	for(int i=0;i<a.size();i++)
		if(a[i]!=c[i]&&b[i]!=c[i])
	{
		f=1;
		break;
	}
	if(f)
		cout<<"NO\n";
	else 
		cout<<"YES\n";
	
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