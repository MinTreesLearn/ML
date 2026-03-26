#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[40001],b[40001],n,m,i,j,k,ans=0;
int main()
{
cin>>n>>m>>k;
for(i=0;i<n;i++){cin>>a[i];if(a[i]) a[i]+=a[i-1];}
for(i=0;i<m;i++){cin>>b[i];if(b[i]) b[i]+=b[i-1];}
for(i=1;i<=n;i++)
if(k%i==0){
ll u=i,v=k/i,x=0,y=0l;
for(j=0;j<n;j++) if(a[j]>=u) x++;
for(j=0;j<m;j++) if(b[j]>=v) y++;
ans+=x*y;
}
cout<<ans;
}
