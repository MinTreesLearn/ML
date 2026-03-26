// LUOGU_RID: 99819798
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
#define N 85
#define K 15
ll n,m,k,ans=0,x,y,l,r,s,z;
ll f[K][N];
ll col[N];
ll e[N][N];
ll cnt=0;
template<typename T>inline void read(T &n){
	T w=1; n=0; char ch=getchar();
	while (!isdigit(ch) && ch!=EOF){ if (ch=='-') w=-1; ch=getchar(); }
	while (isdigit(ch) && ch!=EOF){ n=(n<<3)+(n<<1)+(ch&15); ch=getchar(); }
	n*=w;
}
template<typename T>inline void write(T x){
	if (x==0){ putchar('0'); return ; }
	T tmp;
	if (x>0) tmp=x;
	else tmp=-x;
	if (x<0) putchar('-');
	char F[105];
	long long cnt=0;
	while (tmp){
		F[++cnt]=tmp%10+48;
		tmp/=10;
	}
	while (cnt) putchar(F[cnt--]);
}
struct Suiji{
	#define R ((ll)rand())
	Suiji(){
		srand((unsigned)time(NULL));
		return ;
	}
	ll rrr(){
		return R*R*R*R+R*R*R+R*R+R;
	}
	ll M(ll l,ll r){
		ll ans,mod;
		ans=rrr();
		mod=r-l+1;
		ans=(ans%mod+mod)%mod;
		return ans+l;
	}
}suiji;
#define M(l,r) (suiji.M(l,r))
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    ll i,j,p;
    read(n); read(k);
    for (i=1; i<=n; i++){
    	for (j=1; j<=n; j++){
    		read(e[i][j]);
		}
	}
	cnt=5000;
	ans=inf;
	while (cnt--){
		for (i=1; i<=n; i++) col[i]=M(0,1);
		memset(f,0x3f,sizeof(f));
		f[0][1]=0;
		for (i=1; i<=k; i++){
			for (j=1; j<=n; j++){
				for (p=1; p<=n; p++){
					if (col[j]==col[p]) continue;
					f[i][j]=min(f[i][j],f[i-1][p]+e[p][j]);
				}
			}
		}
		s=f[k][1];
		ans=min(ans,s);
	}
	write(ans);
    return 0;
}