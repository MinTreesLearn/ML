#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <random>
#include <set>
using namespace std;
#define fi first
#define sc second
#define mkp make_pair
#define pii pair<int,int>
typedef long long ll;
const int N=1e5+5,oo=1e8,mod=1e9+9;
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
inline int ok(int x) {return x>0?1:-1;}

int n,m,a[N],t[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=read();m=read();
    int lim=0;
    for(int i=1;i<=n;++i)
        lim+=(i-1)/2;
    if(lim<m) {
        printf("-1\n");
        return 0;
    }
    int p=1;
    for(p=1;p<=n;++p)
        if(m-(p-1)/2>=0) {
            m-=(p-1)/2;
            a[p]=p;
        } else break;
    for(int i=1;i<p;++i)
        for(int j=i+1;j<p;++j)
            ++t[i+j];
    for(int i=2*p;i>=1;--i)
        if(t[i]==m) {
            a[p]=i;
            break;
        }
    for(int i=p+1;i<=n;++i)
        a[i]=oo-(n-i)*10000;
    for(int i=1;i<=n;++i) printf("%d ",a[i]);
    return 0;
}
//yqmpo62327
//Ro5dPTkt