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


void solve(int tt, int TT){
	int n, m , p; 
	cin >> n >> m >> p; 
	
	vector<int> a(n), b(m); 
	for(int i = 0; i < n ; ++i)cin >> a[i]; 
	for(int i = 0; i < m; ++i) cin >> b[i]; 
	
	int i1 = -1; 
	int i2 = -1; 
	for(int  i = 0; i < n; ++i){
		if (a[i]%p != 0){
			i1 = i; 
			break ; 
		}
	}
	for(int  i = 0; i < m; ++i){
		if (b[i]%p != 0){
			i2 = i; 
			break ; 
		}
	}
	
	cout << i1 + i2 << nl;
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