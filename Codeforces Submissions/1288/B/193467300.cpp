#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
# define mod 998244353


int main()
{

/*
  for(int a=1;a<=100;a++)
  {
      for(int b=1;b<=1000;b++)
      {
          int now=a*b+a+b;
          int bb=b,cnt=1;
          while(bb)
          {
              cnt*=10;
              bb/=10;
          }
          ll c=a*cnt+b;
          //cout<<a<<" "<<b<<" "<<c<<endl;
          if(c==now)
          {
              cout<<a<<" "<<b<<endl;
          }
      }
  }
*/
int t;
cin>>t;
while(t--)
{
    ll a,b;
    cin>>a>>b;ll now=9ll;
    ll cnt=0;
    while(now<=b)
    {
        cnt++;
        now*=10ll;
        now+=9;
    }

    cout<<cnt*a<<endl;
}
    return 0;
}


