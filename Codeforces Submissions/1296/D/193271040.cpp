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
int w[N];

void solve() {  
    n=read();
    int a=read(),b=read();
    k=read();
    
    for(int i=1;i<=n;i++) w[i]=read();
    
    vector<int> res;
    int ans=0;
    int p=a+b;
    for(int i=1;i<=n;i++) {
        if(w[i]%p==0) {
            int s=b/a+(b%a!=0);
            res.push_back(s);
        }else if(w[i]%p-a<=0) ans++;
        else {
            int s=w[i]%p-a;
            int t=s/a+(s%a!=0);
            res.push_back(t);
        }
    }
    
    sort(res.begin(),res.end());
    
    for(int i=0;i<res.size();i++) {
        if(k>=res[i]) {
            k-=res[i];
            ans++;
        }else break;
    }
    
    printf("%d\n",ans);
}

int main() {
    // init();
    // stin();
    
    // scanf("%d",&T);
    T=1; 
    while(T--) solve();
    
    return 0;       
}          
	  	 				    	     	  				 	 	