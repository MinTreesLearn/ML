#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
const int N = 1100;
int a[N],s[N];
int f[N][N],g[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i][i]=a[i];
    }
    
    for(int len=2;len<=n;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            for(int k=1;k<r;k++)
            {
                if(f[l][k]==f[k+1][r] && f[l][k]) f[l][r]=f[k+1][r]+1;
            }
        }
    }
    memset(g,0x3f,sizeof g);
    g[0]=0;
    for(int i=1;i<=n;i++)
    for(int j=0;j<i;j++)
    if(f[j+1][i]) g[i]=min(g[i],g[j]+1);
    cout<<g[n];
}