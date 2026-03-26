#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const int mm = 3e5 + 10;
int a[105],dp[105][105][105][3],zero[105];
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	cin>>n;
	int odd=n/2+n%2,even=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]){
			if(a[i]%2)odd--;
			else even--;
		}else zero[i]++;
		zero[i]+=zero[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				dp[i][j][k][0]=dp[i][j][k][1]=105;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=zero[i];j++){
			int k=zero[i]-j;
			if(a[i]){
				if(a[i]%2)dp[i][j][k][1]=min(dp[i-1][j][k][1],dp[i-1][j][k][0]+1),
					dp[i][j][k][0]=105;
				else dp[i][j][k][0]=min(dp[i-1][j][k][0],dp[i-1][j][k][1]+1),
					dp[i][j][k][1]=105;
			}else{
				if(j)dp[i][j][k][1]=min(dp[i-1][j-1][k][0]+1,dp[i-1][j-1][k][1]);
				if(k)dp[i][j][k][0]=min(dp[i-1][j][k-1][0],dp[i-1][j][k-1][1]+1);
			}
		}
	}cout<<min(dp[n][odd][even][1],dp[n][odd][even][0]);
}
