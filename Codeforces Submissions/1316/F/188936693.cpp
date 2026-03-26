// LUOGU_RID: 99436832
#pragma GCC optimize(2,3,"Ofast","inline","unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define ll long long
#define ls (t<<1)
#define rs ((t<<1)|1)
using namespace std;
const int md=1e9+7,N=300010;

int tmp[N<<1],d[N],c[N],p[N],a[N],b[N],m,n,q;

struct Tree{
	int sum,cnt,pre,suf;
}T[4000010];

void update(int t)
{
	T[t].cnt=T[ls].cnt+T[rs].cnt;
	T[t].pre=(T[ls].pre+(ll)T[rs].pre*c[T[ls].cnt])%md;
	T[t].suf=(T[rs].suf+(ll)T[ls].suf*c[T[rs].cnt])%md;
	T[t].sum=(T[ls].sum+T[rs].sum+(ll)T[ls].suf*T[rs].pre)%md;
	return;
}

void change(int t,int l,int r,int x,int y)
{
//	cout<<t<<"   "<<l<<"   "<<r<<"   "<<x<<"   "<<y<<endl;
	if (l==r)
	{
		T[t].cnt+=y;
		if (y>0)
		{
			T[t].sum=(T[t].sum+(ll)T[t].suf*tmp[x]%md*c[1])%md;
			T[t].pre=((ll)T[t].pre*c[1]+(ll)tmp[x]*c[1])%md;
			T[t].suf=T[t].pre;
		}
		else
		{
			T[t].pre=((T[t].pre*2-tmp[x])%md+md)%md;
			T[t].suf=T[t].pre;
			T[t].sum=((T[t].sum-(ll)T[t].suf*tmp[x]%md*c[1])%md+md)%md;
		}
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid)change(ls,l,mid,x,y);
	else change(rs,mid+1,r,x,y);
	update(t);
	return;
}

int getpos(int x)
{
	return lower_bound(tmp+1,tmp+m+1,x)-tmp;
}

int fpow(int a,int b)
{
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%md)
	{
		if (b&1) ret=1ll*ret*a%md;
	}
	return ret;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		tmp[++m]=p[i];
	}
	d[0]=1;
	d[1]=2;
	c[0]=1;
	c[1]=fpow(2,md-2);
	for (int i=2;i<=n;i++)
		d[i]=(ll)d[i-1]*d[1]%md,
		c[i]=(ll)c[i-1]*c[1]%md;
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		tmp[++m]=b[i];
	}
	sort(tmp+1,tmp+m+1);
	m=unique(tmp+1,tmp+m+1)-tmp-1;
	for (int i=1;i<=n;i++)
		change(1,1,m,getpos(p[i]),1);
//	cout<<"SBZHZX"<<endl<<endl;
	printf("%d\n",T[1].sum);
	for (int i=1,x,y;i<=q;i++)
	{
//		cout<<i<<endl<<endl;
		x=a[i],y=b[i];
		change(1,1,m,getpos(p[x]),-1);
		p[x]=y;
		change(1,1,m,getpos(p[x]),1);
		printf("%d\n",T[1].sum);
	}
	return 0;
}