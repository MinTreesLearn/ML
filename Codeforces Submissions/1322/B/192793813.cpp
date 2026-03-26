#include<stdio.h>

int n,a[400002],f[400002],c[1<<26],ans;

int main()
{
scanf("%d",&n);
for(int i=1;i<=n;i++) scanf("%d",&a[i]);
for(int k=0;k<25;k++)
{
long long sum1=0,sum2=0;
if(k>0)
{
for(int i=0;i<(1<<k);i++) c[i]=0;
for(int i=1;i<=n;i++) c[a[i]&((1<<k)-1)]++;
for(int i=(1<<k)-1;i;i--) c[i]+=c[i+1];
for(int i=1;i<=n;i++)
sum1+=c[(1<<k)-(a[i]&((1<<k)-1))]-((a[i]>>(k-1))&1);
}

int t[2]={0};
for(int i=1;i<=n;i++) t[(a[i]>>k)&1]++;
sum2=(long long)t[0]*t[1];

ans|=((sum1/2+sum2)&1)?(1<<k):0;
}
printf("%d",ans);
return 0;
}