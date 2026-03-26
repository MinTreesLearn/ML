#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
//const ll mod = 1e9 + 7;
const ll mm = 2.5e5 + 10;
ll jc[mm];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	ll mod;
	cin>>n>>mod;
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
	}ll ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+jc[i]*jc[n-i+1]%mod*(n-i+1)%mod)%mod;
	}cout<<ans;
}
