#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
typedef long long LL;
typedef pair<int,int> PII;


void solve(){
	int n,x,y;
	cin>>n>>x>>y;
	int mn=(x+y<n+1)?1:min(n,x+y-n+1);
	int mx=min(n,x+y-1);
	cout<<mn<<" "<<mx<<endl;
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--) {
	    solve();
	}

	return 0;
}