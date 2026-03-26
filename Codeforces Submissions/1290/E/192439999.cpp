#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long
#define int ll
#define Inf 0x3f3f3f3f
using namespace std;
const int N=2e5+60,M=1e6+20,mod=998244353;
inline int read(){
    int d=0,f=1;char x=getchar();
    while(x<'0'||x>'9'){if(x=='-'){f=-1;}x=getchar();}
    while(x>='0'&&x<='9'){d=(d<<1)+(d<<3)+(x-48);x=getchar();}
    return d*f;
}
int n,m,a[N],p[N],ret[N];
struct Seg{
    int c[N<<2],mx[N<<2],se[N<<2],tag[N<<2],stag[N<<2],len[N<<2],slen[N<<2],sum[N<<2];
    void mem(int rt,int l,int r){
        c[rt]=mx[rt]=se[rt]=tag[rt]=stag[rt]=len[rt]=slen[rt]=sum[rt]=0;
        if(l==r) return ;
        int mid=(l+r)>>1;
        mem(rt<<1,l,mid);mem(rt<<1|1,mid+1,r);
    }
    void pushup(int rt){
        c[rt]=c[rt<<1]+c[rt<<1|1];sum[rt]=sum[rt<<1]+sum[rt<<1|1];
        if(mx[rt<<1]>mx[rt<<1|1]){
            mx[rt]=mx[rt<<1],se[rt]=max(se[rt<<1],mx[rt<<1|1]);
            len[rt]=len[rt<<1],slen[rt]=slen[rt<<1]+slen[rt<<1|1]+len[rt<<1|1];
        }
        else if(mx[rt<<1]<mx[rt<<1|1]){
            mx[rt]=mx[rt<<1|1],se[rt]=max(se[rt<<1|1],mx[rt<<1]);
            len[rt]=len[rt<<1|1],slen[rt]=slen[rt<<1]+slen[rt<<1|1]+len[rt<<1];
        }
        else{
            mx[rt]=mx[rt<<1],se[rt]=max(se[rt<<1|1],se[rt<<1]);
            len[rt]=len[rt<<1]+len[rt<<1|1],slen[rt]=slen[rt<<1]+slen[rt<<1|1];
        }
    }
    void pushtag(int rt,int tag1,int tag2,int flag){
        if(!flag) tag1=tag2;
        mx[rt]+=tag1;tag[rt]+=tag1;se[rt]+=tag2;stag[rt]+=tag2;
        sum[rt]+=tag1*len[rt]+tag2*slen[rt];
    }
    void pushdown(int rt){
        bool flag=mx[rt<<1]<=mx[rt<<1|1];
        pushtag(rt<<1,tag[rt],stag[rt],mx[rt<<1]>=mx[rt<<1|1]);
        pushtag(rt<<1|1,tag[rt],stag[rt],flag);
        tag[rt]=stag[rt]=0;
    }
    int add(int rt,int l,int r,int ql,int qr){
        if(ql>r||qr<l) return 0;
        if(ql<=l&&r<=qr){pushtag(rt,1,1,1);return c[rt];}
        pushdown(rt);
        int mid=(l+r)>>1;int res=add(rt<<1,l,mid,ql,qr)+add(rt<<1|1,mid+1,r,ql,qr);
        pushup(rt);
        return res;
    }
    void update(int rt,int l,int r,int p,int k){
        if(l==r){sum[rt]=mx[rt]=k;len[rt]=c[rt]=1;return ;}
        pushdown(rt);int mid=(l+r)>>1;
        if(p<=mid) update(rt<<1,l,mid,p,k);
        else update(rt<<1|1,mid+1,r,p,k);
        pushup(rt);return ;
    }
    void updmin(int rt,int l,int r,int ql,int qr,int k){
        if(ql>r||qr<l||k>=mx[rt]) return ;
        if(ql<=l&&r<=qr&&k>se[rt]){pushtag(rt,min(k-mx[rt],0ll),0,1);return ;}
        pushdown(rt);int mid=(l+r)>>1;
        updmin(rt<<1,l,mid,ql,qr,k);updmin(rt<<1|1,mid+1,r,ql,qr,k);
        pushup(rt);
    }
}t;
signed main(){
    n=read();
    for(int i=1;i<=n;i++) p[a[i]=read()]=i;
    for(int i=1;i<=n;i++){
        int x=t.add(1,1,n,p[i]+1,n);t.update(1,1,n,p[i],i+1);
        t.updmin(1,1,n,1,p[i]-1,i-x);ret[i]+=t.sum[1];
    }
    for(int i=1;i<=n;i++) p[i]=n-p[i]+1;
    t.mem(1,1,n);
    for(int i=1;i<=n;i++){
        int x=t.add(1,1,n,p[i]+1,n);t.update(1,1,n,p[i],i+1);
        t.updmin(1,1,n,1,p[i]-1,i-x);ret[i]+=t.sum[1];
    }
    for(int i=1;i<=n;i++) printf("%lld\n",ret[i]-i*(i+2));
    return 0;
}
 	  					  	  		  	   								