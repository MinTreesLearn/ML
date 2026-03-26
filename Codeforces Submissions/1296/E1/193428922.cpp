#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	char f1, f2;
	string s;
	cin>>n;
	cin>>s;
	f1 = 'a';
	f2 = 'a';
	for(int i=0;i<=n-1;++i)
	{
		if(s[i]>=f1)
		{
			f1 = s[i];
			s[i] = '0';
		}
		else if(s[i]>=f2)
		{
			f2 = s[i];
			s[i] = '1';
		}
		else
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<"\n";
	cout<<s<<"\n";
	return 0;
}