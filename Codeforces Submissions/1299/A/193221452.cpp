#include <bits/stdc++.h>


using namespace std;
#define pb push_back
//typedef __int128 lll;
#define ll long long
#define all(x) x.begin(),x.end()
#define repp(n) for(int i=0;i<n;i++)
const ll MOD=998244353;
const ll mod = 1e9 +7;



map<ll,ll> mp;

void f(ll x){

   
  ll bit = 0;
    while(x>0){

      if(x&1){
        mp[bit]++;
      }

      x>>=1;
      bit++;
    }
}
void solve(){

  ll n;
  cin>>n;

  ll a[n];
  repp(n)cin>>a[i];


  repp(n){

    f(a[i]);
  }


  ll ans = 0;
  ll id= 0;
  for(int i=0;i<n;i++){

    ll temp = a[i];
    ll cnt = 0;
    map<ll,ll> ok;
    ok = mp;

    ll bit = 0;
    while(temp>0){

        if(temp&1)ok[bit]--;
        
        if(temp&1 && ok[bit]==0){
          cnt+= pow(2,bit);
        }
        temp>>=1;
        bit++;
    }

    if(cnt>ans){
      ans= cnt;
      id = i;
    }
    

  }

  swap(a[id],a[0]);

  repp(n)cout<<a[i]<<" ";
 





}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);   

  
  // int t;
  // cin>>t;
  // while(t--)
    solve();

  return 0;

}