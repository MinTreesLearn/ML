// LUOGU_RID: 92669665
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,x,y) for (int i=(x);i<=(y);++i)
#define D(i,x,y) for (int i=(x);i>=(y);--i)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define Time (double)clock()/CLOCKS_PER_SEC
static char buf[100000],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++
inline void read(int &x) {
	x=0; int w=0; static char c=getchar();
	for (;!isdigit(c);c=getchar()) w^=!(c^45);
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x=w?-x:x;
}
const int N=3010;
int n,f[N][N],siz[N][N],dp[N][N],root,ans;
vector<int> G[N];
inline void dfs(int x,int fa) {
	f[root][x]=fa; siz[root][x]=1;
	for (auto y:G[x]) {
		if (y==fa) continue;
		dfs(y,x);
		siz[root][x]+=siz[root][y];
	}
}
inline int getdp(int x,int y) {
	if (x==y) return 0;
	if (dp[x][y]) return dp[x][y];
	return dp[x][y]=max(getdp(x,f[x][y]),getdp(f[y][x],y))+siz[x][y]*siz[y][x];
}
signed main() {
// 	freopen("tree.in","r",stdin),freopen("tree.out","w",stdout);
	read(n);
	F(i,1,n-1) {
		int x,y; read(x),read(y);
		G[x].push_back(y),G[y].push_back(x);
	}
	F(i,1,n) root=i,dfs(i,i);
	F(i,1,n) F(j,1,n) ans=max(ans,getdp(i,j));
	printf("%lld\n",ans);
	return 0;
}