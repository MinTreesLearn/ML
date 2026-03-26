# include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main ()
{

     ll t;
     cin>>t;
     while(t--)
     {
         ll a,n;
         cin>>a>>n;
         n/=__gcd(a,n);
         ll ans=n;
         for(ll i=2;i*i<=n;i++)
         {
             if(n%i==0)
             {
                 while(n%i==0)
                 {
                     n/=i;
                 }
                 ans=ans/i*(i-1);
             }
         }
         if(n>1)
         {
             ans=ans/n*(n-1);
         }
         cout<<ans<<endl;
     }


    return 0;
}
