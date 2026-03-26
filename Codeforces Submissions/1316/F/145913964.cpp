#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int n,m;
int a[300005];
ll fac[300005],inv[300005];
pair<ll,int> val[600005];int cnt;
struct query{
    int pos;
    int val;
}que[300005];
struct node{
    int tot;
    ll val,val1,val2;
}tree[2400005];
node operator +(const node &a,const node &b){
    node res;
    res.tot=a.tot+b.tot;
    res.val1=(a.val1+b.val1*fac[a.tot]%mod)%mod;
    res.val2=(a.val2+b.val2*inv[a.tot]%mod)%mod;
    res.val=(a.val+b.val+a.val1*b.val2%mod*inv[a.tot]%mod)%mod;
    return res;
}
void update(int k,int l,int r,int x,int y){
    if(l==r){
        // printf("k=%d\n",k);
        // if(y>0)printf("add %d val=%lld\n",x,val[x].first);
        // else printf("del %d\n",x);
        if(y>0)tree[k].tot=1,tree[k].val=0,tree[k].val1=val[x].first,tree[k].val2=val[x].first*inv[1]%mod;
        else tree[k].tot=tree[k].val=tree[k].val1=tree[k].val2=0;
        return;
    }
    int mid=l+r>>1;
    if(x<=mid)update(k*2,l,mid,x,y);
    else update(k*2+1,mid+1,r,x,y);
    tree[k]=tree[k*2]+tree[k*2+1];
}
ll power(ll a,ll p){
    ll res=1;
    while(p){
        if(p&1)res=res*a%mod;
        p>>=1;
        a=a*a%mod;
    }
    return res;
}
int main(){
    fac[0]=1;
    for(int i=1;i<=300000;i++)fac[i]=fac[i-1]*2%mod;
    inv[300000]=power(fac[300000],mod-2);
    for(int i=299999;i>=0;i--)inv[i]=inv[i+1]*2%mod;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),val[++cnt].first=a[i],val[cnt].second=cnt;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d%d",&que[i].pos,&que[i].val),val[++cnt].first=que[i].val,val[cnt].second=cnt;
    sort(val+1,val+cnt+1);
    for(int i=1;i<=n;i++)a[i]=lower_bound(val+1,val+cnt+1,make_pair(1ll*a[i],i))-val;
    for(int i=1;i<=m;i++)que[i].val=lower_bound(val+1,val+cnt+1,make_pair(1ll*que[i].val,i+n))-val;
    for(int i=1;i<=n;i++)update(1,1,cnt,a[i],1);
    printf("%lld\n",tree[1].val);
    for(int i=1;i<=m;i++){
        update(1,1,cnt,a[que[i].pos],-1);
        a[que[i].pos]=que[i].val;
        update(1,1,cnt,a[que[i].pos],1);
        printf("%lld\n",tree[1].val);
        // printf("%lld %lld %lld\n",tree[3].val,tree[6].val1,tree[7].val2);
    }
    return 0;
}