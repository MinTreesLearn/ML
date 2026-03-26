#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD ((ll) 1e9+7)
#define INF 2e9 
#define MAX_LEN (int) 2e5+1

#define pi pair<int, int>
#define f first
#define s second

void solve() {
	
	int n;
	
	cin >> n;
	
	vector<vector<int>> segs(n, vector<int>(2));
	
	for(int i=0; i<n; i++)
		cin >> segs[i][0] >> segs[i][1];
		
	sort(begin(segs), end(segs));
	
	int gaps = 0, r = segs[0][0];
	
	for(int i=0; i<n; i++) {
		if(r < segs[i][0]) gaps++;
		r = max(r, segs[i][1]);
	}
	
	gaps++;
	
	int last = -INF, res = 0;
	
	for(int i=0; i<n; i++) {
		
		int j = i+1, add = last == -INF ? -1 : 0;
		
		while(j < n && segs[j][0] <= segs[i][1]) {
			
			if(last < segs[j][0]) add++;
			last = max(segs[j][1], last);
			if(last > segs[i][1]) break;
			j++;
			
		}
		
		if(j < n && segs[j][0] > segs[i][1])
			last = -INF;

		if(last > segs[i][1])
			last = segs[i][1];

		i = j-1;
		
		res = max(res, gaps+add);
		
	}
	
	cout << res << endl;
	
	
}


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	
	cin >> t;
	
	while(t--) solve();
	
	return 0;
	
}