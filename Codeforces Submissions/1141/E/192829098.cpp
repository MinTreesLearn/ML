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
    	ll h;
    	int n;
    	cin >> h >> n;
    	vector<ll> a(n);
    	ll sum = 0;
    	ll hh = h;
    	int ch = 0;
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
    		sum += a[i];
    		hh += a[i];
    		if (hh <= 0) {
    			cout << i + 1 << endl;
    			ch = 1;
    			break;
			}
		}
		if (ch) continue;
		if (sum >= 0) {
			cout << -1 << endl;
		} else {
			ll left = 0;
			ll right = -(h - sum - 1) / sum; 
			
			auto check = [&](ll rounds) -> ll {
				if (h + (__int128) rounds * sum <= 0) return rounds * n;
				ll health = h + rounds * sum;
				for (int i = 1; i <= n; i++) {
					health += a[i - 1];
					//out()
					//out(health);
					
					if (health <= 0) {
						return rounds * n + i;
					}
				}
				return -1;
			};
			ll ans = -1;
			while (left <= right) {
				ll mid = left + (right - left) / 2;
				ll days = check(mid);
				if (days == -1) {
					left = mid + 1;
				} else {
					right = mid - 1;
					ans = days;
				}
			}
			
			cout << ans << endl;
		}
	}
}

