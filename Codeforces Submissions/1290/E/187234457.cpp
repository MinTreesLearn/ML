#include<bits/stdc++.h>
#define ll long long
#define ls u<<1
#define rs u<<1|1
#define mm(x) memset(x,0,sizeof(x))
using namespace std;
int read()
{
  int a=0;int f=0;char p=getchar();
  while(!isdigit(p)){f|=p=='-';p=getchar();}
  while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=getchar();}
  return f?-a:a;
}
const int INF=998244353;
const int P=998244353;
const int N=1e6+5;
int T;
int n,m;
int val[N];
ll ans[N];
int pos[N];
bool cmp(int a,int b)
{
  return val[a]<val[b];
}
int cnt[N];
int mn[N],mnn[N],tag1[N],tag2[N];
int tot[N];
ll sum[N];
void update(int u,int X,int Y)
{
  if(!tot[u]) return ;
  mn[u]+=Y; mnn[u]+=Y;  tag1[u]+=Y; tag2[u]+=Y; sum[u]+=(ll)tot[u]*Y;
  if(mn[u]>=X) return ;
  sum[u]=sum[u]+(ll)cnt[u]*(X-mn[u]);
  mn[u]=X;  tag1[u]=max(X,tag1[u]);//X;
}
void pushdown(int u)
{
  update(ls,tag1[u],tag2[u]);
  update(rs,tag1[u],tag2[u]);
  tag1[u]=tag2[u]=0;
}
void pushup(int u)
{
  cnt[u]=0;
  tot[u]=tot[ls]+tot[rs];
  sum[u]=sum[ls]+sum[rs];
  mn[u]=min(mn[ls],mn[rs]);
  mnn[u]=min(mnn[ls],mnn[rs]);
  if(mn[u]==mn[ls]) cnt[u]+=cnt[ls];
  else mnn[u]=min(mnn[u],mn[ls]);
  if(mn[u]==mn[rs]) cnt[u]+=cnt[rs];
  else mnn[u]=min(mnn[u],mn[rs]);
}
void build(int u,int l,int r)
{
  sum[u]=0;
  mn[u]=mnn[u]=INF;
  tag1[u]=tag2[u]=cnt[u]=tot[u]=0;
  if(l==r)  return ;
  int mid=(l+r)>>1;
  build(ls,l,mid);
  build(rs,mid+1,r);
}
int query(int u,int l,int r,int X)
{
  if(l==r)
  {
    mn[u]=0;
    cnt[u]=tot[u]=1;
    return 1;
  }
  int mid=(l+r)>>1; pushdown(u);  int res=0;
  if(X<=mid)  res=query(ls,l,mid,X);
  else  res=tot[ls]+query(rs,mid+1,r,X);
  pushup(u);
  return res;
}
void modify1(int u,int l,int r,int L,int R,int X)
{
  if(L<=l&&r<=R)
  {
    update(u,0,X);
    return ;
  }
  int mid=(l+r)>>1; pushdown(u);
  if(L<=mid)  modify1(ls,l,mid,L,R,X);
  if(R>mid) modify1(rs,mid+1,r,L,R,X);
  pushup(u);
}
void modify2(int u,int l,int r,int L,int R,int X)
{
  if(L<=l&&r<=R)
  {
    if(!tot[u]) return ;
    if(mn[u]>=X)  return ;
    if(mnn[u]>=X)
    {
      update(u,X,0);
      return ;
    }
    int mid=(l+r)>>1; pushdown(u);
    modify2(ls,l,mid,L,R,X);
    modify2(rs,mid+1,r,L,R,X);
    pushup(u);
  }
  int mid=(l+r)>>1; pushdown(u);
  if(L<=mid)  modify2(ls,l,mid,L,R,X);
  if(R>mid) modify2(rs,mid+1,r,L,R,X);
  pushup(u);
}
void solve()
{
  for(int i=1;i<=n;++i) pos[i]=i;
  sort(pos+1,pos+n+1,cmp);
  build(1,1,n);
  for(int i=1;i<=n;++i)
  {
    int now=pos[i];
    int pre=query(1,1,n,now);
    if(now!=n)
    {
      modify1(1,1,n,now+1,n,1);
      modify2(1,1,n,now+1,n,pre);
    }
    ans[i]-=sum[1];
  }
}
int main()
{
  n=read();
  for(int i=1;i<=n;++i)  ans[i]=(ll)i*i;
  for(int i=1;i<=n;++i) val[i]=read();
  solve();
  reverse(val+1,val+n+1);
  solve();
  for(int i=1;i<=n;++i) printf("%lld\n",ans[i]);
  return 0;
}