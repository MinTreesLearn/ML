#include<bits/stdc++.h>
using namespace std;
int i,n,k,x,y,d[200200],e[200200];
vector<int> a[200200],A[200200];
void dfs(int t,int w,int s){
for (int i=0;i<a[t].size();i++)
if (a[t][i]!=w)
e[A[t][i]]=(++s>d[n-k])?s=1:s,dfs(a[t][i],t,s);
return ;
}
int main(){
scanf("%d %d",&n,&k);
for (i=1;i<n;i++){
scanf("%d %d",&x,&y);
a[x].push_back(y);A[x].push_back(i);
a[y].push_back(x);A[y].push_back(i);
d[x]++;d[y]++;
}
sort(d+1,d+1+n);dfs(1,0,0);
printf("%d\n",d[n-k]);
for (i=1;i<n;i++) printf("%d ",e[i]);
return 0;
}