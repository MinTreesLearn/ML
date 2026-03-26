#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const int mm = 1e5 + 10;
ll dp[mm*10];
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	ll x;
	cin>>x;
	ll bjx=x;
	vector<ll>v;
	for(int i=2;i<=x/i;i++){
		if(x%i==0){
			ll js=1;
			while(x%i==0){
				x/=i;
				js*=i;
			}
			v.push_back(js);
		}
	}if(x>1)v.push_back(x);
	int n=v.size();
	int k=sqrt(bjx)+1;
	for(int i=0;i<=k;i++)dp[i]=1;
	for(int i=0;i<n;i++){
		for(int j=k;j>=v[i];j--){
			if(j%v[i]==0){
				dp[j]=max(dp[j],dp[j/v[i]]*v[i]);
			}
		}
	}
	ll ma=1;
	for(int i=k;i>=1;i--){
		ma=max(ma,dp[i]);
	}
	cout<<bjx/ma<<' '<<ma;
}
