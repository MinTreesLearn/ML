#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1010;
const ll inf = 2000000000000000000ll;
struct str {
int l,r,lg;
void L() {lg=r-l+1;}
}w[maxn*maxn];int tmp,w0;
char S[maxn];int n,m,g[maxn][maxn];ll K,f[maxn][maxn],s[maxn][maxn];
bool operator <(str x,str y) {
tmp=min(min(x.lg,y.lg),g[x.l][y.l]);
if(tmp==x.lg&&tmp==y.lg) return x.l<y.l;
if(tmp==x.lg) return 1;
if(tmp==y.lg) return 0;
return S[x.l+tmp]<S[y.l+tmp];
}
bool operator <=(str x,str y) {return x<y||(x.l==y.l&&x.r==y.r);}
ll isok(str mid) {
memset(f,0,sizeof(f)),memset(s,0,sizeof(s)),s[n+1][0]=f[n+1][0]=1;
for(int i=n;i;i--) {
int k=n;while(k>=i&&mid<(str){i,k,k-i+1}) --k;++k;
for(int j=0;j<=m;j++) {
s[i][j]+=s[i+1][j]+(j?f[i][j]=s[k+1][j-1]:0);
if(s[i][j]>inf) s[i][j]=inf;
}
}return f[1][m];
}
signed main() {
scanf("%d%d%lld%s",&n,&m,&K,S+1);
for(int i=n;i;i--)
for(int j=1;j<=n;j++) if(S[i]==S[j]) g[i][j]=g[i+1][j+1]+1;
for(int i=1;i<=n;i++)
for(int j=i;j<=n;j++) w[++w0]=(str){i,j},w[w0].L();
sort(w+1,w+1+w0);
int l=1,r=w0,mid,ans=-1;
while(l<=r)
if(isok(w[mid=l+r>>1])<K) r=(ans=mid)-1;
else l=mid+1;
assert(ans!=-1);
for(int i=w[ans].l;i<=w[ans].r;i++) cout<<S[i];
return 0;
}