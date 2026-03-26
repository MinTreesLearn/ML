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
	ll n,m;cin>>n>>m;
	ll tot=0;
	priority_queue<ll>q;
	FOR(i,1,m){
		ll x;cin>>x;
		tot+=x;q.push(x);
	}
	if(tot<n){cout<<-1<<endl;return ;}
	ll res=0;
	while(n){
		ll x=q.top();q.pop();
		if(x<=n)n-=x,tot-=x;
		else if(tot-x<n){
			res++;
			q.push(x/2);q.push(x/2);
		}else tot-=x;
	}
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