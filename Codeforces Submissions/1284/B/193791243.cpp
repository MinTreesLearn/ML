#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<unordered_map>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<stack>
#include<ctime>
#define forin(i,a,n) for(int i=a;i<=n;i++)
#define forni(i,n,a) for(int i=n;i>=a;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
const double eps=1e-7;
const int N=2e5+7 ,M=2*N , INF=0x3f3f3f3f,mod=1e9+7;
inline ll read() {ll x=0,f=1;char c=getchar();while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
while(c>='0'&&c<='9') {x=(ll)x*10+c-'0';c=getchar();} return x*f;}
void stin() {freopen("in_put.txt","r",stdin);freopen("my_out_put.txt","w",stdout);}

template<typename T> T gcd(T a,T b) {return b==0?a:gcd(b,a%b);}
template<typename T> T lcm(T a,T b) {return a*b/gcd(a,b);}

int T;
int n,m,k;
struct Node{
    int fi,se;
    bool flag;
    bool operator < (const Node &k) const {
        if(fi!=k.fi) return fi<k.fi;
        else return se<k.se;
    }
};
Node w[N];
int sum[N];

void solve() {  
    n=read();
    
    int res=0;
    for(int i=1;i<=n;i++) {
        m=read();
        int maxn=-1,minn=INF;
        bool flag=false;
        int last;
        for(int j=1;j<=m;j++) {
            int c=read();
            if(j==1) last=c;
            else if(j>=2) {
                if(c>last) flag=true;
                last=min(last,c);
            }
            maxn=max(maxn,c);
            minn=min(minn,c);
        }
        if(flag) res++;
        w[i]={minn,maxn,flag};
    }
    
    sort(w+1,w+1+n);
    
    for(int i=1;i<=n;i++) {
        if(w[i].flag) sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1];
    }
    
    ll ans=0;
    for(int i=1;i<=n;i++) {
        if(w[i].flag) {
            ans+=(ll)n;
            continue;
        }
        int l=0,r=n;
        while(l<r) {
            int mid=l+r+1>>1;
            if(w[mid].fi<w[i].se) l=mid;
            else r=mid-1;
        }
        
        ans+=(ll)l-sum[l]+res;
    }
    
    printf("%lld\n",ans);
}

int main() {
    // init();
    // stin();
        
    // scanf("%d",&T);
    T=1; 
    while(T--) solve();
    
    return 0;       
}          