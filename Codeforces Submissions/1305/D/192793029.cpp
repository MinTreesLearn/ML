#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v[1005];
int vis[1005]={0};
int dfs(int a)
{
vis[a]=1;
for(auto i:v[a])
{
if(!vis[i])
return dfs(i);
}
return a;
}
int main()
{
//int n;
//vector<int> v[n];
cin>>n;
for(int i=1;i<n;i++)
{
int u,k;
cin>>u>>k;
v[u].push_back(k);
v[k].push_back(u);
}
int x=0,y=0,r=1;
while(1)
{
x=dfs(r);
y=dfs(r);
if(x==r)
break;
cout<<"? "<<x<<" "<<y<<endl;
cin>>r;
}
cout<<"! "<<r<<endl;
}