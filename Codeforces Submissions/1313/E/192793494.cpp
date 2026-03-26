#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int n,m,z[N],za[N],zb[N];
char a[N],b[N],s[N],t[N];
void Z(char *s,int n){
z[1]=n;
for(int i=2,l=0,r=0;i<=n;i++){
if(i<=r)z[i]=min(z[i-l+1],r-i+1);
else z[i]=0;
while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1])++z[i];
if(i+z[i]-1>r)l=i,r=i+z[i]-1;
}
}
struct tree_array{
int c1[N];ll c2[N];
void add(int i,int v1,ll v2){++i;for(;i<=m;i+=i&-i)c1[i]+=v1,c2[i]+=v2;}
int sum1(int i){++i;int s=0;for(;i;i-=i&-i)s+=c1[i];return s;}
ll sum2(int i){++i;ll s=0;for(;i;i-=i&-i)s+=c2[i];return s;}
}tr;
signed main(){
scanf("%d%d%s%s%s",&n,&m,a+1,b+1,s+1);
for(int i=1;i<m;i++)t[i]=s[i];
t[m]='*';
for(int i=1;i<=n;i++)t[m+i]=a[i];
Z(t,n+m);
for(int i=1;i<=n;i++)za[i]=z[m+i];
for(int i=1;i<m;i++)t[i]=s[m-i+1];
t[m]='*';
for(int i=1;i<=n;i++)t[m+i]=b[n-i+1];
Z(t,n+m);
for(int i=1;i<=n;i++)zb[i]=z[m+n-i+1];
int r=min(m-2,n);
for(int i=1;i<=r;i++)tr.add(m-1-zb[i],1,zb[i]);
ll ans=0;
for(int l=1;l<=n;l++){
if(r<n)++r,tr.add(m-1-zb[r],1,zb[r]);
ans+=1ll*tr.sum1(za[l])*(za[l]-m+1)+tr.sum2(za[l]);
tr.add(m-1-zb[l],-1,-zb[l]);
}
printf("%lld\n",ans);
}