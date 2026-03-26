#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const int mm = 2e5 + 10;
void solve(){
	ll n,d;
	cin>>n>>d;
	ll x=max((ll)sqrt(d)-1,0ll);
	if(d<=n)cout<<"YES\n";
	else{
		for(ll i=max(x-1000,0ll);i<=x+1000;i++){
			if(i+(d+i)/(i+1)<=n){
				cout<<"YES\n";
				return;
			}
		}cout<<"NO\n";
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
