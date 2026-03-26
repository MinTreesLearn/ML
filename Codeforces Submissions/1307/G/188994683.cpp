#include<bits/stdc++.h>
using namespace std; 
struct edge{
	int to,cap;
	int cst;
	int rev;
};
vector<edge>g[53];
void add_edge(int x,int y,int cap,int cst){
	g[x].push_back((edge){y,cap,cst,g[y].size()});
	g[y].push_back((edge){x,0,-cst,g[x].size()-1});
}
int prevv[53],preve[53];
int dist[53];
int min_cost_flow(int s,int t){
	int ret=0;
	while(1){
		memset(dist,31,sizeof(dist));
		priority_queue<pair<int,int> >Q;
		dist[s]=0;
		Q.push(make_pair(0,s));
		while(Q.size()){
			int len=-Q.top().first;
			int nw=Q.top().second;Q.pop();
			if(dist[nw]<len)continue;
			for(int i=0;i<g[nw].size();i++){
				edge &e=g[nw][i];
				if(e.cap>0&&dist[e.to]>dist[nw]+e.cst)
					dist[e.to]=dist[nw]+e.cst,
					prevv[e.to]=nw,preve[e.to]=i,
					Q.push(make_pair(-dist[e.to],e.to));
			}
		}
		if(dist[t]>=192608172)break;
		int f=1;
		for(int v=t;v!=s;v=prevv[v])
			f=min(f,g[prevv[v]][preve[v]].cap);
		ret+=1ll*f*dist[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e=g[prevv[v]][preve[v]];
			e.cap-=f,g[v][e.rev].cap+=f;
		}
		break;
	}return ret;
}int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	while(m--){
		int x,y,w;
		cin>>x>>y>>w;
		x--;y--;
		add_edge(x,y,1,w);
	}
	vector<int>v;
	while(1){
		int tmp=min_cost_flow(0,n-1);
		if(tmp)
			v.push_back(tmp);
		else
			break;
	}
	int q;
	cin>>q;
	while(q--){
		double ans=1e9,sum;
		int t;
		cin>>t;sum=t;
		for(int i=0;i<v.size();i++)
			sum+=v[i],
			ans=min(ans,sum/(i+1));
		cout<<fixed<<setprecision(10)<<ans<<'\n'; 
	}
}
