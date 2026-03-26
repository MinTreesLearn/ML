// LUOGU_RID: 94121184
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<random>
#include<assert.h>
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n'
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<ll,int>pli;
typedef pair<ll,ll>pll;
typedef pair<int,ll>pil;
typedef vector<int>vi;
typedef vector<ll>vll;
typedef vector<pii>vpii;
typedef vector<pil>vpil;
template<typename T>T cmax(T &x, T y){return x=x>y?x:y;}
template<typename T>T cmin(T &x, T y){return x=x<y?x:y;}
template<typename T>
T &read(T &r){
	r=0;bool w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w=ch=='-'?1:0,ch=getchar();
	while(ch>='0'&&ch<='9')r=r*10+(ch^48),ch=getchar();
	return r=w?-r:r;
}
template<typename T1,typename... T2>
void read(T1 &x,T2& ...y){read(x);read(y...);}
const int mod=998244353;
inline void cadd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
inline void cdel(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}
inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
inline int del(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
int bit(int x){
	return 1<<x;
}
int n,m;
int a[6],b[6];
int f[31][21][21][21][21][2][2];
int chk(int c,int k,int p){
	if(k==((m>>c)&1))return p;
	return (k>((m>>c)&1));
}
int dfs(int pos,int xpos,int xneg,int ypos,int yneg,int p,int q){
	if(pos==30)return !(xpos||xneg||ypos||yneg||p||q);
	int &now=f[pos][xpos][xneg][ypos][yneg][p][q];
	if(~now)
		return now;
	now=0;
	for(int S=0;S<(1<<n);S++){
		int xps=xpos,xng=xneg,yps=ypos,yng=yneg;
		for(int i=1;i<=n;i++)
			if(S&bit(i-1)){
				if(a[i]>0)xps+=a[i];
				else xng+=-a[i];
				if(b[i]>0)yps+=b[i];
				else yng+=-b[i];
			}
		if((xps&1)!=(xng&1) || (yps&1)!=(yng&1))continue;
		cadd(now,dfs(pos+1,xps>>1,xng>>1,yps>>1,yng>>1,chk(pos,xps&1,p),chk(pos,yps&1,q)));
	}
	return now;
}
signed main(){
	#ifdef do_while_true
//		assert(freopen("data.in","r",stdin));
//		assert(freopen("data.out","w",stdout));
	#endif
	read(n,m);
	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)read(a[i],b[i]);
	cout << del(dfs(0,0,0,0,0,0,0),1) << '\n';
    #ifdef do_while_true
		cerr<<'\n'<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC*1000<<" ms"<<'\n';
	#endif
	return 0;
}