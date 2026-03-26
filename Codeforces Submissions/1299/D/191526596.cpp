// LUOGU_RID: 101124005
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int Maxn=1e5,Maxk=374,Mod=1e9+7;

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

struct Node{int frm,to,nxt,w;} Edge[Maxn*2+5];
int tot=1,Head[Maxn+5];
map<pair<int,int>,int> mp;
inline void Addedge(int x,int y,int z)
{
    Edge[++tot]=(Node){x,y,Head[x],z};
    Head[x]=tot,mp[make_pair(x,y)]=z;
}
int n,m,fa[Maxn+5],val[Maxn+5][5];
int num[Maxn+5][5],sum[Maxn+5],vis[Maxn+5];
int dfn[Maxn+5],chk[Maxn+5],cnt[Maxn+5],ID,cur;
int id[2][4][8][16][32],st[Maxk+5][5],tyw;
int g[Maxk+5][Maxk+5],f[2][Maxk+5];
vector<int> v,w[Maxn+5];
inline int Find(int x) {return fa[x]==x?x:fa[x]=Find(fa[x]);}

int hzh[5];
inline void add(int &x,int y) {x=(x+y)%Mod;}
inline void Reset(int *A)
{
    Rof(i,4,0) if(A[i]) For(j,i+1,4)
        if(A[j]&(1<<i)) A[j]^=A[i];
}
inline void dfs(int i)
{
    if(i>4)
    {
        id[hzh[0]][hzh[1]][hzh[2]][hzh[3]][hzh[4]]=++tyw;
        memcpy(st[tyw],hzh,sizeof(hzh)); return;
    }
    hzh[i]=0; dfs(i+1);
    For(j,1<<i,(1<<i+1)-1)
    {
        int flag=0; hzh[i]=j;
        For(k,0,i-1) if(hzh[k] && j&(1<<k)) {flag=1; break;}
        if(!flag) dfs(i+1);
    }
}
inline void Merge(int a,int b)
{
    For(i,0,4) hzh[i]=st[a][i];
    For(i,0,4) if(st[b][i])
    {
        int x=st[b][i];
        Rof(j,4,0) if(x&(1<<j))
        {
            if(!hzh[j]) {hzh[j]=x; break;}
            x^=hzh[j];
        }
        if(!x) {g[a][b]=-1; return;}
    }
    Reset(hzh);
    int idx=id[hzh[0]][hzh[1]][hzh[2]][hzh[3]][hzh[4]];
    if(!idx) g[a][b]=-1;
    else g[a][b]=idx;
}
inline void Build()
{
    dfs(0);
    For(i,1,tyw) For(j,1,tyw) Merge(i,j);
}
inline void Insert(int x,int y)
{
    Rof(i,4,0) if(y&(1<<i))
    {
        if(!val[x][i]) {val[x][i]=y; return;}
        y^=val[x][i];
    }
    if(!y) chk[x]=1;
}
inline void dfs(int x,int fa)
{
    dfn[x]=++cur;
    for(int i=Head[x];i;i=Edge[i].nxt)
    {
        int y=Edge[i].to,z=Edge[i].w;
        if(y==fa || y==1) continue;
        if(!dfn[y]) sum[y]=sum[x]^z,dfs(y,x);
        else if(dfn[y]<dfn[x]) Insert(ID,sum[x]^sum[y]^z);
    }
}

int main()
{
    n=read(),m=read();
    For(i,1,n) fa[i]=i;
    For(i,1,m)
    {
        int a=read(),b=read(),c=read();
        Addedge(a,b,c),Addedge(b,a,c);
        if(a!=1 && b!=1 && Find(a)!=Find(b)) fa[Find(a)]=Find(b);
    }
    For(i,2,n) if(Find(i)==i) v.push_back(ID=i),dfs(i,0);
    For(i,2,n) w[Find(i)].push_back(i);
    for(int i=Head[1];i;i=Edge[i].nxt) cnt[Find(Edge[i].to)]++;
    for(auto i:v) if(cnt[i]==2)
    {
        int a=0,b=0;
        for(auto j:w[i]) if(mp.find(make_pair(1,j))!=mp.end()) (!a?a:b)=j;
        int res=mp[make_pair(1,a)]^mp[make_pair(1,b)]^mp[make_pair(a,b)];
        memcpy(num[i],val[i],sizeof(val[i])),vis[i]=chk[i];
        Rof(j,4,0) if(res&(1<<j))
        {
            if(!num[i][j]) {num[i][j]=res; break;}
            res^=num[i][j];
        }
        if(!res) vis[i]=1;
    }
    for(auto i:v) Reset(val[i]),Reset(num[i]);
    Build();
    int o=0,p=1; f[0][1]=1;
    for(auto i:v)
    {
        o^=1,p^=1,memset(f[o],0,sizeof(f[o]));
        memcpy(f[o],f[p],sizeof(f[p]));
        if(cnt[i]==1 && !chk[i])
        {
            int idx=id[val[i][0]][val[i][1]][val[i][2]][val[i][3]][val[i][4]];
            For(j,1,tyw) if(f[p][j] && g[j][idx]>0) add(f[o][g[j][idx]],f[p][j]);
        }
        if(cnt[i]==2 && !chk[i])
        {
            int idx=id[val[i][0]][val[i][1]][val[i][2]][val[i][3]][val[i][4]];
            For(j,1,tyw) if(f[p][j] && g[j][idx]>0) add(f[o][g[j][idx]],f[p][j]*2%Mod);
        }
        if(cnt[i]==2 && !vis[i])
        {
            int idx=id[num[i][0]][num[i][1]][num[i][2]][num[i][3]][num[i][4]];
            For(j,1,tyw) if(f[p][j] && g[j][idx]>0) add(f[o][g[j][idx]],f[p][j]);
        }
    }
    int ans=0;
    For(i,1,tyw) add(ans,f[o][i]);
    printf("%d\n",ans);
    return 0;
}