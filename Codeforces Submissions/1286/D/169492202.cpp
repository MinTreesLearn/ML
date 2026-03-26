#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+10,mod=998244353;
ll n,XX[N],VV[N],P[N];
struct node{
	ll d,v,x,y,f1,f2;
}nd[N];

ll i100;
ll ksm(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%mod;x=x*x%mod;y>>=1;}return res;}
int lim[N][2][2];
struct Segment{
	int l,r;
	ll v[2][2];
	void print(){
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++)
				printf("%d ",v[i][j]);
			puts("");
		}
		puts("");
	}
}s[N<<2];
void pushup(int x){
	int l=s[x<<1].r,r=s[x<<1|1].l;
	//s[x<<1].print(),s[x<<1|1].print();
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			s[x].v[i][j]=0;
			for(int xx=0;xx<2;xx++){
				for(int y=0;y<2;y++){
					//printf("%d ",lim[r][x][y]);
				if(!lim[r][xx][y])
				//printf("%d %d %d %d %lld %lld\n",i,x,y,j,s[x<<1].v[i][x],s[x<<1|1].v[y][j]);
				s[x].v[i][j]=(s[x].v[i][j]+s[x<<1].v[i][xx]*s[x<<1|1].v[y][j]%mod)%mod;	
				}
				//puts("");
			}
		}
	}
	return ;
}
void build(int x,int l,int r){
	s[x].l=l,s[x].r=r;
	if(l==r){
		s[x].v[0][0]=(100-P[l])*i100%mod;
		s[x].v[1][1]=P[l]*i100%mod;
		return ;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pushup(x);
}


bool cmp(node q,node p){
	return q.d*p.v<p.d*q.v;
}
void upd(int x,int p){
	if(s[x].l==p&&s[x].r==p)return ;
	int mid=(s[x].l+s[x].r)/2;
	if(p<=mid)upd(x<<1,p);
	else upd(x<<1|1,p);
	pushup(x);
}
int main(){
	i100=ksm(100,mod-2);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld%lld",&XX[i],&VV[i],&P[i]);
	int qwq=0;
	for(int i=1;i<n;i++){
		nd[++qwq]=(node){(XX[i+1]-XX[i]),(VV[i+1]+VV[i]),i,i+1,1,0};
		if(VV[i]>VV[i+1])nd[++qwq]=(node){(XX[i+1]-XX[i]),(VV[i]-VV[i+1]),i,i+1,1,1};
		if(VV[i]<VV[i+1])nd[++qwq]=(node){(XX[i+1]-XX[i]),(VV[i+1]-VV[i]),i,i+1,0,0};
	}
	sort(nd+1,nd+qwq+1,cmp);
	build(1,1,n);
	ll res=0,nw=1;
	for(int i=1;i<=qwq;i++){
		lim[nd[i].y][nd[i].f1][nd[i].f2]=1;
		upd(1,nd[i].y);
		ll t=(s[1].v[0][0]+s[1].v[0][1]+s[1].v[1][0]+s[1].v[1][1])%mod;
		res=(res+nd[i].d*ksm(nd[i].v,mod-2)%mod*(nw-t)%mod)%mod;
		//printf("%lld [%lld,%lld] %lld %lld %lld %lld\n",nd[i].x,nd[i].f1,nd[i].f2,t,nd[i].d,ksm(nd[i].v,mod-2)%mod);
		//for(int j=1;j<=10;j++)s[j].print();
		nw=t;
	}
	printf("%lld\n",(res%mod+mod)%mod);
	return 0;
} 