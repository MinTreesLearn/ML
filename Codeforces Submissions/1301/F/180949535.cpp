// LUOGU_RID: 94013092
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;
const int N=1005,dir[4][2]={-1,0,1,0,0,-1,0,1};
int n,m,k,a[N][N],dis[45][N][N],x1,x2,y1,y2,ans,q,vis[45];
vector<pair<int,int> >col[45];
template<typename T>inline void readmain(T &n){T sum=0,x=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-')x=-1;ch=getchar();}while (ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}n=sum*x;}
template<typename T>inline T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>inline void read(T &x,Tr&... r){readmain(x);read(r...);}
template<typename T>inline void write(T x){if (x<0){putchar('-');x=-x;}if (x>9)write(x/10);putchar(x%10+'0');return;}
template<typename T>inline void writesc(T x){write(x);putchar(' ');}
template<typename T>inline void writeln(T x){write(x);putchar('\n');}
inline void bfs(int c)
{
	F(i,1,k)vis[i]=0;
	queue<pair<int,int> >q;
	for (auto [i,j]:col[c])q.push({i,j}),dis[c][i][j]=0;
	vis[c]=1;while (q.size())
	{
		int h=q.front().first;
		int l=q.front().second;
		int x=dis[c][h][l],cc=a[h][l];
		q.pop();if (!vis[cc])
		{
			vis[cc]=1;
			for (auto [i,j]:col[cc])if (dis[c][i][j]<0)
			{
				dis[c][i][j]=x+1;
				q.push({i,j});
			}
		}
		F(i,0,3)
		{
			int nh=h+dir[i][0];
			int nl=l+dir[i][1];
			if (nh&&nh<=n&&nl&&nl<=m&&dis[c][nh][nl]<0)
			{
				dis[c][nh][nl]=x+1;
				q.push({nh,nl});
			}
		}
	}
}
int main()
{
	read(n,m,k);
	F(c,1,k)F(i,1,n)F(j,1,m)dis[c][i][j]=-1;
	F(i,1,n)F(j,1,m)read(a[i][j]),col[a[i][j]].push_back({i,j});
	F(i,1,k)bfs(i);
	/*F(c,1,k)
	{
		F(i,1,n)
		{
			F(j,1,m)writesc(dis[c][i][j]);
			puts("");
		}
		puts("");
	}*/
	read(q);while (q--)
	{
		read(x1,y1,x2,y2);ans=abs(x1-x2)+abs(y1-y2);
		F(i,1,k)ans=min(ans,dis[i][x1][y1]+dis[i][x2][y2]+1);
		writeln(ans);
	}
	return 0;
}
