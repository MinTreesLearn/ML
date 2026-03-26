#include <bits/stdc++.h>
#define LL long long
#define uLL unsigned long long
#define N 500005
using namespace std;
uLL ans, v[N], rd[N], c[N];
int id[N];
mt19937_64 rdn(time(0));
int main(){
	int i, j, n, m, T, a, b;
	scanf("%d", &T);
	while(T--){
		unordered_map<uLL, uLL> f;
		ans = 0;
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n; i++) rd[i] = rdn(), scanf("%llu", &c[i]), v[i] = 0;
		for(i = 1; i <= m; i++){
			scanf("%d%d", &a, &b);
			v[b] ^= rd[a];
		}
		for(i = 1; i <= n; i++){
			if(!v[i]) continue;
			f[v[i]] += c[i];
		}
		for(auto u: f) ans = __gcd(ans, u.second);
		printf("%llu\n", ans);
	}
	return 0;
}
