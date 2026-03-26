#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
using namespace std;
int const M=1010,inf=1e9,dx[]={-1,1,0,0},dy[]={0,0,-1,1};
vector<pair<int,int>>g[42];queue<pair<int,int>>q;bool vis[42];
int i,j,n,m,k,c,r1,c1,r2,c2,x,y,T,X,Y,Min,col[M][M],dis[42][M][M];
int read(){
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x;
}
int main(){
	n=read();m=read();k=read();
	memset(dis,63,sizeof(dis));
	for (i=1;i<=n;i++) for (j=1;j<=m;j++)
		g[col[i][j]=read()].pb(mk(i,j));
	for (T=1;T<=k;T++){ memset(vis,0,sizeof(vis));
		for (i=0;i<g[T].size();i++)	q.push(g[T][i]),
			dis[T][g[T][i].first][g[T][i].second]=0;
		while (!q.empty()){
			int x=q.front().first,y=q.front().second;
			q.pop();for (i=0;i<4;i++){
				X=x+dx[i];Y=y+dy[i];
				if (X&&Y&&X<=n&&Y<=m&&dis[T][X][Y]>inf)
					dis[T][X][Y]=dis[T][x][y]+1,q.push(mk(X,Y));
			} c=col[x][y];
			if (vis[c]) continue;vis[c]=1;
			for (i=0;i<g[c].size();i++) 
				if (dis[T][g[c][i].first][g[c][i].second]>inf)
					dis[T][g[c][i].first][g[c][i].second]=dis[T][x][y]+1,q.push(g[c][i]); 
		}
	}
	T=read();while (T--){
		r1=read();c1=read();r2=read();c2=read();Min=abs(r1-r2)+abs(c1-c2);
		for (i=1;i<=k;i++) Min=min(Min,dis[i][r1][c1]+dis[i][r2][c2]+1);
		printf("%d\n",Min);
	}
	return 0;
} 