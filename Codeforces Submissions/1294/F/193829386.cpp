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

int o,y,z;
pair<int,int> dfs1(int i,vector<int> &b,vector<int> v[],vector<pair<int,int>> x[]){
	b[i]=1;
	int r=0;
	int c=i;
	for(auto u:v[i]){
		if(!b[u]){
			pair<int,int> k=dfs1(u,b,v,x);
			k.first++;
			if(r<=k.first){
				r=k.first;
				c=k.second;
			}
			x[i].push_back(k);
		}
	}
	return {r,c};
}
pair<int,int> dfs(int i,vector<int> &b,vector<int> v[],pair<int,int> d,int &ans,vector<pair<int,int>> x[]){
	b[i]=1;
	vector<pair<int,int>> c;
	int f=0;
	int r=i;
	int p=0;
	int pi;
	int w;
	for(int j=0;j<x[i].size();j++){
		if(x[i][j].first>=p){
			w=j;
			p=x[i][j].first;
			pi=x[i][j].second;
		}
	}
	int q=0;
	int qi;
	for(int j=0;j<x[i].size();j++){
		if(j==w){
			continue;
		}
		if(x[i][j].first>=q){
			q=x[i][j].first;
			qi=x[i][j].second;
		}
	}
	int e=0;
	for(auto u:v[i]){
		if(!b[u]){
			pair<int,int> s;
			if(e==w){
				if(d.first+1>=q+1){
					s=dfs(u,b,v,{d.first+1,d.second},ans,x);
				}
				else{
					s=dfs(u,b,v,{q+1,qi},ans,x);
				}
			}
			else{
				if(d.first+1>=p+1){
					s=dfs(u,b,v,{d.first+1,d.second},ans,x);
				}
				else{
					s=dfs(u,b,v,{p+1,pi},ans,x);
				}

			}
			if(s.first+1>f){
				f=s.first+1;
				r=s.second;
			}
			c.push_back({s.first+1,s.second});
			e++;
		}
	}
	c.push_back(d);
	c.push_back({0,i});
	c.push_back({0,i});
	sort(c.rbegin(),c.rend());
	if(c[0].first+c[1].first+c[2].first>=ans){
		ans=c[0].first+c[1].first+c[2].first;
		o=c[0].second;
		y=c[1].second;
		z=c[2].second;
	}
	return {f,r};
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
       	int ans=0;
       	vector<int> b(n+1);
       	vector<pair<int,int>> x[n+1];
       	dfs1(1,b,v,x);
       	for(int i=1;i<=n;i++){
       		b[i]=0;
       	}
       	dfs(1,b,v,{0,1},ans,x);
       	cout<<ans<<endl;
       	if(y==o){
       		if(o!=1&&z!=1){
       			y=1;
       		}
       		else if(o!=2&&z!=2){
       			y=2;
       		}
       		else{
       			y=3;
       		}
       	}
       	if(o==z){
       		if(y!=1&&z!=1){
       			o=1;
       		}
       		else if(y!=2&&z!=2){
       			o=2;
       		}
       		else{
       			o=3;
       		}
       	}
       	if(y==z){
       		if(y!=1&&o!=1){
       			z=1;
       		}
       		else if(y!=2&&o!=2){
       			z=2;
       		}
       		else{
       			z=3;
       		}
       	}
       	cout<<o<<" "<<y<<" "<<z;
    }
#ifndef ONLINE_JUDGE
    cout<<"Time : "<<fixed<<setprecision(6)<<((double)(clock()-time_req))/CLOCKS_PER_SEC<<endl;
#endif    
}