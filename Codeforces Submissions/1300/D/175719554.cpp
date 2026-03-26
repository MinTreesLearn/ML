#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll a[maxn];
ll b[maxn];
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++) cin>>a[i]>>b[i];
	if(t & 1)
	{
		cout<<"nO"<<endl;
		return 0;
	}	
	for(int i=1;i<=t/2;i++)
	{
		if(a[i]+a[i+t/2]==a[1]+a[1+t/2]&&b[i]+b[i+t/2]==b[1]+b[1+t/2])
			continue;
		else 
		{
			cout<<"nO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}

	 		 			 	  					  	  				  	