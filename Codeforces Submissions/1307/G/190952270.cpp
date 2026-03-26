#include<bits/stdc++.h>
using namespace std;
#define lb long double
int n,m,Q,cnt,xl[51][2];
lb ans;
inline int rd(){
    int s=0;char ch=getchar();bool f=0;
    while(ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
    return f?-s:s;
}
struct fyl{
#define NN 500
#define MM 200000
    struct edge{
        int ne,to,fl,di;
    }a[2*MM];
    int num=1,head[NN],pr[NN],flow[NN],dis[NN];
    bool vis[NN];
    inline void clear(){
        for(int i=2;i<=num;i++) head[a[i].to]=0;
        num=1;
    }
    inline void add(int u,int v,int w,int fl,bool tp=0){
        a[++num]=(edge){head[u],v,fl,w};
        head[u]=num;if(!tp) add(v,u,-w,0,1);
    }
    inline bool spfa(int u,int t){
        queue<int> q;
        for(int i=1;i<=t;i++) dis[i]=0x3f3f3f3f;
        q.push(u),dis[u]=0,flow[u]=0x3f3f3f3f;
        while(!q.empty()){
            u=q.front(),q.pop(),vis[u]=0;
            for(int v,i=head[u];i;i=a[i].ne){
                v=a[i].to;if(!a[i].fl) continue;
                if(dis[v]>dis[u]+a[i].di){
                    dis[v]=dis[u]+a[i].di,pr[v]=i^1,flow[v]=min(flow[u],a[i].fl);
                    if(!vis[v]) vis[v]=1,q.push(v);
                }
            }
        }
        return dis[t]!=0x3f3f3f3f;
    }
    inline void wll(int s,int t){
        int fl=0,co=0;
        while(spfa(s,t)){
            co+=dis[t]*flow[t],fl+=flow[t];
            int u=t;
            while(u!=s){
                a[pr[u]].fl+=flow[t],a[pr[u]^1].fl-=flow[t];
                u=a[pr[u]].to;
            }
            //cout<<'['<<co<<','<<fl<<']'<<endl;
            xl[++cnt][1]=co,xl[cnt][0]=fl;
        }
    }
}T;
int main(){
    n=rd(),m=rd();
    for(int u,v,w,i=1;i<=m;i++){
        u=rd(),v=rd(),w=rd();
        T.add(u,v,w,1);
    }
    T.wll(1,n);
    Q=rd();
    while(Q--){
        int x=rd();ans=1000000000;
        for(int i=1;i<=cnt;i++){
            lb res=1.0*(xl[i][1]+x)/xl[i][0];
            if(ans-res>1e-7) ans=res;
        }
        printf("%.7Lf\n",ans);
    }
    return 0;
}
	  		    	 			   	 				   			