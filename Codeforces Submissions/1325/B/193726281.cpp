# include<iostream>
# include<vector>
# include<algorithm>
# include<iomanip>
#include<cmath>
# include<map>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int>v(n);
		map<int, int>mp;
		int e = n;
		for (int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		int l = 0,ans=INT_MIN;
		for (int r = 0; r < n; r++) {
			mp[v[r]]++;
			if (mp[v[r]] == 1) {
				ans = max(ans, r - l + 1);
			}
			else {
				l++;
			}
		}
		cout << ans << endl;
	}
	
}