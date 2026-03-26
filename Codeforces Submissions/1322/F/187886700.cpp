// LUOGU_RID: 98653475
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=5e5+10;

int n,m;
vi e[N];
pii p[N];

int f[N],siz[N],son[N],dep[N];
void dfs(int x,int fa){
    f[x]=fa,siz[x]=1,dep[x]=dep[fa]+1;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y,x);
        siz[x]+=siz[y];
        if(siz[y]>siz[son[x]]) son[x]=y;
    }
}

int dfn[N],low[N],ti,seq[N];
int top[N];
void dfs1(int x,int tp){
    top[x]=tp,dfn[x]=++ti,seq[ti]=x;
    if(son[x]) dfs1(son[x],tp);
    for(auto y:e[x]){
        if(y==f[x]||y==son[x]) continue;
        dfs1(y,y);
    }
    low[x]=ti;
}

int LCA(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        x=f[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}
int g_son(int x,int y){
    while(dep[x]<dep[f[top[y]]]) y=f[top[y]];
    return top[x]==top[y]?son[x]:top[y];
}

struct Dsu{
    int f[N*2];
    void init(int n) {iota(f+1,f+n+1,1);}
    int find(int x) {return x==f[x]?x:f[x]=find(f[x]);}
    void merge(int x,int y) {f[find(y)]=find(x);}
}d;
void merge(int x,int y,bool rev){
    d.merge(x*2,y*2+rev),d.merge(x*2+1,y*2+(rev^1));
}

int subv[N],subv1[N],bl[N],typ[N];
void dfs2(int x){
    for(auto y:e[x]){
        if(y==f[x]) continue;
        dfs2(y);
        subv[x]+=subv[y],subv1[x]+=subv1[y];
    }
    if(subv[x]>0) merge(x,f[x],0);
}

int c[N];
bool dfs_c(int x,int k){
    int L=1,R=k;
    for(auto y:e[x]){
        if(y==f[x]) continue;
        if(!dfs_c(y,k)) return false;
        if(bl[y]&&bl[y]==bl[x]){
            if(typ[x]^typ[y]) R=min(R,k-c[y]);
            else L=max(L,c[y]+1);
        }
    }
    static vi vec[N];
    for(auto y:e[x])
        if(y!=f[x]&&bl[y]&&bl[y]!=bl[x])
            vec[bl[y]].pb(y);
    if(L>R) return false;
    int l1=1,r1=k;
    for(auto y:e[x]){
        if(bl[y]&&!vec[bl[y]].empty()){
            vi &v=vec[bl[y]];
            int l=1,r=k;
            for(auto y:v){
                if(typ[y]) r=min(r,k-c[y]);
                else l=max(l,c[y]+1);
            }
            v.clear();
            if(l>r) return false;
            pii p=min((pii){l,r},(pii){k+1-r,k+1-l});
            if(p.se>=(k+1)/2) L=max(L,p.fi),R=min(R,k+1-p.fi);
            else l1=max(l1,p.fi),r1=min(r1,p.se);
        }
    }
    if(l1>r1) return false;
    if(max(L,l1)<=min(R,r1)) {c[x]=max(L,l1);return true;}
    else if(max(L,k+1-r1)<=min(R,k+1-l1)) {c[x]=max(L,k+1-r1);return true;}
    return false;
}

int res[N];
void construct(int x,int k,bool fl){
    res[x]=(fl?k+1-c[x]:c[x]);
    for(auto y:e[x]){
        if(y==f[x]) continue;
        if(bl[y]&&bl[y]==bl[x])
            construct(y,k,fl^(typ[x]^typ[y]));
        else if(!bl[y])
            construct(y,k,0);
    }
    static vi vec[N];
    for(auto y:e[x])
        if(y!=f[x]&&bl[y]&&bl[y]!=bl[x])
            vec[bl[y]].pb(y);
    static bool tmp[N];
    for(auto y:e[x]){
        if(bl[y]&&!vec[bl[y]].empty()){
            vi &v=vec[bl[y]];
            int l=1,r=k;
            for(auto y:v){
                if(typ[y]) r=min(r,k-c[y]);
                else l=max(l,c[y]+1);
            }
            for(auto y:v)
                tmp[y]=(l<=res[x]&&res[x]<=r)?typ[y]:typ[y]^1;
            v.clear();
        }
    }
    for(auto y:e[x])
        if(y!=f[x]&&bl[y]&&bl[y]!=bl[x])
            construct(y,k,tmp[y]);
}

void solve(){
    dfs(1,0),dfs1(1,1);
    d.init(2*n+1);
    for(int i=1;i<=m;i++){
        int x=p[i].fi,y=p[i].se,lc=LCA(x,y);
        int sx=g_son(lc,x),sy=g_son(lc,y);
        subv1[x]++,subv1[y]++,subv1[lc]-=2;
        if(x!=lc) subv[x]++,subv[sx]--;
        if(y!=lc) subv[y]++,subv[sy]--;
        if(x!=lc&&y!=lc) merge(sx,sy,1);
    }
    dfs2(1);
    bl[1]=0;
    for(int i=2;i<=n;i++){
        int x=i*2,y=i*2+1;
        if(d.find(x)==d.find(y)) {puts("-1");exit(0);}
        if(subv1[i]) bl[i]=d.find(x)/2,typ[i]=d.find(x)&1;
        else bl[i]=0;
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(dfs_c(1,mid)) r=mid;
        else l=mid+1;
    }
    dfs_c(1,l),construct(1,l,0);
    cout<<l<<'\n';
    for(int i=1;i<=n;i++)
        cout<<res[i]<<' ';
    cout<<'\n';
}

int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        p[i]={x,y};
    }
    solve();
    return 0;
}