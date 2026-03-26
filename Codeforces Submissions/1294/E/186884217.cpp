#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int *a[maxn],c[maxn];
int main(){
	int n,m,ans=0;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		a[i]=new int[m];
		for(int j=0;j<m;j++)scanf("%d",a[i]+j),a[i][j]--;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[j][i]%m!=i||a[j][i]<0||a[j][i]>=n*m)continue;
			c[(-a[j][i]/m+n+j)%n]++;
		}
		int w=n;
		for(int j=0;j<n;j++)w=min(n-c[j]+j,w),c[j]=0;
		ans+=w;
	}
	printf("%d",ans);
	return 0;
}