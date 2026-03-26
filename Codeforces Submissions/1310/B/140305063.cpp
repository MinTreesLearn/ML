#include <bits/stdc++.h>
 
using ul = std::uint32_t;
using li = std::int32_t;
using ull = std::uint64_t;
using ll = std::int64_t;
using lf = double;
using llf = long double;
using uss = std::uint8_t;
using us = std::uint16_t;

const ul maxn = 17;

li ans[1 << maxn][2][2];

bool sp[1 << maxn];

ul n, k;

const li inf = 1e9;

int main()
{
	std::scanf("%u%u", &n, &k);
	for (ul i = 1; i <= k; ++i) {
		ul a;
		std::scanf("%u", &a);
		sp[a - 1] = true;
	}
	for (ul i = 1; i != (1 << n); ++i) {
		for (ul s : {0, 1}) {
			for (ul t : {0, 1}) {
				ans[i][s][t] = -inf;
			}
		}
	}
	for (ul i = 0; i != (1 << n); i += 2) {
		ans[1 << n - 1 | i >> 1][sp[i]][sp[i + 1]] = std::max(ans[1 << n - 1 | i >> 1][sp[i]][sp[i + 1]], li(sp[i] || sp[i + 1]));
		ans[1 << n - 1 | i >> 1][sp[i + 1]][sp[i]] = std::max(ans[1 << n - 1 | i >> 1][sp[i + 1]][sp[i]], li(sp[i] || sp[i + 1]));
	}
	for (ul i = (1 << n - 1) - 1; i; --i) {
		for (ul ls : {0, 1}) {
			for (ul lt : {0, 1}) {
				if (ans[i << 1][ls][lt] == -inf) {
					continue;
				}
				for (ul rs : {0, 1}) {
					for (ul rt : {0, 1}) {
						if (ans[i << 1 | 1][rs][rt] == -inf) {
							continue;
						}
						li val = ans[i << 1][ls][lt] + ans[i << 1 | 1][rs][rt];
						for (ul a : {0, 1}) {
							if (a && ls == rs) {
								break;
							}
							li val1 = val + (ls || rs);
							ul ys = a ? ls : rs;
							ul ns = a ? rs : ls;
							for (ul b1 : {0, 1}) {
								if (b1 && lt == rt) {
									break;
								}
								li val2 = val1 + (lt || rt);
								ul yt = b1 ? lt : rt;
								for (ul b2 : {0, 1}) {
									if (b2 && ns == yt) {
										break;
									}
									li val3 = val2 + (ns || yt);
									ul yt2 = b2 ? ns : yt;
									ans[i][ys][yt2] = std::max(ans[i][ys][yt2], val3);
								}
							}
						}
					}
				}
			}
		}
	}
	std::printf("%d\n", std::max(std::max(ans[1][0][0], ans[1][0][1] + 1), std::max(ans[1][1][0] + 1, ans[1][1][1] + 1)));
	return 0;
}


