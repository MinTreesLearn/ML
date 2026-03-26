#include<bits/stdc++.h>
using namespace std;

namespace QSY{ // by OneZzz6174
const int SIZ = 1000000;
namespace IO{ // by OneZzz6174
#ifdef ONLINE_JUDGE
static char buf[SIZ],*A=buf,*B=buf;
#define getchar() A==B&&(B=(A=buf)+fread(buf,1,SIZ,stdin),A==B)?EOF:*A++
#endif
static char obuf[SIZ],*C=obuf;
#define putchar(x) (C-obuf<SIZ)?(*C++=x):(fwrite(obuf,C-obuf,1,stdout),C=obuf,*C++=x)
inline void flush(){fwrite(obuf,C-obuf,1,stdout),C=obuf;}
struct FLS{~FLS(){fwrite(obuf,C-obuf,1,stdout);}}fls;
inline int read(){
    register int x=0,f=1,c=getchar();
    for(;c<48||c>57;c=getchar())if(c=='-')f=-1;
    for(;c>47&&c<58;c=getchar())x=x*10+(c^48);
    return x*f;
}
inline void read(int &x){x=read();}
inline void read(char &c){do{c=getchar();}while(c==' '||c =='\n');}
inline int readc(){return getchar();}
template<typename Int>
inline void print(Int x){
    if(x<0)putchar(45),x=-x;
    if(x>9)print(x/10);putchar(x%10+48);
}
inline void print(char c){putchar(c);}
inline void print(const char *s){for(char *p = (char*)s;*p;++p)putchar(*p);}
template<typename _Tp,typename... _Args>
inline void read(_Tp& x,_Args&... args){read(x);read(args...);}
template<typename _Tp,typename... _Args>
inline void print(_Tp x,_Args... args){print(x);print(args...);}
}
using IO::read;using IO::readc;using IO::print;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define Rep(i,a,b) for(int i = (a);i >= (b);--i)
template<typename T>
T chkmax(T &a,T b){ return a = a > b ? a : b; }
template<typename T>
T chkmin(T &a,T b){ return a = a < b ? a : b; }
template<typename T,typename U>
T max(T a,U b){ return a > b ? a : b; }
template<typename T,typename U>
T min(T a,U b){ return a < b ? a : b; }
#define pb push_back
#define eb emplace_back
#define adde(G,u,v) G[u].pb(v),G[v].pb(u)
#define Adde(G,u,v,w) G[u].eb(v,w),G[v].eb(u,w)
using ll = long long;
const ll inf = 1e18;
} using namespace QSY;

const int N = 2e5 + 5;

int n,m,k,l,V[N],P[N],ft[N],s;
int p[N],t[N],q[N],id[N],stk[N],tp = 0;
int dep[N],siz[N],son[N],fa[N];
int dfn[N],top[N],idfn[N],tot = 0;
int dp[N],v[N]; vector<int> G[N],D;

void dfs1(int u = 1,int ft = 0){
	dep[u] = dep[fa[u] = ft] + 1; siz[u] = 1;
	for(int v : G[u]) if(v != ft){
		dfs1(v,u);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2(int u = 1,int t = 1){
	top[u] = t; idfn[dfn[u] = ++tot] = u;
	if(son[u]) dfs2(son[u],t);
	for(int v : G[u]) if(v != fa[u] && v != son[u]) dfs2(v,v);
}

int lca(int x,int y){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

int dis(int x,int y){
	int d = dep[x] + dep[y] - 2 * dep[lca(x,y)];
	return (d + t[x] - 1) / t[x];
}

void upd(int u,int &x,int y){
	if(!y || !u) return; if(!x) return void(x = y);
	int dx = dis(x,u),dy = dis(y,u);
	if(dx > dy || (dx == dy && id[x] > id[y])) x = y;
}

void init(){
	sort(P + 1,P + s + 1,[](int a,int b){return dfn[a] < dfn[b];});
	stk[tp = 1] = P[1];
	rep(i,2,s){
		int z = lca(stk[tp],P[i]);
		while(dep[z] < dep[stk[tp - 1]]){
			ft[stk[tp]] = stk[tp - 1];
			D.push_back(stk[tp - 1]); D.push_back(stk[tp]);
			--tp;
		}
		if(z != stk[tp]){
			ft[stk[tp]] = z;
			D.push_back(stk[tp]); D.push_back(z);
			stk[tp - 1] == z ? --tp : stk[tp] = z;
		}
		stk[++tp] = P[i];
	}
	while(--tp){
		ft[stk[tp + 1]] = stk[tp];
		D.push_back(stk[tp + 1]); D.push_back(stk[tp]);
	}
}

int main(){
	read(n);
	rep(i,1,n - 1){ int u,v; read(u,v),adde(G,u,v); }
	dfs1(); dfs2();
	read(m);
	while(m--){
		read(k,l); s = 0; D.clear();
		rep(i,1,k) id[p[i] = read()] = i,read(t[p[i]]),dp[p[i]] = p[i];
		rep(i,1,l) q[i] = read();
		rep(i,1,k) if(!V[p[i]]) V[P[++s] = p[i]] = 1,D.pb(p[i]);
		rep(i,1,l) if(!V[q[i]]) V[P[++s] = q[i]] = 1,D.pb(q[i]);
		init();
		sort(D.begin(),D.end(),[](int a,int b){ return dfn[a] < dfn[b]; });
		D.resize(unique(D.begin(),D.end()) - D.begin());
		reverse(D.begin(),D.end());
		for(int x : D) upd(ft[x],dp[ft[x]],dp[x]);
		reverse(D.begin(),D.end());
		for(int x : D) upd(x,dp[x],dp[ft[x]]);
		rep(i,1,l) print(id[dp[q[i]]],' '); print('\n');
		rep(i,1,s) V[P[i]] = 0;
		rep(i,1,k) id[p[i]] = 0,t[p[i]] = 0;
		for(int x : D) dp[x] = ft[x] = 0;
	}
	return 0;
} // 114514