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
const int N=4e2+5;
const int mod=1e9+7;
/*-----------------------------------------------------------------------------------------------*/

ll f[N][N];//s的前i个匹配t1的前j个最多能匹配t2的前几个
string s;
bool check(string t1,string t2){
	mem(f,-1);
	f[0][0]=0;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<=t1.size();j++){
			if(f[i][j]==-1)continue;
			ll tmp=f[i][j];
			if(s[i]==t1[j]&&j<t1.size())f[i+1][j+1]=max(f[i+1][j+1],tmp);
			if(s[i]==t2[tmp]&&tmp<t2.size())f[i+1][j]=max(f[i+1][j],tmp+1);
			f[i+1][j]=max(f[i+1][j],f[i][j]);
		}
	}
	return f[s.size()][t1.size()]==t2.size();
}

void solve(){
	string t;cin>>s>>t;
	for(int i=0;i<t.size();i++){
		string x=t.substr(0,i);
		string y=t.substr(i);
		//cout<<x<<' '<<y<<endl;
		if(check(x,y)){cout<<"YES"<<endl;return ;}
	}
	cout<<"NO"<<endl;
}

signed main(){IOS
	ll T;T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}