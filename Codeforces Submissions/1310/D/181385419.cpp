// LUOGU_RID: 94439220
/*****************************************
Note  :
******************************************/
#include <queue>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string.h>
#include <algorithm>
#include <time.h>
#define LL long long
#define IL inline
const int N = 1e6+10;
const LL INF = 1e18;
using namespace std;
IL int read()
{
    char ch = getchar();
    int f = 1, num = 0;
    while(ch>'9'||ch<'0')
    {
        if(ch=='-') f = -1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
        num = num*10+ch-'0', ch = getchar();
    return num*f;
}
LL dp[20][100],dis[100][100],ans=INF;
int col[100];
int n,k,t=5000;
int main()
{
    srand((unsigned)time(NULL));
	n=read(),k=read();
	for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            dis[i][j]=read();
    while(t--)
    {
        for(int i = 1;i<=n;i++)
        {
            col[i]=rand()&1;
            dp[0][i]=INF;
        }
        dp[0][1]=0;
        for(int i = 0 ;i<k;i++)
        {
            for(int j = 1;j<=n;j++)
                dp[i+1][j]=INF;
            for(int j = 1;j<=n;j++)
                for(int u = 1;u<=n;u++)
                    if(col[j]!=col[u])
                        dp[i+1][u]=min(dp[i+1][u],dp[i][j]+dis[j][u]);
        }
        ans=min(ans,dp[k][1]);
    }
    printf("%lld\n",ans);
}
