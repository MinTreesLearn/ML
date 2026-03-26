#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define em emplace_back
#define fi(l, r) for(ll i=l; i<r; i++)
#define fir(r, l) for(ll i=r; i>=l; i--)

void solve(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	if(s.length() <= 1){
		cout << -1 << endl;
		return;
	}
	string ans = "";
	ll cnt = 2;
	fi(0, s.length()){
		if((s[i]-48) &1 == 1){
			ans += s[i];
			cnt--;
		}
		if(cnt == 0){
			break;
		}
	}

	if(cnt != 0){
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}

}

int main(){
    ll t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}