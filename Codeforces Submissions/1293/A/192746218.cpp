#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define mk make_pair
using namespace std;
vector<ll> a;
ll n, s, k;

void solve() {
	for (ll i = 0; i <= k; i++) {
		if(s - i >= 1 && find(a.begin(), a.end(), s - i) == a.end()){
            cout << i << '\n';
            return;
        }
		if(s + i <= n && find(a.begin(), a.end(), s + i) == a.end()){
            cout << i << '\n';
            return;
        }
	}
	assert(false);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> s >> k;
        a.clear();
        a.resize(k);
        for(auto &x: a) cin >> x;
        solve();
    }
}
