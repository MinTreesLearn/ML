#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e6+9;
int n,m,sz;
int id[M],c[M][26],b[M],t[M],dp[M],L[M],R[M],val[M];
bool vis[M],bo[M];
int Min(int x,int y){
	return id[x]<id[y]?x:y;
}
int Max(int x,int y){
	return id[x]>id[y]?x:y;
}
void dfs(int u){
	id[u]=++sz;
	L[u]=n+1,R[u]=0;
	if(vis[u]){
		L[u]=u;
		R[u]=u;
	}
	for(int i=0;i<26;++i){
		if(c[u][i]){
			dfs(c[u][i]);
			if(R[c[u][i]]){
				if(R[u]){
					L[u]=Min(L[u],L[c[u][i]]);
					R[u]=Max(R[u],R[c[u][i]]);
				}
				else L[u]=L[c[u][i]],R[u]=R[c[u][i]];
			}
		}
	}
}
void solve(int u,int z){
	if(vis[u])dp[u]=min(dp[u],z+val[u]);
	if(R[u])z=min(z,dp[u]+1-val[L[u]]);
	for(int i=0;i<26;++i){
		if(c[u][i]){
			dp[c[u][i]]=dp[u]+1;
			solve(c[u][i],z);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		int p;
		char s[5];
		cin>>p>>s;
		c[p][s[0]-'a']=i;
	}
	
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>b[i];
		t[i]=i;
		vis[b[i]]=1;
	}
	dfs(0);
	sort(t+1,t+m+1,[&](const int&l,const int&r){return id[b[l]]<id[b[r]];});
	for(int i=1;i<=m;++i){
		val[b[t[i]]]=i;
	}
	solve(0,0);
	for(int i=1;i<=m;++i){
		cout<<dp[b[i]]<<" \n"[i==m];
	}
	return 0;
}
/*
1 2 2 4 3 6
*/