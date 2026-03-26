#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

// #define _GLIBCXX_DEBUG
// #define int int64_t

using namespace std;

signed main() {
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
 	int n;
 	cin >> n;
 	vector<int> a(n), b(n);
 	for (int &i : a) {
 		cin >> i;
 	}  	
 	for (int &i : b) {
 		cin >> i;
 	}  	
 	int q = 0;
 	int w = 0;
 	forn(i, n) {
 		if (a[i] > b[i]) q++;
 		if (a[i] < b[i]) w++;
 	}
 	if (q == 0) {
 		cout << -1;
 	}
 	else {
 		cout << w / q + 1;
 	}

    return 0;
}