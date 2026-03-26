#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
#define int long long
#define endl "\n"
#define xx first
#define yy second

using namespace std;

typedef pair<int, int> PII;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int m, k, _, n, x;
int arr[N];

void solve()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++) cin >> arr[i];

	k = min(k, m-1);
	int ans = 0;
	for(int i = 0; i <= k; i ++)
	{
		int mi = INF;
		for(int j = i+1; j <= m-k+i; j ++)
			mi = min(mi, max(arr[j], arr[j+n-m]));
		ans = max(ans, mi);
	}
	cout << ans << endl;
}	

signed main()
{
	IOS;
	cin >> _;
	while(_--)
		solve();
	return 0;
}
					         	 		 	  	     	