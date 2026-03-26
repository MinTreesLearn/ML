// LUOGU_RID: 97154482
#include <bits/stdc++.h>
#define int long long 
#define se second
using namespace std;
const int INF=5e5+5;
int t,n,m,a[INF];
map <set<int>,int> M;
set <int> s[INF];
void solve() {
	M.clear();
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i],s[i].clear();
	for (int i=1;i<=m;i++) {
		int x=0,y=0;
		cin>>x>>y;
		s[y].insert(x);
	}
	for (int i=1;i<=n;i++) 
		if (s[i].size()) M[s[i]]+=a[i];
	int ans=0;
	for (map <set<int>,int>::iterator it=M.begin();it!=M.end();it++)
		ans=__gcd(ans,it->se);
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) solve();
	return 0;
}