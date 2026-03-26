#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(a) a.begin() , a.end()
#define F first
#define S second
 
using namespace std;
using ll = long long;
 
const ll N = 3e5+5 , M = 10 ,inf = 2e9 + 7;
const ll INF = 1e18 ,   mod = 1e9+7 , P = 6547;	

ll a[N][M] , n , m , pos[1024];
pair<ll,ll> check(ll md){
	for(int mask = 0; mask < (1ll << m); mask++) pos[mask] = 0;
	for(int i = 1; i <= n; i++){
		ll num = 0 , kk = 0;
		for(int j = 0; j < m; j++) {
			if(a[i][j] >= md) num += (1ll << j);
			else kk += (1ll << j);
		}
		if(pos[kk] > 0) return {pos[kk],i};
		if(kk == 0) return {i,i};
		for(int sb = num; sb > 0; sb = ((sb-1) & num)) pos[sb] = i;
	}
	return {0,0};
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++) cin >> a[i][j];
	}
	pair<ll,ll> res = {1,1};
	for(ll l = 0 , r = 1e9; l <= r;){
		ll md = (l+r) >> 1;
		pair<ll,ll> r1 = check(md);
		if(r1.F != 0) {
			res = r1 , l = md+1;
		}
		else r = md-1;
	}
	cout << res.F <<" " << res.S <<"\n";
}
signed main(){
	ios;
	solve();
	return 0;
}