#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<utility>
#include<queue>
#include<stack>
#include<map>
struct edge{int x,y,d;edge(int x=0,int y=0,int d=0){this->x=x,this->y=y,this->d=d;}};
struct tree
{
	std::vector<int> a[200005];
	int n,rt,dep[200005],fa[200005],sz[200005],son[200005],top[200005],g[200005],cnt;
	static int id[200005];
	void add(int x,int y)
	{
		a[x].push_back(y);
		a[y].push_back(x);
	}
	void dfs1(int v,int d)
	{
		sz[v]=1;dep[v]=d;son[v]=0;
		for (int i=0;i<(int)a[v].size();i++)
		{
			int u=a[v][i];
			if (u==fa[v]) continue;
			fa[u]=v;
			dfs1(u,d+1);
			sz[v]=sz[v]+sz[u];
			if (sz[son[v]]<sz[u]) son[v]=u; 
		}
	}
	void dfs2(int v,int k)
	{
		id[v]=++cnt;top[v]=k;
		if (son[v]) dfs2(son[v],k);
		for (int i=0;i<(int)a[v].size();i++)
		{
			int u=a[v][i];
			if (u==fa[v]||u==son[v]) continue;
			dfs2(u,u);
		}
	}
	void pre(int nn,int x=1)
	{
		rt=x;
		n=nn;cnt=0;
		fa[rt]=0;
		dfs1(rt,1);
		dfs2(rt,rt);
	}
	int lca(int x,int y)
	{
		while (top[x]!=top[y])
		{
			if (dep[top[x]]<dep[top[y]]) std::swap(x,y);
			x=fa[top[x]];
		}
		if (dep[x]<dep[y]) std::swap(x,y);
		return y;
	}
	static int cmp(int x,int y)
	{
		return id[x]<id[y];
	}
	std::vector<edge> solve(std::vector<int> s)
	{
#define rt 1
		std::sort(s.begin(),s.end(),cmp);
		std::vector<int> p;
		std::stack<int> st;
		std::vector<edge> e;
		st.push(rt);p.push_back(rt);
		for (int i=0;i<(int)s.size();i++)
		{
			int x=s[i],d=lca(st.top(),x);
			if (x==rt) continue;
			if (st.top()==d){st.push(x),p.push_back(x),g[x]=d;continue;}
			while (!st.empty())
			{
				int k=st.top();st.pop();
				if (st.empty()){st.push(k);st.push(x);p.push_back(x);break;}
				if (dep[st.top()]<=dep[d])
				{
					if (st.top()==d){st.push(x),p.push_back(x),g[x]=d;break;}
					g[k]=d;
					g[d]=st.top(),st.push(d);p.push_back(d);
					g[x]=d,st.push(x),p.push_back(x);
					break;
				}
			}
		}
		for (int i=0;i<(int)p.size();i++) if (p[i]!=rt) e.push_back(edge(p[i],g[p[i]],dep[p[i]]-dep[g[p[i]]]));
		for (int i=0;i<(int)p.size();i++) g[p[i]]=0;
		return e;
#undef rt
	}
};
int tree::id[200005];
struct graph
{
	struct edge
	{
		int to,w;
		edge(int to=0,int w=0){this->to=to,this->w=w;}
	};
	struct node
	{
		int t,c,d,s;
		node(int t=0,int c=0,int d=0,int s=0){this->t=t,this->c=c,this->d=d,this->s=s;}
		int operator >(node x)
		{
			if (t!=x.t) return t>x.t;
			if (c!=x.c) return c>x.c;
			return s>x.s;
		}
		int operator <(node x)
		{
			if (t!=x.t) return t<x.t;
			if (c!=x.c) return c<x.c;
			return s<x.s;
		}
		node operator -()
		{
			node ret=*this;
			ret.t=-ret.t;
			return ret;
		}
		node operator +(int w)
		{
			node ret=*this;
			ret.d=ret.d+w;
			ret.t=(ret.d-1)/ret.s+1;
			return ret;
		}
	};
	int n,vis[200005];
	node dis[200005];
	std::vector<edge> a[200005];
	struct cmp
	{
		int operator()(std::pair<node,int> x,std::pair<node,int> y){return x.first>y.first;}
	};
	std::priority_queue< std::pair<node,int>,std::vector< std::pair<node,int> >,cmp > pq;
	void add(int x,int y,int s){a[x].push_back(edge(y,s));a[y].push_back(edge(x,s));}
	void make(int x,int c,int s){dis[x]=node(0,c,0,s);pq.push(std::make_pair(dis[x],x));}
	void dijkstra()
	{
		while (!pq.empty())
		{
			int v=pq.top().second;pq.pop();
			if (vis[v]) continue;vis[v]=1;
			for (int i=0;i<(int)a[v].size();i++)
			{
				int u=a[v][i].to,w=a[v][i].w;
				if (dis[v]+w<dis[u]) dis[u]=dis[v]+w,pq.push(std::make_pair(dis[u],u));
			}
		}
		while (!pq.empty()) pq.pop();
	}
	void clear(int s)
	{
		dis[s]=node(1000000000,-1,-1,-1);
		vis[s]=0;
		a[s].clear();
	}
	void pre(int n)
	{
		this->n=n;
		for (int i=1;i<=n;i++) dis[i]=node(1000000000,-1,-1,-1);
	}
};
graph g;
tree t;
int n,q,pt[200005],p[200005],d[200005];
std::map<int,int> mp;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		t.add(x,y);
	}
	t.pre(n);
	g.pre(n);
	scanf("%d",&q);
	while (q--)
	{
		std::vector<int> vec,used;
		int m,s;
		scanf("%d%d",&m,&s);
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&p[i],&d[i]);
			if (!mp[p[i]]) mp[p[i]]=1,vec.push_back(p[i]);
		}
		for (int i=1;i<=s;i++)
		{
			scanf("%d",&pt[i]);
			if (!mp[pt[i]]) mp[pt[i]]=1,vec.push_back(pt[i]);
		}
		std::vector<edge> e=t.solve(vec);
		used.push_back(1);
		for (int i=0;i<(int)e.size();i++)
		{
			int x=e[i].x,y=e[i].y,d=e[i].d;
			used.push_back(x);
			used.push_back(y);
			g.add(x,y,d);
		}
		for (int i=1;i<=m;i++) g.make(p[i],i,d[i]);
		g.dijkstra();
		for (int i=1;i<=s;i++) printf("%d ",g.dis[pt[i]].c);puts("");
		for (int i=0;i<(int)used.size();i++) g.clear(used[i]);
		for (int i=1;i<=m;i++) p[i]=d[i]=0;
		for (int i=1;i<=s;i++) pt[i]=0;
		mp.clear();
	}
	return 0;
}