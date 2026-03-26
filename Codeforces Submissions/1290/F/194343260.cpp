// LUOGU_RID: 102614426
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 11
#define yu (998244353)
ll n,m;
ll ans=0;
inline void add(ll &x,ll y){x+=y;if(x>=yu)x-=yu;return ;}
ll xi[6],yi[6];
ll f[31][22][22][22][22][2][2];
inline ll dfs(ll pos,ll x,ll fx,ll y,ll fy,ll x1,ll x2){
	if(pos==31){
		return ((x==0)&(fx==0)&(y==0)&(fy==0)&(x1==0)&(x2==0));
	}if(f[pos][x][fx][y][fy][x1][x2]!=-1)return f[pos][x][fx][y][fy][x1][x2];
	ll an=0;
	for(int i=0;i<(1<<n);i++){
		ll jix=0,jifx=0,jiy=0,jify=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				if(xi[j]>0)jix+=xi[j];
				else jifx-=xi[j];
				if(yi[j]>0)jiy+=yi[j];
				else jify-=yi[j];
			} 
		}	
		jix+=x;jifx+=fx;jiy+=y;jify+=fy;
		if(((jix&1)!=(jifx&1))||((jiy&1)!=(jify&1)))continue;
		ll o=(m>>pos)&1;
		add(an,dfs(pos+1,jix>>1,jifx>>1,jiy>>1,jify>>1,((o==(jix&1))?x1:(o<(jix&1))),((o==(jiy&1))?x2:(o<(jiy&1))))); 
	}return f[pos][x][fx][y][fy][x1][x2]=an;
}
int main()
{
//	freopen("test1.in","r",stdin);
	//freopen(".in","r",stdin);
	//freopen("test1.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>xi[i]>>yi[i];
	}memset(f,-1,sizeof(f));
	cout<<(dfs(0,0,0,0,0,0,0)-1+yu)%yu;
	return 0;
}
