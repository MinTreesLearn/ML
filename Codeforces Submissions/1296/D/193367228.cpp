#include <bits/stdc++.h>
using namespace std;
#define pb push_back
//typedef __int128 lll;
#define ll long long
#define all(x) x.begin(),x.end()
#define repp(n) for(int i=0;i<n;i++)
const ll MOD=998244353;
const ll mod = 1e9 +7;

void solve(){
  
    ll n,a,b,k;
    cin>>n>>a>>b>>k;

    vector<ll> h(n);

    repp(n)cin>>h[i];

    ll ans = 0;
    ll ok = a+b;

    vector<pair<ll,ll>> v;
    for(int i=0;i<n;i++){

        ll temp = h[i]%ok;

        if(temp==0 || temp>a){
            
            if(temp == 0){
                temp = b;
            }
            else{

                temp-=a;
            }
            
            ll t1 = 0;

            if(temp%a==0) t1 = temp/a;
            else t1 = temp/a +1;

            v.pb({t1,h[i]});
            
        }
        else
            ans++;

    }


    sort(all(v));

    repp(v.size()){
        
        if(v[i].first<=k){
            ans++;
            k-=v[i].first;
        }

        else
            break;

    }



    cout<<ans<<endl;



}
int main()
{
    // int t;
    // cin>>t;
    // while(t--)
    {
        solve();
    }
    return 0;
}