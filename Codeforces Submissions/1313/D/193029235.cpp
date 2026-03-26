// LUOGU_RID: 101831831
// Problem: Happy New Year
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1313D
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//不回家了，我们去鸟巢！
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
pair<int,int> a[100003];
int f[100003][1<<8],g[100003][13],tr[13],arr[13];
signed main()
{
	int n=read(),m=read(),w=read(),N=1<<w;
	for(int i=1; i<=n; ++i)
		a[i].first=read(),a[i].second=read();
	sort(a+1,a+n+1),
	memset(f,0xc0,sizeof(f)),
	f[0][0]=0;
	a[n+1].first=m+1;
	for(int i=0; i<w; ++i) g[0][i]=0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<w; ++j) tr[j]=1<<j;
		int o=0;
		while(o<w&&a[i].second>g[i-1][o]) ++o;
		assert(o!=0);
		for(int j=o; j<w; ++j) g[i][j]=g[i-1][j];
		for(int j=0; j+1<o; ++j) g[i][j]=g[i-1][j+1];
		g[i][o-1]=a[i].second;
		int O=(1<<o)-1;
		for(int j=0; j<N; ++j)
			f[i][j-(j&O)+((j&O)>>1)]=
			max(f[i][j-(j&O)+((j&O)>>1)],f[i-1][j]),
			f[i][j-(j&O)+((j&O)>>1)+(1<<(o-1))]=
			max(f[i][j-(j&O)+((j&O)>>1)+(1<<(o-1))],f[i-1][j]);
		for(int j=0; j<N; ++j) if(f[i][j]>=0)
		{
			int cnt=0;
			arr[0]=a[i].first-1;
			for(int k=0; k<w; ++k)
				if(((j>>k)&1))
					arr[++cnt]=max(a[i].first-1,
					min(a[i+1].first-1,g[i][k]));
			for(int k=cnt; k>=1; k-=2)
				f[i][j]+=arr[k]-arr[k-1];
		}
	}
	int ans=0;
	for(int i=0; i<N; ++i) ans=max(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}