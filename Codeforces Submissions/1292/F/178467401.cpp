// LUOGU_RID: 92191453
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define fi first
#define sc second
#define mkp make_pair
#define pii pair<int,int>
typedef long long ll;
const int N=65,M=(1<<12)+5,oo=1e9,mod=1e9+7;
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

int n,a[N],F[N],cnt,st[N],top,tag[N],vc[N];
int S[M],f[N][M],C[N][N];
pii Ans[N]; bool vis[N];
int ff(int x) {return F[x]==x?x:F[x]=ff(F[x]);}
inline void merge(int x,int y) {
    int fx=ff(x),fy=ff(y);
    if(fx!=fy) F[fy]=fx;
}
inline void ADD(int&x,int y) {x=(x+y>=mod?x+y-mod:x+y);}
inline pii solve(int p) {
    top=0; memset(vis,0,sizeof vis);memset(tag,0,sizeof tag);
    for(int i=1;i<=n;++i)
        if(ff(i)==p) st[++top]=a[i];
    sort(st+1,st+top+1);
    int tt=0; vc[0]=0;
    for(int i=1,sum;i<=top;++i) {
        sum=0;
        for(int j=1;j<i;++j)
            if(st[i]%st[j]==0&&vis[j])
                sum|=(1<<tag[j]);
        if(!sum) vis[i]=1,tag[i]=tt++;
        else vc[++vc[0]]=sum;
    }
    if(!vc[0]) return mkp(0,1);
    memset(S,0,sizeof S);
    for(int i=1;i<=vc[0];++i)
        for(int j=1;j<(1<<tt);++j)
            if((j&vc[i])==vc[i])
                ++S[j];
    memset(f,0,sizeof f); f[0][0]=1;
    for(int i=1;i<=vc[0];++i)
        for(int j=0;j<(1<<tt);++j) { 
            if(!f[i-1][j]) continue;
            for(int k=1;k<=vc[0];++k)
                if(((vc[k]&j)!=vc[k]&&(vc[k]&j))||!j) ADD(f[i][vc[k]|j],f[i-1][j]);
            if(S[j]-i>=0) ADD(f[i][j],1ll*(S[j]-i+1)*f[i-1][j]%mod);
        }
    return mkp(vc[0]-1,f[vc[0]][(1<<tt)-1]);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=read(); bool flag=0;
    for(int i=1;i<=n;++i) {
        a[i]=read();
        if(a[i]==1) flag=1;
    }
    if(flag) {
        int sum=0,ans=1;
        for(int i=1;i<=n;++i)
            sum+=(a[i]>1);
        for(int i=1;i<=sum;++i) ans=1ll*ans*i%mod;
        printf("%d\n",ans);
        return 0;
    }
    for(int i=1;i<=n;++i) F[i]=i;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j&&a[i]%a[j]==0)
                merge(i,j);
    for(int i=1;i<=n;++i)
        if(ff(i)==i) Ans[++cnt]=solve(i);
    C[0][0]=1;
    for(int i=1;i<=n;++i) {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    int pos=0,ans=1;
    for(int i=1;i<=cnt;++i) 
        ans=1ll*ans*Ans[i].sc%mod*C[pos+Ans[i].fi][Ans[i].fi]%mod,
        pos+=Ans[i].fi;
    printf("%d\n",ans);
    return 0;
}