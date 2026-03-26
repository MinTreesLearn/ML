#pragma GCC target("fpmath=387")
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define ss se.se
#define fs fi.se
#define sf se.fi
#define all(x) x.begin(), x.end()
#define endl "\n"

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
vector<pll> v,tmp;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		ll x;cin>>x;
		v.pb({x,1LL});
	}
	while(true){
		tmp.clear();
		for(int j=0;j<v.size();j++){
			ll jum=v[j].fi;
			ll cnt=v[j].se;
			while(j+1<v.size()){
				ll jum_nw=jum+v[j+1].fi;
				ll cnt_nw=cnt+v[j+1].se;
				if(jum*cnt_nw>=jum_nw*cnt){
					jum=jum_nw;
					cnt=cnt_nw;
					j++;
				}
				else break;
			}
			
			tmp.pb({jum, cnt});
		}
		
		if(v==tmp)break;
		v=tmp;
		tmp.clear();
		for(int j=v.size()-1;j>=0;j--){
			ll jum=v[j].fi;
			ll cnt=v[j].se;
			while(j-1>=0){
				ll jum_nw=jum+v[j-1].fi;
				ll cnt_nw=cnt+v[j-1].se;
				if(jum*cnt_nw<=jum_nw*cnt){
					jum=jum_nw;
					cnt=cnt_nw;
					j--;
				}
				else break;
			}
			
			tmp.pb({jum, cnt});
		}
		reverse(tmp.begin(), tmp.end());
		if(v==tmp)break;
		v=tmp;
		tmp.clear();
	}
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].se;j++){
			cout<<fixed<<setprecision(10)<<((long double)v[i].fi/(long double)v[i].se)<<endl;
		}
	}
	return 0;
}
 			 	 					     	  	 	     		