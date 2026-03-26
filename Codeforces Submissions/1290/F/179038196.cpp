// LUOGU_RID: 92655356
#include<bits/stdc++.h>
#define fi(s) freopen(s".in","r",stdin)
#define fo(s) freopen(s".out","w",stdout)
#define file(s) fi(s),fo(s)
using namespace std;
namespace tomorinao {char arrs;
typedef long long ll;
const int mod = 998244353;
int MOD(int x) {return x>=mod?x-mod:x;}
int f[31][25][25][25][25][2][2],w[31],n,m,X[5],Y[5];
int fin(int x,int zx,int zy,int fx,int fy,int lzx,int lzy) {
	if(x==w[0]+1) return !zx&&!zy&&!fx&&!fy&&lzx&&lzy;
	int&r=f[x][zx][zy][fx][fy][lzx][lzy];if(~r) return r;r=0;
	for(int S=0;S<1<<n;S++) {
		int nzx=zx,nzy=zy,nfx=fx,nfy=fy;
		for(int i=0;i<n;i++) if(S>>i&1) {
			if(X[i]>0) nzx+=X[i];else nfx-=X[i];
			if(Y[i]>0) nzy+=Y[i];else nfy-=Y[i];
		}
		if((nzx&1)^(nfx&1)||(nzy&1)^(nfy&1)) continue;
		r=MOD(r+fin(x+1,nzx>>1,nzy>>1,nfx>>1,nfy>>1,(nzx&1)<w[x]?1:(nzx&1)==w[x]?lzx:0,(nzy&1)<w[x]?1:(nzy&1)==w[x]?lzy:0));
	}	return r;
}
char arre;void Main() {
	cerr<<fixed<<setprecision(1)<<(((&arre)-(&arrs))/1024./1024.)<<'\n';
	cin>>n>>m,memset(f,-1,sizeof(f));
	for(int i=0;i<n;i++) cin>>X[i]>>Y[i];
	while(m) w[++w[0]]=m&1,m>>=1;
	cout<<MOD(fin(1,0,0,0,0,1,1)+mod-1)<<'\n';
}}signed main() {tomorinao::Main();return 0;}
