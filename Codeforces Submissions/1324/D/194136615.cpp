/*     Code by Poojan Patel (poojanpatel2712)    */
#include<bits/stdc++.h>
using namespace std;
#define ll             long long 
#define pb             push_back
#define tt             ll testcase; cin>>testcase; while(testcase--)
#define ic(n)          ll n; cin>>n
#define arr(a,n)       ll a[n]; for(ll i=0; i<n; i++) cin>>a[i]
#define is(s)          string s; cin>>s
#define floi(xi,xn,xs) for(ll i=xi; i<xn; i+=xs)
#define vll            vector<ll>
#define vpll           vector<pair<ll,ll>>
#define iv(vi,n)       vll vi(n); for(ll i=0; i<n; i++) cin>>vi[i]
#define all(vi)        (vi).begin(),(vi).end()
#define pv(vi)         for(auto x : vi) cout<<x<<' '; cout<<endl;
#define pm(mp)         for(auto x:mp) cout<<mp.first<<' '<<mp.second<<endl;
#define pa(a,n)        for(ll i=0; i<n; i++){cout<<a[i]<<' ';} cout<<endl;
#define mll            map<ll,ll>
#define ff             first
#define ss             second
#define setbit(x)      __builtin_popcountll(x)
#define ctzll(x)       __builtin_ctzll(x)
#define clzll(x)       __builtin_clzll(x)

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

const ll N=1e9+7;
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a,ll b){return (a*1ll*b)/__gcd(a,b);}
ll power(ll a,ll b){ll ans=1;while(b){if(b&1) ans=(ans*a)%N; b>>=1;a=(a*a)%N;}return ans;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void solve(){
      ic(n);
      iv(a,n);
      iv(b,n);

      vll ai(n);
      for(ll i=0; i<n; i++){
        ai[i]=a[i]-b[i];
        
      }
      sort(all(ai));
      ll ans=0;
      for(ll i=0; i<n; i++){
        if(ai[i]<=0) continue;
       ll lower=lower_bound(all(ai),-1*ai[i]+1)-ai.begin();
       ans+=i-lower;
      }
      cout<<ans<<endl;
      
}

int main ()

{
     ios_base::sync_with_stdio(false); // for fast inputs and outputs....
     cin.tie(NULL);   // this flushes cout....
  // tt{
     solve();
  // }

  // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
return 0;
}
