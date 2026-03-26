// LUOGU_RID: 101683611
//This code is written by Hmz(Hmz is cute!!!)
#include<bits/stdc++.h>
using namespace std;
#define TY int
#define mod (TY)(1e9+7)
#define MAXN 55
#define MAXM 20005
#define MAXK 27
#define For(i,a,b) for(TY i=(a);i<=(b);++i)
#define FOR(i,a,b) for(TY i=(a);i<(b);++i)
#define Rof(i,a,b) for(TY i=(a);i>=(b);--i)
#define ROF(i,a,b) for(TY i=(a);i>(b);--i)
inline TY qr(){
	TY x=0,f=1;char op=getchar();
	for(;op<'0'||op>'9';op=getchar())if(op=='-')f=-1;
	for(;op>='0'&&op<='9';op=getchar())x=x*10+(op^48);
	return x*f;
}inline char getc(){
    char op=getchar();
    while(op==' '||op=='\n'||op=='\r')op=getchar();
	return op;
}inline string qs(){
	string op="";char u=getchar();
	while(u=='\n'||u=='\r'||u==' ')u=getchar();
	while(u!='\n'&&u!='\r'&&u!=' ')op+=u,u=getchar();
	return op;
}inline void qw(TY x){
	if(!x){putchar('0');return;}
	if(x<0)putchar('-'),x=-x;
	if(x>=10)qw(x/10);putchar(x%10+'0');
}inline void qw(TY x,char op){qw(x),putchar(op);}
inline void ws(string s){FOR(i,0,s.size())putchar(s[i]);}
inline TY Ceil(TY a,TY b){return a/b+(a%b!=0);}
inline TY Mod(TY a){return (a>=mod?a-mod:a);}
inline TY Pow(TY a,TY b){
	TY ans=1,base=a;
	while(b){
		if(b&1)ans=ans*base%mod;
		base=base*base%mod;b>>=1;
	}return ans;
}TY n,m,k,ans,val[MAXN][MAXM],tree[MAXM<<2],tag[MAXM<<2],dp[MAXN][MAXM];
inline void push_down(TY now){
	tree[now<<1]+=tag[now],tree[now<<1|1]+=tag[now];
	tag[now<<1]+=tag[now],tag[now<<1|1]+=tag[now];
	tag[now]=0;
}void build(TY deep,TY now,TY l,TY r){
	tag[now]=0;
	if(l==r){tree[now]=dp[deep][l];return;}
	TY mid=(l+r)>>1;
	build(deep,now<<1,l,mid);build(deep,now<<1|1,mid+1,r);
	tree[now]=max(tree[now<<1],tree[now<<1|1]);
}void update(TY now,TY l,TY r,TY x,TY y,TY w){
	if(l>y||r<x)return;
	if(x<=l&&r<=y){tree[now]+=w;tag[now]+=w;return;}
	push_down(now);TY mid=(l+r)>>1;
	update(now<<1,l,mid,x,y,w);update(now<<1|1,mid+1,r,x,y,w);
	tree[now]=max(tree[now<<1],tree[now<<1|1]);
}int main(){
	n=qr();m=qr();k=qr();
	For(i,1,n)For(j,1,m)val[i][j]=qr();
	For(i,2,n+1){
		build(i-1,1,1,m);
		TY l=1,r=0,sum=0;while(r<=m){
			if(r-l+1<k){
				++r;sum+=val[i][r]+val[i-1][r];
				if(i!=2)update(1,1,m,max(1,r-k+1),r,-val[i-1][r]);
			}else{
				dp[i][l]=sum+tree[1];if(i==n+1)ans=max(ans,dp[i][l]);
				if(i==n+1)ans=max(ans,dp[i][l]);
				sum-=val[i][l]+val[i-1][l];
				if(i!=2)update(1,1,m,max(1,l-k+1),l,val[i-1][l]);++l;
				++r;sum+=val[i][r]+val[i-1][r];
				if(i!=2)update(1,1,m,max(1,r-k+1),r,-val[i-1][r]);
			}
		}
	}qw(ans);
    return 0;
}//zhushi