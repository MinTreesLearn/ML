#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, a, b, c, ans, tmp, aa, bb, cc;
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c;
		ans = 2e9; 
		for(int i=1;i<=20000;++i)
		{
			for(int j=i;j<=20000;j+=i)
			{
				for(int k=j;k<=20000;k+=j)
				{
					tmp = fabs(i-a)+fabs(j-b)+fabs(k-c);
					if(ans>tmp)
					{
						ans = tmp;
						aa = i;
						bb = j;
						cc = k;
					}
				}
			}
		}
		cout<<ans<<"\n"<<aa<<" "<<bb<<" "<<cc<<"\n";
	}
	return 0;
}