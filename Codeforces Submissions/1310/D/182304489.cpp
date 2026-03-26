// LUOGU_RID: 95225327
#include <bits/stdc++.h>

using namespace std;

int n, k;
const int maxn = 88 ;
int dis[maxn][maxn] ;
int dp[11][maxn] ;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= n ; j ++)
		{
			cin>>dis[i][j];
		}
	}
	int seed = 0 ;
	for(char c : "sooketxdy")
		seed = seed * 233 + c ;
	srand(seed) ;
	int times = 5000 ;
	vector < int > col(n + 1 , 0);
	int ans = 1e9 ;
	while(times --)
	{
		for(int i = 1 ; i <= n ; i ++)
			col[i] = rand() & 1 ;
		memset(dp , 0x3f , sizeof(dp)) ;
		dp[0][1] = 0;
		for(int kk = 0 ; kk < k ; kk ++)
		{
			for(int i = 1 ; i <= n ; i ++)
			{
				for(int j = 1 ; j <= n ; j ++)
				{
					if(col[i] ^ col[j])
					{
						dp[kk + 1][j] = min(dp[kk + 1][j] , dp[kk][i] + dis[i][j]) ;
					}
				}
			}
		}
		ans = min(ans , dp[k][1]) ;
	}
	cout<<ans<<endl;
	return 0 ;
}