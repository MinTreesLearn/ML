//Author: Frustrated_EH
//Complexity: O(?)

#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int mod = 998244353;

namespace FastIO {
	template<typename T>inline T    read(){T x=0,w=1;char c=0;while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*w;}
	template<typename T>inline void write(T x){if(x<0){x=-x;putchar('-');}if(x>9)write(x/10);putchar(x%10+'0');}
	inline int                      getInt(){return read<int>();}
	inline int                      putInt(int x,char c){write<int>(x),putchar(c);return 0;}
} namespace Number_Theory {
	int  pw(int a,int b,int p=mod){int res=1;while(b){if(b&1)res=res*a%p;a=a*a%p;b>>=1;}return res;}
	int  gcd(int x,int y){return!y?x:gcd(y,x%y);}
	void exgcd(int a,int b,int&x,int&y){if(!b){x=1,y=0;return;}exgcd(b,a%b,y,x);y-=(a/b*x);}
	int  inv(int x,int p=mod){exgcd(x,p,x,*new int);return(x%p+p)%p;}
	int  bsgs(int a,int b,int p){map<int,int>val;int A=1,t=sqrt(p)+1;for(int i=0;i<t;i++){val[A*b%p]=i;A=A*a%p;}for(int i=1,_a=A;i<=t;i++){if(val[_a]&&val[_a]!=-1){int ans=i*t-val[_a];for(int i=0,A=1;i<t;i++){val[A*b%p]=-1;A=A*a%p;}return ans;}_a=_a*A%p;}return-1;}
} using namespace FastIO; using namespace Number_Theory;

const int N = 85;
int e[N][N], f[N], t[N];

int Solve() {
	srand(time(0));
	int n = getInt(), k = getInt();
	int res = mod;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) e[i][j] = getInt();
	for(int T = 1; T <= 5000; T++) {
		for(int j = 2; j <= n; j++) f[j] = mod, t[j] = rand() & 1;
		for(int i = 1; i <= k; i++) for(int j = 1; j <= n; j++) if((i & 1) == t[j]) {
			f[j] = mod;
			for(int k = 1; k <= n; k++) if((i & 1) != t[k]) f[j] = min(f[j], f[k] + e[k][j]);
		}
		res = min(res, f[1]);
		f[1] = 0;
	}
	putInt(res, '\n');
	return 0;
}

signed main() {
	int T = 1;
//	T = getInt();
	while(T--) Solve();
	return 0;
}

