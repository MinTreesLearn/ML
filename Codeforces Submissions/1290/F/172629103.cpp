#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0' or ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' and ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
const int mod = 998244353;
int n,m;
int x[5],y[5];
int dp[32][22][22][22][22][2][2];
void add(int &x,int y){x=(x+y)%mod;};
int get(int x,int y,int z){return (x^y)?y>x:z;}
int dfs(int p,int a,int b,int c,int d,int f1,int f2){
	if((1ll<<p)>m) return (!a and !b and !c and !d and !f1 and !f2);
	if(dp[p][a][b][c][d][f1][f2]>=0) return dp[p][a][b][c][d][f1][f2];
	int g=(m>>p)&1,res = 0;
	for(int s=0;s<(1<<n);s++){
		for(int i = 0;i<n;i++)
			if((s>>i)&1) (x[i]>0?a+=x[i]:b-=x[i]),(y[i]>0?c+=y[i]:d-=y[i]);
		if((a&1)==(b&1) and (c&1)==(d&1)) add(res,dfs(p+1,a>>1,b>>1,c>>1,d>>1,get(g,a&1,f1),get(g,c&1,f2)));
		for(int i = 0;i<n;i++)
			if((s>>i)&1) (x[i]>0?a-=x[i]:b+=x[i]),(y[i]>0?c-=y[i]:d+=y[i]);
	}
	return dp[p][a][b][c][d][f1][f2]=res;
}
signed main(){
	// freopen("T.in","r",stdin);
	// freopen("T.out","w",stdout);
	n = read(),m = read(),memset(dp,0x80,sizeof(dp));
	for(int i = 0;i<n;i++) x[i] = read(),y[i] = read();
	write((dfs(0,0,0,0,0,0,0)+mod-1)%mod);
	return 0;
}