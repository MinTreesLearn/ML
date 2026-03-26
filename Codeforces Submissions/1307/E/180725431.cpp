
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)

#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

const int P = 1e9 + 7;
inline int plu(int x, int y) {return x + y >= P ? x + y - P : x + y;}
inline int del(int x, int y) {return x - y <  0 ? x - y + P : x - y;}
inline void add(int &x, int y) {x = plu(x, y);}
inline void sub(int &x, int y) {x = del(x, y);}
inline int qpow(int a, int b) {int s = 1; for(; b; b >>= 1, a = 1ll * a * a % P) if(b & 1) s = 1ll * s * a % P; return s;}

char buf[1<<22],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}

const int N = 5010;
int n, m, s[N], c[N];
int p[N][N], q[N][N];

int cnt, head[N];
struct node {int nxt, v;} e[N];

int main() {
	n = read(), m = read();
	rep(i, 1, n) s[i] = read();
	rep(i, 1, n) rep(j, 1, n) p[i][j] = n + 1, q[i][j] = -1;
	rep(i, 1, n) p[s[i]][++ c[s[i]]] = i;
	rep(i, 1, n) c[i] = 0;
	per(i, n, 1) q[s[i]][++ c[s[i]]] = i;
	
	rep(i, 1, m) {int f = read(), h = read(); e[++ cnt] = (node) {head[f], h}, head[f] = cnt;} 
	
	vector<int> arc;
	rep(i, 1, n) if(head[i]) arc.emplace_back(i);
	
	int dat = 0, sum = 0;
	rep(t, 0, n) {
		
		int val = 0;
		int num[2]; num[0] = 1, num[1] = 0;
		int rec[2]; rec[0] = 1, rec[1] = 0;
		bool flag = false;
		
		for(int i : arc) {
			int f[3][2]; rep(a, 0, 2) rep(b, 0, 1) f[a][b] = 0; f[0][0] = 1;
			int d[3]; rep(b, 0, 2) d[b] = 0; d[0] = 1;
			int cntl = 0, cntr = 0, cnto = 0;
			Ede(x, i) {
				int o = e[x].v;
				int h[3][2]; 
				h[0][0] = f[0][0], h[0][1] = f[0][1];
				h[1][0] = f[1][0], h[1][1] = f[1][1];
				h[2][0] = f[2][0], h[2][1] = f[2][1];
				if(p[i][o] <= t) {
					cntl ++;
					add(f[1 + (p[i][o] == t)][0], h[0][0]);
					add(f[1 + (p[i][o] == t)][1], h[0][1]);
				}
				if(q[i][o] >  t) {
					cntr ++;
					add(f[0][1], h[0][0]);
					add(f[1][1], h[1][0]);
					add(f[2][1], h[2][0]);
					add(d[1 + (q[i][o] == t + 1)], 1);
				}
				if(p[i][o] <= t && q[i][o] > t) cnto ++;
			}
			int cur[2]; cur[0] = cur[1] = 0;
			int nxt[2]; nxt[0] = nxt[1] = 0;
			val += (cntl > 0) + (cntr > 0);
			
			rep(b, (cntr > 0), 2) add(nxt[b == 2], d[b]);
			
			if(cnto == 1 && cntl == 1 && cntr == 1) {
				val --;
				add(cur[0], f[0][1]);
				add(cur[0], f[1][0]);
				add(cur[1], f[2][0]);
			}
			else {
				flag |= (cntl > 0);
				if(cntl == 0) {
					if(cntr == 0) add(cur[0], f[0][0]); else add(cur[0], f[0][1]);
				}
				else {
					if(cntr == 0) add(cur[0], f[1][0]), add(cur[1], f[2][0]);
					else add(cur[0], f[1][1]), add(cur[1], f[2][1]);
				}
			}

			int pre[2]; pre[0] = num[0], pre[1] = num[1]; num[0] = num[1] = 0;
			int v = (1ll * (pre[0] + pre[1]) * cur[1] + 1ll * pre[1] * cur[0]) % P;
			add(num[1], v);
			add(num[0], 1ll * pre[0] * cur[0] % P);
			
			pre[0] = rec[0], pre[1] = rec[1]; rec[0] = rec[1] = 0;
			v = (1ll * plu(pre[0], pre[1]) * nxt[1] + 1ll * pre[1] * nxt[0]) % P;
			add(rec[1], v);
			add(rec[0], 1ll * pre[0] * nxt[0] % P);
		}
		
		if(! flag) add(num[1], rec[1]);
		if(val > dat) dat = val, sum = num[1]; else if(val == dat) add(sum, num[1]);
	}
	
	if(dat == 0) sum = 1;
	printf("%d %d\n", dat, sum);
	return 0;
}
