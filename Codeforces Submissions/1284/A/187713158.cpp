// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define spc <<" "<<
#define pii pair<int, int>
#define vvi vector<vector<int>>
//#define int long long

const int M = 1e9+7;
const int N = 1e5+1;

bool SOLVE(){ 		
	int n, m; cin >> n >> m;
	vector<string> s(n), t(m);
	for(int i=0 ; i<n ; i++) cin >> s[i];
	for(int i=0 ; i<m ; i++) cin >> t[i];
	int q; cin >> q;
	while(q--){
		int x; cin >> x; --x;
		cout << s[x%n] + t[x%m] << endl;
	}
	return 1;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1; //cin >> T;
	while(T--){
		if(SOLVE()) ;//cout << "YES\n";
		else cout << "NO\n";
	}
}