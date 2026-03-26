#include <bits/stdc++.h>
#define IOS   ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define xs(a) cout<<setiosflags(ios::fixed)<<setprecision(a);
#define lbit(a) (__builtin_ffsll(a))
#define ubit(a) (64-__builtin_clzll(a))
#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define mem(a,b) memset(a,b,sizeof(a));
using namespace std;
#define ull unsigned long long
#define ll long long
#define endl '\n'
typedef pair<ll,ll> pll;
const int N=1e6+5;
const int mod=1e9+7;
/*-----------------------------------------------------------------------------------------------*/


void solve(){
    ll n,a,b;cin>>n>>a>>b;
    ll sum=(n+1)/2;
    ll x=sum/a,res;
    if(sum%a==0){
        res=(x-1)*(a+b)+a;
    }else res=x*(a+b)+sum%a;
    if(res<n)res=n;
    cout<<res<<endl;

}

signed main(){IOS
    ll T;T=1;
    cin>>T;
    while(T--){
        solve();
    }


    return 0;
}