#include<bits/stdc++.h>
using namespace std;
int const M=1000100;char ch;
int i,n,k,x,a[M],f[M],g[M],s[M];
vector<pair<char,int> >G[M];
void dfs(int x,int p){
	f[x]=f[p]+1;g[x]=min(f[x],g[p]+s[p]);
	if (s[x]) f[x]=min(f[x],g[x]+1);
	sort(G[x].begin(),G[x].end());
	for (auto v:G[x]) dfs(v.second,x);
	s[p]+=s[x];
}
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++){
	  scanf("%d %c",&x,&ch);
	  G[x].push_back(make_pair(ch,i));
	  }
	scanf("%d",&k);
	for (i=1;i<=k;i++) scanf("%d",&a[i]),s[a[i]]=1;
	f[0]=-1;dfs(0,0);
	for (i=1;i<=k;i++) printf("%d ",f[a[i]]);
	return 0;
}