#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i< (n);i++)
#define all(x) (x).begin(), (x).end()
#define f first  
#define s second
#define SZ(a) (int)a.size()
#define bit(x,i)(((x)>>(i))&1)
typedef long long ll;
using namespace std; 

ll m;

void solve(){
	ll n; cin >> n >> m;
	vector<ll> v(n);
	ll ans = 1;
	for(auto &x : v){
		cin >> x;
	}	
	if(n > m){
		cout << 0 << endl;
		return;
	}
	
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			ans *= abs(v[i] - v[j]);
			ans %= m;
		}
	}
	cout << ans << endl;
}



int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	solve();
	
}

