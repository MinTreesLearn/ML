#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
typedef int i32;
typedef long double ld;

void like(void)
{
	int n,m;
	cin>>n>>m;
	int a[n+2];
	map<int,int> mp;
	int i,j;
	for(i=1;i<=n;i++)
	cin>>a[i];
	while(m--)
	{
		int x;
		cin>>x;
		mp[x]++;
	}
	for(i=1;i<=n;i++)
		for(j=n;j>1;j--)
			if(a[j]<a[j-1]&&mp[j-1]==0)
			{
			
				cout<<"NO"<<endl;
				return ;
			} 
			else if(a[j]<a[j-1])swap(a[j],a[j-1]);
	cout<<"YES"<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
    like();
	return 0;
}
