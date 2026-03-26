// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define spc <<" "<<
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define all(t) t.begin(), t.end()
//#define int long long

const int Mod = 1e9+7;
const int N = 2e5+1;

bool check(vector<int> &v, int n){
	set<int> st;
	for(int x : v) {
		if(x > 0 and x <= n) st.insert(x);
	}
	return (st.size() ==  v.size());
}
void SOLVE(){ 
	int n; cin >> n;
	vector<int> q(n);
	int mx = 0, mn = N;
	for(int i=1 ; i<n ; i++){
		cin >> q[i];
		q[i] += q[i-1];
		mx = max(mx, q[i]);
		mn = min(mn, q[i]);
	}
	vector<int> p(n);
	int p1;
	if(mx > 0 and mn > 0) p1 = 1;
	else if(mx < 0 and mn < 0) p1 = n;
	else {
		int t = (n+1-mx-mn);
		if(t&1){
			cout << -1 << endl;
			return;
		}
		p1 = t/2;
	}
	p[0] = p1;
	for(int i = 1 ; i < n ; i++){
		p[i] = q[i] + p1;
	}
	if(check(p, n)){
		for(int x : p) cout << x <<" ";
		cout << endl;
	}else cout << "-1\n";
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1; //cin >> T;
	while(T--) SOLVE();
}