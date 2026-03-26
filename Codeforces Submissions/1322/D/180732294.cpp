// LUOGU_RID: 93923800
#include<stdio.h>
#include<bits/stdc++.h>
#define fir first
#define sec second
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 int128;
typedef __uint128_t uint128;
typedef pair<int,int> pii;
template<typename type>
inline void chmin(type &x,const type &y)
{
	if(y<x)
		x=y;
}
template<typename type>
inline void chmax(type &x,const type &y)
{
	if(x<y)
		x=y;
}
constexpr int Max=2100;
constexpr ll inf=1e18;
int a[Max],b[Max],c[Max*2],n,m;
vector<int>d[Max];
ll f[Max*2][Max];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m,m+=n;
	for(int i=1;i<=n;++i)
		cin>>b[i];
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=m;++i)
		cin>>c[i];
	memset(f,0xcf,sizeof(f));
	for(int i=0;i<=m;++i)
		f[i][0]=0;
	for(int i=n,x;i;--i)
	{
		x=b[i];
		for(int j=n;j;--j)
			chmax(f[x][j],f[x][j-1]-a[i]+c[x]);
		for(int j=x+1;j<=m;++j)
			for(int k=0;k<=((j-x)<=30?n>>(j-x):0);++k)
				chmax(f[j][k],max(f[j-1][k*2],f[j-1][k*2+1])+k*c[j]);
	}
	cout<<f[m][0]<<"\n";
	return 0;
}