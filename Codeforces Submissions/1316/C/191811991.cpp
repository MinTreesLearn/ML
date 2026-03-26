#include <bits/stdc++.h>
using namespace std;
#define ll long long

void slv(){
	ll n,m,p;
	cin>>n>>m>>p;
	vector<ll> a(n),b(m);
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=0;i<m;i++)cin>>b[i];
	ll ai=0,bi=0;
	while(a[ai]%p==0)ai++;
	while(b[bi]%p==0)bi++;
	cout<<ai+bi<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	ll t=1;
	//cin>>t;
	while(t--)slv();
	return 0;

}
