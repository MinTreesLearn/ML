#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define sze(x) (ll)(x.size())
#define mp(x , y) make_pair(x , y)
#define wall cout<<"--------------------------------------\n";
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
typedef pair<pll , ll> plll;
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll maxn = 3e5 + 17 , md = 1e9 + 7 , inf = 2e16;

ll ds[maxn] , dsz[maxn][2];
bool dt[maxn] , dl[maxn];
ll ans = 0;

pll dsu(ll v){
	if(v == ds[v]) return {v , dt[v]};
	pll p = dsu(ds[v]);
	p.second ^= dt[v];
	dt[v] = p.second ^ dt[p.first];
	return {ds[v] = p.first , p.second};
}

void merge(ll v , ll u , bool t){
	pll pv = dsu(v) , pu = dsu(u);
	v = pv.first; u = pu.first;
	if(v == u) return;
	ans -= dsz[v][1 ^ dt[v]];
	ans -= dsz[u][1 ^ dt[u]];
	if(dl[v] && dl[u]){
		ds[u] = v;
		bool h = dt[u] ^ dt[v];
		dsz[v][0] += dsz[u][h];
		dsz[v][1] += dsz[u][1 ^ h];
		dt[u] ^= dt[v];
		ans += dsz[v][1 ^ dt[v]];
		return;
	}
	if(dl[u]) swap(v , u);
	if(dl[v]){
		ds[u] = v;
		bool h = pv.second ^ pu.second ^ t ^ dt[u] ^ dt[v];
		dsz[v][0] += dsz[u][h];
		dsz[v][1] += dsz[u][1 ^ h];
		dt[u] ^= h ^ dt[u];
		ans += dsz[v][1 ^ dt[v]];
		return;
	}
	ds[u] = v;
	bool h = pv.second ^ pu.second ^ t ^ dt[u] ^ dt[v];
	dsz[v][0] += dsz[u][h];
	dsz[v][1] += dsz[u][1 ^ h];
	dt[u] ^= h ^ dt[u];
	if(dsz[v][dt[v]] < dsz[v][1 ^ dt[v]]) dt[v] ^= 1;
	ans += dsz[v][1 ^ dt[v]];
	return;
}

void fix(ll v , bool t){
	pll p = dsu(v);
	v = p.first;
	ans -= dsz[v][1 ^ dt[v]];
	if(p.second != t) dt[v] ^= 1;
	ans += dsz[v][1 ^ dt[v]];
	dl[v] = true;
	return;
}

string s;
vector<ll> a[maxn];

/*
2 3
00
1
1
1
2
2
1 2
*/

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n , k;
	cin>>n>>k>>s;
	for(ll i = 0 ; i < k ; i++){
		ll m;
		cin>>m;
		for(ll j = 0 ; j < m ; j++){
			ll h;
			cin>>h;
			a[--h].push_back(i);
		}
	}
	for(ll i = 0 ; i < k ; i++){
		dt[i] = 0;
		ds[i] = i;
		dsz[i][0] = 1; dsz[i][1] = 0;
		dl[i] = false;
	}
	for(ll i = 0 ; i < n ; i++){
		bool t = (s[i] ^ '1');
		if(a[i].empty()){
			cout<<ans<<'\n';
			continue;
		}
		if(sze(a[i]) == 1){
			fix(a[i][0] , t);
			cout<<ans<<'\n';
			continue;
		}
		merge(a[i][0] , a[i][1] , t);
		cout<<ans<<'\n';
	}
	return 0;
}