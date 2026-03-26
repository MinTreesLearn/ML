// LUOGU_RID: 102594139
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200010
#define inf (1e9)
ll n;
ll a[N];
ll ans[N]; 
ll pos[N];
struct sgt{
	ll sum[N<<2],tag1[N<<2],tag2[N<<2],mx[N<<2],smx[N<<2],cn[N<<2],cnmx[N<<2];
	inline void pushup(ll x){
		sum[x]=sum[x<<1]+sum[x<<1|1];
		cn[x]=cn[x<<1]+cn[x<<1|1];
		if(mx[x<<1]==mx[x<<1|1]){
			smx[x]=max(smx[x<<1],smx[x<<1|1]);
			mx[x]=mx[x<<1];
			cnmx[x]=cnmx[x<<1]+cnmx[x<<1|1]; 
		}
		if(mx[x<<1]<mx[x<<1|1]){
			mx[x]=mx[x<<1|1];
			smx[x]=max(mx[x<<1],smx[x<<1|1]);
			cnmx[x]=cnmx[x<<1|1];
		}
		if(mx[x<<1]>mx[x<<1|1]){
			mx[x]=mx[x<<1];
			smx[x]=max(mx[x<<1|1],smx[x<<1]);
			cnmx[x]=cnmx[x<<1];
		}
		return ;
	}
	inline void pushdown(ll x){
		if(tag1[x]){
			ll u=tag1[x];
			if(mx[x<<1]==mx[x<<1|1]){
				mx[x<<1]+=u;mx[x<<1|1]+=u;
				sum[x<<1]+=u*(cnmx[x<<1]);sum[x<<1|1]+=u*(cnmx[x<<1|1]);
				tag1[x<<1]+=u;tag1[x<<1|1]+=u;
			}else{
				if(mx[x<<1]<mx[x<<1|1]){
					mx[x<<1|1]+=u;
					sum[x<<1|1]+=u*(cnmx[x<<1|1]);
					tag1[x<<1|1]+=u;
				}else{
					mx[x<<1]+=u;
					sum[x<<1]+=u*(cnmx[x<<1]);
					tag1[x<<1]+=u; 
				}
			}
			tag1[x]=0;
		}
		if(tag2[x]){
			ll u=tag2[x];
			if(mx[x<<1]==mx[x<<1|1]){
				smx[x<<1]+=u;smx[x<<1|1]+=u;
				sum[x<<1]+=u*(cn[x<<1]-cnmx[x<<1]);sum[x<<1|1]+=u*(cn[x<<1|1]-cnmx[x<<1|1]);
				tag2[x<<1]+=u;tag2[x<<1|1]+=u;
			}else{
				if(mx[x<<1]<mx[x<<1|1]){
					mx[x<<1]+=u;
					smx[x<<1]+=u;smx[x<<1|1]+=u;
					sum[x<<1]+=u*(cn[x<<1]);sum[x<<1|1]+=u*(cn[x<<1|1]-cnmx[x<<1|1]);
					tag2[x<<1]+=u;tag1[x<<1]+=u;tag2[x<<1|1]+=u;
				}else{
					mx[x<<1|1]+=u;
					smx[x<<1]+=u;smx[x<<1|1]+=u;
					sum[x<<1]+=u*(cn[x<<1]-cnmx[x<<1]);sum[x<<1|1]+=u*(cn[x<<1|1]);
					tag2[x<<1]+=u;tag2[x<<1|1]+=u;tag1[x<<1|1]+=u; 
				}
			}
			tag2[x]=0;	
		}return ;
	}
	inline void update(ll o,ll l,ll r,ll x,ll y,ll z){
		if(x<=l&&r<=y){
			if(mx[o]<=z)return ;
			if(z>smx[o]){
				sum[o]+=(z-mx[o])*cnmx[o];
				tag1[o]+=(z-mx[o]);mx[o]=z;
				return ;
			}
		}pushdown(o);
		ll mid=(l+r)>>1;
		if(mid>=x)update(o<<1,l,mid,x,y,z);
		if(mid<y)update(o<<1|1,mid+1,r,x,y,z);
		pushup(o);
		return ;
	}
	inline void upd(ll o,ll l,ll r,ll x,ll y){
		if(l==r){
			sum[o]=mx[o]=y;
			smx[o]=-inf;cn[o]=cnmx[o]=1;
			return ;
		}pushdown(o);
		ll mid=(l+r)>>1;
		if(mid>=x)upd(o<<1,l,mid,x,y);
		else upd(o<<1|1,mid+1,r,x,y);
		pushup(o);
		return ;
	}
	inline void add(ll o,ll l,ll r,ll x,ll y){
		if(x<=l&&r<=y){
			sum[o]+=cn[o];mx[o]++;smx[o]++;
			tag1[o]++;tag2[o]++;
			return ;
		}
		pushdown(o);
		ll mid=(l+r)>>1;
		if(mid>=x)add(o<<1,l,mid,x,y);
		if(mid<y)add(o<<1|1,mid+1,r,x,y);
		pushup(o);
		return ;
	}
	inline ll ask(ll o,ll l,ll r,ll x,ll y){
		if(x>y)return 0;
		if(x<=l&&r<=y)return cn[o];
		pushdown(o);	
		ll an=0;ll mid=(l+r)>>1;
		if(mid>=x)an+=ask(o<<1,l,mid,x,y);
		if(mid<y)an+=ask(o<<1|1,mid+1,r,x,y);
		return an;
	}
	inline void build(ll o,ll l,ll r){
		sum[o]=tag1[o]=tag2[o]=mx[o]=smx[o]=cn[o]=cnmx[o]=0;
		if(l==r)return ;
		ll mid=(l+r)>>1;
		build(o<<1,l,mid);build(o<<1|1,mid+1,r);
		return ;
	}
}g;
inline void suan(){
	for(int i=1;i<=n;i++)pos[a[i]]=i;
	g.build(1,1,n);
	for(int i=1;i<=n;i++){
		ll o=pos[i];
		ll p=g.ask(1,1,n,1,o-1);
		if(o>1)g.update(1,1,n,1,o-1,p+1);
		if(o<n)g.add(1,1,n,o+1,n);
		g.upd(1,1,n,o,i+1);
		ans[i]+=g.sum[1];
	}return ;
}
int main()
{
//	freopen("test1.in","r",stdin);
	//freopen(".in","r",stdin);
	//freopen("test1.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
	suan();
	reverse(a+1,a+n+1);
	suan();
	for(int i=1;i<=n;i++)cout<<ans[i]-1ll*i*(i+2)<<'\n';
	return 0;
}
