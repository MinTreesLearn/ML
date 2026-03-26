#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define per(i, a, b) for(int i = (a); i >= (b); i --)
#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
using namespace std;

#define eb emplace_back

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 1 << 18;
int n, k, ans, c[N], f[18][N], g[18][N];
vector<int> h[N];

int calc(int x) {
	int dat = c[x];
	x --, x >>= 2; int c = 1;
	while(c < n && g[c][x] < 1) c ++, x >>= 1;
	return (c - 1) * 2 - dat;
}

void inst(int x) {
	for(int o : h[x]) c[o] ++;
	x --, x >>= 2; int c = 1;
	while(c < n && g[c][x] < 1) g[c][x] ++, c ++, x >>= 1;
}

int main() {
	n = read(), k = read();
	rep(i, 1, k) {int x = read(); f[0][x - 1] = x;}
	rep(i, 0, n - 1) {
		int len = 1 << (n - i);
		
		// cerr << "current " << i << endl;
		// rep(j, 0, len - 1) cerr << f[i][j] << ' ';
		// cerr << "\nend" << endl;
		
		for(int j = 0; j < len; j += 2) {
			
			// cerr << "time " << j << endl;
			
			int x = f[i][j];
			int y = f[i][j + 1];
			
			ans += (x > 0 || y > 0);
			if(x > 0) {if(i > 0 && y > 0) h[y].eb(x); else if(i > 0) c[x] ++;}
			if(y > 0) {if(i > 0 && x > 0) h[x].eb(y); else if(i > 0) c[y] ++;}
			
			if(!x || !y) {f[i + 1][j >> 1] = x | y; continue;}
			
			int vx = calc(x);
			int vy = calc(y);
			
			// cerr << "this " << x << ' ' << vx << ' ' << c[x] << ' ' << y << ' ' << vy - c[y] << endl;
			
			if(vx <= vy) {
				f[i + 1][j >> 1] = x;
				inst(y), ans += max(0, vy);
			}
			else {
				f[i + 1][j >> 1] = y;
				inst(x), ans += max(0, vx);
			}
		}
		
		// cerr << "ans " << ans << endl;
	}
	
	// cerr << "pos " << f[n][0] << ' ' << calc(f[n][0]) << endl;

	int p = f[n][0];
	ans += (p > 0 || g[n - 1][0] > 0);
	if(p) ans += max(0, calc(p));
	printf("%d\n", ans);
	return 0;
}
