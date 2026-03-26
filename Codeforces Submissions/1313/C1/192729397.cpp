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
  ll n, m, i, j, a[1005], b[300005], fin =0, fink;
  ll ans[1005][1005];
  cin>>n;
  for(i=1;i<=n;i++)
  {
    cin>>a[i];
    ans[i][0] = 1e18;
  }

  for(i=1;i<=n;i++)
  { 

    ll s =0; 
    ans[i][i] = a[i];
    //cout<<i<<" "<<ans[i][i]<<endl;
    s+=a[i];
    for(j=i+1;j<=n;j++)
    {
      ans[i][j] = min(ans[i][j-1], a[j]);
      s+=ans[i][j];
    }
    for(j=i-1;j>=1;j--)
    {
      ans[i][j] = min(ans[i][j+1], a[j]);
      s+=ans[i][j];
    }

    if(s>fin)
    {
      fin = s;
      fink = i;
    }
  }

  //cout<<fink<<endl;
  for(i=1;i<=n;i++)
  {
    cout<<ans[fink][i]<<" ";
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