#include <bits/stdc++.h>
using namespace std;
int ch[1000005][26],dfnow,id[1000005],ans[1000005],dep[1000005];
multiset<int> s;
void dfs(int u)
{
	int nw=dep[u]-dfnow;
	if(id[u])
	{
		ans[id[u]]=min(dep[u],*s.begin()+dfnow+1);
		dep[u]=min(dep[u],ans[id[u]]);
		nw=dep[u]-dfnow;
		++dfnow;
	}
	s.insert(nw);
	for(int i=0;i<26;i++)
		if(ch[u][i]) dep[ch[u][i]]=dep[u]+1,dfs(ch[u][i]);
	s.erase(s.find(nw));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int fa;
		char c;
		cin >> fa >> c;
		ch[fa][c-'a']=i;
	}
	int m;
	cin >> m;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin >> x;
		id[x]=i;
	}
	dfs(0);
	for(int i=1;i<=m;i++)
		cout << ans[i] << " ";
	return 0;
}