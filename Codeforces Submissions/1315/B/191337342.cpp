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
const int N=1e5+7 ,M=2*N , INF=0x3f3f3f3f,mod=1e9+7;
inline ll read() {ll x=0,f=1;char c=getchar();while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
while(c>='0'&&c<='9') {x=(ll)x*10+c-'0';c=getchar();} return x*f;}
void stin() {freopen("in_put.txt","r",stdin);freopen("my_out_put.txt","w",stdout);}

template<typename T> T gcd(T a,T b) {return b==0?a:gcd(b,a%b);}
template<typename T> T lcm(T a,T b) {return a*b/gcd(a,b);}

int T;
int n,m,k;
char str[N];
PII w[N];

void solve() {  
    int a=read(),b=read(),p=read();
    
    scanf("%s",str+1);
    n=strlen(str+1);
    
    memset(w,0,sizeof(PII)*(n+4));
    
    for(int i=n-1;i>=1;i--) {
        if(str[i]==str[i+1]&&i!=n-1) w[i]=w[i+1];
        else {
            if(str[i]=='A') w[i].first=w[i+1].first+1,w[i].second=w[i+1].second;
            else w[i].fi=w[i+1].fi,w[i].se=w[i+1].se+1;
        }
    } 
    
    int i=1;
    while(i<n&&(ll)w[i].fi*a+(ll)w[i].se*b>p) i++;
    printf("%d\n",i);
}

int main() {
    // init();
    // stin();
    
    scanf("%d",&T);
    // T=1; 
    while(T--) solve();
    
    return 0;       
}          
	  	 			 		  	  	 	 	  	   	 		