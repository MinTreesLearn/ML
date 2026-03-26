#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, n;
	ll a, b, c;
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>n;
		n = n+a+b+c;
		if(n%3!=0)
		{
			cout<<"NO"<<"\n";
		}
		else 
		{
			n /= 3;
			if(n<a||n<b||n<c)
			{
				cout<<"NO"<<"\n";
			}
			else cout<<"YES"<<"\n";
		}
	}
	return 0;
}