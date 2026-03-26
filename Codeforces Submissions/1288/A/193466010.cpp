#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define mod 998244353

int main()
{

  int t;
  cin>>t;
  while(t--)
  {
      ll n,d;
      cin>>n>>d;

      if((n-1)*(n-1)+4ll*(n-d)>=0)
      {
          cout<<"YES"<<endl;
      }
      else
      {
          cout<<"NO"<<endl;
      }
  }
    return 0;
}


