#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define all(s) s.begin(),s.end()
typedef long long ll;
const double pi = acos(-1),ef=1e-9;
const ll N=100+5,M=1e9+7;
ll n,a[N],mm[N][N][N][2];

ll rec(ll i,ll one,ll zero,ll lst)
{

	if(i>n){
		return 0;
	}
	ll &ans=mm[i][one][zero][lst];
	if(ans!=-1)return ans;
	ans=1e15;
	
	if(a[i]==-1){
		if(one>0){
			ans=min(ans,(lst!=1)+rec(i+1,one-1,zero,1));
		}
		if(zero>0){
			ans=min(ans,(lst!=0)+rec(i+1,one,zero-1,0));
		}
	}
	else{
		ans=min(ans,(lst!=a[i])+rec(i+1,one,zero,a[i]));
	}
	
	return ans;
}

void solve()
{
	memset(mm,-1,sizeof mm);
	ll c[2]={0};
	cin>>n;
	set<ll>st;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			a[i]=-1;
			//cout<<a[i]<<' ';
			continue;
		}
		st.insert(a[i]);
		a[i]%=2;
	}
	for(ll i=1;i<=n;i++){
		if(st.count(i))continue;
		c[i%2]++;
	}
	//for(auto p:st)cout<<p<<' ';
	
	//cout<<c[0]<<' '<<c[1]<<"\n";
	
	ll ans=1e18;
	ans=min(ans,rec(1,c[1],c[0],0));
	ans=min(ans,rec(1,c[1],c[0],1));
	
	
	cout<<ans<<"\n";
	
}

int main()
{
	fast;
	ll t=1,tc=1;
//	cin>>tc;
	while(tc--){
		solve();
	}

}
 	      	  				 			  						 		