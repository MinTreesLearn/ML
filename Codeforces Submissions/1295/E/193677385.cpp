#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010;
int n,p[N],a[N],f[N];
struct segtree{
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
#define mid (((l)+(r))>>1)
	static int const T=N<<2;
	int tr[T],lt[T];
	void update(int x){
		tr[x]=min(tr[ls(x)],tr[rs(x)]);
	}
	void add(int x,int k){
		tr[x]+=k,lt[x]+=k;
	}
	void pushdown(int x){
		if(!lt[x])return;
		add(ls(x),lt[x]),add(rs(x),lt[x]),lt[x]=0;
	}
	void modify(int x,int l,int r,int ql,int qr,int k){
		if(ql>qr)
			return;
		if(ql<=l&&r<=qr)
			return add(x,k);
		pushdown(x);
		if(ql<=mid)
			modify(ls(x),l,mid,ql,qr,k);
		if(qr>mid)
			modify(rs(x),mid+1,r,ql,qr,k);
		update(x);
	}
	int query(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)
			return tr[x];
		pushdown(x);
		int res=LLONG_MAX;
		if(ql<=mid)
			res=min(res,query(ls(x),l,mid,ql,qr));
		if(qr>mid)
			res=min(res,query(rs(x),mid+1,r,ql,qr));
		return res;
	}
#undef ls
#undef rs
#undef mid
};
segtree tr;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		tr.modify(1,1,n,p[i],n,a[i]);
	int ans=min(a[1],a[n]);
	for(int i=1;i<n;i++)
		tr.modify(1,1,n,1,p[i]-1,a[i]),tr.modify(1,1,n,p[i],n,-a[i]),
		ans=min(ans,tr.query(1,1,n,1,n));
	cout<<ans<<"\n";
}