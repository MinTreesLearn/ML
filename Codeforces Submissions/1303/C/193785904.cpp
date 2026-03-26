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
	map<char,ll>mp;
	string s;cin>>s;
	string t;t+=s[0];mp[s[0]]=1;
	ll pos=0;
	for(int i=1;i<s.size();i++){
		if(!mp[s[i]]){
			if(!pos){
				t=s[i]+t;
			}else if(pos==t.size()-1)t+=s[i],pos++;
			else {
				cout<<"NO"<<endl;
				return ;
			}
			mp[s[i]]=1;
		}else {
			if(pos>0&&t[pos-1]==s[i])pos--;
			else if(pos<t.size()-1&&t[pos+1]==s[i])pos++;
			else {
				cout<<"NO"<<endl;
				return ;
			}
		}
	}	

	for(char i='a';i<='z';i++){
		if(!mp[i])t+=i;
	}
	cout<<"YES"<<endl;
	cout<<t<<endl;

}

signed main(){IOS
	ll T;T=1;
	cin>>T;
	while(T--){
		solve();
	}


	return 0;
}