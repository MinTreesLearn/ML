#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<unordered_map>
typedef long long ll;
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int counter=0;
		int p;
		cin>>p;
		for(int i=1;i<n;i++)
		{
			int q;
			cin>>q;
			if(abs(p-q)%2!=0)
			{
				counter=1;
			}
			p=q;
		}
		if(counter==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}