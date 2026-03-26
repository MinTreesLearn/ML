#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define mod (998244353)
#define eps (1e-8)
#define mk make_pair
#define tim (double)clock()/CLOCKS_PER_SEC
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,a,b) for(int i=(a);i>=(b);--i)
inline namespace IO{
	inline int read(){
		int x=0,f=1;char ch;
		while((ch=getchar())<'0'||x>'9')if(ch=='-')f=-1;
		while(ch>='0'&&ch<='9'){x=((x<<1)+(x<<3)+(ch^48)),ch=getchar();}
		return x*f;
	}
	void write(char x){putchar(x);}
	void write(const char *x){for(;*x;++x)putchar(*x);}
	void write(char *x){for(;*x;++x)putchar(*x);}
	void write(signed x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10); putchar('0'+x-x/10*10);
	}
	void write(long long x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10); putchar('0'+x-x/10*10);
	}
	void write(unsigned long long x){
		if(x>9)write(x/10);
		putchar('0'+x-x/10*10);
	}
	void write(double x){printf("%0.9lf",x);}
	template<typename type1,typename type2,typename ...typen>
	void write(type1 a1,type2 a2,typen ...an){
		write(a1);
		write(a2,an...);
	}
}using namespace IO;
inline int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
inline int lcm(int x,int y){return x/gcd(x,y)*y;}
inline int lowbit(int x){return x&(-x);}
mt19937 rnd(time(NULL)^clock());
inline int rad(int x,int y){return rnd()%(y-x+1)+x;}
const int N=105;
int n,k;
int a[N][N];
int c[N];
int dis[N][12],vis[N][12];
int ans=1e18;
queue<pair<int,int>> q;
inline void spfa(int s){
	while(!q.empty())q.pop();
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push(mk(s,0)); vis[s][0]=1,dis[s][0]=0;
	while(!q.empty()){
		int x=q.front().first,t=q.front().second; q.pop();
		vis[x][t]=0;
		if(t==k)continue;
		For(y,1,n)if(c[x]!=c[y]&&y!=x){
			int w=a[x][y];
			if(t+1==k&&y==1)ans=min(ans,dis[x][t]+w);
			if(dis[y][t+1]>dis[x][t]+w){
				dis[y][t+1]=dis[x][t]+w;
				if(!vis[y][t+1]){vis[y][t+1]=1;q.push(mk(y,t+1));}
			}
		}
	}
}
signed main()
{
	n=read(),k=read();
	For(i,1,n)For(j,1,n)a[i][j]=read();
	For(t,1,5000){
		For(i,1,n)c[i]=rad(0,1);
		spfa(1);
	}
	write(ans,'\n');
	return 0;
}
/*
*/




