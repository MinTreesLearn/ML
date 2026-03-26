#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const int mm = 1e5 + 10;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	ll x;
	cin>>x;
	ll ans=1;
	for(ll i=1;i<=x/i;i++){
		if(x%i==0){
			if(lcm(x/i,i)==x)ans=i;
		}
	}cout<<ans<<' '<<x/ans;
}
