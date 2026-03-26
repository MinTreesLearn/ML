#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const int mm = 1e5 + 10;
ll a[mm];
void solve(){
	int n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i],sum+=a[i];
	}
	ll mal=-mod*2,mar=-mod*2;
	ll bj=0;
	for(int i=1;i<n;i++){
		bj+=a[i];
		mal=max(mal,bj);
		if(bj<0)bj=0;
	}bj=0;
	for(int j=2;j<=n;j++){
		bj+=a[j];
		mar=max(mar,bj);
		if(bj<0)bj=0;
	}
	if(sum>max(mal,mar))cout<<"YES";
	else cout<<"NO";
	cout<<"\n";
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
