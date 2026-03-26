#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+1;
int n;
int f[N][N],s[N],p[N],c[N];
signed main()
{
scanf("%lld",&n);
for(int i=1;i<=n;i++)
{
int x;
scanf("%lld",&x);
c[x]++;
}
p[0]=1;
for(int i=1;i<=5000;i++)
{
p[i]=p[i-1];
for(int j=2,x=i;j<=i;j++)
{
f[i][j]=f[i-1][j];
if(x%j)continue;
while(x%j==0)f[i][j]++,x/=j;
p[i]=max(p[i],j);
}
}
int ans=0;
for(int i=1;i<=5000;i++)
for(int j=1;j<=i;j++)ans+=f[i][j]*c[i];
while(1)
{
memset(s,0,sizeof(s));
for(int i=1;i<=5000;i++)s[p[i]]+=c[i];
int mx=1;
for(int i=1;i<=5000;i++)if(s[i]>s[mx])mx=i;
if(mx==1||s[mx]*2<n)break;
ans=ans+n-s[mx]*2;
for(int i=1;i<=5000;i++)
{
if(p[i]!=mx)p[i]=1;
if(p[i]==1)continue;
f[i][p[i]]--;
while(p[i]>1&&!f[i][p[i]])p[i]--;
}
}
printf("%lld\n",ans);
return 0;
}