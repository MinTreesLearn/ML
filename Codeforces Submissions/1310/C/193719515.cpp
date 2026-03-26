// LUOGU_RID: 102218004
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const long long INF=2e18;
int n,m,tot,len[N][N];
long long k,f[N][N];
char s[N];
struct Sub{
	int l,r,t;
	Sub(int _l=0,int _r=0){ l=_l, r=_r, t=r-l+1; }
}rcd[N*N];
inline bool cmp(Sub x,Sub y){
	int k=len[x.l][y.l];
	if(k<min(x.t,y.t)) return s[x.l+k]<s[y.l+k];
	return x.t<y.t;
}
inline bool Check(Sub sub){
	//cout<<"Check: ";
	//for(register int i=sub.l;i<=sub.r;++i) cout<<s[i];
	//cout<<'\n';
	int L=sub.l,R=sub.r;
	memset(f,0,sizeof(f)), f[0][0]=1, f[1][0]=-1;
	for(register int i=0;i<n;++i)
		for(register int j=0;j<=m;++j){
			if(!f[i][j]) continue;
			int x=min(sub.t,len[i+1][L]);
			if(x==sub.t){
				f[i+x][j+1]=min(INF,f[i+x][j+1]+f[i][j]);
				//for(register int k=i+x;k<=n;++k)
				//	f[k][j+1]=min(INF,f[k][j+1]+f[i][j]);
			}
			else if(s[i+x+1]>s[L+x]){
				f[i+x+1][j+1]=min(INF,f[i+x+1][j+1]+f[i][j]);
				//for(register int k=i+x+1;k<=n;++k)
				//	f[k][j+1]=min(INF,f[k][j+1]+f[i][j]);
			}
			f[i+1][j]=min(INF,f[i+1][j]+f[i][j]);
		}
	//cout<<"res: "<<f[n][m]<<'\n';
	return f[n][m]>=k;
}
inline Sub Find(){
	int l=0,r=tot+1,mid;
	while(l<r-1)
		mid=(l+r)>>1, Check(rcd[mid])?l=mid:r=mid;
	return rcd[l];
}
int main(){
	cin>>n>>m>>k;
	for(register int i=1;i<=n;++i) cin>>s[i];
	for(register int i=n;i>=1;--i)
		for(register int j=n;j>=1;--j)
			if(s[i]==s[j]) len[i][j]=len[i+1][j+1]+1;
	for(register int i=1;i<=n;++i)
		for(register int j=i;j<=n;++j)
			rcd[++tot]=Sub(i,j);
	sort(rcd+1,rcd+1+tot,cmp);
	/*
	for(register int i=1;i<=tot;++i){
		for(register int j=rcd[i].l;j<=rcd[i].r;++j) cout<<s[j];
		cout<<'\n';
	}
	*/
	Sub sub=Find();
	for(register int i=sub.l;i<=sub.r;++i) printf("%c",s[i]);
	putchar('\n');
	return 0;
}