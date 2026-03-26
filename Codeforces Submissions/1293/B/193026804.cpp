#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
   ll n;
   cin>>n;
   double ans=1;
   for(ll i=n;i>=2;i--){
    ans+=(double)(1/(double)i);
    // cout<<double(1/(double)i)<<endl;
   }
   cout<<fixed<<setprecision(12)<<ans<<endl;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)
    {
      
      solve();
    }
    

return 0;

}
