#include <bits/stdc++.h>
#define ll long long
#define N 502
using namespace std;
int n,m,q,i,j,bin[N],rmq[N][N][10][10],f[N][N][5],c[N][N];
int sum(int x1,int y1,int x2,int y2,int k)
{
    return f[x2][y2][k]-f[x1-1][y2][k]-f[x2][y1-1][k]+f[x1-1][y1-1][k];
}
bool check(int x,int y,int k)
{
    int tg=k*k;
    return sum(x-k+1,y-k+1,x,y,0)==tg
        && sum(x-k+1,y+1,x,y+k,1)==tg
        && sum(x+1,y-k+1,x+k,y,2)==tg
        && sum(x+1,y+1,x+k,y+k,3)==tg;
}
int get(int x1,int y1,int x2,int y2)
{
    int kx=bin[x2-x1+1],ky=bin[y2-y1+1];
    return max(max(rmq[x2][y2][kx][ky],rmq[x1+(1<<kx)-1][y1+(1<<ky)-1][kx][ky]),
               max(rmq[x2][y1+(1<<ky)-1][kx][ky],rmq[x1+(1<<kx)-1][y2][kx][ky]));
}
int main()
{
   // freopen("ntu.inp","r",stdin);
   // freopen("ntu.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            char ch; cin>>ch;
            for(int ok=0;ok<4;ok++)
                f[i][j][ok]=f[i-1][j][ok]+f[i][j-1][ok]-f[i-1][j-1][ok];
            f[i][j][0]+=(ch=='R');
            f[i][j][1]+=(ch=='G');
            f[i][j][2]+=(ch=='Y');
            f[i][j][3]+=(ch=='B');
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            int l=0,r=min(min(i,j),min(n-i,m-j));
            while(l<r)
            {
                int mid=(l+r+1)>>1;
                if(check(i,j,mid)) l=mid; else r=mid-1;
            }
            c[i][j]=l;
        }
    for(i=1;i<=max(n,m);i++) bin[i]=trunc(log2(i));
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            for(int ki=0;ki<=bin[i];ki++)
                for(int kj=0;kj<=bin[j];kj++)
                {
                    if(ki==0 && kj==0) rmq[i][j][ki][kj]=c[i][j];
                    else if(ki==0)
                        rmq[i][j][ki][kj]=max(rmq[i][j][ki][kj-1],rmq[i][j-(1<<(kj-1))][ki][kj-1]);
                    else
                        rmq[i][j][ki][kj]=max(rmq[i][j][ki-1][kj],rmq[i-(1<<(ki-1))][j][ki-1][kj]);
                }
    while(q--)
    {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        int l=0,r=min(x2-x1+1,y2-y1+1)/2;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(get(x1+mid-1,y1+mid-1,x2-mid,y2-mid)>=mid) l=mid; else r=mid-1;
        }
        cout<<4*l*l<<'\n';
    }
}
