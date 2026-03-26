#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=1e5+3;
int a[N];
void solve() {
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=0;i<=100;i++) a[i]=0;
	for(int i=1; i<=m; i++) {
		int x,cnt=0;
		cin>>x;
		sum+=x;
		while(x)cnt++,x/=2;
		a[cnt-1]++;
	}
	if(sum<n) cout<<"-1"<<endl;
	else {
		int ans=0;
		for(int i=0;i<64; i++) {
			int x=(n>>i)&1;
			a[i]-=x;
			if(a[i]>=2)a[i+1]+=a[i]/2;
			if(a[i]<0)ans++,a[i+1]--;
		}
		cout<<ans<<endl;
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}


