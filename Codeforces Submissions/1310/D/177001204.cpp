// LUOGU_RID: 90587440
#include<bits/stdc++.h>
using namespace std;

const int N=90,K=20,INF=1e9+10;
int n,k,ans=INF,rand_cnt;
int g[N][N];
int col[N],f[K][N];

inline void get_rand()
{
    for(int i=1;i<=n;i++) col[i]=rand()%2;
    return ;
}

int solve()
{
    memset(f,0x3f,sizeof f);
    f[0][1]=0;
    for(int i=0;i<=k-1;i++)
        for(int u=1;u<=n;u++)
            for(int v=1;v<=n;v++)
                if(col[u]!=col[v])
                    f[i+1][v]=min(f[i+1][v],f[i][u]+g[u][v]);
    return f[k][1];
}

int main()
{
    srand(time(NULL));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&g[i][j]);
    for(int i=1;i<=4000;i++)
    {
        get_rand();
        ans=min(ans,solve());
    }
    printf("%d\n",ans);
    return 0;
}