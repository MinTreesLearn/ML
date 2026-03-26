#include<bits/stdc++.h>
using namespace std;
int n;
int fa[2005],rk[2005],rt;
vector<int> vec[2005],tmp[2005];
void dfs(int x){
if(!rk[x])tmp[x].push_back(x);
for(auto u:vec[x]){
dfs(u);
for(auto it:tmp[u]){
tmp[x].push_back(it);
if(tmp[x].size()==rk[x])tmp[x].push_back(x);
}
}
if(tmp[x].size()<rk[x]){
puts("NO");
exit(0);
}
}
int ans[2005];
int main(){
scanf("%d",&n);
for(int i=1;i<=n;i++){
scanf("%d%d",&fa[i],&rk[i]);
if(!fa[i])rt=i;
else vec[fa[i]].push_back(i);
}
dfs(rt);
for(int i=0;i<n;i++)ans[tmp[rt][i]]=i+1;
puts("YES");
for(int i=1;i<=n;i++)printf("%d ",ans[i]);



return 0;
}


