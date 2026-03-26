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
 	string s;
 	cin >> s;
 	int cnt = 0;
 	for (char c = 'z'; c > 'a'; c--) {
 		forn(j, n) {
 			forn(i, n) {
	 			if (s[i] == c) {
	 				if (i > 0 and s[i - 1] == c - 1 or
	 					 i < n - 1 and s[i + 1] == c - 1) 
	 				{
	 					s.erase(s.begin() + i);
	 					cnt++;
	 				}
	 			}
	 		}
 		}
 	}
 	cout << cnt;

    return 0;
}