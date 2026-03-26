#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mp make_pair
#define inf 1e9
#define pii pair <int, int>
const int mod = 1e9 + 7;
int read () {
	int x = 0, f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar ();
	}
	return x * f;
}
void write (int x) {
	if (x < 0) x = -x, putchar ('-');
	if (x >= 10) write (x / 10);
	putchar (x % 10 + '0');
}
int quickmod (int x, int y) {
	int Ans = 1;
	while (y) {
		if (y & 1) Ans = (Ans * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return Ans;
}
int n;
int a[25];
int cnt[(1<<20)+5], sum[(1<<20)+5];
int Abs(int x) {
    if(x > 0) return x;
    return -x;
}
int f[(1<<20)+5], g[(1<<20)+5];
signed main () {
//	freopen (".in", "r", stdin);
//	freopen (".out", "w", stdout);
    n = read();
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        if(!a[i]) i--, n--;
    }
    for(int S = 0; S < (1 << n); S++) for(int i = 1; i <= n; i++) cnt[S] += (S >> (i - 1) & 1), sum[S] += (S >> (i - 1) & 1) * a[i];
    for(int S = 1; S < (1 << n); S++) {
        f[S] = 0;
        if((sum[S] & 1) == (cnt[S] & 1)) continue;
        for(int S2 = (S & (S - 1)); S2 && !f[S]; S2 = (S & (S2 - 1))) {
            if(Abs(sum[S2] - sum[S2^S]) < cnt[S]) f[S] = 1;
        }
    }
    for(int S = 1; S < (1 << n); S++) {
        if(!g[S] && f[S]) {
            g[S] = 1;
            int t = (((1 << n) - 1) ^ S);
            for(int S2 = t; S2; S2 = t & (S2 - 1)) {
                if(g[S2|S] < f[S] + g[S2]) {
                    g[S2|S] = f[S] + g[S2];
                }
            }
        }
    }
    write(n - g[(1<<n)-1]), putchar('\n');
	return 0;
}
/*
20
526805827792 2946441309935 2619096608386 9462003520606 829843147948 5909009666920 2206445867397 3851452239345 6154793167158 1650033916993 6214706573505 3819943114210 1014716803427 768188477266 1627392133013 400808866999 5142425094925 1819004093493 5772426450305 6635878556611


f[i|j]=min{f[i]+f[j]}
*/