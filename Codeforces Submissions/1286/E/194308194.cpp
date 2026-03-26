// LUOGU_RID: 102578485
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
#define inf 1e18
#define N 1000010
ll n;
ll ji[N];
ll nxt[N],fl[N],nn[N];
const ll mask=(1ll<<30)-1;
lll ans=0;
struct node{
	ll val[N<<2];
	inline void pushup(ll x){
		val[x]=min(val[x<<1],val[x<<1|1]);
		return ;
	}
	inline void update(ll o,ll l,ll r,ll x,ll y){
		if(l==r){
			val[o]=y;return ;
		}ll mid=(l+r)>>1;
		if(mid>=x)update(o<<1,l,mid,x,y);
		else update(o<<1|1,mid+1,r,x,y);
		pushup(o);return ;
	}
	inline ll ask(ll o,ll l,ll r,ll x,ll y){
		if(x<=l&&r<=y)return val[o];
		ll mid=(l+r)>>1,an=inf;
		if(mid>=x)an=min(an,ask(o<<1,l,mid,x,y));
		if(mid<y)an=min(an,ask(o<<1|1,mid+1,r,x,y));
		return an;
	}
}g;
struct T{
	ll fi;
	mutable ll se;
	bool operator <(const T y)const{
		if(y.fi==fi)return se<y.se;
		return fi<y.fi;
	}
};
set< T >s;
inline void del(ll x){
	auto o=s.lower_bound((T){x,0});
	(*o).se--;ans-=x;
	return ;
}
inline void push(ll x){
	auto o=s.lower_bound((T){x,0});
	if(o!=s.end()&&(*o).fi==x)(*o).se++;
	else{
		s.insert((T){x,1});
	}
	ans+=x;
	return ;
}
inline void qm(ll x){
	auto o=s.lower_bound((T){x+1,0}),p=o;
	ll cnt=0;
	while(o!=s.end()){
		ans-=(*o).fi*(*o).se;cnt+=(*o).se;	
		o++;
	}s.erase(p,s.end());ans+=cnt*x;
	p=s.lower_bound((T){x,0});
	if(p!=s.end()&&(*p).fi==x){
		(*p).se+=cnt;
	}else{
		s.insert((T){x,cnt});
	}
	return ;
}
ll u[31],cnn=0;
inline void out(lll x){
	if(x==0){
		putchar('0');putchar(10);
		return ;
	}cnn=0;while(x){
		u[++cnn]=x%10;x/=10;
	}for(int i=cnn;i>=1;i--)putchar(u[i]+'0');
	putchar(10);
	return ;
}
int main()
{
//	freopen("test1.in","r",stdin);
	//freopen(".in","r",stdin);
	//freopen("test1.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;char x;ll y;lll las=0;
	memset(g.val,0x3f,sizeof(g.val));
	for(int i=1;i<=n;i++){
		cin>>x>>y;ll o=x-'a';
		o=(o+las)%26;y=y^(las&mask);
		g.update(1,1,n,i,y);ji[i]=o;
		if(i>1){
			nn[i-1]=o;
			if(nn[nxt[i-1]]!=o)fl[i-1]=nxt[i-1];
			else fl[i-1]=fl[nxt[i-1]];
			ll nw=i-1;
			while(nw){
				if(nn[nw]!=ji[i]){
					del(g.ask(1,1,n,i-nw,i-1));
					nw=nxt[nw];
				}else nw=fl[nw];
			}
		}
		if(ji[1]==o){
			push(y);
		}qm(y);
		out(las=las+ans);
		ll p=nxt[i-1];
		while(p>0&&ji[p+1]!=ji[i])p=nxt[p];
		if(i!=1&&ji[p+1]==ji[i])nxt[i]=p+1;
	} 
	return 0;
}
