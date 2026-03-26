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
       	int n;
       	cin>>n;
       	map<pair<int,int>,int> m;
       	pair<int,int> a[n][n];
       	for(int i=0;i<n;i++){
       		for(int j=0;j<n;j++){
       			cin>>a[i][j].first>>a[i][j].second;
       			if(a[i][j].first!=-1||a[i][j].second!=-1){
       				a[i][j].first--;
       				a[i][j].second--;
	       			m[a[i][j]]++;
	       		}
       		}
       	}
       	char ans[n][n];
       	int z=1;
       	vector<vector<int>> b(n,vector<int>(n));
       	for(auto u:m){
       		if(u.first.first==-1){
       			continue;
       		}
       		queue<pair<int,int>> q;
       		if(a[u.first.first][u.first.second]!=u.first){
       			z=0;
       		}
       		b[u.first.first][u.first.second]=1;
       		q.push({u.first.first,u.first.second});
       		ans[u.first.first][u.first.second]='X';
       		int r=0;
       		while(!q.empty()){
       			r++;
       			int i=q.front().first;
       			int j=q.front().second;
       			q.pop();
       			if(i&&(a[i-1][j]==a[i][j])&&b[i-1][j]==0){
       				q.push({i-1,j});
       				b[i-1][j]=1;
       				ans[i-1][j]='D';
       			}
       			if(i<n-1&&(a[i+1][j]==a[i][j])&&b[i+1][j]==0){
       				q.push({i+1,j});
       				b[i+1][j]=1;
       				ans[i+1][j]='U';
       			}
       			if(j&&(a[i][j-1]==a[i][j])&&b[i][j-1]==0){
       				q.push({i,j-1});
       				b[i][j-1]=1;
       				ans[i][j-1]='R';
       			}
       			if(j<n-1&&(a[i][j+1]==a[i][j])&&b[i][j+1]==0){
       				q.push({i,j+1});
       				b[i][j+1]=1;
       				ans[i][j+1]='L';
       			}
       		}
       		if(r!=u.second){
       			z=0;
       		}
       	}
       	for(int k=0;k<n;k++){
       		for(int l=0;l<n;l++){
       			if(b[k][l]==0){
       				queue<pair<int,int>> q;
		       		b[k][l]=1;
		       		q.push({k,l});
		       		int r=0;
		       		while(!q.empty()){
		       			r++;
		       			int i=q.front().first;
		       			int j=q.front().second;
		       			q.pop();
		       			if(i&&b[i-1][j]==0){
		       				q.push({i-1,j});
		       				b[i-1][j]=1;
		       				ans[i-1][j]='D';
		       				if(k==i&&l==j){
		       					ans[k][l]='U';
		       				}
		       			}
		       			if(i<n-1&&b[i+1][j]==0){
		       				q.push({i+1,j});
		       				b[i+1][j]=1;
		       				ans[i+1][j]='U';
		       				if(k==i&&l==j){
		       					ans[k][l]='D';
		       				}
		       			}
		       			if(j&&b[i][j-1]==0){
		       				q.push({i,j-1});
		       				b[i][j-1]=1;
		       				ans[i][j-1]='R';
		       				if(k==i&&l==j){
		       					ans[k][l]='L';
		       				}
		       			}
		       			if(j<n-1&&b[i][j+1]==0){
		       				q.push({i,j+1});
		       				b[i][j+1]=1;
		       				ans[i][j+1]='L';
		       				if(k==i&&l==j){
		       					ans[k][l]='R';
		       				}
		       			}
		       		}
		       		if(r==1){
		       			z=0;
		       		}
       			}
       		}
       	}
       	if(z){
       		cout<<"VALID"<<endl;
       		for(int i=0;i<n;i++){
       			for(int j=0;j<n;j++){
       				cout<<ans[i][j];
       			}
       			cout<<endl;
       		}
       	}
       	else{
       		cout<<"INVALID"<<endl;
       	}
    }
#ifndef ONLINE_JUDGE
    cout<<"Time : "<<fixed<<setprecision(6)<<((double)(clock()-time_req))/CLOCKS_PER_SEC<<endl;
#endif    
}