#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define mod 998244353
ll a[1000],b[1000],c[1000];
ll dp[1010][1010],g[1010],inv[1010];
ll qp(ll base, ll pow)
{
    ll ans=1;
    while(pow)
    {
        if(pow&1)
            ans=ans*base%mod;
        pow>>=1;
        base=base*base%mod;
    }

    return ans;
}
int main()
{

   for(int i=1;i<=1000;i++)
   {
       inv[i]=qp((ll)i,mod-2);

   }
   int n;
   cin>>n;

   for(int i=1;i<=n;i++)
   {
       cin>>a[i]>>b[i];
       b[i]++;
   }
   int len=0;
   for(int i=1;i<=n;i++)
   {
       len++;
       c[len]=a[i];
       len++;
       c[len]=b[i];
   }

   sort(c+1,c+1+len);

   len=unique(c+1,c+1+len)-c-1;

   for(int i=1;i<=n;i++)
   {
       a[i]=lower_bound(c+1,c+1+len,a[i])-c;
       b[i]=lower_bound(c+1,c+1+len,b[i])-c;

   }

   for(int i=0;i<=1000;i++)
   {
       dp[0][i]=1;
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=a[i];j<b[i];j++)
       {
          ll len1=c[j+1]-c[j];
           //当前数字个数

           g[1]=len1;

           for(int k=2;k<=i;k++)
           {
               g[k]=g[k-1]*(ll)(len1+k-1)%mod*inv[k]%mod;
           }

           for(int k=i-1;k>=0;k--)
           {

               if(!(j>=a[k+1]&&j+1<=b[k+1]))
                break;

               dp[i][j]=(dp[i][j]+dp[k][j+1]*g[i-k]%mod)%mod;

           }
       }
       for(int j=len;j>=1;j--)
       {
           dp[i][j]=(dp[i][j]+dp[i][j+1])%mod;
       }
   }

   ll ans=dp[n][1];

   //cout<<ans<<endl;
   for(int i=1;i<=n;i++)
   {
       ans=(ans*qp(c[b[i]]-c[a[i]],mod-2)%mod)%mod;
   }

   cout<<ans;
    return 0;
}


