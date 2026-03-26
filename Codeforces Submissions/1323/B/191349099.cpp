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
const int N=6e5+7 ,M=2*N , INF=0x3f3f3f3f,mod=1e9+7;
inline ll read() {ll x=0,f=1;char c=getchar();while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
while(c>='0'&&c<='9') {x=(ll)x*10+c-'0';c=getchar();} return x*f;}
void stin() {freopen("in_put.txt","r",stdin);freopen("my_out_put.txt","w",stdout);}

template<typename T> T gcd(T a,T b) {return b==0?a:gcd(b,a%b);}
template<typename T> T lcm(T a,T b) {return a*b/gcd(a,b);}

int T;
int n,m,k;
int a[N],b[N];
int la[N],lb[N];

void solve() {  
    n=read(),m=read(),k=read();
    
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) b[i]=read();
    
    vector<int> vec;
    for(int i=1;i<=k/i;i++) {
        if(k%i==0) {
            vec.push_back(i);
            if(i!=k/i) vec.push_back(k/i);
        }
    }
    
    sort(vec.begin(),vec.end());
    
    int last=0;
    for(int i=1;i<=n;i++) {
        if(a[i]==1) last++;
        else {
            int temp=last;
            for(int j=1;j<=temp;j++) la[j]+=last--;
            last=0;
        }
    }
    
    if(last!=0) {
        int temp=last;
        for(int j=1;j<=temp;j++) la[j]+=last--;
    }
    
    last=0;
    for(int i=1;i<=m;i++) {
        if(b[i]==1) last++;
        else {
            int temp=last;
            for(int j=1;j<=temp;j++) lb[j]+=last--;
            last=0;
        }
    }
    
    if(last!=0) {
        int temp=last;
        for(int j=1;j<=temp;j++) lb[j]+=last--;
    }
    
    ll ans=0;
    for(int i=0;i<vec.size();i++) {
        int l=vec[i],r=k/vec[i];
        if(l>=1&&l<=n&&r>=1&&r<=m) {
            ans+=(ll)la[l]*lb[r];
        }
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
 			    		   		  	   		  	 		