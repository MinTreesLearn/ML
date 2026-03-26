#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const int mm = 2e5 + 10;
void solve(){
	ll a,b;
	cin>>a>>b;
	ll ans=0;
	for(int i=10;i-1<=b;i*=10){
		ans+=a;
	}cout<<ans<<'\n';
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
