#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define fi first
#define sc second
#define mkp make_pair
#define pii pair<int,int>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=25,M=(1<<20)+5,K=40000,oo=1e9;
inline int read() {
    int x=0;int flag=0;char ch=getchar();
    while(ch<'0'||ch>'9') {flag|=(ch=='-');ch=getchar();}
    while('0'<=ch&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return flag?-x:x;
}
inline int mx(int x,int y) {return x>y?x:y;}
inline int mn(int x,int y) {return x<y?x:y;}
inline void swp(int &x,int &y) {x^=y^=x^=y;}
inline int as(int x) {return x>0?x:-x;}

int n,st[N],dp[M];
ll a[N];
inline vector<ll> getq(int L,int R) {
    if(L>R) return vector<ll>{0}; 
    vector<ll> now,now1,now2; now.clear();
    now1=now2=getq(L+1,R);
    for(ll &now:now1) now+=a[st[L]];
    for(ll &now:now2) now-=a[st[L]];
    int len=now1.size(),l=0,r=0;
    now.resize(len<<1);
    while(l<len&&r<len) {
        if(now1[l]<now2[r]) now[l+r]=now1[l],++l;
        else now[l+r]=now2[r],++r;
    }
    while(l<len) now[l+r]=now1[l],++l;
    while(r<len) now[l+r]=now2[r],++r;
    return now;
}
inline bool check(int S) {
    int sum=0,sz=0;
    for(int i=0;i<n;++i)
        if((S>>i)&1) sum+=a[i+1],st[++sz]=i+1;
    if(sz==1) return !sum;
    if((sum&1)^((sz-1)&1)) return 0;
    int mid=(sz+1)/2;
    vector<ll> L=getq(1,mid),R=getq(mid+1,sz);
    // printf("%d:\n",S);
    int ccnd=1+(abs(sum)<sz)*2;
    int l1=L.size(),l2=R.size(); R.push_back(1e18);
    for(int i=0,vl=l2,vr=l2;i<l1;++i) {
        while(vr>=0&&L[i]+R[vr]>=sz) --vr;
        while(vl>=0&&L[i]+R[vl]>-sz) --vl; ++vl;
        ccnd-=mn(ccnd,vr-vl+1);
    }
    return !ccnd;
}
int main() {
    n=read();
    for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
    for(int i=1;i<(1<<n);++i) if(!dp[i]&&check(i)) {
        int lst=((1<<n)-1)^i;
        for(int j=lst;;j=(j-1)&lst) {
            dp[i|j]=mx(dp[i|j],dp[j]+1);
            if(!j) break;
        }
    }
    printf("%d\n",n-dp[(1<<n)-1]);
    return 0;
}
