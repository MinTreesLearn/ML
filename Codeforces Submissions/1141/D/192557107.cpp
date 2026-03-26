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
const int N = 1e5+1;

void SOLVE(){ 
	int n; cin >> n;
	string l, r; cin >> l >> r;

	vvi li(27), ri(27);
	for(int i=0 ; i<n ; i++){
		if(l[i] == '?') li[26].push_back(i+1);
		else li[l[i] - 'a'].push_back(i+1);

		if(r[i] == '?') ri[26].push_back(i+1);
		else ri[r[i] - 'a'].push_back(i+1);
	}
	vector<pii> ans;
	vector<int> pLeft, pRight;
	for(int i=0 ; i<26 ; i++){
		int m = min(li[i].size(), ri[i].size());
		for(int j=0 ; j<m ; j++){
			ans.push_back({li[i][j], ri[i][j]});
		}
		for(int j = m ; j < li[i].size() ; j++){
			pLeft.push_back(li[i][j]);
		}
		for(int j = m ; j < ri[i].size() ; j++){
			pRight.push_back(ri[i][j]);
		}
	}
	int i = 0, j = 0;
	int pr = 0, pl = 0;
	while(i < li[26].size() and pr < pRight.size()){
		ans.push_back({li[26][i], pRight[pr]});
		i++, pr++;
	}
	while(j < ri[26].size() and pl < pLeft.size()){
		ans.push_back({pLeft[pl], ri[26][j]});
		j++, pl++;
	}
	while(i < li[26].size() and j < ri[26].size()){
		ans.push_back({li[26][i], ri[26][j]});
		i++, j++;
	}
	cout << ans.size() << endl;
	for(pii x : ans)
		cout << x.first spc x.second << endl;
}
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T = 1; //cin >> T;
	while(T--) SOLVE();
}