#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 20
#define LL long long
using namespace std;
int n,f[1<<N],p[1<<N],c[1<<N];LL a[N+5],s[1<<N];
int main()
{
int i,j;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%lld",a+i),a[i]?s[1<<i-1]=a[i]:(--i,--n);
int l=1<<n;for(i=0;i^l;++i) c[i]=c[i>>1]+(i&1);for(j=0;j^n;++j) for(i=0;i^l;++i) i>>j&1&&(s[i]+=s[i^(1<<j)]);
for(i=0;i^l;++i) if((s[i]&1)^(c[i]&1)) for(j=i&(i-1);j;j=(j-1)&i) if(1-c[i]<=s[j]-s[i^j]&&s[j]-s[i^j]<=c[i]-1) {p[i]=1;break;}
for(i=1;i^l;++i) for(f[i]=1e9,j=i;j;j=(j-1)&i) c[j]==1?f[i]=min(f[i],f[i^j]+1):p[j]&&(f[i]=min(f[i],f[i^j]+c[j]-1));
return printf("%d\n",f[l-1]),0;
}