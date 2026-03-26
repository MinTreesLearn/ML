// S2OJ Submission #67679 @ 1675132874448
#include <bits/stdc++.h>
#define int long long

const int N = 1e6 + 10;
int n;
char s[N];
int w[N];
std::map<int, int> cnt;
int q[N], top;
int nxt[N], anc[N];
int ans1, ans2;
__int128_t ans;
int sum;

void write(__int128_t x) {
	if (!x) return ;
	write(x / 10);
	putchar(x % 10 + '0');
}

signed main() {
	scanf("%lld", &n);
	nxt[1] = 0;
	getchar();
	s[1] = getchar();
	scanf("%lld", &w[1]);
	ans = w[1];
	ans1 = w[1] % 26, ans2 = w[1];
	q[top = 1] = 1;
	if (ans == 0) {
		puts("0");
	}
	else {
		write(ans);
		puts("");
	}
	for (int i = 2, j = 0; i <= n; ++i) {
		getchar();
		s[i] = getchar();
		scanf("%lld", &w[i]);
		s[i] = (s[i] - 'a' + ans1) % 26 + 'a';
		w[i] ^= ans2;
		while (j && s[j + 1] != s[i]) {
			j = nxt[j];
		}
		if (s[j + 1] == s[i]) ++j;
		nxt[i] = j;
		if (s[nxt[i - 1] + 1] == s[i]) {
			anc[i - 1] = anc[nxt[i - 1]];
		}
		else {
			anc[i - 1] = nxt[i - 1];
		}
		for (int k = i - 1; k > 0;) {
			if (s[k + 1] == s[i]) {
				k = anc[k];
			}
			else {
				int v = w[*std::lower_bound(q + 1, q + top + 1, i - k)];
				--cnt[v];
				sum -= v;
				if (cnt[v] == 0) cnt.erase(v);
				k = nxt[k];
			}
		}
		if (s[1] == s[i]) {
			++cnt[w[i]];
			sum += w[i];
		}
		while (top && w[i] <= w[q[top]]) {
			--top;
		}
		q[++top] = i;
		int num = 0;
		for (auto it = cnt.upper_bound(w[i]); it != cnt.end();) {
			sum -= 1ll * (it->first) * (it->second);
			num += it->second;
			auto jt = std::next(it);
			cnt.erase(it);
			it = jt;
		}
		cnt[w[i]] += num;
		sum += num * w[i];
		int res = w[q[1]] + sum;
		ans1 = (ans1 + res) % 26;
		ans2 = (ans2 + res) & ((1ll << 30) - 1);
		ans += res;
		if (ans == 0) {
			puts("0");
		}
		else {
			write(ans);
			puts("");
		}
	}
	return 0;
}