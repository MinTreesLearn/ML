#include <bits/stdc++.h>
 
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(a) a.begin() , a.end()
#define F first
#define S second
 
using namespace std;
using ll = long long;
 
const ll N = 3e5+5 , inf = 2e9 + 7;
const ll INF = 1e18 ,   mod = 1e9+7 , P = 6547;	

ll dp[N] , a[4] , ans = 0;
ll n;
pair<ll,ll> mx[N];
vector<ll> g[N];
void dfs(ll v , ll p = 0){
	dp[v] = dp[p]+1;
	mx[v].F = v;
	for(ll to : g[v]) if(to != p) dfs(to,v);
}
vector<ll> V;
queue<ll> q;

void go(){
	while(!q.empty()){
		ll v = q.front();
		q.pop();
		for(ll to : g[v]){
			if(dp[to] > dp[v]+1){
				dp[to] = dp[v]+1;
				q.push(to);
			}
		}
	}
	ll mx = 0;
	for(ll i = 1; i <= n; i++){
		if(i != a[0] && i != a[1]){
			if(dp[i] >= mx) {
				mx = dp[i];
				a[2] = i;
			}
		}
	}
}
void bfs(ll v , ll p = 0){
	V.push_back(v);
	if(v == a[0]){
		for(ll x : V){
			dp[x] = 0;
			q.push(x);
		}
		go();
		return;
	}
	for(ll to : g[v]) if(to != p) bfs(to,v);
	V.pop_back();
}
void solve(){
	cin >> n;
	for(ll i = 1; i < n; i++) {
		ll a , b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	ll V = 1 , mx = 0;
	for(ll i = 1; i <= n; i++){
		if(dp[i] > mx) mx = dp[i] , V = i;
		dp[i] = 0;
	}
	a[0] = V;
	dfs(V);
	V = 1 , mx = 0;
	for(ll i = 1; i <= n; i++){
		if(dp[i] > mx) mx = dp[i] , V = i;
		dp[i] = inf;
	}
	a[1] = V;
	bfs(V);
	cout << mx-1 + dp[a[2]] <<"\n";
	cout << a[0] << " " << a[1] <<" " << a[2] <<"\n";
}	
/*

*/
signed main(){
	ios;
	solve();
	return 0;
} 