// LUOGU_RID: 92674887
#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define mod 998244353
#define ll long long
using namespace std;
template<class T>void read(T&x) {
	T f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
template<class T>void write(T x) {
	if(x<0)putchar('-'),x=-x;int s[20],top=0;
	while(s[++top]=x%10,x/=10);
	while(top)putchar(s[top--]+'0');putchar(' ');
}
template<class T,class...Ts>void write(T arg,Ts...args){write(arg);write(args...);}
template<class...Ts>void print(Ts...args){write(args...);putchar('\n');}
void cer(){cerr << '\n';}
template<class T,class...Ts>void cer(T arg,Ts...args){cerr << arg << ' ';cer(args...);}
namespace SHIK {
char _st;
int n,m,x[6],y[6];
ll f[31][21][21][21][21][2][2];
ll dfs(int d,int px,int nx,int py,int ny,int p,int q) {
	if(d == 30)return !px&&!nx&&!py&&!ny&&!p&&!q;
	if(~f[d][px][nx][py][ny][p][q])return f[d][px][nx][py][ny][p][q];
	int v = m>>d&1;ll res = 0;
	for(int s=0; s<1<<n; ++s) {
		int PX = px,NX = nx,PY = py,NY = ny;
		for(int i=1; i<=n; ++i)if(s>>i-1&1) {
			if(x[i] > 0)PX += x[i];else NX -= x[i];
			if(y[i] > 0)PY += y[i];else NY -= y[i];
		}
		if((PX&1) == (NX&1) && (PY&1) == (NY&1))
			res += dfs(d+1,PX>>1,NX>>1,PY>>1,NY>>1,(v==(PX&1))?p:!v,(v==(PY&1))?q:!v);
	}return f[d][px][nx][py][ny][p][q] = res%mod;
}
char _ed;
int main() {
	cerr << "Memory: " << ((&_st-&_ed)>>20) << '\n';
	read(n);read(m);
	for(int i=1; i<=n; ++i)read(x[i]),read(y[i]);
	memset(f,-1,sizeof(f));
	print((dfs(0,0,0,0,0,0,0)-1+mod)%mod);
	return 0;
}
}
int main(){SHIK::main();}