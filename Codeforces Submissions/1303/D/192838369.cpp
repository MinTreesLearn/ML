#include <bits/stdc++.h>
#define N 100005
#define wr cout << "Continue debugging\n";
#define all(x) (x).begin(), (x).end()
#define ll long long int
#define pii pair <int, int>
#define pb push_back
#define ff first
#define ss second
using namespace std;

int t, cnt[N];

int logs(int x){
	int res = 0;
	while(x > 1){
		res++;
		x /= 2;
	}
	return res;
}
ll powd(int x, int y){
	ll res = 1;
	while(y--){
		res *= x;
	}
	return res;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--){
		ll n, m;
		cin >> n >> m;
		for (int i = 0; i <= 30; i++){
			cnt[i]=0;
		}
		for (int i = 1; i <= m; i++){
			int x;
			cin >> x;
			cnt[logs(x)]++;
		}	
		ll ans = 0;
		int res = 0;	
		bool tr = 0;
		while(n){
			if (n%2){
				ll x = powd(2, res);
				for (int i = 30; i >= 0; i--){
					ll cur = 0;
					while(cnt[i] > 0 and x > cur){
						cnt[i]--;
						cur += powd(2, i);
					}
					if (x < cur){
						cur -= powd(2, i);
						cnt[i]++;
					}
					x -= cur;
				}
				if (x){
					int idx = -1;
					for (int i = res+1; i <= 30; i++){
						if (cnt[i]){
							idx = i;
							break;
						}
					}
					if (idx == -1){
						tr = 1;
						break;
					}
					ans += idx-res;
					cnt[idx]--;
					for (int i = idx-1; i >= res; i--){
						cnt[i]++;
					}
				} 
			}
			n /= 2;
			res++;
		}
		if (tr) ans = -1;
		cout << ans << '\n';
	}
}	