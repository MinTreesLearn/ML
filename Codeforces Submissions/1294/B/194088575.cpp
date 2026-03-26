#include <bits/stdc++.h>
 
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define optimus_prime ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fxd(x) fixed << setprecision(x)
#define all(a) (a.begin() , a.end())
#define lwb lower_bound
#define upb upper_bound
#define dl double long
#define ll long long
#define pb push_back
#define sz() size()
#define F first
#define S second
 
using namespace std;
 
const ll N = 1e2+9;

void solve() {
	vector <char> v;
	ll n;
	cin >> n;
	pair <int , int> p[n+9];
	for (int i = 1 ; i <= n ; i++)cin >> p[i].F >> p[i].S;
	sort (p+1 , p+1+n);
	ll x1=p[1].F , x2=p[1].S;
	while (x1--)v.pb('R');
	while (x2--)v.pb('U');
	for (int i = 2 ; i <= n ; i++){
		if (p[i].F>p[i-1].F&&p[i].S<p[i-1].S){
			cout << "NO\n";
			return;
		}
		if (p[i].F==p[i-1].F){
			ll x=p[i].S-p[i-1].S;
			while(x--)v.pb('U');
		}
		if (p[i].F>p[i-1].F&&p[i].S==p[i-1].S){
			ll x=p[i].F-p[i-1].F;
			while (x--)v.pb('R');
		}
		if (p[i].F!=p[i-1].F&&p[i].S!=p[i-1].S){
			ll x=p[i].F-p[i-1].F;
			while (x--)v.pb('R');
			x=p[i].S-p[i-1].S;
			while (x--)v.pb('U');
		}
	}
	cout << "YES\n";
	for (int i = 0 ; i < v.sz() ; i++)cout << v[i];
	cout << "\n";
}

signed main() {
    optimus_prime;
    ll t;
    cin >> t;
    while (t--)solve();
return 0;
}