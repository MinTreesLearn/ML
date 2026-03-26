#define _CRT_SECURE_NO_WARNINGS
#define debug(l) cerr<<" smotri huinyi : "<<#l<<' '<<l<<'\n';
#include "bits/stdc++.h"
using namespace std;
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef long double ld;
signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    ll n;
    string s;
    cin >> n;
    cin >> s;
    for (char c = 'z'; c >= 'b'; --c) {
        bool ok;
        do {
            ok = false;
            for (int i = 0; i < n; ++i) {
                if (s[i] != c) 
                    continue;
                if ((i != 0 && s[i - 1] == c - 1) || (i != n - 1 && s[i + 1] == c - 1)) {
                    s.erase(i, 1);
                    ok = true;
                }
            }
        } while (ok);
    }
    cout << n - s.size() << '\n';
}

