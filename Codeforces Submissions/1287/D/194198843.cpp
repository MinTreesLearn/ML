#include<bits/stdc++.h>
using namespace std; 

#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back                            //  stoi() , to_string()
#define mp make_pair   
#define lb lower_bound                         
#define nl "\n" 
#define pll pair<ll, ll> 
#define vll vector<ll> 
#define prtvec(v)  for(auto it = v.begin(); it != v.end(); ++it){cout<<*it<<" ";}cout<<nl;

const ll MOD = 1e9 + 7;
// const ll MOD = 998244353 ;

// Use LL ? yes => use everywhere. 


vector<vll> gr; 
vector<bool> vis; 
vector<ll> c; 
vector<vector<ll>> order; 
vector<ll> dp ;
bool fl = true; 
void dfs(ll x){
	vis[x] = true; 
	dp[x] = 1; 
	for(auto ch : gr[x]){
		if (!vis[ch]){
			dfs(ch); 
			for(auto i : order[ch]){
				order[x].pb(i); 
			}
			dp[x] += dp[ch]; 
		}
	}
	if (dp[x] <= c[x]){
		fl = false; 
		cout << "NO\n"; 
		exit(0) ;
	}
	order[x].insert(order[x].begin() + c[x], x); 
}


void solve(int tt, int TT){
	ll n;  cin >> n; 
	gr.resize(n+1); vis.resize(n+1); c.resize(n+1); order.resize(n+1); dp.resize(n+1); 
	
	ll root = -1; 
	for(int i = 1; i<=n; ++i){
		ll p, ct; 
		cin >> p >> ct; 
		c[i] = ct; 
		if (p == 0){
			root = i; 
		}
		else{
			gr[i].pb(p); 
			gr[p].pb(i); 
		}
	}
	// cout << root << nl;
	dfs(root); 
	// if (!fl){
		// cout << "NO\n"; 
	// }
	cout << "YES\n"; 
	
	vll final = order[root]; 
	vll ans(n+1); 
	for(int i = 0; i < n; ++i){
		ans[final[i]] = i + 1; 
	}
	for(int i = 1; i<= n; ++i)cout << ans[i] << " ";
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	int TCS = 1; 
	// cin >> TCS; 
	int tcs = 1; 
	while(tcs <= TCS){
		solve(tcs, TCS);
		tcs++; 
	}
	return 0; 
}