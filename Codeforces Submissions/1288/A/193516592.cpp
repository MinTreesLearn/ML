#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define ll long long
#define ld long double
#define pii pair<ll, ll>
typedef __int128 lll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpi;
typedef set<ll> si;
typedef map<ll, ll> mii;
#define all(value) value.begin(), value.end()
const int M = 1e9+7;
	
//..................................................................
	
void solve(){
	ll n,d;
	cin>>n>>d;
	if(d<=n)
	{
		cout<<"YES"<<endl;return;
	}
	for (int i = 1 ;i <= n; i++)
	{
		ll curr=i+d/(i+1);
		if(d%(i+1)!=0) curr++;
		if(curr<=n)
		{
			cout<<"YES"<<endl;
			return;
		}
	}
	
	cout<<"NO"<<endl;
	

}
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	ll t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}
}