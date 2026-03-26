#include<bits/stdc++.h>
#define R(i,a,b) for(int i=(a),i##E=(b);i<=i##E;i++)
#define L(i,a,b) for(int i=(b),i##E=(a);i>=i##E;i--)
using namespace std;
int n,m;
vector<int>e[555555];
inline void ns()
{
	cout<<"-1"<<endl;
	exit(0);
}
struct dsu
{
	int fa[555555];
	bool v[555555];
	inline void clear()
	{
		R(i,1,n) fa[i]=i,v[i]=0;
	}
	int fnd(int x)
	{
		if(x==fa[x]) return x;
		int f=fa[x];
		fa[x]=fnd(fa[x]);
		v[x]^=v[f];
		return fa[x];
	}
	inline void mrg(int x,int y,int k)
	{
		//printf("mrg: x:%d y:%d k:%d\n",x,y,k);
		int fx=fnd(x),fy=fnd(y),t=v[x]^v[y]^k;
		if(fx==fy) 
		{
			if(t) ns();
		}
		else fa[fx]=fy,v[fx]=t;
	}
}dsu;
struct tree
{
	int hson[555555],htop[555555],dfn[555555],pos[555555],tim;
	int siz[555555],dep[555555],fa[555555];
	int v[555555],vv[555555];

	void dfs1(int u,int f)
	{
		siz[u]=1;
		int mx=-1;
		for(int v:e[u]) if(v^f)
		{
			fa[v]=u;dep[v]=dep[u]+1;
			dfs1(v,u);
			siz[u]+=siz[v];
			if(siz[v]>mx) hson[u]=v,mx=siz[v];
		}
	}
	void dfs2(int u,int topf)
	{
		dfn[u]=++tim;
		pos[tim]=u;
		htop[u]=topf;
		if(!hson[u]) return;
		dfs2(hson[u],topf);
		//printf("u:%d hson:%d\n",u,hson[u]);
		for(int v:e[u]) if(v^fa[u]&&v^hson[u]) dfs2(v,v);
	}
	inline int LCA(int x,int y)
	{
		while(htop[x]^htop[y])
		{
			if(dep[htop[x]]<dep[htop[y]]) swap(x,y);
			x=fa[htop[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
	int jmp(int x,int y)
	{
		while(1)
		{
			if(dep[htop[x]]<=dep[y]) return pos[dfn[y]+1];
			if(dep[htop[x]]==dep[y]+1) return htop[x];
			x=fa[htop[x]];
		}
		assert(0);
	}
	void ins(int x,int y)
	{
		int l_a=LCA(x,y);
		++v[x],++v[y],v[l_a]-=2;
		//printf("x:%d y:%d l_a:%d\n",x,y,l_a);
		if(dep[x]^dep[l_a]) ++vv[x],--vv[x=jmp(x,l_a)];
		if(dep[y]^dep[l_a]) ++vv[y],--vv[y=jmp(y,l_a)];
		if((x^l_a)&&(y^l_a)) dsu.mrg(x,y,1);
	}
	void mian()
	{
		L(i,1,n)
		{
			int x=pos[i];
			v[fa[x]]+=v[x],vv[fa[x]]+=vv[x];
			if(vv[x]) dsu.mrg(x,fa[x],0);
		}
	}
}tr;
int vis[555555],tim;
int dp[555555];
int vl[555555],vr[555555];
int rev[555555],s[555555];

inline int check(int k)
{
	deque<int>q;
	L(i,1,n)
	{
		int u=tr.pos[i],f=tr.fa[u];
		int l=0,r=0;
		++tim;
		for(int v:e[u]) if(v^f&&tr.v[v])
		{
			int fv=dsu.fa[v];
			if(vis[fv]!=tim) vis[fv]=tim,vl[fv]=vr[fv]=0,q.emplace_back(fv);
			if(!dsu.v[v]) vl[fv]=max(vl[fv],dp[v]);
			else vr[fv]=max(vr[fv],dp[v]);
		}
		int fv=dsu.fa[u];
		if(vis[fv]==tim)
		{
			l=vl[fv],r=vr[fv];
			if(dsu.v[u]) swap(l,r);
		}
		int mn=0,mx=0;
		while(q.size())
		{
			int x=q.front();
			q.pop_front();
			if(x!=fv)
			{
				if(vl[x]>vr[x]) swap(vl[x],vr[x]);
				mn=max(mn,vl[x]),mx=max(mx,vr[x]);
			}
		}
		if(max(mn,min(l,r))+max(mx,max(l,r))>=k) return 0;
		dp[u]=(max(mn,l)+max(mx,r)>=k?max(mx,l):max(mn,l))+1;
	}
	return 1;
}
void solve(int k)
{
	deque<int>q;
	R(i,1,n)
	{
		int u=tr.pos[i],f=tr.fa[u];
		++tim;
		for(int v:e[u]) if(v^f&&tr.v[v])
		{
			int fv=dsu.fa[v];
			if(vis[fv]!=tim) vis[fv]=tim,vl[fv]=vr[fv]=0,q.emplace_back(fv);
			if(!dsu.v[v]) vl[fv]=max(vl[fv],dp[v]);
			else vr[fv]=max(vr[fv],dp[v]);
		}
		while(q.size())
		{
			int x=q.front();
			q.pop_front();
			s[x]=rev[u];
			if(x!=dsu.fa[u]) s[x]^=((vl[x]>=dp[u])||(vr[x]+dp[u]>k));
			else s[x]^=dsu.v[u];
		}
		for(int v:e[u]) if(v^f&&tr.v[v]) rev[v]=s[dsu.fa[v]]^dsu.v[v];
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	R(i,1,n-1)
	{
		int x,y;
		cin>>x>>y;
		e[x].emplace_back(y),e[y].emplace_back(x);
	}
	dsu.clear();tr.dfs1(1,0);tr.dfs2(1,1);
	R(i,1,m)
	{
		int x,y;
		cin>>x>>y;
		tr.ins(x,y);
	}
	tr.mian();
	R(i,1,n) dsu.fnd(i);
	int l=1,r=n,ans=0;
	while(r-l>5)
	{
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	R(i,l,r) if(check(i)) 
	{
		ans=i;
		break;
	}
	cout<<ans<<endl;
	check(ans);
	solve(ans);
	R(i,1,n) cout<<((!rev[i])?dp[i]:ans+1-dp[i])<<" ";
	cout<<endl;

}