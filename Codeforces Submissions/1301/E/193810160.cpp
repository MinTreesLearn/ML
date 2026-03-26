// LUOGU_RID: 102254356
#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int INF=505;
int n,m,q;
char a[INF][INF];
mt19937 rnd(chrono::system_clock().now().time_since_epoch().count());
int gen(int l,int r) {return rnd()%(r-l+1);}
int vis[INF],p[INF],b[INF][INF],ans[INF][INF];
int f[INF][INF][13][13];
int Get(int x,int y,int xx,int yy) {
//	cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<" qweijqwej\n";
	return b[xx][yy]-b[x][yy]-b[xx][y]+b[x][y];
}
int solve2(int l,int r,int ll,int rr) {
	if (ll-l+1<2) return 0;
	if (rr-r+1<2) return 0;
	if (l<1 || r<1 || ll>n || rr>m) return 0;
	for (int i=0;i<=5;i++) vis[i]=0;
	int Mid1=(l+ll)>>1,Mid2=(r+rr)>>1;
	int kk=Get(l-1,r-1,Mid1,Mid2);
	for (int i=0;i<=0;i++)
		if (kk%p[i]==0) {vis[i]++;break;}
	kk=Get(Mid1,r-1,ll,Mid2);
	for (int i=2;i<=2;i++)
		if (kk%p[i]==0) {vis[i]++;break;}
	kk=Get(Mid1,Mid2,ll,rr);
	for (int i=3;i<=3;i++)
		if (kk%p[i]==0) {vis[i]++;break;}
	kk=Get(l-1,Mid2,Mid1,rr);
	for (int i=1;i<=1;i++)
		if (kk%p[i]==0) {vis[i]++;break;}
	for (int i=0;i<4;i++)
		if (vis[i]!=1) return 0;
	return 1;
}

int query(int l,int r,int ll,int rr) {
	if (l>ll || r>rr) return -1e9;
	int xx=__lg(ll-l+1),yy=__lg(rr-r+1);
	return max({f[l][r][xx][yy],f[ll-(1ll<<xx)+1][r][xx][yy],
			f[l][rr-(1ll<<yy)+1][xx][yy],f[ll-(1ll<<xx)+1][rr-(1ll<<yy)+1][xx][yy]});
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for (int i=0;i<4;i++) p[i]=rnd();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) {
			cin>>a[i][j];
			if (a[i][j]=='R') b[i][j]=p[0];
			else if (a[i][j]=='G') b[i][j]=p[1];
			else if (a[i][j]=='Y') b[i][j]=p[2];
			else b[i][j]=p[3];
		}
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=m;j++)
			b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
	
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			int l=1,r=min(n,m),ans2=0;
			while (l<=r) {
				int Mid=(l+r)>>1;
				if (solve2(i-Mid+1,j-Mid+1,i+Mid,j+Mid)) l=(ans2=Mid)+1;
				else r=Mid-1;
			}
			ans[i][j]=ans2;
			f[i][j][0][0]=ans2;
		}
	}
	
	for (int i=1;i<21;i++) {
		if ((1ll<<i)>n) break;
		for (int j=1;j+(1ll<<i)-1<=n;j++) 
			for (int k=1;k<=m;k++)
				f[j][k][i][0]=max(f[j][k][i-1][0],f[j+(1ll<<(i-1))][k][i-1][0]);
	}
	
	for (int i=1;i<21;i++) {
		if ((1ll<<i)>m) break;
		for (int j=1;j<=n;j++)
			for (int k=1;k+(1ll<<i)-1<=m;k++)
				f[j][k][0][i]=max(f[j][k][0][i-1],f[j][k+(1<<(i-1))][0][i-1]);
	}
	
	for (int i=1;i<21;i++) {
		if ((1ll<<i)>n) break;
		for (int p=1;p<21;p++) {
			if ((1ll<<p)>m) break;
			for (int j=1;j+(1ll<<i)-1<=n;j++) {
				for (int k=1;k+(1ll<<p)-1<=m;k++) {
					f[j][k][i][p]=max({f[j][k][i-1][p-1],f[j+(1ll<<(i-1))][k][i-1][p-1],
									f[j][k+(1ll<<(p-1))][i-1][p-1],f[j+(1ll<<(i-1))][k+(1ll<<(p-1))][i-1][p-1]});
				}
			}
		}
	}
	for (int i=1;i<=q;i++) { //123123
		int x=0,y=0,xx=0,yy=0;
		cin>>x>>y>>xx>>yy;
		int l=1,r=min(yy-y+1,xx-x+1),ans2=-1;
		while (l<=r) {
			int Mid=(l+r)>>1;
			if (query(x+Mid-1,y+Mid-1,xx-Mid,yy-Mid)>=Mid) l=(ans2=Mid)+1;
			else r=Mid-1;
		}
		
		if (ans2==-1) cout<<"0\n";
		else cout<<ans2*ans2*4<<"\n";
	}
	return 0;
}