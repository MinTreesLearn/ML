#include <cstdio>
#include <iostream>
const int N		= 1e6+10;
const int INF	= 1e9;
using namespace std;

int arr[N];
int n, K;

void Sol()
{
	int ans = arr[1];
	int rmn = K;
	for (int i=2; i<=n; i++)
	{
		int t = min(rmn/(i-1), arr[i]);
		ans += t;
		rmn -= t*(i-1);
		if(rmn <= 0)
			break;
	}
	printf("%d\n", ans);
}

int main()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d %d",&n,&K);
		for (int i=1; i<=n; i++)
			scanf("%d",&arr[i]);
		Sol();
	}
	
	return 0;
}