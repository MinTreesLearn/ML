#include<bits/stdc++.h>
using namespace std;
const int modulo = 1;
const int INF = 0x3f3f3f3f;
const int N = 400000 + 10;
const int M = 10;
int n; 
int a[N],b[N];


void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int ans = 0;
	for (int B=1;B<=2e7;B<<=1)
	{
		for (int j=1;j<=n;j++)
		{
			b[j] = a[j] & ((B << 1) -1);
		}
		
		sort(b+1,b+1+n);
		
		long long sum = 0;
		for (int i=n,x=1,y=1,z=1;i>=1;i--)
		{
			while (x <= n && b[x] + b[i] < B) x++;
			while (y <= n && b[y] + b[i] < 2*B) y++;
			while (z <= n && b[z] + b[i] < 3*B) z++;
			sum += max(0,min(i,y) - x);
			sum += max(0,i-z);
		}
		
		if (sum & 1) ans |= B;
	}
	
	cout<<ans<<endl;
	
	return;
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}
					 		 				   		 	 		 	     	