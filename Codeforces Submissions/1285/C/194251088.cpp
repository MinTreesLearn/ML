#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll lcm(ll a, ll b){
	return (a*b)/__gcd(a,b);
}
void solve(){
	ll x;
	cin>>x;
	ll res1 = x;
	ll res2 = 1;
	ll res = x;
	for(ll i = 1; i*i <= x; i++){
		if(x % i == 0){
			if(lcm(i, x/i) == x){
				if(res > max(x/i, i)){
					res = max(i, x/i);
					res1 = i;
					res2 = x/i;
				}
			}
		}
	}
	cout<<res1<<" "<<res2<<endl;
}
int main() {
	int tc = 1;
	//cin>>tc;
	while(tc--){
		solve();
	}
	return 0;
}
					 	   			 			 	 		 		 	 			