#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#define ll long long
#define inf 0x3f3f3f3f
#define INF  0x3f3f3f3f3f3f3f3f
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		int m;
		vector<int>e(65,0);
		cin >> n >> m;
		ll now = 0;
		for (int i = 1; i <= m; i++)
		{
			int tem;
			cin >> tem;
			now += tem;
			e[log2(tem)]++;
		}
		if (now < n)
		{
			cout << -1 << endl;
			continue;
		}
		ll ans = 0;
		for (int i = 0; i <= 63 && n; i++)
		{
			if (n & 1 == 1)
			{
				int j = i;
				while (e[j] == 0)
					j++;
				while (j != i)
				{
					e[j]--;
					j--;
					e[j] += 2;
					ans++;
				}
				e[i]--;
			}
			e[i + 1] += e[i] / 2;
			n >>=1;
		}
		cout << ans << endl;
	}
}
 	 	 	 	 	 		 				 	  	    	 	