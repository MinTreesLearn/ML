#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

// #define _GLIBCXX_DEBUG
#define int int64_t

using namespace std;

signed main() {
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
 	int n;
 	cin >> n;
 	vector<int> a(n);
 	map<int,int> q;
 	forn(i, n) {
 		cin >> a[i];
 		q[i - a[i]] += a[i];
 	}  	
 	int ans = 0;
 	for (auto[x,y] : q) {
 		ans = max(ans, y);
 	}
 	cout << ans;

    return 0;
}