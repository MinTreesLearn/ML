// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define spc <<" "<<
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define all(t) t.begin(), t.end()
#define int long long

const int Mod = 1e9+7;
const int N = 1e5+1;

void SOLVE(){ 
	int H, n; cin >> H >> n;
	vector<int> d(n);
	for(int i=0 ; i<n ; i++){
		cin >> d[i];
	}
	int mn = d[0];
	for(int i=1 ; i<n ; i++){
		d[i] += d[i-1];
		mn = min(mn, d[i]);
	}
	if(d[n-1] >= 0){
		int idx = -1;
		for(int i=0 ; i<n ; i++){
			if(d[i] + H <= 0){
				idx = i+1;
				break;
			}
		}
		cout << idx << endl;
	}else{
		int pH = H + mn, t;
		if(pH < 0) t = 0;
		else{
			t = pH/abs(d[n-1]);
			if(pH % abs(d[n-1])) t++;
		}
		H += t*d[n-1];
		for(int i=0 ; i<n ; i++){
			if(d[i] + H <= 0){
				cout << t*n + i+1 << endl;
				return;
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1; //cin >> T;
	while(T--) SOLVE();
}