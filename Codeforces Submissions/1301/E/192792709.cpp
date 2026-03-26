#include <bits/stdc++.h>
using namespace std;

char ch[510][510];
int n,m,q,f[510][510],g[510][510][5],h[510][510][275];

int main()
{
scanf("%d%d%d",&n,&m,&q);
for (int i=1;i<=n;i++) scanf("%s",ch[i]+1);
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
{
for (int k=0;k<4;k++)
g[i][j][k]=g[i-1][j][k]+g[i][j-1][k]-g[i-1][j-1][k];
if(ch[i][j]=='R') g[i][j][0]++;
if(ch[i][j]=='G') g[i][j][1]++;
if(ch[i][j]=='B') g[i][j][2]++;
if(ch[i][j]=='Y') g[i][j][3]++;
}
for (int i=1;i<n;i++)
for (int j=1;j<m;j++)
if(ch[i][j]=='R'&&ch[i+1][j]=='Y'&&ch[i][j+1]=='G'&&ch[i+1][j+1]=='B')
{
f[i][j]=1;
for (int k=2;k<=min(n,m)/2;k++)
{
int x=i-k+1,y=j-k+1;
int a=i,b=j;
if(x<1||y<1) break;
if(g[a][b][0]-g[a][y-1][0]-g[x-1][b][0]+g[x-1][y-1][0]!=k*k) break;
x=i-k+1,y=j+1;
a=i,b=j+k;
if(x<1||y<1||a>n||b>m) break;
if(g[a][b][1]-g[a][y-1][1]-g[x-1][b][1]+g[x-1][y-1][1]!=k*k) break;
x=i+1,y=j+1;
a=i+k,b=j+k;
if(x<1||y<1||a>n||b>m) break;
if(g[a][b][2]-g[a][y-1][2]-g[x-1][b][2]+g[x-1][y-1][2]!=k*k) break;
x=i+1,y=j-k+1;
a=i+k,b=j;
if(x<1||y<1||a>n||b>m) break;
if(g[a][b][3]-g[a][y-1][3]-g[x-1][b][3]+g[x-1][y-1][3]!=k*k) break;
f[i-k+1][j-k+1]=k;
}
}
for (int i=1;i<n;i++)
for (int j=1;j<m;j++)
if (f[i][j]) h[i][j][f[i][j]]=1;
for (int i=1;i<=n;i++)
for (int j=1;j<=m;j++)
for (int k=1;k<=min(n,m)/2;k++)
h[i][j][k]+=h[i-1][j][k]+h[i][j-1][k]-h[i-1][j-1][k];
while (q--)
{
int x,y,xx,yy;
scanf("%d%d%d%d",&x,&y,&xx,&yy);
int mx=min(xx-x+1,yy-y+1)/2;
bool bo=0;
for (int k=mx;k>=1;k--)
{
int sx=xx-2*k+1;
int sy=yy-2*k+1;
if (h[sx][sy][k]-h[sx][y-1][k]-h[x-1][sy][k]+h[x-1][y-1][k])
{
printf("%d\n",k*k*4);
bo=1;
break;
}
}
if (bo) continue;
puts("0");
}
return 0;
}
