// LUOGU_RID: 102636546
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
}inline void dread(){}template<class T1,class ...T2>
inline void dread(T1 &a,T2&...b){
    register double w=0;register ll x=0,base=1;
    register bool f=false;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    w=(f?-x:x);if(ch!='.') return a=w,dread(b...);x=0,ch=getchar();
    while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),base*=10,ch=getchar();
    register double tmp=(double)(x/(double)base);w=w+(double)(f?-tmp:tmp);a=w;dread(b...);
}template<class T>void cmax(T &x,T y){if(x<y) x=y;}template<class T>void cmin(T &x,T y){if(x>y) x=y;}
template<class T> T qmax(T x,T y){return x>y?x:y;}
template<class T,class ...Arg> T qmax(T x,T y,Arg ...arg){return qmax(x>y?x:y,arg...);}
template<class T> T qmin(T x,T y){return x<y?x:y;}
template<class T,class ...Arg> T qmin(T x,T y,Arg ...arg){return qmin(x<y?x:y,arg...);}
template<class T> T randint(T l,T r){static mt19937 eng(time(0));uniform_int_distribution<T>dis(l,r);return dis(eng);}
const int MAXN=5e5+7;
int T,n,a[MAXN],m;set<int>s[MAXN];map<set<int>,int>mp;
signed main(){
    qread(T);int i,j;
    while(T--){
        qread(n,m);for(i=1;i<=n;i++) qread(a[i]),s[i].clear();mp.clear();
        for(i=1;i<=m;i++){
            int u,v;qread(u,v);
            s[v].emplace(u);
        }for(i=1;i<=n;i++) if(!s[i].empty()) mp[s[i]]+=a[i];int ans=0;
        for(auto i:mp){
            if(!ans) ans=i.second;else ans=__gcd(ans,i.second);
        }printf("%lld\n",ans);
    }
    #ifndef ONLINE_JUDGE
    cerr<<"Time: "<<clock()<<endl;
    system("pause > null");
    #endif
    return 0;
}