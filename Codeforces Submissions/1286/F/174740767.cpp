#include <cstdio>
#include <map>
#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <queue>
#include <stack>
#include <random>
#include <cstring>
#include <ctime>
#include <cmath>
#include <assert.h> 
using namespace std;
#define LL long long
#define pp pair<int,int>
#define mp make_pair 
#define ull unsigned long long
namespace IO{
    const int sz=1<<22;
    char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
    inline char gc(){
       // return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
        return getchar();
    }
    template<class T> void gi(T& x){
        x=0; int f=1;char c=gc();
        if(c=='-')f=-1;
        for(;c<'0'||c>'9';c=gc())if(c=='-')f=-1;
        for(;c>='0'&&c<='9';c=gc())
            x=x*10+(c-'0');
        x=x*f;
    }
    inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
    inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
    template<class T> void pi(T x,char c='\n'){
        if(x<0)pc('-'),x=-x;
        if(x==0) pc('0'); int t=0;
        for(;x;x/=10) p[++t]=x%10+'0';
        for(;t;--t) pc(p[t]); pc(c);
    }
    struct F{~F(){flush();}}f; 
}
using IO::gi;
using IO::pi;
using IO::pc;
const int mod=998244353;
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int dec(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1ll*x*y%mod;}
inline int qkpow(int a,int b){
    int ans=1,base=a%mod;
    while(b){
        if(b&1)ans=1ll*ans*base%mod;
        base=1ll*base*base%mod;
        b>>=1;
    }
    return ans;
}
int n,f[(1<<20)+5],sz[(1<<20)+5],f2[(1<<20)+5];
LL a[25],sum[(1<<20)+5];
signed main(){
    gi(n);
    for(int i=0;i<n;i++){
        gi(a[i]);
        if(!a[i])i--,n--;
    }
    for(int i=0;i<(1<<n);i++){
        int cnt=0;
        for(int j=0;j<n;j++)if((1<<j)&i)sz[i]++,sum[i]+=a[j],cnt+=(a[j]!=0);
    }
    for(int i=1;i<(1<<n);i++){
        for(int S=(i&(i-1));S;S=(S-1)&i){
            LL s=abs(sum[S]-sum[i^S]);
            if(s<sz[i]&&(sz[i]&1)!=(s&1)){
                f2[i]=1;
                break;
            }
        }
    }
    int all=(1<<n)-1;
    for(int s=1;s<(1<<n);s++){
        if(!f[s]&&f2[s]){
            f[s]=1;
            int sta=all^s;
            for(int t=sta;t;t=(t-1)&sta)
                f[s|t]=max(f[s|t],f[t]+1);
        }
    }
    printf("%d\n",n-f[(1<<n)-1]);
    return 0;
}
/*
错误的，偏激的，极右翼的，非马恩主义的，女权的，失败的，人民日报的，乐的！ 
文明之美看东方
*/