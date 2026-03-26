#include <bits/stdc++.h>
using namespace std;
#include <ext/rope>
using namespace __gnu_cxx;

// #pragma comment(linker, "/stack:2000000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")


typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

#define precise(a) cout<<fixed<<setprecision(a)
#define sz size()
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
// t1
const ll mod = ll(1e9)+7; //(b + (a%b)) % b (to mod -1%(10^9+7) correctly in c++ its -1 but its suppose to be 10^9+6
const ll MOD = 998244353;  // (a%mod)*(binpow(b,mod-2,mod) = (a/b)%mod
const ll N = ll(3e5)+10;
const ll K = 17;
const ll inf = 1e18;
const ld eps = 1e-15L;
//const ll B = 316;
ll lcm(ll a, ll b){ return (a / __gcd(a,b)) * b; }
//const ld P = acos(-1.0);

// ll binpow(ll a, ll b, ll m){ ll res=1;a%=m; while(b>0){ if(b&1)res=(res*a)%m; a=(a*a)%m; b/=2; } return res%m;}
ld binpow(ld a, ll b){ ld res=1; while(b>0){ if(b&1)res=(res*a); a=(a*a); b/=2; } return res;}


void Freopen(string Key){ freopen((Key+".in").c_str(), "r", stdin); freopen((Key+".out").c_str(), "w", stdout); }


void precalc() {
}

ll fact[N];

void Baizho()
{   
	ll n, m; cin>>n>>m;
	fact[0] = 1;
	for(ll i=1; i<N; i++) fact[i] = (fact[i-1]*i)%m;
	ll ans = 0;
	for(ll len = 1; len<=n; len++) {
		ans = (((fact[len]*fact[n-len+1])%m)*(n-len+1)+ans)%m;
	}
	cout<<ans;
	

}

    
int main() {

    // Freopen("div7");
    ios_base::sync_with_stdio(false);   
    cin.tie(0);cout.tie(0); 

    precalc();

    int ttt = 1;
    // cin>>ttt;

    for(int i=1; i<=ttt; i++) { Baizho();}
}