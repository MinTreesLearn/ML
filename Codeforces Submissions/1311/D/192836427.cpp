#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(a) a.begin() , a.end()
#define F first
#define S second
 
using namespace std;
using ll = long long;
 
const ll N = 305 ,inf = 2e9 + 7;
const ll INF = 1e18 ,   mod = 1e9+7 , P = 6547;	


void solve(){
	ll a , b , c , ans = inf;
	cin >> a >> b >> c;
	ll A = a , B = b , E = c;
	for(ll i = 1; i <= 2e4; i++){
		ll sum = abs(i-b) , num = inf , C = 0 , D = 0;
		for(ll j = i; j <= 4e4; j += i) {
			num = min(num , abs(j-c));
			if(abs(j-c) == num) C = j;
		}
		sum += num;
		num = inf;
		for(ll j = 1; j <= sqrt(i); j++){
			if(i % j == 0) {
				num = min(num , abs(j-a));
				if(abs(j-a) == num) D = j; 
				num = min(num , abs(i/j-a));
				if(abs(i/j-a) == num) D = i/j; 
			}
		}
		sum += num;
		ans = min(ans , sum);
		if(ans == sum){
			A = D, B = i , E = C;
		}
	}
	cout << ans <<"\n";
	cout << A <<" " << B <<" " << E <<"\n";
}
signed main(){
	ios;
	ll t;
	cin >> t;
	while(t--) solve();
	return 0;
} 