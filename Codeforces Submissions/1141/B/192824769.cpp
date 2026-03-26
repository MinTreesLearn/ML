#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define out(x) cout << #x << '=' << x << endl;
#define lowbit(x) (x & -x);


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    
    while (t--) {
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	int c = 0;
    	int aa = 0;
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
    		if (a[i] == 0) {
    			c = 0;
			} else {
				aa = max(aa, ++c);
			}
		}
		for (int i = 0; i < n; i++) {
    	
    		if (a[i] == 0) {
    			c = 0;
			} else {
				aa = max(aa, ++c);
			}
		}
		cout << aa << endl;
	}
}
