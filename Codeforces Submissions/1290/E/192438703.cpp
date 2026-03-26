// LUOGU_RID: 101572938
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=150005,inf=1e18;
int n,a[maxn],pos[maxn];
struct vl 
{int sum,mx,sc,cnt;
vl(){sum=0;mx=sc=-inf;cnt=0;}
};
inline vl merge(vl a,vl b)
{
    vl ret;
    ret.sum=a.sum+b.sum;
    ret.mx=max(a.mx,b.mx);
    ret.sc=-inf;
    ret.cnt=0;
    if(a.mx!=ret.mx)ret.sc=max(ret.sc,a.mx);
    else ret.cnt+=a.cnt;
    if(b.mx!=ret.mx)ret.sc=max(ret.sc,b.mx);
    else ret.cnt+=b.cnt;
    if(a.sc!=ret.mx)ret.sc=max(ret.sc,a.sc);
    if(b.sc!=ret.mx)ret.sc=max(ret.sc,b.sc);
    return ret;
}
vl val[maxn<<2];
int tag[maxn<<2],add[maxn<<2],len[maxn<<2];
inline void pushup(int i)
{
    val[i]=merge(val[i<<1],val[i<<1|1]);
    len[i]=len[i<<1]+len[i<<1|1];
}
inline void pushtgmin(int i,int v)
{
    if(v>=val[i].mx)return;
    val[i].sum-=(val[i].mx-v)*val[i].cnt;
    val[i].mx=v;
    tag[i]=min(tag[i],v);
    return;
}
inline void pushtgadd(int i,int v)
{
    add[i]+=v;
    val[i].sum+=len[i]*v;
    if(tag[i]!=inf)tag[i]+=v;
    if(val[i].mx!=-inf)val[i].mx+=v;
    if(val[i].sc!=-inf)val[i].sc+=v;  
}
inline void pushdown(int i)
{
    pushtgadd(i<<1,add[i]);
    pushtgadd(i<<1|1,add[i]);
    add[i]=0;
    pushtgmin(i<<1,tag[i]);
    pushtgmin(i<<1|1,tag[i]);
    tag[i]=inf;
}
void update(int i,int l,int r,int L,int R,int v)
{
    if(L>R)return;
    if(L<=l&&r<=R){pushtgadd(i,v);return;}
    int mid=l+r>>1;pushdown(i);
    if(L<=mid)update(i<<1,l,mid,L,R,v);
    if(R>mid)update(i<<1|1,mid+1,r,L,R,v);
    pushup(i);
}
void calcmin(int i,int l,int r,int L,int R,int v)
{
    //if(i==1)printf("#%d %d %d\n",L,R,v);
    if(r<L||l>R||L>R)return;
    if(L<=L&&r<=R&&val[i].sc<v){pushtgmin(i,v);return;}
    if(l==r)return;
    int mid=l+r>>1;pushdown(i);
    calcmin(i<<1,l,mid,L,R,v);
    calcmin(i<<1|1,mid+1,r,L,R,v);
    pushup(i);
}
void build(int i,int l,int r)
{
    len[i]=0;
    val[i].cnt=val[i].sum=0;
    val[i].mx=val[i].sc=-inf;
    tag[i]=inf;add[i]=0;
    if(l==r)return;
    int mid=l+r>>1;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
}
int query(int i,int l,int r,int p)
{
    if(l==r)return val[i].sum;
    int mid=l+r>>1;
    pushdown(i);
    if(p<=mid)return query(i<<1,l,mid,p);
    else return query(i<<1|1,mid+1,r,p);
}
void modify(int i,int l,int r,int p,int v)
{
    if(l==r)
    {
        val[i].cnt=1;
        val[i].mx=v;
        val[i].sc=-inf;
        val[i].sum=v;
        len[i]=1;
        return;
    }
    int mid=l+r>>1;
    pushdown(i);
    if(p<=mid)modify(i<<1,l,mid,p,v);
    else modify(i<<1|1,mid+1,r,p,v);
    pushup(i);
}
int c[maxn];
int num[maxn];
void uadd(int p,int v){while(p<=n){c[p]+=v;p+=p&-p;}}
int ask(int p){int ret=0;while(p){ret+=c[p];p-=p&-p;}return ret;}
int sum[maxn];
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
    pos[a[i]]=i,num[a[i]]=ask(a[i]),uadd(a[i],1);
    build(1,1,n);
    for(int i=1;i<=n;i++)
    { 
        update(1,1,n,pos[i]+1,n,1);
        calcmin(1,1,n,1,pos[i]-1,num[i]);
        modify(1,1,n,pos[i],i);
       
        int S=0;
        //for(int j=1,x;j<=n;j++)
         //   if(a[j]<=i)
        //        printf("%d ",(x=query(1,1,n,j))),S+=x;
        // putchar('\n');
        //printf("%d\n",val[1].sum);
        sum[i]+=val[1].sum;
    }
    reverse(a+1,a+1+n);
    memset(c,0,sizeof c);
    for(int i=1;i<=n;i++)
    pos[a[i]]=i,num[a[i]]=ask(a[i]),uadd(a[i],1);
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        update(1,1,n,pos[i]+1,n,1);
        calcmin(1,1,n,1,pos[i]-1,num[i]);
        modify(1,1,n,pos[i],i);
        
       // int S=0;
        // for(int j=n,x;j>=1;j--)
        //     if(a[j]<=i)
        //         printf("%d ",i-(x=query(1,1,n,j))+1),S+=x;
        // putchar('\n');
        //printf("%d\n",val[1].sum);
        sum[i]-=i*i-val[1].sum;
    }
    for(int i=1;i<=n;i++)
        printf("%lld\n",sum[i]);
   // putchar('\n');
    return 0;
}