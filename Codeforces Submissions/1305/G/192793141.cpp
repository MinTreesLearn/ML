#include<iostream>
#define q 1<<18
long long h;int c[q],f[q],i,j,s,t;int p(int a){return f[a]==a?a:f[a]=p(f[a]);}main(){for(*c=1,scanf("%d",&t);t--&&scanf("%d",&s);c[s]++)h-=s;for(i=q;--i;f[i]=i);for(i=q;--i;)for(j=i;j;--j&=i)if(c[j]&&c[i^j]&&(s=p(j))^(t=p(i^j)))f[s]=t,h+=i*(c[s]+c[t]-1LL),c[t]=1;std::cout<<h;}