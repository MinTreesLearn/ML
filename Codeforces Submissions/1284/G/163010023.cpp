#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<LL,LL> pii;
#define MAXN 100005
#define pb push_back
#define mkpr make_pair
#define fir first
#define sec second
#define lson (rt<<1)
#define rson (rt<<1|1)
#define lowbit(x) (x&-x)
const int mo=998244353;
const int inv2=5e8+4;
const int jzm=2333;
const int zero=15;
const int INF=0x3f3f3f3f;
const double Pi=acos(-1.0);
const double eps=1e-9;
const int orG=3,ivG=332748118;
template<typename _T>
_T Fabs(_T x){return x<0?-x:x;}
template<typename _T>
void read(_T &x){
    _T f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+(s^48);s=getchar();}
    x*=f;
}
int add(int x,int y,int p){return x+y<p?x+y:x+y-p;}
void Add(int &x,int y,int p){x=add(x,y,p);}
int qkpow(int a,int s,int p){int t=1;while(s){if(s&1)t=1ll*a*t%p;a=1ll*a*a%p;s>>=1;}return t;}
int n,m,TT,id[25][25],idx,col[405],cnt,head[1005],tot;
int dis[1005],cntp,S,T,deg[405],fa[405],pre[405];
char maze[25][25],ans[45][45];bool used[1005];queue<int>q;
struct ming{int u,v,x,y;}s[1005];
struct edge{int to,nxt;}e[MAXN*10];
void addEdge(int u,int v){e[++tot]=(edge){v,head[u]};head[u]=tot;}
void makeSet(int x){for(int i=1;i<=x;i++)fa[i]=i;}
int findSet(int x){return x==fa[x]?x:fa[x]=findSet(fa[x]);}
void unionSet(int x,int y){int u=findSet(x),v=findSet(y);if(fa[u]^v)fa[u]=v;}
int main(){
    read(TT);int allTT=TT;
    while(TT--){
        read(n);read(m);
        for(int i=1;i<=n;i++)scanf("%s",maze[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(maze[i][j]=='O')
                    id[i][j]=++idx,col[idx]=(i+j)&1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(id[i][j]&&id[i][j+1])
                    s[++cntp]=(ming){id[i][j],id[i][j+1],i+i-1,j+j};
                if(id[i][j]&&id[i+1][j])
                    s[++cntp]=(ming){id[i][j],id[i+1][j],i+i,j+j-1};
            }
        cnt=cntp;S=++cnt;T=++cnt;
        while(1){
            for(int i=1;i<=cnt;i++)head[i]=0;tot=0;
            for(int i=1;i<=idx;i++)deg[i]=0;makeSet(idx);
            for(int i=1;i<=cntp;i++)if(used[i])
                unionSet(s[i].u,s[i].v),deg[s[i].u]++,deg[s[i].v]++;
            for(int i=1;i<=cntp;i++)if(!used[i]){
                int u=s[i].u,v=s[i].v;if(findSet(u)!=findSet(v))addEdge(S,i);
                if((col[u]||deg[u]<2)&&(col[v]||deg[v]<2)&&u!=1)addEdge(i,T);
            }
            for(int i=1;i<=cntp;i++)if(used[i]){
                makeSet(idx);deg[s[i].u]--;deg[s[i].v]--;
                for(int j=1;j<=cntp;j++)if(used[j]&&i!=j)unionSet(s[j].u,s[j].v);
                for(int j=1;j<=cntp;j++)if(!used[j]){
                    int u=s[j].u,v=s[j].v;if(u==1)continue;
                    if(findSet(u)!=findSet(v))addEdge(i,j);
                    if((col[u]||deg[u]<2)&&(col[v]||deg[v]<2))addEdge(j,i);
                }
                deg[s[i].u]++;deg[s[i].v]++;
            }
            for(int i=1;i<=cnt;i++)dis[i]=pre[i]=0;dis[S]=1;
            while(!q.empty())q.pop();q.push(S);
            while(!q.empty()){
                int u=q.front();q.pop();
                for(int i=head[u];i;i=e[i].nxt){
                    int v=e[i].to;if(dis[v])continue;
                    q.push(v);dis[v]=dis[u]+1;pre[v]=u;
                }
            }
            if(!dis[T])break;int now=pre[T];
            while(now^S)used[now]^=1,now=pre[now];
        }
        for(int i=1;i<=idx;i++)deg[i]=0;makeSet(idx);
        for(int i=1;i<=cntp;i++)if(used[i])
            deg[s[i].u]++,deg[s[i].v]++,unionSet(s[i].u,s[i].v);
        bool flag=0;for(int i=2;i<=idx;i++)if(!col[i])flag|=(deg[i]<2);
        if(flag)puts("NO");
        else{
            for(int i=1;i<n+n;i++)
                for(int j=1;j<m+m;j++)ans[i][j]=' ';
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    ans[i+i-1][j+j-1]=maze[i][j];
            for(int i=1;i<=cntp;i++)if(findSet(s[i].u)^findSet(s[i].v))
                used[i]=1,unionSet(s[i].u,s[i].v);
            for(int i=1;i<=cntp;i++)if(used[i])
                ans[s[i].x][s[i].y]='O';
            puts("YES");
            for(int i=1;i<n+n;i++,puts(""))
                for(int j=1;j<m+m;j++)
                    printf("%c",ans[i][j]),ans[i][j]=0;
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)id[i][j]=maze[i][j]=0;
        for(int i=1;i<=cntp;i++)used[i]=0;
        for(int i=1;i<=idx;i++)col[i]=0;idx=cntp=cnt=0;
    }
    return 0;
}
