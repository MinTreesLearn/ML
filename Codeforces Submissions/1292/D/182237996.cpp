#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int const m=5000,M=10010;bool vis[M];vector<int> g[M],h[M];map<ull,int> mp;long long dp[M];
int i,j,n,x,v,tp,num,sum,Ans,Index,pri[670],cnt[M],c[M],d[M],head[M];queue<int> q;
struct node{
	int dep=0,num,x[670];ull Hash;
	node(){memset(x,0,sizeof(x));}	
}stk[M<<1];
int read(){
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x;
}
void Addedge(int u,int v,int w){g[u].push_back(v);h[u].push_back(w);d[u]++;}
void addedge(int u,int v,int w){Addedge(u,v,w);Addedge(v,u,w);}
node lca(node a,node b){ node c;
	for (int i=669;i>0;i--)
		if (a.x[i]!=b.x[i]){
			for (int j=i+1;j<670;j++)
				c.x[j]=a.x[j];
			c.x[i]=min(a.x[i],b.x[i]);
			for (int j=1;j<670;j++)
				c.dep+=c.x[j];
			return c;
		}
}
int dist(node a,node b){
	for (int i=669;i>0;i--)
		if (a.x[i]!=b.x[i]){
			int res=abs(a.x[i]-b.x[i]);
			for (int j=1;j<i;j++) res+=a.x[j]+b.x[j];
			return res; 
		}
}
ull Hash(node a){int hsh=0;
	for (int i=1;i<670;i++)
		hsh=hsh*2333333+a.x[i];
	if (!mp[hsh]) mp[hsh]=++Index;
	return mp[hsh];
}
bool Cmp(node a,node b){
	for (int i=1;i<670;i++)
		if (a.x[i]!=b.x[i])
			return 1;
	return 0;
}
void ins(int x,int val){ node s;
	for (int i=1;i<670;i++){
		for (int j=x/pri[i];j;j/=pri[i])
			s.x[i]+=j;
		s.dep+=s.x[i];
	} s.num=Hash(s);c[s.num]=val;
	if (!tp) {stk[tp=1]=s;return ;}
	node ance=lca(stk[tp],s);ance.num=Hash(ance);
	if (!Cmp(ance,s)) ance.num=s.num; 
	while (tp>1&&ance.dep<stk[tp-1].dep)
		addedge(stk[tp-1].num,stk[tp].num,dist(stk[tp-1],stk[tp])),tp--;
	if (ance.dep<stk[tp].dep) addedge(ance.num,stk[tp].num,dist(ance,stk[tp])),tp--;
	if (!tp||Cmp(stk[tp],ance)) stk[++tp]=ance; stk[++tp]=s;
}
int main(){
	sum=n=read();
	for (i=2;i<=m;i++){
		if (!vis[i]) pri[++num]=i;
		for (j=i<<1;j<=m;j+=i) vis[j]=1;
	}
	for (i=1;i<=n;i++) cnt[read()]++; cnt[1]+=cnt[0];
	for (i=1;i<=m;i++) if (i==1||cnt[i]) ins(i,cnt[i]);
	while (tp>1) addedge(stk[tp-1].num,stk[tp].num,dist(stk[tp-1],stk[tp])),tp--;
	for (n=Index,i=1;i<=n;i++) vis[i]=0;
	for (i=1;i<=n;i++)
		if (d[i]==1) 
			q.push(i),vis[i]=1;
	for (i=1;i<=n;i++)
	while (!q.empty()){
		x=q.front();q.pop();
		if (c[x]>sum/2) {Ans=x;continue;}
		for (i=0;i<g[x].size();i++){
			c[v=g[x][i]]+=c[x];dp[v]+=dp[x]+1ll*c[x]*h[x][i];
			if (!vis[v]&&--d[v]==1) q.push(v),vis[v]=1;
		}
	}
	printf("%lld\n",dp[Ans]);
	return 0;
} 