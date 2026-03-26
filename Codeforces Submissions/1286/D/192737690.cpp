// LUOGU_RID: 101728700
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100001
#define yu (998244353)
inline ll ksm(ll x,ll y){
	ll an=1;
	for(;y;y>>=1){
		if(y&1)an=an*x%yu;
		x=x*x%yu;
	}return an;
}inline ll ni(ll x){return ksm(x,yu-2);}
ll n;
ll x[N],v[N],p[N];
ll xu[N]; 
struct juz{
	ll a[3][3],n,m;
	juz(){
		memset(a,0,sizeof(a));return;
	}
	inline juz operator*(const juz &x){
		juz t;t.n=n;t.m=x.m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=t.m;j++){
				for(int k=1;k<=m;k++){
					t.a[i][j]=(t.a[i][j]+a[i][k]*x.a[k][j])%yu;
				}
			}
		}return t;
	}
};
juz sum[N<<2],a[N];
inline void pushup(ll o){
	sum[o]=sum[o<<1]*sum[o<<1|1];
	return ;
}
inline void build(ll o,ll l,ll r){
	if(l==r){sum[o]=a[l];return ;}
	ll mid=(l+r)>>1;
	build(o<<1,l,mid);build(o<<1|1,mid+1,r);
	pushup(o);
	return ;
}
inline void update(ll o,ll l,ll r,ll x){
	if(l==r){
		sum[o]=a[l];return ;
	}ll mid=(l+r)>>1;
	if(mid>=x)update(o<<1,l,mid,x);
	else update(o<<1|1,mid+1,r,x);
	pushup(o);
	return ;
}
inline juz ask(ll o,ll l,ll r,ll x,ll y){
	if(x<=l&&r<=y)return sum[o];
	ll mid=(l+r)>>1;
	if(mid>=x&&mid>=y)return ask(o<<1,l,mid,x,y);
	if(mid<x&&mid<y)return ask(o<<1|1,mid+1,r,x,y);
	return ask(o<<1,l,mid,x,y)*ask(o<<1|1,mid+1,r,x,y);
}
inline void add(ll &x,ll y){x+=y;if(x>=yu)x-=yu;return ;}
#define T pair<double,ll>
#define mk make_pair
#define fi first
#define se second
T t[N<<1];
ll cn=0;
int main()
{
//	freopen("test1.in","r",stdin);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;for(int i=1;i<n;i++)xu[i]=i;ll xs=ni(100);
	for(int i=1;i<=n;i++)cin>>x[i]>>v[i]>>p[i],p[i]=p[i]*xs%yu;
	for(int i=1;i<n;i++)t[++cn]=mk((double)(x[i+1]-x[i])/(double)(v[i]+v[i+1]),i);
	for(int i=1;i<n;i++)if(v[i]!=v[i+1])t[++cn]=mk((double)(x[i+1]-x[i])/(double)(max(v[i],v[i+1])-min(v[i],v[i+1])),i+n);
	sort(t+1,t+cn+1);
	for(int i=1;i<=n;i++){
		a[i].n=a[i].m=2;
		a[i].a[1][1]=a[i].a[2][1]=yu+1-p[i];a[i].a[1][2]=a[i].a[2][2]=p[i];
	}build(1,1,n);
	ll ans=0; 
	for(int i=1;i<=cn;i++){
		ll q=t[i].se,o=q;
		if(q>n)o-=n;
		juz an;an.n=1;an.m=2;an.a[1][1]=1;an.a[1][2]=0;
		juz z=an,y=an;
		juz tem=ask(1,1,n,1,o);
		z=z*tem;
		if(q<n||v[o]<v[o+1])y.a[1][1]=yu+1-p[o+1],y.a[1][2]=0;
		else y.a[1][1]=0,y.a[1][2]=p[o+1];
		if(o+2<=n){
			y=y*ask(1,1,n,o+2,n);
		}ll x1,x2=(y.a[1][1]+y.a[1][2]);
		if(q<n||v[o]>v[o+1])x1=z.a[1][2];
		else x1=z.a[1][1];
		ll ji=x1*x2%yu;
		ll val;
		if(q<n)val=(x[o+1]-x[o])*ni(v[o]+v[o+1])%yu;
		else val=(x[o+1]-x[o])*ni(max(v[o],v[o+1])-min(v[o],v[o+1]))%yu;
		add(ans,ji*val%yu);
		if(q<n)a[o+1].a[2][1]=0;
		else{
			if(v[o]>v[o+1])a[o+1].a[2][2]=0;
			else a[o+1].a[1][1]=0;
		}
		update(1,1,n,o+1);
		
	}cout<<ans;
	return 0;
}
