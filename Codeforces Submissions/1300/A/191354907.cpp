// LUOGU_RID: 100979414
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int sum=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			sum+=x;
			if(x==0)
			{
				sum++,ans++;
			}
		}	
		if(sum==0)
		{
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}