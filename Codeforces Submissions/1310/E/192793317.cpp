#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int N=3000+5;
const int Mod=998244353;
int n,k,ans,f[N];
vector<int> vc,t,nw;
void solve1()
{	f[0]=1;
for(int i=1;i<=n;i++)
for(int j=i;j<=n;j++)f[j]=(f[j]+f[j-i])%Mod;
for(int i=1;i<=n;i++)ans=(ans+f[i])%Mod;
}
void solve2()
{	f[0]=1;
for(int i=1;(i*(i+1)>>1)<=n;i++)
for(int j=i*(i+1)>>1;j<=n;j++)
f[j]=(f[j]+f[j-(i*(i+1)>>1)])%Mod;
for(int i=1;i<=n;i++)ans=(ans+f[i])%Mod;
}
bool check()
{	t=vc;
for(int j=1;j<k;j++,nw.clear())
{	int s=0;
sort(t.begin(),t.end()),reverse(t.begin(),t.end());
for(int i=0;i<(int)t.size();i++)s+=t[i]*(i+1);
if(s>n)return 0;
if(j+3<k&&s>23)return 0;
for(int i=0;i<(int)t.size();i++)
for(int j=0;j<t[i];j++)nw.push_back(i+1);
t=nw;
}
return 1;
}
bool dfs(int x)
{	if(!check())return 0;
ans++;
for(int i=x;;i++)
{	vc.push_back(i);
int res=dfs(i);
vc.pop_back();
if(!res)return 1;
}
return 1;
}
int main()
{	scanf("%d%d",&n,&k);
if(k==1)solve1();
else if(k==2)solve2();
else dfs(1),ans--;
printf("%d\n",ans);
return 0;
}