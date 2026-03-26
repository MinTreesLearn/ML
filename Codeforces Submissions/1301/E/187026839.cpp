// LUOGU_RID: 98169232
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
int const N=5e2+10;
char s[N][N];int f[N][N],qz[N][N][255],g[N][N][5];
inline int search(int x,int y,int xx,int yy,int k){return qz[xx][yy][k]-qz[x-1][yy][k]-qz[xx][y-1][k]+qz[x-1][y-1][k];}
inline int Search(int x,int y,int xx,int yy,int k){return g[xx][yy][k]-g[x-1][yy][k]-g[xx][y-1][k]+g[x-1][y-1][k];}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,q;cin>>n>>m>>q;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){
			cin>>s[i][j];
			for (int k=0;k<4;++k) g[i][j][k]=g[i-1][j][k]+g[i][j-1][k]-g[i-1][j-1][k];
			if (s[i][j]=='R') ++g[i][j][0];
			if (s[i][j]=='G') ++g[i][j][1];
			if (s[i][j]=='B') ++g[i][j][2];
			if (s[i][j]=='Y') ++g[i][j][3];
		}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j){			
			if (s[i][j]=='R' && s[i+1][j]=='Y' && s[i][j+1]=='G' && s[i+1][j+1]=='B');else continue;
			f[i][j]=1;
			for (int k=2;k<=min(n,m)/2;++k){
				int x=i-k+1,y=j-k+1,xx=i,yy=j;
				if (x<1 || y<1 || xx>n || yy>m || y>m || x>n || xx<1 || yy<1) break;
				if (Search(x,y,xx,yy,0)!=k*k) break;
				x=i-k+1,y=j+1,xx=i,yy=j+k;
				if (x<1 || y<1 || xx>n || yy>m || y>m || x>n || xx<1 || yy<1) break;
				if (Search(x,y,xx,yy,1)!=k*k) break;
				x=i+1,y=j+1,xx=i+k,yy=j+k;
				if (x<1 || y<1 || xx>n || yy>m || y>m || x>n || xx<1 || yy<1) break;
				if (Search(x,y,xx,yy,2)!=k*k) break;
				x=i+1,y=j-k+1,xx=i+k,yy=j;
				if (x<1 || y<1 || xx>n || yy>m || y>m || x>n || xx<1 || yy<1) break;
				if (Search(x,y,xx,yy,3)!=k*k) break;
				f[i-k+1][j-k+1]=k;
			}
		}
	for (int i=1;i<n;++i) 
		for (int j=1;j<m;++j)
			if (f[i][j]) qz[i][j][f[i][j]]=1;
	for (int i=1;i<=n;++i) 
		for (int j=1;j<=m;++j)
			for (int k=1;k<=min(n,m)/2;++k) 
				qz[i][j][k]+=qz[i-1][j][k]+qz[i][j-1][k]-qz[i-1][j-1][k];
	while (q--){
		int x,y,xx,yy;cin>>x>>y>>xx>>yy;
		int k=min(xx-x+1,yy-y+1)/2;
		while (k && !search(x,y,xx-2*k+1,yy-2*k+1,k)) --k;
		cout<<4*k*k<<'\n';
	}
	return 0;
}