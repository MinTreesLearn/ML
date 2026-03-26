#include<bits/stdc++.h>
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
using namespace std;
int const lim=(1<<18)-1;long long res;
int i,j,n,x,u,v,f[lim+5],cnt[lim+5];
int read(){
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x;
}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main(){ n=read();cnt[0]=1;
	for (i=1;i<=n;i++) cnt[x=read()]++,res-=x;
	for (i=0;i<=lim;i++) f[i]=i;
	for (i=lim;~i;i--)
		for (j=i;j;j=(j-1)&i)
			if (cnt[j]&&cnt[i^j]){
				u=find(j);v=find(i^j);
				if (u==v) continue;	
				res+=1ll*i*(cnt[u]+cnt[v]-1);
				f[u]=v;cnt[v]=1;
			}
	printf("%lld\n",res);		
	return 0;
}