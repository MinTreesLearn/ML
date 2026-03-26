#include<stdio.h>
int main()
{
long long int n,m,ans=0;scanf("%lld%lld",&n,&m);
long long int store[n+2]; store[1] = 1;
for(int i=2;i<=n+1;i++)store[i]=(store[i-1]*i)%m;
for(int i=1;i<=n;i++)ans+=(n-i+1)*(store[i]*store[n-i+1]%m),ans%=m;
printf("%lld\n",ans);
}