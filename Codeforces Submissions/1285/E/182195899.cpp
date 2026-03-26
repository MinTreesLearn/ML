// LUOGU_RID: 95118453
#include <bits/stdc++.h>
#define int long long 
#define pb push_back
using namespace std;
const int INF=7e5+5;
int t,n,l[INF],r[INF],f[INF];
vector <int> v;
int Get(int x) {return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
struct node_{
	bool l,r;
	int xx;
};
node_ mer(node_ x,node_ y) {return {x.l,y.r,x.xx+y.xx-(x.r&y.l)};}
struct Segment{
	#define ll tl[id]
	#define rr tr[id]
	#define ls(x) x<<1
	#define rs(x) x<<1|1
	node_ sum[INF<<2];
	int tl[INF<<2],tr[INF<<2];
	void push_up(int id) {
		sum[id]=mer(sum[ls(id)],sum[rs(id)]);
	}
	void build(int l,int r,int id) {
		ll=l;rr=r;
		if (l==r) {sum[id]={f[l]>0,f[l]>0,f[l]>0};return ;}
		int Mid=(l+r)>>1;
		build(l,Mid,ls(id));
		build(Mid+1,r,rs(id));
		push_up(id);
	}
	node_ query(int l,int r,int id) {
		if (l<=ll && rr<=r) return sum[id];
		int Mid=(ll+rr)>>1;
		if (l>Mid) return query(l,r,rs(id));
		else if (r<=Mid) return query(l,r,ls(id));
		else return mer(query(l,r,ls(id)),query(l,r,rs(id)));
	}
} T1;


struct Segment2{
	#define ll tl[id]
	#define rr tr[id]
	#define ls(x) x<<1
	#define rs(x) x<<1|1
	node_ sum[INF<<2];
	int tl[INF<<2],tr[INF<<2];
	void push_up(int id) {
		sum[id]=mer(sum[ls(id)],sum[rs(id)]);
	}
	void build(int l,int r,int id) {
		ll=l;rr=r;
		if (l==r) {sum[id]={f[l]>1,f[l]>1,f[l]>1};return ;}
		int Mid=(l+r)>>1;
		build(l,Mid,ls(id));
		build(Mid+1,r,rs(id));
		push_up(id);
	}
	node_ query(int l,int r,int id) {
		if (l<=ll && rr<=r) return sum[id];
		int Mid=(ll+rr)>>1;
		if (l>Mid) return query(l,r,rs(id));
		else if (r<=Mid) return query(l,r,ls(id));
		else return mer(query(l,r,ls(id)),query(l,r,rs(id)));
	}
} T2;
void solve() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>l[i]>>r[i];
		l[i]*=2;r[i]*=2;
		v.pb(l[i]);v.pb(r[i]);
		v.pb(r[i]+1);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int len=v.size();
	for (int i=1;i<=len+5;i++) f[i]=0;
	for (int i=1;i<=n;i++) {
		int it=Get(l[i]),it1=Get(r[i]+1);
		f[it]++;f[it1]--;
	}
	for (int i=1;i<=len;i++) f[i]+=f[i-1];
	T1.build(1,len,1);T2.build(1,len,1);
	int res=0;
	for (int i=1;i<=n;i++) {
		int it=Get(l[i]),it1=Get(r[i]);
		node_ xx={0,0,0};if (it-1>=1) xx=T1.query(1,it-1,1);
		node_ yy={0,0,0};yy=T2.query(it,it1,1);
		node_ zz={0,0,0};if (it1+1<=len) zz=T1.query(it1+1,len,1);
		res=max(res,mer(xx,mer(yy,zz)).xx); 
	}
	cout<<res<<"\n";
	return ;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while (t--) solve();
	return 0;
}