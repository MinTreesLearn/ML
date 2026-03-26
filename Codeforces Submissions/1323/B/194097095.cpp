# include <bits/stdc++.h>
# define ll long long
# define fi first
# define se second
using namespace std;
int n, m , k;
vector<pair<int, int>> fac;
int sub[40003], cub[40003];
void factors(ll a) {
	for(int i=1; i<=sqrt(a); i++) {
		if(a%i==0) {
			if(i<=n && (a/i)<=m) {
				fac.push_back({i, a/i});
			}
			if(i!=a/i) {
				if(a/i<=n && i<=m) {
					fac.push_back({a/i, i});
				}
			}
		}
	}
}
int main() {
	cin >> n >> m >> k;
	factors(k);
	int last=1;
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if(x==0) {
			int p=i-last;
			for(int j=1; j<=p; j++) {
				sub[j]+=p-j+1;
			}
			last=i+1;
		}
		if(i==n && x==1) {
			int p=i-last+1;
			for(int j=1; j<=p; j++) {
				sub[j]+=p-j+1;
			}
		} 
	}
	last=1;
	for(int i=1; i<=m; i++) {
		int x;
		cin >> x;
		if(x==0) {
			int p=i-last;
			for(int j=1; j<=p; j++) {
				cub[j]+=p-j+1;
			}
			last=i+1;
		}
		if(i==m && x==1) {
			int p=i-last+1;
			for(int j=1; j<=p; j++) {
				cub[j]+=p-j+1;
			}
			last=i+1;
		}
	}
	ll ans=0;
	for(int i=0; i<fac.size(); i++) {
		ans+=(sub[fac[i].fi]*cub[fac[i].se]);
	}
	cout << ans << endl;
}
