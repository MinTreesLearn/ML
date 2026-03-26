#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int h[200001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a, b, k, ans;
	cin>>n>>a>>b>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>h[i];
		h[i] %= (a+b);
		if(h[i]>=1&&h[i]<=a)
		{
			h[i] = 0;
		}
		else if(h[i]==0)
		{
			h[i] = a+b;
			h[i] = h[i]%a==0?(h[i]/a-1):(h[i]/a);
		}
		else
		{
			h[i] = h[i]%a==0?(h[i]/a-1):(h[i]/a);
		}
	}
	ans = 0;
	sort(h+1, h+n+1);
	for(int i=1;i<=n;++i)
	{
		if(h[i]==0)
		{
			++ans;
		}
		else 
		{
			if(k>=h[i]) 
			{
				k -= h[i];
				++ans;
			}
			else break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}