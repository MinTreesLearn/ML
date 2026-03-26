 //ANY TIME YOU SEE OPTIMIZATION PROBLEM -> BINARY SEARCH THE ANSWER!!!

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define No cout<<"No"<<endl; 
#define NO cout<<"NO"<<endl;  
#define Yes cout<<"Yes"<<endl; 
#define YES cout<<"YES"<<endl; 
#define MOD 1000000007



void solve()
{ 
  ll n, i, j, a[200005], m, l, k, r, fans=0, p, x, y, ans=1e10;
  int nbElem, pos, nbControl;
      cin >> nbElem >> pos >> nbControl;

      int before = pos-1, behind = nbElem-pos;
      nbControl = min(nbControl, before);

  for(i=1;i<=nbElem;i++)
  {
    cin>>a[i];
  }

  for(i=0;i<=nbControl;i++)
  { 
    ll ans = 1e10;
    for(j=0;j<=before - nbControl;j++)
    { 
      ans = min(ans, max(a[i+j+1], a[i+j+behind+1]));
     // cout<<ans<<endl;
    }

    fans = max(ans, fans);
  }
 
  


  cout<<fans<<endl;





}

  
 
  
 

  
 







  

  

 

 
 
 int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
    solve();
    
  }
 
//Iterate through maps:
/*for(auto it: m)
{
  ll x=it.first;
  ll y=it.second;
}*/
 
// lower_bound() --> first element greater than or equal to...
// upper_bound() --> first element strictly greater than...
// UT for BS...s// UT for BS...s// UT for BS...s// UT for BS...s// UT for BS...s// UT for BS...s// UT for BS...s// UT for BS...s // UT for BS...s// UT for BS...s// UT for BS...s// UT for BS...s// UT for BS...s// UT for BS...s// UT for BS...s// UT for BS...s // Source: https://usaco.guide/general/io
