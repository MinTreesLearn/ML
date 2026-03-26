#include<bits/stdc++.h>
#define ll long long
using namespace std;


int  main()
{

	ll n, m, i, j, k;
	cin >> n;
	map<ll,ll> mp;
	for (i = 1; i <= n; i++)
	{
		ll x;
		cin >> x;
		mp[x - i]+=x;
	}

	ll sum = 0;
	for (auto I : mp) {
		ll currsum = I.second;
		if(currsum>sum){
			sum=currsum;
		}
		
	}
	cout << sum << "\n";

	return 0;
}