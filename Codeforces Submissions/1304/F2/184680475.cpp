#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static const ll INF=1e14;
ll N,M,K;
ll A[55][20005];
ll dp[55][20005];
ll sum[55][20005];
ll dat[80005];
ll lazy[80005];
ll n;
ll Left(ll x){
	if(1<=x-K+1)return x-K+1;else return 1;
}
ll Right(ll x){
	if(x<=M-K+1)return x;else return M-K+1;
}
void eval(ll k){
    dat[k]+=lazy[k];
    if(k<n-1){
        lazy[2*k+1]+=lazy[k];
        lazy[2*k+2]+=lazy[k];
    }lazy[k]=0;

}
void add(ll a,ll b,ll x,ll k,ll l,ll r){
    eval(k);
    if(a<=l&&r<=b){
        lazy[k]+=x;
        eval(k);
    }else if(a<r&&l<b){
        add(a,b,x,2*k+1,l,(l+r)/2);
        add(a,b,x,2*k+2,(l+r)/2,r);
        dat[k]=max(dat[2*k+1],dat[2*k+2]);
    }
}
ll query(ll a,ll b,ll k,ll l,ll r){
    eval(k);
    if(a<=l&&r<=b)return dat[k];
    else if(r<=a||b<=l)
    return -INF;
    else{
        ll val=query(a,b,2*k+1,l,(l+r)/2);
        ll var=query(a,b,2*k+2,(l+r)/2,r);
        return max(val,var);
    }
}
void solve(){
	for(ll i=1;i<=N;i++)
	for(ll j=1;j<=M;j++)sum[i][j]=A[i][j];
	for(ll i=1;i<=N;i++){
		for(ll j=2;j<=M;j++)sum[i][j]+=sum[i][j-1];
	}


	for(ll i=2;i<=N+1;i++){

if(i!=2){ll Sum=0;for(ll j=K;1<=j;j--){
	Sum+=A[i-1][j];
	if(j<=M-K+1)dp[i-1][j]-=Sum;
	

}

    n=1;
    while(n<=M-K+2)n*=2;
    for(ll j=0;j<2*n-1;j++){
        lazy[j]=0;
    }for(ll j=0;j<n;j++)if(1<=j&&j<=M-K+1)dat[n-1+j]=dp[i-1][j];
	else dat[n-1+j]=-INF;
	for(ll j=n-2;0<=j;j--)dat[j]=max(dat[2*j+1],dat[2*j+2]);



for(ll j=1;j<=M-K+1;j++){
dp[i][j]=query(1,M-K+2,0,0,n)+sum[i][K+j-1]-sum[i][j-1]+sum[i-1][K+j-1]-sum[i-1][j-1];

add(Left(j),1+Right(j),A[i-1][j],0,0,n);
add(Left(j+K),1+Right(j+K),-A[i-1][j+K],0,0,n);
}

	}else{
		for(ll j=1;j<=M-K+1;j++)dp[i][j]=sum[i][K+j-1]-sum[i][j-1]+sum[i-1][K+j-1]-sum[i-1][j-1];
	}
	}

	ll ans=0;
	for(ll j=1;j<=M-K+1;j++)ans=max(ans,dp[N+1][j]);
	cout<<ans<<endl;
}
int main(){
cin>>N>>M>>K;
for(ll i=1;i<=N;i++)
for(ll j=1;j<=M;j++)scanf("%lld",&A[i][j]);
solve();
	return 0;
}
