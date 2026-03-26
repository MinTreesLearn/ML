#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define F first
#define S second
#define endl "\n"
const int N=1e2+2 , inf=2e9;
pair<int,int> dp[N];
bool solve (int num , int cur)
{
	bool c=true;
	int time[N];
	dp[0]={cur,cur};
	time[0]=0;
	for (int i=1 ; i<=num ; i++)
	{
		int l,r;
		cin >> time[i] >> l >> r;
		int dif=time[i]-time[i-1];
		int a,b;
		a=dp[i-1].F-dif;	
		b=dp[i-1].S+dif;
		if (a>r || b<l)	c=false;
		dp[i].F = max (a,l);
		dp[i].S = min (b,r);
	}
	return c;
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int test;	cin >> test;
	while (test--)
	{
		int num;	cin >> num;
		int cur;		cin >> cur;
		if (solve (num,cur))	cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}