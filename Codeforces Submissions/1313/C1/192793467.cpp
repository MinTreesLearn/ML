#include<bits/stdc++.h>
using namespace std;
int an[1111],m[1111],ans[1111];
int main()
{
long long mx=0,sum;
int n,i,j;
scanf("%d",&n);
for(i=1; i<=n; i++)scanf("%d",&m[i]);
for(i=1; i<=n; i++)
{
an[i]=m[i],sum=m[i];
for(j=i-1; j>=1; j--)an[j]=min(m[j],an[j+1]),sum+=an[j];
for(j=i+1; j<=n; j++)an[j]=min(m[j],an[j-1]),sum+=an[j];
if(mx<sum)
{
mx=sum;
for(j=1; j<=n; j++)ans[j]=an[j];
}
}
for(i=1; i<=n; i++)cout<<ans[i]<<" ";
cout<<endl;
}
