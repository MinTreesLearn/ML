#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e6+9;
int n,m,sz;
int id[M],c[M][26],b[M],t[M],dp[M],L[M],R[M],val[M];
bool vis[M],bo[M];
int Min(int x,int y){
	return id[x]<id[y]?x:y;
}
int Max(int x,int y){
	return id[x]>id[y]?x:y;
}
void dfs(int u){
	id[u]=++sz;
	L[u]=n+1,R[u]=0;
	if(vis[u]){
		L[u]=u;
		R[u]=u;
	}
	for(int i=0;i<26;++i){
		if(c[u][i]){
			dfs(c[u][i]);
			if(R[c[u][i]]){
				if(R[u]){
					L[u]=Min(L[u],L[c[u][i]]);
					R[u]=Max(R[u],R[c[u][i]]);
				}
				else L[u]=L[c[u][i]],R[u]=R[c[u][i]];
			}
		}
	}
}
struct Segment_tree{
    int vis[M<<2],sum[M<<2];
    void pd(int now,int l,int r){
        int &v=vis[now];
        if(v){
            int ls=now<<1,rs=now<<1|1;
            vis[ls]=min(vis[ls],v);
            vis[rs]=min(vis[rs],v);
            sum[ls]=min(sum[ls],v);
            sum[rs]=min(sum[rs],v);
            v=0;
        }
    }
    void pu(int now){
        sum[now]=min(sum[now<<1],sum[now<<1|1]);
    }
    void update(int now,int l,int r,int x,int y,int v){
        if(x>y)return;
        if(x<=l&&r<=y){
        	vis[now]=min(vis[now],v);
            sum[now]=min(sum[now],v);
            return;
        }
        pd(now,l,r);
        int mid=(l+r)>>1;
        if(x<=mid)update(now<<1,l,mid,x,y,v);
        if(y>mid)update(now<<1|1,mid+1,r,x,y,v);
        pu(now);
    }
    int query(int now,int l,int r,int x,int y){
        if(x>y)return 0;
        if(x<=l&&r<=y){
            return sum[now];
        }
        pd(now,l,r);
        int mid=(l+r)>>1;
        int rex=0;
        if(x<=mid)rex=min(rex,query(now<<1,l,mid,x,y));
        if(y>mid)rex=min(rex,query(now<<1|1,mid+1,r,x,y));
        return rex;
    }
}T;
void solve(int u){
	if(vis[u])dp[u]=min(dp[u],T.query(1,1,m,val[u],val[u])+val[u]);
	if(R[u])T.update(1,1,m,val[L[u]],val[R[u]],dp[u]+1-val[L[u]]);
	for(int i=0;i<26;++i){
		if(c[u][i]){
			dp[c[u][i]]=dp[u]+1;
			solve(c[u][i]);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		int p;
		char s[5];
		cin>>p>>s;
		c[p][s[0]-'a']=i;
	}
	
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>b[i];
		t[i]=i;
		vis[b[i]]=1;
	}
	dfs(0);
	sort(t+1,t+m+1,[&](const int&l,const int&r){return id[b[l]]<id[b[r]];});
	for(int i=1;i<=m;++i){
		val[b[t[i]]]=i;
	}
	solve(0);
	for(int i=1;i<=m;++i){
		cout<<dp[b[i]]<<" \n"[i==m];
	}
	return 0;
}
/*
1 2 2 4 3 6
*/