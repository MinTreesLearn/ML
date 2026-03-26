#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 800
using namespace std;
int n,a[N+5],p[N+5],pp[N+5],o[N+5];vector<int> v;
int Q(vector<int> v)
{
	printf("? %d ",(int)v.size());for(auto x:v) printf("%d ",x);putchar('\n'),fflush(stdout);
	int t;return scanf("%d",&t),t;
}
int main()
{
	if(scanf("%d",&n),n==2) return puts("! 1 2"),0;
	int i,j;for(i=1;i<=n;++i)
	{
		for(vector<int>().swap(v),j=1;j<=n;++j) j^i&&(v.push_back(j),0);
		if(Q(v)) if(!p[1]) p[a[i]=1]=i;else {p[a[i]=n]=i;break;}
	}
	for(o[p[1]]=i=1;i<=n;++i) !a[i]&&(o[i]=Q({p[1],i}));
	int P=2;for(int V=2;2*V<=n;++V)
	{
		for(i=1;i<=n;++i) if(!a[i]&&o[i]==V%P)
		{
			for(vector<int>().swap(v),j=1;j<=n;++j) !a[j]&&j^i&&(v.push_back(j),0);
			if(v.empty()||Q(v)) {p[a[i]=V]=i;break;}
		}
		for(i=1;i<=n;++i) if(!a[i]&&o[i]==(n-V+1)%P)
		{
			for(vector<int>().swap(v),j=1;j<=n;++j) (!a[j]||a[j]==V)&&j^i&&(v.push_back(j),0);
			if(v.empty()||Q(v)) {p[a[i]=n-V+1]=i;break;}
		}
		if(V==(P<<1)) for(P<<=1,i=1;i<=n;++i) if(!a[i])
		{
			for(vector<int>().swap(v),v.push_back(i),j=1;j<=P;++j) (j%P)^o[i]&&(v.push_back(p[j]),0);
			if(Q(v)) o[i]+=P>>1;
		}
	}
	if(a[1]>(n>>1)) for(i=1;i<=n;++i) a[i]=n-a[i]+1;for(printf("! "),i=1;i<=n;++i) printf("%d ",a[i]);return 0;
}