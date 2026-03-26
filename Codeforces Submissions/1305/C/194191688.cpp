 //ANY TIME YOU SEE OPTIMIZATION PROBLEM -> BINARY SEARCH THE ANSWER!!!

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define No cout<<"No"<<endl; 
#define NO cout<<"NO"<<endl;  
#define Yes cout<<"Yes"<<endl; 
#define YES cout<<"YES"<<endl; 
#define MOD 1000000007
#define endl '\n'
 

void solve()
{   
  //PIGEON - HOLE PRINCIPLE
  ll n, i, j, a[200005], pro = 1, m;
  cin>>n>>m;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }

  if(n<=m)
  {
    for(i=0;i<n-1;i++)
    {
      for(j=i+1;j<n;j++)
      {
        ll p = abs(a[i] - a[j]);
        pro = (pro * (p%m))%m;
      }
    }

    cout<<pro<<endl;
  }
  else
  {
    cout<<0<<endl;
  }

}

   


 
 int main()
 {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int t; cin>>t;
    //while(t--)
    solve();
  }