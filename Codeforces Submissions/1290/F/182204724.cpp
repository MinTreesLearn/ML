// LUOGU_RID: 95129357
#include<bits/stdc++.h>
using namespace std;
const int N=6,M=20,mod=998244353;
int n,m,lim,ans,dx[N],dy[N];
int nx[32],px[32],ny[32],py[32];
int f[32][M][M][M][M][2][2];
void check(int &x){x-=mod,x+=x>>31&mod;}
int main(){
	cin>>n>>m,lim=(1<<n)-1;
	for(int i=0;i<n;++i) cin>>dx[i]>>dy[i];
	for(int i=0;i<=lim;++i)
		for(int j=0;j<n;++j)
			if((i>>j)&1){
				(dx[j]>0?nx:px)[i]+=abs(dx[j]);
				(dy[j]>0?ny:py)[i]+=abs(dy[j]);
			}
	f[0][0][0][0][0][0][0]=1;
	for(int t=0;t<=30;++t)
	for(int i=0;i<=nx[lim];++i)
	for(int j=0;j<=px[lim];++j)
	for(int k=0;k<=ny[lim];++k)
	for(int l=0;l<=py[lim];++l)
	for(int a:{0,1})
	for(int b:{0,1})
		for(int s=0;s<=lim;++s)
			if(!((i+nx[s]+j+px[s])&1)&&!((k+ny[s]+l+py[s])&1)){
				check(f[t+1]
					[i+nx[s]>>1]
					[j+px[s]>>1]
					[k+ny[s]>>1]
					[l+py[s]>>1]
					[(a+(i+nx[s]&1))>(m>>t&1)]
					[(b+(k+ny[s]&1))>(m>>t&1)]
					+=f[t][i][j][k][l][a][b]);
			}
	ans=f[31][0][0][0][0][0][0]-1+mod;
	cout<<ans%mod;
	return 0;
}