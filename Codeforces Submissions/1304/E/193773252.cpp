#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
#define endl '\n'
#define ilihg ios_base::sync_with_stdio(false);cin.tie(NULL)

void dfs(int i,int par,vector<int> v[],vector<int> &p,int d,vector<int> &depth){
	depth[i]=d;
	p[i]=par;
	for(auto u:v[i]){
		if(u!=par){
			dfs(u,i,v,p,d+1,depth);
		}
	}
}
void eval(int n,vector<int> v[],vector<vector<int>> &dp,vector<int> &depth){
	vector<int> p(n+1);
	int r=log2(n);
	dp.resize(n+1,vector<int>(r+2));
	depth.resize(n+1);
	dfs(1,0,v,p,1,depth);
	for(int i=1;i<=n;i++){
		dp[i][0]=p[i];
	}
	for(int i=1;i<=r+1;i++){
		for(int j=1;j<=n;j++){
			dp[j][i]=dp[dp[j][i-1]][i-1];
		}
	}
}
int lca(int x,int y,vector<vector<int>> &dp,vector<int> &depth){
	int ans=0;
	if(depth[x]<depth[y]){
		swap(x,y);
	}
	int c=depth[x]-depth[y];
	while(c){
		int p=log2(c);
		x=dp[x][p];
		c-=(1<<p);
		ans+=(1<<p);
	}
	int g=log2(depth[x]);
	while(g>=0){
		if(dp[x][g]!=dp[y][g]){
			ans+=(1<<(g+1));
			x=dp[x][g];
			y=dp[y][g];
		}
		g--;
	}
	if(x!=y){
		ans+=2;
		x=dp[x][0];
	}
	return ans;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	clock_t time_req=clock();
	ilihg;
	int t=1;
    // cin>>t;
    while(t--){
       	int n;
       	cin>>n;
       	vector<int> v[n+1];
       	for(int i=0;i<n-1;i++){
       		int c,d;
       		cin>>c>>d;
       		v[c].push_back(d);
       		v[d].push_back(c);
       	}
       	vector<vector<int>> dp;
       	vector<int> depth;
       	eval(n,v,dp,depth);
       	int q;
       	cin>>q;
       	while(q--){
       		int x,y,a,b,k;
       		cin>>x>>y>>a>>b>>k;
       		int z=0;
       		int a1=lca(a,b,dp,depth),a2=lca(a,x,dp,depth)+lca(b,y,dp,depth)+1,a3=lca(b,x,dp,depth)+lca(a,y,dp,depth)+1;
       		if(a1<=k&&a1%2==k%2){
       			z=1;
       		}
       		if(a2<=k&&a2%2==k%2){
       			z=1;
       		}
       		if(a3<=k&&a3%2==k%2){
       			z=1;
       		}
       		if(z){
       			cout<<"Yes"<<endl;
       		}
       		else{
       			cout<<"No"<<endl;
       		}
       	}
    }
#ifndef ONLINE_JUDGE
    cout<<"Time : "<<fixed<<setprecision(6)<<((double)(clock()-time_req))/CLOCKS_PER_SEC<<endl;
#endif    
}