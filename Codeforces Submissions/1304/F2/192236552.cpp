// Judges with GCC >= 12 only needs Ofast
// #pragma GCC optimize("O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize")
// MLE optimization
// #pragma GCC optimize("conserve-stack")
// Old judges
// #pragma GCC target("sse4.2,popcnt,lzcnt,abm,mmx,fma,bmi,bmi2")
// New judges. Test with assert(__builtin_cpu_supports("avx2"));
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
// Atcoder
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#include<bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<> pp(0.0,1.0);
#define ld long double
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second
const int inf=1e9;
const int mod=998244353;
const int mod2=1e9+7;
const int maxn=55;
const int maxm=20005;
const int maxq=500005;
const int maxl=20;
const int maxa=1000005;
int power(int a,int n){
    int res=1;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;n>>=1;
    }
    return res;
}
struct node{
    int Max[3];
    node(){Max[0]=Max[1]=Max[2]=inf;}
    friend node operator+(node a,node b){
        node res;
        for(int i=0;i<3;i++) res.Max[i]=max(a.Max[i],b.Max[i]);
        return res;
    }
};
int n,m,k,a[maxn][maxm],pre[maxm],suf[maxm],dp[maxm],cur[maxm];
namespace Segtree{
    node tree[4*maxm];
    void build(int l,int r,int id){
        if(l==r){
            tree[id].Max[0]=dp[l];
            tree[id].Max[1]=dp[l]+suf[l+k];
            tree[id].Max[2]=dp[l]+pre[l-1];
            return;
        }
        int mid=(l+r)>>1;
        build(l,mid,id<<1);build(mid+1,r,id<<1|1);
        tree[id]=tree[id<<1]+tree[id<<1|1];
    }
    int query(int l,int r,int id,int tl,int tr,int t){
        if(r<tl || tr<l) return -inf;
        if(tl<=l && r<=tr) return tree[id].Max[t];
        int mid=(l+r)>>1;
        return max(query(l,mid,id<<1,tl,tr,t),query(mid+1,r,id<<1|1,tl,tr,t));
    }
}
void solve(){
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> a[i][j];
    }
    for(int i=1;i<=k;i++) dp[1]+=a[1][i]+a[2][i];
    for(int i=2;i<=m-k+1;i++) dp[i]=dp[i-1]-a[1][i-1]-a[2][i-1]+a[1][i+k-1]+a[2][i+k-1];
    for(int i=1;i<=m;i++) cur[i]=cur[i-1]+a[2][i];
    for(int i=3;i<=n+1;i++){
        for(int j=1;j<=m;j++){pre[j]=cur[j];cur[j]=cur[j-1]+a[i][j];}
        for(int j=m;j>=1;j--) suf[j]=suf[j+1]+a[i-1][j];
        Segtree::build(1,m-k+1,1);
        for(int j=1;j<=m-k+1;j++){
            dp[j]=Segtree::query(1,m-k+1,1,max(1,j-k+1),j,1)-suf[j+k]+cur[j+k-1]-cur[j-1];
            //cout << dp[j] << ' ';
            dp[j]=max(dp[j],Segtree::query(1,m-k+1,1,j,min(j+k-1,m-k+1),2)-pre[j-1]+cur[j+k-1]-cur[j-1]);
            //cout << dp[j] << ' ';
            if(j>k) dp[j]=max(dp[j],Segtree::query(1,m-k+1,1,1,j-k,0)+pre[j+k-1]-pre[j-1]+cur[j+k-1]-cur[j-1]);
            //cout << dp[j] << ' ';
            if(j+k<=m-k+1) dp[j]=max(dp[j],Segtree::query(1,m-k+1,1,j+k,m-k+1,0)+pre[j+k-1]-pre[j-1]+cur[j+k-1]-cur[j-1]);
            //cout << dp[j] << ' ' << pre[j+k-1]-pre[j-1]+cur[j+k-1]-cur[j-1] << '\n';
        }
        //cout << '\n';
    }
    int ans=0;
    for(int i=1;i<=m-k+1;i++) ans=max(ans,dp[i]);
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int test=1;//cin >> test;
    while(test--) solve();
}
