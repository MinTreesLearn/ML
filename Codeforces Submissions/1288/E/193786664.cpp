#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(a) a.begin() , a.end()
#define F first
#define S second
 
using namespace std;
using ll = long long;
 
const ll N = 6e5+5 , inf = 2e9 + 7;
const ll INF = 1e18 ,   mod = 1e9+7 , P = 6547;	

ll a[N] , t[N*4] , mn[N] , mx[N] , p[N];
ll n , m;
void build(ll v , ll tl , ll tr){
	if(tl > n) return;
	if(tl == tr){
		t[v] = 1;
		return;
	}
	ll tm = (tl+tr) >> 1;
	build(v*2,tl,tm);
	build(v*2+1,tm+1,tr);
	t[v] = t[v*2] + t[v*2+1];
}
ll get(ll v, ll tl , ll tr , ll l){
	if(tl >= l) return t[v];
	if(tr < l) return 0;
	ll tm = (tl+tr) >> 1;
	return get(v*2,tl,tm,l) + get(v*2+1,tm+1,tr,l);
}
void upd(ll v, ll tl, ll tr , ll pos, ll val){
	if(tl == tr){
		t[v] = val;
		return;
	}
	ll tm = (tl+tr) >> 1;
	if(tm >= pos) upd(v*2,tl,tm,pos,val);
	else upd(v*2+1,tm+1,tr,pos,val);
	t[v] = t[v*2] + t[v*2+1];
}
void solve(){
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		mn[i] = i;
		mx[i] = i;  
		p[i] = n-i+1;
	}	
	build(1,1,n+m);
	ll nw = n+1;
	for(ll i = 1; i <= m; i++){
		cin >> a[i];
		mn[a[i]] = 1;
		ll res = get(1,1,n+m,p[a[i]]);
		mx[a[i]] = max(mx[a[i]] , res);
		upd(1,1,n+m,p[a[i]],0);
		p[a[i]] = nw++;
		upd(1,1,n+m,p[a[i]],1);
	}
	for(ll i = 1; i <= n; i++){
		ll res = get(1,1,n+m,p[i]);
		mx[i] = max(mx[i] , res);
	}
	for(ll i = 1; i <= n; i++){
		cout << mn[i] <<" " << mx[i] <<"\n";
	}
}
/*

*/
signed main(){
	ios;
	solve();
	return 0;
}