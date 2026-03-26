#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;

template<typename T>inline void read(T&num){
    int f=1,ch=getchar();num=0;
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){num=num*10+(ch^48);ch=getchar();}
    num=num*f;
}
template<typename T>void print(T x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)print(x/10);
    putchar(x%10+48);
}

const int MAXN=82,MAXK=12,INF=0x3f3f3f3f;
int dis[MAXN][MAXN],n,k,dp[MAXK][MAXN],col[MAXN],ans=INF;
template<typename T>inline void Min(T&a,T b){if(a>b)a=b;}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    for(int i=1;i<=n;i++)col[i]=rng()%2;
    for(int i=0;i<=k;i++)for(int j=1;j<=n;j++)dp[i][j]=INF;
    dp[0][1]=0;
    for(int i=0;i<k;i++){
        for(int j=1;j<=n;j++){
            if(dp[i][j]==INF)continue;
            for(int K=1;K<=n;K++){
                if(col[j]==col[K])continue;
                Min(dp[i+1][K],dp[i][j]+dis[j][K]);
            }
        }
    }
    Min(ans,dp[k][1]);
}

int main(){
    read(n);read(k);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)read(dis[i][j]);
    while((double)clock()/CLOCKS_PER_SEC<=2.55)solve();
    cout<<ans<<'\n';
    return 0;
}
