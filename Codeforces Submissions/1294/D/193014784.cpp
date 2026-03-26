#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define AQUA                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
const ll N = 2e5 + 5;
const ll mod = 998244353;

int main()
{
  AQUA
      ll tt = 1;
//   cin >> tt;

  while (tt--)
  {
  ll n,x;
  cin>>n>>x;
  
  ll mx=0;
  map<ll,ll> m;
  ll a;
  for(int i=0;i<n;i++){
    cin>>a;
    if(mx%x==a%x)mx++;
    else m[a%x]++;
    while(1){
    if(m[mx%x]>0)m[mx%x]--,mx++;
    else break;
    }
    cout<<mx<<endl;
    
    
  }
    
  }
}