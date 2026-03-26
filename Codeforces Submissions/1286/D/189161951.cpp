// LUOGU_RID: 99710629
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
struct mat{
	int p[3][3];
	mat operator*(const mat&a){
		mat nw;
		nw.p[1][1]=(p[1][1]*a.p[1][1]+p[1][2]*a.p[2][1])%mod;
		nw.p[1][2]=(p[1][1]*a.p[1][2]+p[1][2]*a.p[2][2])%mod;
		nw.p[2][1]=(p[2][1]*a.p[1][1]+p[2][2]*a.p[2][1])%mod;
		nw.p[2][2]=(p[2][1]*a.p[1][2]+p[2][2]*a.p[2][2])%mod;
		return nw;
	}
};
mat g[1000001];
int qpow(int a,int k){
	int ans=1;
	while(k){
		if(k&1)ans=ans*a%mod;
		k>>=1;a=a*a%mod;
	}
	return ans;
}
#define mid(l,r) ((l+r)>>1)
void modify(int l,int r,int t,mat s,int id){
	if(l==r){
		g[id]=s;
		return ;
	}
	if(t<=mid(l,r))modify(l,mid(l,r),t,s,id*2);
	else modify(mid(l,r)+1,r,t,s,id*2+1);
	g[id]=g[id*2+1]*g[id*2];
	return ;
}
mat query(int l,int r,int t,int id){
	if(l==r)return g[id];
	if(t<=mid(l,r))return query(l,mid(l,r),t,id*2);
	return query(mid(l,r)+1,r,t,id*2+1);
}
struct pr{
	int x,y,type,l;
}w[700001];
int pos[300001];
int v[300001];
int c[300001];
int ptr=0;
int inv=qpow(100,mod-2);
void build(int l,int r,int id){
	if(l==r){
		g[id].p[1][1]=(100-c[l])*inv%mod;
		g[id].p[1][2]=(100-c[l])*inv%mod;
		g[id].p[2][1]=c[l]*inv%mod;
		g[id].p[2][2]=c[l]*inv%mod;
		return ;
	}
	build(l,mid(l,r),id*2);build(mid(l,r)+1,r,id*2+1);
	g[id]=g[id*2+1]*g[id*2];
	return ;
}
signed main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>pos[i]>>v[i]>>c[i];
	for(int i=2;i<=n;i++){
		if(c[i]!=100 and c[i-1]!=0)w[++ptr]={pos[i]-pos[i-1],v[i]+v[i-1],0,i};
		if(v[i]!=v[i-1]){
			if(v[i]>v[i-1] and (c[i]==100 or c[i-1]==100))continue;
			if(v[i]<v[i-1] and (c[i]==0 or c[i-1]==0))continue;
			w[++ptr]={pos[i]-pos[i-1],abs(v[i]-v[i-1]),1,i};
		}
	}
	sort(w+1,w+1+ptr,[](pr a,pr b){return a.x*b.y<a.y*b.x;});
	build(1,n,1);
	int ans=0;
	for(int i=1;i<=ptr;i++){
		mat a=query(1,n,w[i].l-1,1);
		mat b=query(1,n,w[i].l,1);
		mat tmp=a,tmp2=b;
		if(w[i].type==0){
			b.p[1][2]=0;
			tmp.p[1][1]=0;tmp.p[1][2]=0;
			tmp2.p[2][1]=0;tmp2.p[2][2]=0;
		}else{
			if(v[w[i].l-1]<v[w[i].l]){
			   b.p[1][1]=0;
			   tmp.p[2][1]=0;tmp.p[2][2]=0;
			   tmp2.p[2][1]=0;tmp2.p[2][2]=0;
			}else{
				b.p[2][2]=0;
				tmp.p[1][1]=0;tmp.p[1][2]=0;
				tmp2.p[1][1]=0;tmp2.p[1][2]=0;
			}
		}
		modify(1,n,w[i].l-1,tmp,1);modify(1,n,w[i].l,tmp2,1);
		ans=(ans+(g[1].p[1][1]+g[1].p[2][1])*(w[i].x*qpow(w[i].y,mod-2)%mod))%mod;
		modify(1,n,w[i].l-1,a,1);modify(1,n,w[i].l,b,1);
	}
	if(ans<0)ans+=mod;
	cout<<ans<<endl;
	return 0;
}