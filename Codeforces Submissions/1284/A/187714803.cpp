#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main()
{
	ll n,m;cin>>n>>m;
	vector<string> vn,vm;
	for(ll i=0;i<n;i++) {
	string x;cin>>x;vn.pb(x);}
	for(ll i=0;i<m;i++) {
	string x;cin>>x;vm.pb(x);}
	ll q;cin>>q;
	while(q--){
		ll x;cin>>x;
		cout<<vn[(x-1+n)%n]<<vm[(x-1+m)%m]<<endl;
	}
}