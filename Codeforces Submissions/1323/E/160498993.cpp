#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define vi vector<int> 
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define all(v) v.begin(),v.end()
const double eps=1e-7;
const double pi=acos(-1);
//void print(__int128 x){
//	if(x<0) putchar('-') ,x=-x;
//	if(x>9) print(x/10);
//	putchar(x%10+'0');
//}
const int N=5e5+5;
vi g[N];
int c[N];
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int __;
	cin>>__;
	while(__--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>c[i];g[i].clear();
		}
		map<vi,int >mp;
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			g[y].pb(x);
		}
		for(int i=1;i<=n;i++){
			sort(all(g[i]));
		}
		for(int i=1;i<=n;i++){
			if(g[i].size()) mp[g[i]]+=c[i];
		}
		int ans=0;
		for(auto [x,y]:mp){
			ans=__gcd(ans,y);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
