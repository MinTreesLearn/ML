// LUOGU_RID: 101284853
#include <bits/stdc++.h>
#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pair;
const double eps=1e-8;
const int inf=2139062143;
#ifdef ONLINE_JUDGE
static char buf[1000000],*p1=buf,*p2=buf,obuf[1000000],*p3=obuf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#endif
inline void qread(){}template<class T1,class ...T2>
inline void qread(T1 &a,T2&...b){
    register T1 x=0;register bool f=false;char ch=getchar();
    while(ch<'0') f|=(ch=='-'),ch=getchar();
    while(ch>='0') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    x=(f?-x:x);a=x;qread(b...);
}
inline void dread(){}template<class T1,class ...T2>
inline void dread(T1 &a,T2&...b){
    register double w=0;register ll x=0,base=1;
    register bool f=false;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    w=(f?-x:x);if(ch!='.') return a=w,dread(b...);x=0,ch=getchar();
    while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),base*=10,ch=getchar();
    register double tmp=(double)(x/(double)base);w=w+(double)(f?-tmp:tmp);a=w;dread(b...);
}
template<class T> T qmax(T x,T y){return x>y?x:y;}
template<class T,class ...Arg> T qmax(T x,T y,Arg ...arg){return qmax(x>y?x:y,arg...);}
template<class T> T qmin(T x,T y){return x<y?x:y;}
template<class T,class ...Arg> T qmin(T x,T y,Arg ...arg){return qmin(x<y?x:y,arg...);}
template<class T> T randint(T l,T r){static mt19937 eng(time(0));uniform_int_distribution<T>dis(l,r);return dis(eng);}
const int MAXN=57;
const int MAXM=2e4+7;
int n,m,k,b[MAXM],a[MAXN][MAXM],f[MAXN][MAXM];
struct Seg_tree{
    #define ls p<<1
    #define rs p<<1|1
    #define mid ((l+r)>>1)
    int tr[MAXM<<2],tag[MAXM<<2];
    inline void pup(int p){tr[p]=qmax(tr[ls],tr[rs]);}
    inline void f(int p,int l,int r,int k){tr[p]+=k;tag[p]+=k;}
    void pwn(int p,int l,int r){
        f(ls,l,mid,tag[p]);f(rs,mid+1,r,tag[p]);tag[p]=0;
    }void build(int a[],int p,int l,int r){
        tag[p]=0;if(l==r) tr[p]=a[l];
        else build(a,ls,l,mid),build(a,rs,mid+1,r),pup(p);
    }void upd(int p,int l,int r,int L,int R,int k){
        if(L<=l&&r<=R) f(p,l,r,k);
        else{
            pwn(p,l,r);if(L<=mid) upd(ls,l,mid,L,R,k);
            if(R>mid) upd(rs,mid+1,r,L,R,k);pup(p);
        }
    }int que(int p,int l,int r,int L,int R){
        if(L<=l&&r<=R) return tr[p];
        else{
            int res=0;pwn(p,l,r);
            if(L<=mid) res=que(ls,l,mid,L,R);
            if(R>mid) res=qmax(res,que(rs,mid+1,r,L,R));return res;
        }
    }
    #undef mid
}st[MAXN];int s[MAXN][MAXM],ans;
signed main(){
    qread(n,m,k);int i,j;for(i=1;i<=n;i++) for(j=1;j<=m;j++) qread(a[i][j]),s[i][j]=s[i][j-1]+a[i][j];
    for(j=1;j<=m-k+1;j++) f[1][j]=s[1][j+k-1]-s[1][j-1];
    for(i=2;i<=n;i++){
        for(j=1;j<=k;j++) b[j]=f[i-1][j]+s[i][j+k-1]-s[i][k];
        for(j=k+1;j<=m-k+1;j++) b[j]=f[i-1][j]+s[i][j+k-1]-s[i][j-1];
        st[i-1].build(b,1,1,m);f[i][1]=st[i-1].que(1,1,m,1,m-k+1)+s[i][k];
        // if(i==2){
        //     for(j=1;j<=m;j++) cout<<b[j]<<" ";cout<<endl;
        //     // cout<<b[j]<<" ";cout<<endl;
        //     cout<<st[i-1].que(1,1,m,1,m-k+1)<<" "<<s[i][k]<<endl;
        // }
        for(j=2;j<=m-k+1;j++){
            st[i-1].upd(1,1,m,qmax(1ll,j-k),j-1,a[i][j-1]);
            st[i-1].upd(1,1,m,j,j+k-1,-a[i][j+k-1]);
            f[i][j]=st[i-1].que(1,1,m,1,m-k+1)+s[i][j+k-1]-s[i][j-1];
        }
    }for(i=1;i<=m-k+1;i++) ans=qmax(ans,f[n][i]);printf("%lld\n",ans);
    // for(i=1;i<=n;i++){for(j=1;j<=m-k+1;j++) cout<<f[i][j]<<" ";cout<<endl;}
    #ifndef ONLINE_JUDGE
    cerr<<"Time: "<<clock()<<endl;
    system("pause > null");
    #endif
    return 0;
}