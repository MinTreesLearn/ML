// LUOGU_RID: 101764554
//#pragma GCC optimize(3)
#include<iostream>
#include<climits>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<complex>
#include<random>
#include<chrono>
#define int long long
//#define double long double
#define invert dsfsdf
using namespace std;
const long long INF=LLONG_MAX/4ll;
const long long mod=998244353;
const long long mod2=1000009;
const long long mod3=924844033;
const double Pai=acos(-1);
map< pair<int,pair<int,int> >,int> mp;
int n,cnt=0,sign=0,ans=INF;
int pri[1000005],a[1000005],h[1000005],vt[1000005],t[1000005],ct[1000005],pos[1000005],sta[1000005],d[1000005];
int sum[30005][705],num[30005][705];
int N=5000;
struct edge {
	int from,to,next,v;
}e[100005];
void addedge(int x,int y,int z) {
	e[++cnt]={x,y,h[x],z},h[x]=cnt;
	swap(x,y);
	e[++cnt]={x,y,h[x],z},h[x]=cnt;
}
int qp(int x,int y) {
	int res=1;
	while(y) {
		if(y&1) y--,res*=x,res%=mod3;
		y>>=1,x*=x,x%=mod3;
	}
	return res;
}
void init() {
	for(int i=1;i<=N;i++) {
		int sq=sqrt(i),fg=1;
		for(int j=2;j<=sq;j++) if(i%j==0) fg=0;
		if(fg) pri[++pri[0]]=i;
	}
	sum[1][1]=1;
	for(int i=2;i<=N;i++) {
		for(int j=1;j<=pri[0];j++) sum[i][j]=sum[i-1][j];
		int x=i;
		for(int j=2;j<=pri[0];j++) {
			while(x%pri[j]==0) x/=pri[j],sum[i][j]++;
		}
	}
	for(int i=1;i<=N;i++) {
		int sm=0,sm2=0,sm3=1;
//		cout<<i<<endl;
		for(int j=pri[0];j>=1;j--) /*cout<<pri[j]<<" "<<sum[i][j]<<"\n",*/num[i][j]=sum[i][j],ct[i]+=sum[i][j],sm+=pri[j]*sum[i][j]%mod,sm%=mod,sm2^=pri[j]^sum[i][j],sm2%=mod2,sm3*=qp(pri[j],sum[i][j]),sm3%=mod3;
		mp[{sm3,{sm,sm2}}]=i;
//		cout<<sm3<<"\n";
	}
}
int LCA(int x,int y) {
	sign++;
	for(int i=pri[0];i>=1;i--) {
		if(num[x][i]!=num[y][i]) {
			num[sign][i]=min(num[x][i],num[y][i]);
			for(int j=i-1;j>=1;j--) num[sign][j]=0;
			break;
		}
		else num[sign][i]=num[x][i];
	}
	num[sign][1]=1;
	int sm=0,sm2=0,sm3=1;
	for(int i=pri[0];i>=1;i--) ct[sign]+=num[sign][i],sm+=pri[i]*num[sign][i]%mod,sm%=mod,sm2^=pri[i]^num[sign][i],sm2%=mod2,sm3*=qp(pri[i],num[sign][i]),sm3%=mod3;
	if(mp[{sm3,{sm,sm2}}]) {
		ct[sign]=0,sign--;
		return mp[{sm3,{sm,sm2}}];
	}
//	cout<<sm<<" "<<sm2<<" "<<sm3<<endl;
//	for(int i=pri[0];i>=1;i--) cout<<num[x][i]<<" ";puts("");
//	for(int i=pri[0];i>=1;i--) cout<<num[y][i]<<" ";puts("");
//	for(int i=pri[0];i>=1;i--) cout<<num[sign][i]<<" ";puts("");
	return mp[{sm3,{sm,sm2}}]=sign;
}
bool cmp(int x,int y) {
	for(int i=1;i<=pri[0];i++) {
		if(num[x][i]>num[y][i]) return 0;
		if(num[x][i]<num[y][i]) return 1;
	}
	return 0;
}
int calc(int x,int y) {
	return ct[y]-ct[x];
}
void Build() {
	sort(vt+1,vt+N+1);
	int tp=1;
	sta[tp]=1,h[1]=0,cnt=0;
	for(int i=1;i<=N;i++) {
		if(vt[i]==1) continue;
		int lca=LCA(vt[i],sta[tp]);
		if(lca!=sta[tp]) {
			while(cmp(lca,sta[tp-1])) addedge(sta[tp-1],sta[tp],calc(sta[tp-1],sta[tp])),tp--;
			if(!cmp(lca,sta[tp-1])) addedge(lca,sta[tp],calc(lca,sta[tp])),sta[tp]=lca;
			else addedge(lca,sta[tp--],calc(lca,sta[tp--]));
		}
		sta[++tp]=vt[i];
	}
	for(int i=1;i<tp;i++) addedge(sta[i],sta[i+1],calc(sta[i],sta[i+1]));
}
void dfs(int s,int fa,int dep) {
	d[s]=dep;
	for(int i=h[s];i;i=e[i].next) {
		int y=e[i].to;
		if(y==fa||y==s) continue;
//		cout<<s<<" "<<y<<endl;
		dfs(y,s,dep+e[i].v);
	}
}
signed main() {
	scanf("%lld",&n);sign=N;
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		if(a[i]==0) a[i]=1;
		t[a[i]]++;
	}
	for(int i=1;i<=N;i++) vt[i]=i;
	init();
	Build();
//	for(int i=1;i<=cnt;i++) {
//		cout<<e[i].from<<" "<<e[i].to<<" "<<e[i].v<<endl;
//	}
	for(int i=1;i<=sign;i++) {
		int res=0;
		dfs(i,0,0);
		for(int j=1;j<=N;j++) res+=t[j]*d[j]/*,cout<<d[j]<<" "*/;
//		for(int j=1;j<=sign;j++) vis[j]=0;
//		cout<<res<<endl;
		ans=min(ans,res);
	}
//	for(int i=1;i<=sign;i++) {
//		int res=1;
//		for(int j=pri[0];j>=1;j--) res*=qp(pri[j],sum[i][j]),res%=mod3;
//		cout<<res<<endl;
//	}
	printf("%lld",ans);
	return 0;
}