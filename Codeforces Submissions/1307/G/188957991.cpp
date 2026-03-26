#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007 
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,m,q;
long long f[60];
vector<pair<pair<int,int>,pair<int,int> > > g[60];
int dist[60],pre[60],edge[60],vis[60];

inline void add_edge(int x,int y,int c,int num)
{
	g[x].push_back(make_pair(make_pair(y,c),make_pair(num,g[y].size())));
	g[y].push_back(make_pair(make_pair(x,0),make_pair(-num,g[x].size()-1)));
}

inline int min_cost_flow(int f)
{
	int res=0;
	while(f>0){
		for(int i=1;i<=n;i++) dist[i]=INF;
		dist[1]=0;
		queue<int> q;
		q.push(1);vis[1]=1;
		while(!q.empty()){
			int u=q.front();q.pop();vis[u]=0;
			for(int i=0;i<(int)g[u].size();i++){
				pair<pair<int,int>,pair<int,int> > e=g[u][i];
				if(e.first.second>0&&dist[e.first.first]>dist[u]+e.second.first){
					dist[e.first.first]=dist[u]+e.second.first;
					pre[e.first.first]=u;
					edge[e.first.first]=i;
					if(!vis[e.first.first]){
						vis[e.first.first]=1;
						q.push(e.first.first);
					}
				}
			}
		}
		if(dist[n]==INF) return -1;
		int flow=f;
		for(int i=n;i!=1;i=pre[i]){
			flow=min(flow,g[pre[i]][edge[i]].first.second);
		}
		f-=flow;
		res+=flow*dist[n];
		for(int i=n;i!=1;i=pre[i]){
			g[pre[i]][edge[i]].first.second-=flow;
			g[i][g[pre[i]][edge[i]].second.second].first.second+=flow;
		}
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,w;cin>>x>>y>>w;
		add_edge(x,y,1,w);
	}
	int pos=n;f[0]=0ll;
	for(int i=1;i<=n;i++){
		int now=min_cost_flow(1);
		if(now==-1){
			pos=i-1;break;
		}
		f[i]=f[i-1]+1ll*now;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		int x;cin>>x;
		double ans=(f[1]+1ll*x)*1.0;
		for(int j=2;j<=pos;j++) ans=min(ans,(f[j]+1ll*x)*1.0/j);
		cout<<fixed<<setprecision(10)<<ans<<'\n';
	}
	return 0;
}
