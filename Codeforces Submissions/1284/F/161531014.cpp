# include <bits/stdc++.h>
using namespace std;
int n,ecnt,go[1000010],adj[500010],nxt[1000010],fa[500010],lg[250010],d[250010],bz[30][250010];
struct disjoint_set_union {
    struct node { int fa,sz;} f[250010];
    void init_(int x) { 
        for (int i=1;i<=x;i++) f[i].fa=i, f[i].sz=1;
    }
    int find_(int x) { return f[x].fa==x ? x : f[x].fa=find_(f[x].fa);}
    void merge_(int x,int y) {
        int l=find_(x),r=find_(y);
        if (l==r) return;
        if (f[l].sz<f[r].sz) swap(l,r);
        f[l].sz+=f[r].sz, f[r].fa=l;
    }
} dsu;
void add_(int u,int v) { go[++ecnt]=v, nxt[ecnt]=adj[u], adj[u]=ecnt;}
void DFS_(int x) {
    d[x]=d[fa[x]]+1, bz[0][x]=fa[x];
    for (int i=1;i<=lg[d[x]];i++) bz[i][x]=bz[i-1][bz[i-1][x]];
    for (int i=adj[x];i;i=nxt[i]) if (go[i]!=fa[x]) fa[go[i]]=x, DFS_(go[i]);
}
int LCA_(int x,int y) { 
    if (d[x]<d[y]) swap(x,y);
    int j=lg[d[x]];
    while (d[x]>d[y]) {
        if (d[bz[j][x]]>=d[y]) x=bz[j][x];
        j--;
    }
    if (x==y) return x;
    j=lg[d[x]];
    while (j>=0) {
        if (bz[j][x]!=bz[j][y]) x=bz[j][x], y=bz[j][y];
        j--;
    }
    return fa[x];
}
void work_(int x,int y) {
    int k=LCA_(x,y);
    if (dsu.find_(k)!=dsu.find_(x)) {
        int op=x;
        for (int i=lg[n];i>=0;i--) if (dsu.find_(bz[i][op])==dsu.find_(op)) op=bz[i][op];
        printf("%d %d %d %d\n",op,fa[op],x,y);
        dsu.merge_(op,fa[op]);
    }
    else {
        int op=y;
        for (int i=lg[n];i>=0;i--) if (d[bz[i][op]]>d[k]&&dsu.find_(bz[i][op])!=dsu.find_(k)) op=bz[i][op];
        printf("%d %d %d %d\n",op,fa[op],x,y); 
        dsu.merge_(op,fa[op]);
    }
}
void solve_(int x) {
    for (int i=adj[x];i;i=nxt[i]) if (go[i]!=fa[x]) fa[go[i]]=x, solve_(go[i]), work_(go[i]-n,x-n);
}
int main() {
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
    
    scanf("%d",&n);
    for (int u,v,i=1;i<n;i++) scanf("%d%d",&u,&v), add_(u,v), add_(v,u);
    for (int u,v,i=1;i<n;i++) scanf("%d%d",&u,&v), add_(u+n,v+n), add_(v+n,u+n);

    for (int i=2;i<=n;i++) lg[i]=lg[i/2]+1;
    DFS_(1);

    dsu.init_(n);

    printf("%d\n",n-1);
    solve_(n+1);

    return 0;
}