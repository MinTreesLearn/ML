#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>
#include <set>
using namespace std;
#define fi first
#define sc second
#define mkp make_pair
#define pii pair<int,int>
typedef long long ll;
const int N=1005,oo=1e9,mod=1e9+9;
inline int read() {
    int x=0,flag=0;char ch=getchar();
    while(ch<'0'||ch>'9') {flag|=(ch=='-');ch=getchar();}
    while('0'<=ch&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return flag?-x:x;
}
inline int mx(int x,int y) {return x>y?x:y;}
inline int mn(int x,int y) {return x<y?x:y;}
inline void swp(int &x,int &y) {x^=y^=x^=y;}
inline int as(int x) {return x>0?x:-x;}
inline int ok(int x) {return x>0?1:-1;}

int n,hd[N],num;
struct node {
    int nxt,to;
}e[N<<1];
#define v e[i].to
inline void adde(int x,int y) {
    e[++num]=(node){hd[x],y};
    hd[x]=num;
}
int Rt,maxp[N],sz[N],tot,col[N];
bool vis[N];
void getrt(int x,int fa) {
    maxp[x]=0;sz[x]=1;
    for(int i=hd[x];i;i=e[i].nxt) {
        if(vis[v]||v==fa) continue;
        getrt(v,x);
        sz[x]+=sz[v];
        maxp[x]=mx(maxp[x],sz[v]);
    }
    maxp[x]=mx(maxp[x],tot-sz[x]);
    if(maxp[x]<maxp[Rt]) Rt=x;
}
void Dfs(int x,int fa,int c) {
    col[x]=c;
    for(int i=hd[x];i;i=e[i].nxt) {
        if(v==fa||vis[v]) continue;
        Dfs(v,x,c);
    }
}
inline int query(int x,int y) {
    printf("? %d %d\n",x,y);fflush(stdout);
    return read();
}
int solve() {
    int rt=0;tot=0;
    for(int i=1;i<=n;++i)
        if(!vis[i]) {
            ++tot;
            if(!rt) rt=i;
        }
    if(tot==1) return rt;
    if(tot==2) {
        for(int i=1;i<=n;++i)
            if(!vis[i]&&rt!=i)
                return query(rt,i);
    }
    maxp[Rt=0]=oo;
    getrt(rt,0);
    for(int i=hd[Rt];i;i=e[i].nxt)
        if(!vis[v]) Dfs(v,Rt,v);
    int now1=0,now2=0;
    for(int i=1;i<=n;++i)
        if(!vis[i]&&i!=Rt) {
            if(now1&&col[i]!=col[now1]) {
                now2=i;
                break;
            } else now1=i;
        }
    int Now=query(now1,now2);
    if(Now==Rt) {
        for(int i=1;i<=n;++i)
            if(col[i]==col[now1]||col[i]==col[now2])
                vis[i]=1;
        memset(col,0,sizeof col);
    } else {
        for(int i=1;i<=n;++i)
            if(col[i]!=col[Now])
                vis[i]=1;
        memset(col,0,sizeof col);
    }
    return solve();
}
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("1.in","r",stdin);
//     freopen("1.out","w",stdout);
// #endif
    n=read();
    for(int i=1,x,y;i<n;++i) {
        x=read();y=read();
        adde(x,y);adde(y,x);
    }
    printf("! %d\n",solve());
    return 0;
}
//yqmpo62327
//Ro5dPTkt