/*
	  author : evenbao
	  created : 2020 / 03 / 06
*/
#include<bits/stdc++.h>

using namespace std;

#ifndef LOCAL
	  #define eprintf(...) fprintf(stderr , _VA_ARGS)
#else
	  #define eprintf(...) 42
#endif

// define evenbao
#define PII pair<int , int>
#define FI first
#define SE second
#define MP make_pair

typedef long long LL;

const int N = 2e5 + 10;
const int mx = (1 << 18);

int n;
int cnt[mx] , p[mx] , rnk[mx];
LL ans;

template <typename T> inline void chkmax(T &x , T y) { x = max(x , y); }
template <typename T> inline void chkmin(T &x , T y) { x = min(x , y); }
template <typename T> inline void read(T &x) {
    T f = 1; x = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
    x *= f;
}

inline int get_root(int v) {
		return (p[v] == v) ? v : (p[v] = get_root(p[v]));
} 
inline int join(int u , int v) {
		u = get_root(u) ,
		v = get_root(v);
		if (u != v) {
				if (rnk[u] > rnk[v]) 
						swap(u , v);
				p[u] = v;
				if (rnk[u] == rnk[v])
						++rnk[v];
				return 1;
		} else return 0;
}

int main() {
 		
		read(n);
		for (int i = 0; i < n; ++i) {
				int val;
				read(val);
				ans -= val;
				++cnt[val];
		}
		iota(p , p + mx , 0);
		++cnt[0]; 
		for (int e = mx - 1; e >= 0; --e)
		for (int i = e; true; i = ((i - 1) & e)) {
				if (cnt[i] && cnt[e ^ i] && join(i , e ^ i)) {
						ans += (LL)(cnt[i] + cnt[e ^ i] - 1) * e; 
						cnt[i] = 1;
						cnt[i ^ e] = 1;
				}
				if (i == 0) break;
		}
		printf("%lld\n" , ans);
	  return 0; 
}