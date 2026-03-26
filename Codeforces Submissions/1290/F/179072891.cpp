// LUOGU_RID: 92701667
//No More Time, No More Chance.
#include <cstdio>
#include <cstring>
namespace KamiyamaShiki{
	const int mod = 998244353;
	int abs(int x){return x<0?-x:x;}
	int n,m,x[6],y[6],nxs[32],nys[32],pxs[32],pys[32];
	int dp[31][26][26][26][26][2][2];
	int DP(int dig,int nx,int ny,int px,int py,int bdx,int bdy){
		if(dig == 30)return (!nx&&!ny&&!px&&!py&&!bdx&&!bdy);
		int &r = dp[dig][nx][ny][px][py][bdx][bdy];if(~r)return r;
		r = 0;int md = (m>>dig)&1;
		for(int i=0;i<(1<<n);++i){
			int now[] = {(nx+nxs[i])&1,(ny+nys[i])&1,(px+pxs[i])&1,(py+pys[i])&1};
			int nxt[] = {(nx+nxs[i])/2,(ny+nys[i])/2,(px+pxs[i])/2,(py+pys[i])/2};
			if(now[0] == now[2] && now[1] == now[3])
				r = (r+DP(dig+1,nxt[0],nxt[1],nxt[2],nxt[3],(now[0]==md?bdx:now[0]>md),(now[1]==md?bdy:now[1]>md)))%mod;
		}
		return r;
	}
	int main(){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d %d",&x[i],&y[i]);
		for(int s=0;s<(1<<n);++s)
			for(int i=1;i<=n;++i)
				(x[i]<0?nxs:pxs)[s] += ((s>>i-1)&1)*abs(x[i]),
				(y[i]<0?nys:pys)[s] += ((s>>i-1)&1)*abs(y[i]);
		memset(dp,-1,sizeof(dp));
		return printf("%d\n",(DP(0,0,0,0,0,0,0)-1+mod)%mod),0;//È¥µô¿Õ¡£ 
	}
}
int main(){return KamiyamaShiki::main();}

