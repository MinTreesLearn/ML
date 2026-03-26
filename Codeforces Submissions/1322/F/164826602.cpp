#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 500000
#define LN 20
#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define Tp template<typename Ty>
	#define Ts template<typename Ty,typename... Ar>
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}struct IO_Cl {~IO_Cl() {clear();}}CL;
	Tp void read(Ty& x) {x=0;while(!isdigit(oc=tc()));while(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts void read(Ty& x,Ar&... y) {read(x),read(y...);}
	Tp void write(Ty x) {while(OS[++OT]=x%10+48,x/=10);while(OT) pc(OS[OT--]);pc(' ');}
}using namespace FastIO;
int n,m,ee,lnk[N+5];struct edge {int to,nxt;}e[N<<1];
namespace U
{
	int f[N+5],g[N+5];int fa(int x) {if(!f[x]) return x;int t=fa(f[x]);return g[x]^=g[f[x]],f[x]=t;}
	void U(int x,int y,int z)
	{
		int fx=fa(x),fy=fa(y);if(fx==fy) {g[x]^g[y]^z&&(puts("-1"),exit(0),0);return;}
		f[fy]=fx,g[fy]=g[x]^g[y]^z;
	}
}
namespace T
{
	int D[N+5],f[N+5][LN+1];
	int h[N+5];int H(int x) {return h[x]?h[x]=H(h[x]):x;}
	void Init(int x=1)
	{
		int i,y;for(i=1;i<=LN;++i) f[x][i]=f[f[x][i-1]][i-1];
		for(i=lnk[x];i;i=e[i].nxt) (y=e[i].to)^f[x][0]&&(D[y]=D[f[y][0]=x]+1,Init(y),0);
	}
	void Mg(int x,int y)
	{
		#define Mg_(x,y) while(D[x=H(x)]>D[y]+1) U::U(f[x][0],x,0),h[x]=f[x][0]
		D[x]<D[y]&&(swap(x,y),0);int i,x0=x,y0=y;for(i=0;D[x]^D[y];++i) (D[x]^D[y])>>i&1&&(x=f[x][i]);
		if(x==y) {Mg_(x0,y);return;}for(i=0;f[x][i]^f[y][i];++i);for(--i;~i;--i) f[x][i]^f[y][i]&&(x=f[x][i],y=f[y][i]);
		Mg_(x0,f[x][0]);Mg_(y0,f[y][0]);U::U(x,y,1);
	}
}
int a[N+5],p[N+5],q[N+5],s[N+5][2];bool Chk(int u,int x=1,int lst=0)
{
	int i,y,f,c=0,F=U::fa(x),G=U::g[x];for(i=lnk[x];i;i=e[i].nxt) if(e[i].to^lst&&!Chk(u,e[i].to,x)) return false;
	for(i=lnk[x];i;i=e[i].nxt) (y=e[i].to)^lst&&(f=U::fa(y),p[f]=s[f][0]=s[f][1]=0);p[F]=0;
	for(i=lnk[x];i;i=e[i].nxt) (y=e[i].to)^lst&&(f=U::fa(y),!p[f]&&(p[q[++c]=f]=1),s[f][U::g[y]]=max(s[f][U::g[y]],a[y]));
	int m1=0,m2=0;for(i=1;i<=c;++i) q[i]^F&&(m1=max(m1,min(s[q[i]][0],s[q[i]][1])),m2=max(m2,max(s[q[i]][0],s[q[i]][1])));
	if(m1+m2+1>u) return false;if(!p[F]) return a[x]=m1+1,true;
	if(max(s[F][G],m1)+max(s[F][G^1],m2)+1<=u) return a[x]=max(s[F][G],m1)+1,true;
	if(max(s[F][G],m2)+max(s[F][G^1],m1)+1<=u) return a[x]=max(s[F][G],m2)+1,true;return false;
}
int w[N+5];void Col(int u,int x=1,int lst=0)
{
	int i,y,f,c=0,F=U::fa(x),G=U::g[x];w[x]=w[F]^G;
	for(i=lnk[x];i;i=e[i].nxt) (y=e[i].to)^lst&&(f=U::fa(y),p[f]=s[f][0]=s[f][1]=0);p[F]=0;
	for(i=lnk[x];i;i=e[i].nxt) (y=e[i].to)^lst&&(f=U::fa(y),!p[f]&&(p[q[++c]=f]=1),s[f][U::g[y]]=max(s[f][U::g[y]],a[y]));
	if(!p[F]) {for(i=1;i<=c;++i) w[q[i]]=w[x]^(s[q[i]][0]>s[q[i]][1]);}else
	{
		int m1=0,m2=0;for(i=1;i<=c;++i) q[i]^F&&(m1=max(m1,min(s[q[i]][0],s[q[i]][1])),m2=max(m2,max(s[q[i]][0],s[q[i]][1])));
		if(max(s[F][G],m1)+max(s[F][G^1],m2)+1<=u) for(i=1;i<=c;++i) q[i]^F&&(w[q[i]]=w[x]^(s[q[i]][0]>s[q[i]][1]));
		else for(i=1;i<=c;++i) q[i]^F&&(w[q[i]]=w[x]^(s[q[i]][0]<s[q[i]][1]));
	}
	for(i=lnk[x];i;i=e[i].nxt) e[i].to^lst&&(Col(u,e[i].to,x),0);
}
int d[N+5],v[N+5];vector<int> g[N+5];
void Topo()
{
	#define Add(x,y) (g[x].push_back(y),++d[y])
	int i;for(i=2;i<=n;++i) w[i]?Add(i,T::f[i][0]):Add(T::f[i][0],i);
	int k,H=1,T=0;for(i=1;i<=n;++i) !d[i]&&(v[q[++T]=i]=1);
	while(H<=T) {k=q[H++];for(auto y:g[k]) !--d[y]&&(v[q[++T]=y]=v[k]+1);}
	for(i=1;i<=n;++i) write(v[i]);
}
int main()
{
	int i,x,y;for(read(n,m),i=1;i^n;++i) read(x,y),add(x,y),add(y,x);T::Init();
	for(i=1;i<=m;++i) read(x,y),T::Mg(x,y);int l=1,r=n,u;while(l^r) Chk(u=l+r-1>>1)?r=u:l=u+1;
	return printf("%d\n",r),Chk(r),Col(r),Topo(),0; 
}