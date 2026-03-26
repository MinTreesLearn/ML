/*
 * 
 * 	\OoO/
 * 
 */
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <climits>
#include <cstdlib>
#include <chrono>
// #include <ext/pd_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// #define ordered_set tree<ll, null_tyoe, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define iamtefu ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define ld long double
#define fl(i,a,n) for (ll i(a); i<n; i++)
#define rfl(i,a,n) for (ll i(n-1); i>=a; i--)
#define print(a) for (auto x:a){cout<<x<<" ";} cout<<"\n";
#define tt int tt; cin>>tt; for(;tt--;)
template <typename T1, typename T2>
decltype(auto) max(T1 a, T2 b){return (a>b?a:b);}
template <typename T1, typename T2>
decltype(auto) min(T1 a, T2 b){return (a<b?a:b);}
ll gcd(ll a, ll b){
	if (b==0){
		return a;
	}
	return gcd(b, a%b);
}
ll pw(ll a, ll b, ll m){
	ll res=1;
	a%=m;
	while (b){
		if (b&1){
			res=(res*a)%m;
		}
		a=(a*a)%m;
		b>>=1;
	}
	return res;
}
void scn(){
	ll x0, y0, ax, ay, bx, by; cin>>x0>>y0>>ax>>ay>>bx>>by;
	vector <vector <ll>> huh={{x0, y0}};
	while ((ld)(ax-1)*1.0*huh.back()[0]+bx+(ld)(ay-1)*1.0*huh.back()[1]+by<=1e17){
		huh.push_back({ax*huh.back()[0]+bx, ay*huh.back()[1]+by});
		//print(huh.back());
	}
	ll xs, ys, t; cin>>xs>>ys>>t;
	//cerr<<"huh\n";
	ll ans=0;
	fl(i,0,huh.size()){
		ll co=(abs(xs-huh[i][0])+abs(ys-huh[i][1]));
		if (co>t){
			continue;
		}
		ll dj=1;
		fl(j,i+1,huh.size()){
			if (co>t)break;
			else{
				co+=(abs(huh[j-1][0]-huh[j][0])+abs(huh[j-1][1]-huh[j][1]));
				if (co>t)break;
				dj++;
			}
		}
		ll co1=(abs(xs-huh[i][0])+abs(ys-huh[i][1]));
		ll dj1=1;
		rfl(j,1,i+1){
			if (co1>t)break;
			else{
				co1+=(abs(huh[j-1][0]-huh[j][0])+abs(huh[j-1][1]-huh[j][1]));
				if (co1>t)break;
				dj1++;
			}
		}
		dj=max(dj, dj1);
		ans=max(dj, ans);
		/*if (dj==ans){
			cout<<i<<"\n";
		}*/
	}
	cout<<ans<<"\n";
}
int main(){
	iamtefu;
	#if defined(airths)
		auto t1=chrono::high_resolution_clock::now();
		freopen("in", "r", stdin);
		//freopen("out", "w", stdout);
	#endif
	//tt
	{
		scn();
	}
	#if defined(airths)
		auto t2=chrono::high_resolution_clock::now();
		ld ti=chrono::duration_cast<chrono::nanoseconds>(t2-t1).count();
		ti*=1e-6;
		cerr<<"Time: "<<setprecision(12)<<ti;
		cerr<<"ms\n";
	#endif
	return 0;
}