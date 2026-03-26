/*
 * 
 * 	^v^
 * 
 */
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <map>
#include <functional>
#include <algorithm>
#include <set>
#include <queue>
#include <climits>
#include <cstdlib>
#include <chrono>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// #define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define iamtefu ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long int
#define ld long double
#define fl(i,a,n) for (ll i(a); i<n; i++)
#define rfl(i,a,n) for (ll i(n-1); i>=a; i--)
#define print(a) for (auto x:a){cout<<x<<" ";} cout<<"\n";
#define tt int tt; cin>>tt; for(;tt--;)
ll gcd(ll a, ll b){
	if (b==0){
		return a;
	}
	return gcd(b, a%b);
}
ll pw(ll a, ll b, ll m){
	ll res=1;
	a%=m;
	while (b){
		if (b&1){
			res=(res*a)%m;
		}
		a=(a*a)%m;
		b>>=1;
	}
	return res;
}
void scn(){
	ll n; cin>>n;
	vector <ll> a(n+1);
	vector <vector <ll>> ed(n+1);
	ll rt = 0;
	fl(i,0,n){
		ll x; cin>>x>>a[i+1];
		// cout<<x<<' '<<a[i+1]<<'\n';
		if (x==0){
			rt = i+1;
		} else {
			ed[x].push_back(i+1);
			ed[i+1].push_back(x);
		}
	}
	ll don = 0;
	vector <ll> vis(n+1);
	function<vector<ll>(ll)> dfs=[&](ll i){
		vis[i]++;
		vector <ll> ans;
		for (auto x:ed[i]){
			if (!vis[x]){
				vector <ll> hu = dfs(x);
				ans.insert(ans.end(), hu.begin(), hu.end());
			}
		}
		if (ans.size()<a[i]){
			don++;
			ans.push_back(i);
			return ans;
		} else {
			ans.insert(ans.begin()+a[i], i);
		}
		return ans;
	};
	vector <ll> hu = dfs(rt);
	if (don){
		cout<<"No\n";
		return;
	} else {
		vector <ll> an(n);
		fl(i,0,n){
			an[hu[i]-1]=i+1;
		}
		cout<<"Yes\n";
		print(an)
	}
}
int main(){
	iamtefu;
#if defined(airths)
	auto t1=chrono::high_resolution_clock::now();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//
#endif
	// tt
	{
		scn();
	}
#if defined(airths)
	auto t2=chrono::high_resolution_clock::now();
	ld ti=chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();
	ti*=1e-6;
	cerr<<"Time: "<<setprecision(12)<<ti;
	cerr<<"ms\n";
#endif
	return 0;
}