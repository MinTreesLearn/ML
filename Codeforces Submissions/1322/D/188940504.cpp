// LUOGU_RID: 99449566
#include<bits/stdc++.h>
using namespace std;
const int N=2010;

int l[N],s[N],c[N<<1],f[N<<1][N];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	m=n+m;
	for (int i=n;i;i--)
		scanf("%d",&l[i]);
	for (int i=n;i;i--)
		scanf("%d",&s[i]);
	for (int i=1;i<=m;i++)
		scanf("%d",&c[i]);
	memset(f,0xaf,sizeof(f));
	for (int i=0;i<=m;i++)
		f[i][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=n;j;j--)
			f[l[i]][j]=max(f[l[i]][j],f[l[i]][j-1]+c[l[i]]-s[i]);
		for (int j=l[i];j<=m;j++)
			for (int k=0;k<=n>>j-l[i];k++)
				f[j+1][k/2]=max(f[j+1][k/2],f[j][k]+k/2*c[j+1]);
	}
	printf("%d",f[m][0]);
	return 0;
}