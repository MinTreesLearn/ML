#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int _=100,inf=1e9;
int S,T,n,m,Q,head[_],ne[_*_],to[_*_],w[_*_],c[_*_],tot=1,x;
int dis[_],vis[_],p[_];
vector<pair<int,int>>ans;
void add(int x,int y,int z,int a){
	ne[++tot]=head[x],head[x]=tot,to[tot]=y,w[tot]=z,c[tot]=a;
}
void ad(int x,int y,int z){
	add(x,y,1,z),add(y,x,0,-z);
}
bool bfs(){
	for(int i=1;i<=n;i++)dis[i]=inf,vis[i]=0;
	queue<int>q;q.push(S),vis[S]=1,dis[S]=0;
	while(q.size()){
		int u=q.front();q.pop(),vis[u]=0;
		for(int i=head[u];i;i=ne[i])
			if(w[i]&&dis[to[i]]>dis[u]+c[i]){
				dis[to[i]]=dis[u]+c[i],p[to[i]]=i;
				if(!vis[to[i]])vis[to[i]]=1,q.push(to[i]);
			}
	}
	return dis[T]!=inf;
}
void EK(){
	int flow=0,cost=0;
	while(bfs()){
		int f=inf;
		for(int i=T;i!=S;i=to[p[i]^1])f=min(f,w[p[i]]);
		flow+=f,cost+=dis[T]*f;
		for(int i=T;i!=S;i=to[p[i]^1])w[p[i]]-=f,w[p[i]^1]+=f;
		ans.push_back({flow,cost});
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,y,z;i<=m;i++)
		scanf("%d%d%d",&x,&y,&z),ad(x,y,z);
	S=1,T=n;EK();
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&x);
		long double Min=inf;
		for(auto v:ans)Min=min(Min,(long double)(v.se+x)/v.fi);
		printf("%.10Lf\n",Min);
	}
	return 0;
}

	  				  	 	 	   	 	  	