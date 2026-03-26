// Problem: B. Present
// Contest: Codeforces - Codeforces Round #626 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1322/problem/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	int ans = 0;
	for(int b = 25; b >= 0; b--) {
		vector<int> counts(1<<(b+1));
		for(auto &i : a) {
			i &= (1<<(b+1)) - 1;
			counts[i]++;
		}
		for(int i = 1; i < 1<<(b+1); i++) counts[i] += counts[i - 1];
		array<int, 4> bc;
		bc.fill(0);
		auto get = [&](int l, int r) {
			--l, --r;
			r = min(r, (1<<(b+1)) - 1);
			l = min(l, (1<<(b+1)) - 1);
			return (r < 0 ? 0 : counts[r]) - (l < 0 ? 0 : counts[l]);
		};
		for(auto i : a) {
			for(int v = 0; v < 4; v++) {//[v*2^b; (v+1)*2^b)
				int low = v<<b, high = (v+1)<<b;
				bc[v] += get(low - i, high - i);
			}
			bc[(i+i)>>b] -= 1;
		}
		int ones = bc[1] / 2 + bc[3] / 2;
		if(ones & 1) ans += 1<<b;
	}
	cout << ans << '\n';
	
}
