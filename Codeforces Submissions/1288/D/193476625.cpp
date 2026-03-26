#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define mod 1000000007

int a[300000+10][10];
int b[1010],n,m;
int ans1,ans2;
bool check(int mid)
{
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
    {
        int now=0;
        for(int j=1;j<=m;j++)
        {
            int fuck=j-1;
            if(a[i][j]>=mid)
            {
                now|=(1<<fuck);
            }
        }
        b[now]=i;
    }
    for(int i=0;i<(1<<m);i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            if(b[i]&&b[j])
            {
                if((i|j)==(1<<m)-1)
                {
                    ans1=b[i];
                    ans2=b[j];
                    return 1;
                }
            }
        }
    }

    return 0;
}
int main()
{
    //二分枚举当前最小值
    //把小于最小值的设置0，否则是1，那么只需要检查当前位置之前是否具有一个二进制数字
    //取或之后全是1，
    //把小于最小值的设为1，否则是0，那么只需要检查当前位置之前，是否有一个数字和他
    //取并之后是0，暴力即可
   cin>>n>>m;

   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           cin>>a[i][j];
       }
   }
   int l=0,r=1e9;

   while(l<=r)
   {
       int mid=(l+r)>>1;

       if(check(mid))
       {
           l=mid+1;
       }
       else
       {
           r=mid-1;
       }
   }
   //cout<<l<<" "<<r<<endl;

   cout<<ans1<<" "<<ans2<<endl;

    return 0;
}


