// LUOGU_RID: 91777092
#include<cmath>
#include<cstdio>
#include<bitset>
#include<iostream>
#include<algorithm>
#include<queue> 
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<random>
#include<ctime>
#include<unordered_map>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pp pair<int,int>
#define LL long long
#define ull unsigned long long
namespace IO{
	const int sz=1<<22;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	inline char gc(){
	//	return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
		return getchar();
	}
	template<class T> void gi(T& x){
		x=0; int f=1;char c=gc();
		if(c=='-')f=-1;
		for(;c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(;c>='0'&&c<='9';c=gc())
			x=x*10+(c-'0');
		x=x*f;
	}
	inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
	template<class T> void pi(T x,char c='\n'){
		if(x<0)pc('-'),x=-x;
		if(x==0) pc('0'); int t=0;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
	}
	struct F{~F(){flush();}}f; 
}
using IO::gi;
using IO::pi;
using IO::pc;
const int mod=1e9+7;
inline int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
inline int dec(int x,int y){
	return x-y<0?x-y+mod:x-y;
}
int qkpow(int a,int b){
	int ans=1,base=a%mod;
	while(b){
		if(b&1)ans=1ll*ans*base%mod;
		base=1ll*base*base%mod;
		b>>=1;
	}
	return ans;
}
int fac[10000005],inv[10000005],Invn[600005];
inline int C(int n,int m){
	if(n<m||m<0)return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void init_C(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod; 
	inv[0]=1;
	inv[n]=qkpow(fac[n],mod-2);
	for(int i=n-1;i>=1;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	Invn[0]=Invn[1]=1;
	for(int i=1;i<=200000;i++)Invn[i]=(LL)(mod-mod/i)*Invn[mod%i]%mod;
}
int n,m,a[2005],b[2005],c[4005],dp[4005][4005],val[4005][4005];
const int INF=-1e9;
struct bittree{
	int t[4005];
	int lowbit(int x){
		return x&-x;
	}
	void init(){
		for(int i=1;i<=n+m;i++)t[i]=INF;
	}
	void add(int x,int v){
		while(x<=+m){
			t[x]=max(t[x],v);
			x+=lowbit(x);
		}
	}
	int query(int x){
		int res=INF;
		while(x>=1){
			res=max(res,t[x]);
			x-=lowbit(x);
		}
		return res;
	}
}T;
signed main(){
	gi(n),gi(m);
	for(int i=1;i<=n;i++)gi(a[i]);
	T.init();
	for(int i=1;i<=n;i++)gi(b[i]);
	for(int i=1;i<=n+m;i++)gi(c[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=val[i][j]=INF;
	for(int i=n;i>=1;i--){
		int fk=T.query(a[i]-1);
		dp[i][1]=max(dp[i][1],c[a[i]]-b[i]+max(fk,0));
		for(int j=1;j<=n;j++)
			if(val[a[i]][j]!=INF)dp[i][j]=max(dp[i][j],val[a[i]][j]+c[a[i]]-b[i]);
		for(int j=1;j<=n;j++){
			if(dp[i][j]!=INF){
				int now=a[i],gs=j,res=0;
				val[now][gs+1]=max(val[now][gs+1],dp[i][j]);
				while(gs){
					res+=gs/2*c[now+1];
					gs/=2,now++;
					val[now][gs+1]=max(val[now][gs+1],dp[i][j]+res);
				}
				T.add(now,dp[i][j]+res);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]!=INF){
				int now=a[i],gs=j,res=0;
				while(gs){
					res+=gs/2*c[now+1];
					gs/=2,now++;
				}
				ans=max(ans,res+dp[i][j]);
			}
		}
	}
	pi(ans,'\n');
	return 0;
} 
/*
4 3 1 1
*/