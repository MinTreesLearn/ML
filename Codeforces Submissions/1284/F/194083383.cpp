#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 250100
ll n;
ll du[N]; 
queue<ll>q;
ll v[N<<1],fir[N],nxt[N<<1],cnt=0; 
inline void add(ll x,ll y){
	v[++cnt]=y;nxt[cnt]=fir[x];fir[x]=cnt;
	return ;
}
bool vis[N];
ll fa[N];
inline ll getf(ll x){
	if(fa[x]==x)return x;
	return fa[x]=getf(fa[x]);
}
ll faa[19][N],dep[N];
inline void dfs(ll x,ll ff){
	faa[0][x]=ff;dep[x]=dep[ff]+1;
	for(int i=1;i<=18;i++)faa[i][x]=faa[i-1][faa[i-1][x]];
	for(int i=fir[x];i;i=nxt[i]){
		ll vi=v[i];if(vi==ff)continue;
		dfs(vi,x);
	}return ;
}
inline ll lca(ll x,ll y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=18;i>=0;i--)if(dep[faa[i][x]]>=dep[y])x=faa[i][x];
	if(x==y)return x;
	for(int i=18;i>=0;i--)if(faa[i][x]!=faa[i][y])x=faa[i][x],y=faa[i][y];
	return faa[0][x];
}
inline ll gt(ll x,ll y){
	ll nw=x;
	for(int i=0;i<=18;i++){
		if(y&(1<<i))nw=faa[i][nw];
	}return nw;
}
inline void del(ll x,ll y){
	ll o=lca(x,y);
	if(getf(o)==x){
		ll p=dep[y]-dep[o];
		ll l=0,r=p,mid,an;
		while(l<=r){
			mid=(l+r)>>1;
			if(getf(gt(y,mid))==x)an=mid,r=mid-1;
			else l=mid+1;
		}ll g=gt(y,an),u=gt(y,an-1);
		cout<<g<<' '<<u;fa[x]=u;
	}else{
		ll nw=x;
		for(int i=18;i>=0;i--){
			if(getf(faa[i][nw])==x)nw=faa[i][nw];
		}cout<<nw<<' '<<faa[0][nw];
		ll g=getf(faa[0][nw]);
		fa[x]=g;
	}
	cout<<' '<<x<<' '<<y<<'\n' ;
	return ;
}
vector<ll>e[N];
int main()
{
//	freopen("test1.in","r",stdin);
	//freopen(".in","r",stdin);
	//freopen("test1.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;for(int i=1;i<=n;i++)fa[i]=i;cout<<n-1<<'\n'; 
	for(int i=1;i<n;i++){
		ll u,v;cin>>u>>v;add(u,v);add(v,u);
	}for(int i=1;i<n;i++){
		ll u,v;cin>>u>>v;du[u]++;du[v]++;e[u].push_back(v);e[v].push_back(u);
	}for(int i=1;i<=n;i++)if(du[i]==1)q.push(i);
	dfs(1,0);
	while(!q.empty()){
		ll o=q.front();q.pop();vis[o]=1;
		for(auto vi:e[o]){
			if(vis[vi])continue;
			del(o,vi);
			du[vi]--;if(du[vi]==1)q.push(vi);			
		} 
	}
	return 0;
}
