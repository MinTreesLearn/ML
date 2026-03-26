#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
#define xx first
#define yy second

using namespace std;

typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n, m, k, _;
int arr[N], dp[N];

signed main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> arr[i];

	int tmp = 0;

	for(int i = 30; i >= 0; i --)
	{
		int cnt = 0, pos = 0;
		for(int j = 1; j <= n; j ++)
		{
			if(arr[j] & (1 << i))
			{
				pos = j;
				cnt++;
			}
		}
		if(cnt == 1)
		{
			cout << arr[pos] << " ";
			for(int i = 1; i <= n; i ++) 
				if(i != pos) cout << arr[i] << " ";
			cout << "\n";
			return 0;
		}
	}

	for(int i = 1; i <= n; i ++) cout << arr[i] << " \n"[i == n];

	return 0;
}