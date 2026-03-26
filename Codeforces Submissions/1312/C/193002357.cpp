#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;

map<ll, ll> mp ;
void check(ll n, ll k) {
	ll cnt=0 ;
	while(n) {
		mp[cnt]+=(n%k);
		n/=k ;
		cnt++ ;
	}
}

int main() {
	ll tc; cin >> tc ;
	while(tc--) {
		ll n, k, i ;
		cin >> n >> k ;
		
		bool bb = 1 ;
		for(int i=0; i<n; i++) {
			ll a; cin >> a ;
			check(a, k) ;
		}
		
		for(auto it: mp) {
			//cout << it.first << " " << it.second << endl ;
			if(it.second>1) {
				bb = 0 ;
				break;
			}
		}
		
		if(bb)
			cout << "YES" << endl ;
		else
			cout << "NO" << endl ;
		mp.clear();
	}
	return 0;
}