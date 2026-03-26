#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#define mod 998244353
struct matrix
{
	long long a[2][2];
	matrix(){}
	matrix(long long a0,long long a1,long long a2,long long a3){a[0][0]=a0,a[0][1]=a1,a[1][0]=a2,a[1][1]=a3;}
};
matrix operator *(matrix x,matrix y)
{
	matrix ans;
	ans.a[0][0]=(x.a[0][0]*y.a[0][0]+x.a[0][1]*y.a[1][0])%mod;
	ans.a[0][1]=(x.a[0][0]*y.a[0][1]+x.a[0][1]*y.a[1][1])%mod;
	ans.a[1][0]=(x.a[1][0]*y.a[0][0]+x.a[1][1]*y.a[1][0])%mod;
	ans.a[1][1]=(x.a[1][0]*y.a[0][1]+x.a[1][1]*y.a[1][1])%mod;
	return ans;
}
struct sgt
{
	struct node
	{
		matrix s;
	};
	node a[300005];
	matrix mat[100005];
	void pushup(int k){a[k].s=a[k*2+1].s*a[k*2].s;}
	void build(int k,int l,int r)
	{
		if (l==r) return a[k].s=mat[l],void();
		int mid=(l+r)/2;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
		pushup(k);
	}
	void update(int k,int l,int r,int x,int pos,long long w)
	{
//		if (k==1) printf("Upd %d %d %lld\n",x,pos,w);
		if (l==r) return /*printf("clear %d %d\n",pos>>1,pos&1),*/a[k].s.a[pos>>1][pos&1]=0,void();
		int mid=(l+r)/2;
		if (x<=mid) update(k*2,l,mid,x,pos,w);
		if (mid<x) update(k*2+1,mid+1,r,x,pos,w);
		pushup(k);
	}
};
sgt t;
struct node{double t;int id,pos;node(double t=0,int id=0,int pos=0){this->t=t,this->id=id,this->pos=pos;}};
std::vector<node> vec;
int n,pos[100005],v[100005];
long long ans=0,pb[100005];
std::map<double,long long> mp;
long long fp(long long x,int y){return (y&1?x:1ll)*(y>>1?fp(x*x%mod,y>>1):1ll)%mod;}
int cmp(node x,node y){return x.t<y.t;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d%lld",&pos[i],&v[i],&pb[i]),pb[i]=pb[i]*828542813%mod;
	t.mat[1]=matrix((1-pb[1]+mod)%mod,(1-pb[1]+mod)%mod,pb[1],pb[1]);
	for (int i=2;i<=n;i++) t.mat[i]=matrix((1-pb[i]+mod)%mod,(1-pb[i]+mod)%mod,pb[i],pb[i]);
//	for (int i=1;i<=n;i++) printf("%d:(%lld %lld %lld %lld)\n",i,t.mat[i].a[0][0],t.mat[i].a[0][1],t.mat[i].a[1][0],t.mat[i].a[1][1]);
	t.build(1,1,n);
	for (int i=2;i<=n;i++)
	{
		if (v[i]>v[i-1])
		{
			double w=(pos[i]-pos[i-1])/(double)(v[i]-v[i-1]);
			long long c=(pos[i]-pos[i-1])*fp(v[i]-v[i-1],mod-2)%mod;
			mp[w]=c;
			vec.push_back(node(w,i,0));
		}
		if (v[i]<v[i-1])
		{
			double w=(pos[i]-pos[i-1])/(double)(v[i-1]-v[i]);
			long long c=(pos[i]-pos[i-1])*fp(v[i-1]-v[i],mod-2)%mod;
			mp[w]=c;
			vec.push_back(node(w,i,3));
		}
		double w=(pos[i]-pos[i-1])/(double)(v[i]+v[i-1]);
		long long c=(pos[i]-pos[i-1])*fp((v[i-1]+v[i])%mod,mod-2)%mod;
		mp[w]=c;
		vec.push_back(node(w,i,1));
	}
	std::sort(vec.begin(),vec.end(),cmp);
	int d=0;
	long long np=1;
	while (d<(int)vec.size())
	{
		double tm=vec[d].t;
//		printf("tm = %lf\n",tm);
		while (d<(int)vec.size()&&vec[d].t==tm) t.update(1,1,n,vec[d].id,vec[d].pos,0),++d;
		matrix mat=t.a[1].s;
//		printf("(%lld %lld %lld %lld)\n",t.a[1].s.a[0][0],t.a[1].s.a[0][1],t.a[1].s.a[1][0],t.a[1].s.a[1][1]);
		long long pp=499122177*(mat.a[0][0]+mat.a[0][1]+mat.a[1][0]+mat.a[1][1])%mod;
//		printf("%lld\n",mp[tm]);
		ans=(ans+(np-pp+mod)*mp[tm])%mod;
//		printf("qwq %lld %lld\n",np,pp);
		np=pp;
	}
	printf("%lld\n",ans);
	return 0;
}