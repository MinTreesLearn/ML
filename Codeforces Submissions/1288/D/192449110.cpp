#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N=3e5+3;
int n,m,x;
int vis[N],a[N][10];
bool check(int mid) {
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; i++) {
		int ans=0;
		for(int j=0; j<m; j++) {
			if(a[i][j]>=mid) ans+=(1<<j);
		}
		vis[ans]=1;
	}
	for(int i=0; i<(1<<m); i++)
		for(int j=0; j<(1<<m); j++) if(vis[i]&&vis[j]&&(i|j)==x)return 1;
	return 0;
}
void solve() {
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		for(int j=0; j<m; j++)  cin>>a[i][j];
	int l=0,r=1e9,sum;
	x=(1<<m)-1;
	while(l<=r) {
		int mid=(l+r)/2;
		if(check(mid)) sum=mid,l=mid+1;
		else r=mid-1;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; i++) {
		int ans=0;
		for(int j=0; j<m; j++) {
			if(a[i][j]>=sum) ans+=(1<<j);
		}
		vis[ans]=i;
	}
	int x1,x2;
	for(int i=0; i<(1<<m); i++)
		for(int j=0; j<(1<<m); j++)
			if(vis[i]&&vis[j]&&(i|j)==x) {
				x1=vis[i],x2=vis[j];
				break;
			}
	cout<<x1<<" "<<x2<<endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	int t;	cin>>t;	while(t--)
	solve();
	return 0;
}


