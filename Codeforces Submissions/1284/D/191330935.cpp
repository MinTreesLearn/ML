#include <bits/stdc++.h>
#define IOS   ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define xs(a) cout<<setiosflags(ios::fixed)<<setprecision(a);
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define mem(a,b) memset(a,b,sizeof(a));
using namespace std;
#define ull unsigned long long
#define ll long long
#define endl '\n'
typedef pair<ll,ll> pll;
const int N=1e6+5;
const int mod=1e9+7;
/*-----------------------------------------------------------------------------------------------*/
ll sa[N],sb[N],ea[N],eb[N];
ll n;

bool check(){
	multiset<ll>s,e;
	vector<array<ll,3>>vec;
	FOR(i,1,n){
		vec.push_back({sa[i],i,-1});
		vec.push_back({ea[i],i,1});
	}
	sort(vec.begin(),vec.end(),[&](auto l,auto r){
		if(l[0]==r[0])return l[2]<r[2];
		else return l[0]<r[0];
	});
	for(auto &to:vec){
		if(to[2]==1){
			s.erase(s.find(sb[to[1]]));
			e.erase(e.find(eb[to[1]]));
		}else {
			s.insert(sb[to[1]]);
			e.insert(eb[to[1]]);
			ll mx=*s.rbegin();
			ll mi=*e.begin();
			if(mx>mi)return 0;
		}
	}
	return 1;
}

signed main(){IOS
	cin>>n;
	FOR(i,1,n)cin>>sa[i]>>ea[i]>>sb[i]>>eb[i];
	bool f=1;
	f&=check();
	swap(sa,sb);
	swap(ea,eb);
	f&=check();
	if(f)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	return 0;
}