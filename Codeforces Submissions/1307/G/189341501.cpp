// LUOGU_RID: 99917153
#include <deque>
#include <cstdio>
#include <cstring>
#include <algorithm>
using std :: swap;using std :: min;
namespace nagisa{
	const int maxn = 55,maxm = 2505,inf = 0x3f3f3f3f;
	int n,m,q,ans[maxn],F;
	struct MCMF{
		int head[maxn],tot;MCMF(){tot = 1;}
		struct Edge{int next,to,cap,val;}e[maxm<<1];
		void ade(int x,int y,int z,int w){
			e[++tot] = (Edge){head[x],y,z,w},head[x] = tot;
			e[++tot] = (Edge){head[y],x,0,-w},head[y] = tot;
		}
		int dis[maxn],vis[maxn],pre[maxn],eid[maxn];
		bool spfa(){
			std :: deque <int> q;memset(dis,0x3f,sizeof(dis));
			dis[1] = 0,vis[1] = 1,q.push_back(1);
			#define SWAP if(q.size()>=2&&dis[q.front()]>dis[q.back()])swap(q.front(),q.back())
			while(!q.empty()){
				int u = q.front();q.pop_front(),vis[u] = 0;SWAP;
				for(int i=head[u],v;v=e[i].to,i;i=e[i].next){
					if(e[i].cap && dis[v] > dis[u] + e[i].val){
						dis[v] = dis[u] + e[i].val,pre[v] = u,eid[v] = i;
						if(!vis[v]){vis[v] = 1;q.empty()||dis[q.front()]<dis[v]?q.push_front(v):q.push_back(v);SWAP;}
					}
				}
			}return dis[n]!=inf;
		}
		void gans(){
			while(spfa()){
				int p = n;for(;p^1;p=pre[p])e[eid[p]].cap = 0,e[eid[p]^1].cap = 1;
				ans[F+1] = ans[F] + dis[n],++F;
			}
		}
	}G;
	int main(){
		scanf("%d %d",&n,&m);
		for(int i=1,x,y,z;i<=m;++i)scanf("%d %d %d",&x,&y,&z),G.ade(x,y,1,z);
		G.gans(),scanf("%d",&q);
		for(int i=1,x;i<=q;++i){
			double t = 1e18;scanf("%d",&x);
			for(int j=1;j<=F;++j)t = min(t,1.*(x+ans[j])/j);printf("%.10lf\n",t);
		}
		return 0;
	}
}
int main(){return nagisa::main();}
