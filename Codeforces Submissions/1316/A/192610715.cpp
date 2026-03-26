#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

void solve(){
	int n,m,x,sum=0; cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> x;
		sum+=x;
	}
	cout << ((sum<m)?sum:m) << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
