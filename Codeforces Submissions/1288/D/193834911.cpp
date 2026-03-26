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
       	int n,m;
       	cin>>n>>m;
       	int a[n][m];
       	for(int i=0;i<n;i++){
       		for(int j=0;j<m;j++){
       			cin>>a[i][j];
       		}
       	}
       	int l=0;
       	int r=1e9;
       	while(l<r){
       		vector<int> dp(1<<m);
       		int x=(l+r+1)/2;
       		for(int i=0;i<n;i++){
       			int c=0;
       			for(int j=0;j<m;j++){
       				if(a[i][j]>=x){
       					c+=(1<<j);
       				}
       			}
       			dp[c]=i+1;
       		}
       		for(int i=(1<<m)-1;i>=0;i--){
       			if(dp[i]){
       				for(int j=0;j<m;j++){
       					if(i&(1<<j)){
       						dp[i^(1<<j)]=dp[i];
       					}
       				}
       			}
       		}
       		int z=0;
       		for(int i=0;i<n;i++){
       			int c=0;
       			for(int j=0;j<m;j++){
       				if(a[i][j]>=x){
       					c+=(1<<j);
       				}
       			}
       			if(dp[(1<<m)-1-c]){
       				z=1;
       			}
       		}
       		// cout<<x<<" "<<z<<endl;
       		if(z){
       			l=x;
       		}
       		else{
       			r=x-1;
       		}
       	}
       	vector<int> dp(1<<m);
   		for(int i=0;i<n;i++){
   			int c=0;
   			for(int j=0;j<m;j++){
   				if(a[i][j]>=l){
   					c+=(1<<j);
   				}
   			}
   			dp[c]=i+1;
   		}
   		for(int i=(1<<m)-1;i>=0;i--){
   			if(dp[i]){
   				for(int j=0;j<m;j++){
   					if(i&(1<<j)){
   						dp[i^(1<<j)]=dp[i];
   					}
   				}
   			}
   		}
       	for(int i=0;i<n;i++){
   			int c=0;
   			for(int j=0;j<m;j++){
   				if(a[i][j]>=l){
   					c+=(1<<j);
   				}
   			}
   			if(dp[(1<<m)-1-c]){
   				cout<<i+1<<" "<<dp[(1<<m)-1-c]<<endl;
   				break;
   			}
   		}
    }
#ifndef ONLINE_JUDGE
    cout<<"Time : "<<fixed<<setprecision(6)<<((double)(clock()-time_req))/CLOCKS_PER_SEC<<endl;
#endif    
}