////#include<tr1/unordered_map>
////using namespace std::tr1;
#include<bits/stdc++.h>
// #define fastcall __attribute__((optimize("-O3")))
// #pragma GCC optimize(1)
// #pragma GCC optimize(2)
// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-fhoist-adjacent-loads")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define db double
#define il inline
#define re register
#define ldb long db
#define ll long long
#define ui unsigned int
#define ull unsigned ll
#define fi first
#define se second
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pii pair<int,int>
#define MP(x,y) make_pair(x,y)
#define lowbit(x) ((x)&(~(x)+1))
#define iL (1<<20)
#define TEM template<class T>il void
#define Write(x,LC) write((x)),*iter++=LC
#define Writeneg(x,LC) writeneg((x)),*iter++=LC
#define flush() fwrite(Out,1,iter-Out,stdout),iter=Out
#define gc() ((iS==iT)?(iT=(iS=ibuf)+fread(ibuf,1,iL,stdin),(iS==iT)?EOF:*iS++):*iS++)
using namespace std;
namespace IO{
	char ibuf[iL],*iS=ibuf+iL,*iT=ibuf+iL,Out[iL],*iter=Out;
	TEM Readneg(re T &x){re char c;re bool f;for(f=false,c=getchar();!isdigit(c);f|=c=='-',c=getchar());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getchar());if(f)x=~x+1;}
	TEM readneg(re T &x){re char c;re bool f;for(f=false,c=gc();!isdigit(c);f|=c=='-',c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());if(f)x=~x+1;}
	TEM writeneg(re T x){if(x<0)*iter++='-',x=~x+1;re T c[35],l;for(l=0;!l || x;c[l]=x%10,++l,x/=10);for(;l;--l,*iter++=c[l]+'0');flush();}
	TEM Read(re T &x){re char c;for(c=getchar();!isdigit(c);c=getchar());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getchar());}
	TEM read(re T &x){re char c;for(c=gc();!isdigit(c);c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());}
	TEM write(re T x){re T c[35],l;for(l=0;!l||x;c[l++]=x%10,x/=10);for(;l;*iter++=c[--l]+'0');flush();}
}
using namespace IO;
#define MAXL 21
#define MAXB 405
#define MAXA 2750135
#define MAXN 200005
#define MAXC 100005
#define MAXM 45
#define MAXQ 500005
#define MAXK 500005
#define MAXS 500005
#define MAXT 500005
#define mod 998244353
#define inv2 499122177
#define BS 1919810
#define mod1 1000000007
#define mod2 1000000009
#define begT 114514
#define endT 1e-10
#define chgT 0.9260871
const ll M[2]={1000000007,1000000009};
int n,m,cnt[MAXN][2][2];char s[MAXN];
int C[2][2][2],P[MAXN];ll hs[2][MAXN],bs[2][MAXN],Hsh[2][2][MAXN];
il ll HS(int id,int l,int r){return (hs[id][r]+M[id]-hs[id][l-1]*bs[id][r-l+1]%M[id])%M[id];}
il ll HSH(int k,int id,int l,int r){return (Hsh[k][id][r]+M[id]-Hsh[k][id][l-1]*bs[id][r-l+1]%M[id])%M[id];}
vector<pii>T;ll rnm[2][2];
il void WORK(){
  scanf("%d%s",&n,s+1),bs[0][0]=bs[1][0]=1;
  for(re int i=1;i<=n;++i)for(re int j=0;j<2;++j)bs[j][i]=bs[j][i-1]*131%M[j],hs[j][i]=(hs[j][i-1]*131+s[i])%M[j];
  for(re int i=1;i<=n;++i){
    for(re int j=0;j<2;++j)for(re int k=0;k<2;++k)cnt[i][j][k]=cnt[i-1][j][k];
    ++cnt[i][i&1][s[i]&15],P[i]=P[i-1];if(s[i]=='1'&&s[i-1]=='1')++P[i];
  }
  T.emplace_back(MP(0,0));for(re int i=1;i<=n;++i)if(s[i]=='0')T.emplace_back(MP(i,i&1));T.emplace_back(MP(n+1,1));
  for(re int i=1;i<T.size();++i)for(re int j=0;j<2;++j)for(re int k=0;k<2;++k)Hsh[k][j][i]=(Hsh[k][j][i-1]*131+(T[i].se^k))%M[j];
  scanf("%d",&m);
  for(re int i=0,x,y,w,lx,rx,ly,ry;i<m;++i){
    scanf("%d%d%d",&x,&y,&w);
    if(x&1){
      C[0][0][0]=cnt[x+w-1][0][0]-cnt[x-1][0][0];
      C[0][0][1]=cnt[x+w-1][0][1]-cnt[x-1][0][1];
      C[0][1][0]=cnt[x+w-1][1][0]-cnt[x-1][1][0];
      C[0][1][1]=cnt[x+w-1][1][1]-cnt[x-1][1][1];
    }
    else{
      C[0][0][0]=cnt[x+w-1][1][0]-cnt[x-1][1][0];
      C[0][0][1]=cnt[x+w-1][1][1]-cnt[x-1][1][1];
      C[0][1][0]=cnt[x+w-1][0][0]-cnt[x-1][0][0];
      C[0][1][1]=cnt[x+w-1][0][1]-cnt[x-1][0][1];
    }
    if(y&1){
      C[1][0][0]=cnt[y+w-1][0][0]-cnt[y-1][0][0];
      C[1][0][1]=cnt[y+w-1][0][1]-cnt[y-1][0][1];
      C[1][1][0]=cnt[y+w-1][1][0]-cnt[y-1][1][0];
      C[1][1][1]=cnt[y+w-1][1][1]-cnt[y-1][1][1];
    }
    else{
      C[1][0][0]=cnt[y+w-1][1][0]-cnt[y-1][1][0];
      C[1][0][1]=cnt[y+w-1][1][1]-cnt[y-1][1][1];
      C[1][1][0]=cnt[y+w-1][0][0]-cnt[y-1][0][0];
      C[1][1][1]=cnt[y+w-1][0][1]-cnt[y-1][0][1];
    }
    re bool flg=true;for(re int j=0;j<2;++j)for(re int k=0;k<2;++k)if(C[0][j][k]!=C[1][j][k])flg=false;if(!flg){printf("No\n");continue;}
    if(P[x+w-1]==P[x]&&P[y+w-1]==P[y]){
      if(HS(0,x,x+w-1)!=HS(0,y,y+w-1)||HS(1,x,x+w-1)!=HS(1,y,y+w-1))printf("No\n");
      else printf("Yes\n");continue;
    }
    lx=lower_bound(T.begin(),T.end(),MP(x,0))-T.begin(),rx=lower_bound(T.begin(),T.end(),MP(x+w,0))-T.begin()-1;
    ly=lower_bound(T.begin(),T.end(),MP(y,0))-T.begin(),ry=lower_bound(T.begin(),T.end(),MP(y+w,0))-T.begin()-1;
    if(lx>rx||ly>ry){printf("Yes\n");continue;}
    if(x&1){
      rnm[0][0]=HSH(0,0,lx,rx);
      rnm[0][1]=HSH(0,1,lx,rx);
    }
    else{
      rnm[0][0]=HSH(1,0,lx,rx);
      rnm[0][1]=HSH(1,1,lx,rx);
    }
    if(y&1){
      rnm[1][0]=HSH(0,0,ly,ry);
      rnm[1][1]=HSH(0,1,ly,ry);
    }
    else{
      rnm[1][0]=HSH(1,0,ly,ry);
      rnm[1][1]=HSH(1,1,ly,ry);
    }
    // printf("%d %d %d %d\n",lx,rx,ly,ry);
    // printf("%d %d %d %d\n",T[lx].fi,T[rx].fi,T[ly].fi,T[ry].fi);
    // for(re int i=lx;i<=rx;++i)printf("%d ",T[i].se);printf("\n");
    // for(re int i=ly;i<=ry;++i)printf("%d ",T[i].se);printf("\n");
    // if(HSH(0,lx,rx)!=HSH(0,ly,ry)||HSH(1,lx,rx)!=HSH(1,ly,ry))printf("No\n");else printf("Yes\n");
    for(re int j=0;j<2;++j)if(rnm[0][j]!=rnm[1][j])flg=false;
    printf(flg?"Yes\n":"No\n");
  }
}
int main(){
  re int T=1;for(re int i=0;i<T;++i)WORK();
}