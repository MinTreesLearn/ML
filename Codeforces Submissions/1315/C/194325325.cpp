#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll ans[100000];
ll depth=0;


int main()
{
  ll t; cin>>t;
  while(t--)
  {
    ll n; cin>>n;
    ll arr[n];
set<ll>s;
vector<ll>v(2*n+1);
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
  v[arr[i]]=1;
    }
    ll flag=0;
    ll kk=0;
    ll ans[2*n];
    ll x=-1;
//     for(int i=1;i<=2*n;i++)
// {
//   cout<<v[i]<<" ";
// }
// cout<<endl;


      for(int i=0;i<n;i++)
      {
        ++x;
        flag=0;
        ll val=arr[i];
        ans[x]=arr[i];
       
        for(int j=arr[i]+1;j<=2*n;j++)
        {
          if(v[j]==0)
          {  
            ++x;
ans[x]=j;
flag=-1;
v[j]=1;
break;
          }
        }
        
        if(flag==0)
        {
          cout<<-1<<endl;
          kk=-1;
          break;
        }
      }
      if(kk==0)
      {
        for(auto &it:ans)
{
  cout<<it<<" ";
}
 cout<<endl;
      }
     
  }}


   