#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=100005;
int prime[1100000],primesize;
bool isprime[11000000];
ll f[N],invf[N];
void getlist(int listsize){
    memset(isprime,1,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<=listsize;i++){
        if(isprime[i])prime[++primesize]=i;
         for(int j=1;j<=primesize&&i*prime[j]<=listsize;j++) {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
}
ll fpow(ll a,ll k){
    ll res=1;
    while(k){
        if(k&1) res=(res*a)%mod;
        k>>=1;
        a=a*a%mod;
        //cout<<1<<endl;
    }
    return res;
}
void init(int n){
    f[0]=1;
    for(int i=1;i<=n;++i){
        f[i]=f[i-1]*i%mod;
    }
    invf[n]=fpow(f[n],mod-2);
    for(int i=n-1;i>=0;--i){
        invf[i]=invf[i+1]*(i+1)%mod;
    }
}
ll C(int n,int k){
    if(k<0 || k>n) return 0;
    return f[n]*invf[k]%mod*invf[n-k]%mod;
}
ll a[4005];
void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	if(m<=k){
		k=m-1;
	}
	for(int l=0;l<=k;l++){
		int r=k-l;
		ll temp=0x3f3f3f3f3f3f3f;
		ll len=m-k-1;
		for(int ll=0;ll<=len;ll++){
			int rr=len-ll;
			temp=min(temp,max(a[ll+1+l],a[n-rr-r]));
		} 
	//	cout<<l<<" "<<r<<" "<<len<<endl;
		ans=max(temp,ans);
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//euler(1e7);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
