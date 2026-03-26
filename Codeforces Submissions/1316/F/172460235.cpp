#include<map>
#include<ctime>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<vector>
#include<random>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
#define I inline ll
#define her1 20090115
#define IV inline void
#define cht 1000000007
#define ld long double
#define Aestas16 392699
#define ull unsigned long long
#define mem(x,val)memset(x,val,sizeof x)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,o)for(register int i=first[o];i;i=e[i].nxt)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define DL(i,j,n)for(register ll i=j;i>=n;i--)
#define EL(i,o)for(register ll i=first[o];i;i=e[i].nxt)
#define FL(i,j,n)for(register ll i=j;i<=n;i++)
//#define D(i,j,n)for(int i=j;i>=n;i--)
//#define E(i,o)for(int i=first[o];i;i=e[i].nxt)
//#define F(i,j,n)for(int i=j;i<=n;i++)
//#define DL(i,j,n)for(ll i=j;i>=n;i--)
//#define EL(i,o)for(ll i=first[o];i;i=e[i].nxt)
//#define FL(i,j,n)for(ll i=j;i<=n;i++)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
#define ls (o<<1)
#define rs (o<<1|1)
mt19937 rnd(her1);
const int N = 6e5+5;
const int maxn = 1e6+5;
struct tree{ll l,r,tot,val,val1,val2;}t[N*4];
struct item{ll val,*s;}b[maxn];ll cnt,tot,pw[N],ip[N],n,q,a[N],p[N],x[N];
IV build(ll o,ll l,ll r){
	t[o].l=l;t[o].r=r;t[o].tot=t[o].val=t[o].val1=t[o].val2=0;
	if(l==r)return;ll mid=l+r>>1;build(ls,l,mid);build(rs,mid+1,r);
}
IV pushup(ll o){
	t[o].tot=t[ls].tot+t[rs].tot;
	t[o].val1=(t[ls].val1+t[rs].val1*pw[t[ls].tot])%cht;
	t[o].val2=(t[ls].val2+t[rs].val2*ip[t[ls].tot])%cht;
	t[o].val=(t[ls].val+t[rs].val+t[ls].val1*t[rs].val2%cht*ip[t[ls].tot])%cht;
}
IV upd(ll o,ll p,ll ty){
	if(t[o].l==t[o].r){
		if(~ty){
			t[o].tot=1;t[o].val1=b[p].val;
			t[o].val2=b[p].val*ip[1]%cht;t[o].val=0;
		}
		else t[o].tot=t[o].val1=t[o].val2=t[o].val=0;return;
	}
	ll mid=t[o].l+t[o].r>>1;
	p<=mid?upd(ls,p,ty):upd(rs,p,ty);pushup(o);
}
int main(){
	n=read();F(i,1,n)b[++cnt].val=a[i]=read(),b[cnt].s=a+i;
	q=read();F(i,1,q)p[i]=read(),b[++cnt].val=x[i]=read(),b[cnt].s=x+i;
	sort(b+1,b+1+cnt,[](item u,item v){return u.val<v.val;});F(i,1,cnt)(*b[i].s)=++tot;
	pw[0]=1;F(i,1,n)pw[i]=pw[i-1]*2%cht;ip[ip[0]=1]=(cht+1)>>1;F(i,2,n)ip[i]=ip[i-1]*ip[1]%cht;
	build(1,1,tot);F(i,1,n)upd(1,a[i],1);printf("%lld\n",t[1].val);
	F(i,1,q)upd(1,a[p[i]],-1),a[p[i]]=x[i],upd(1,a[p[i]],1),printf("%lld\n",t[1].val);return 0;
}