// Problem: D. Reachable Strings
// Contest: Codeforces - Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// URL: https://codeforces.com/contest/1320/problem/D
// Memory Limit: 256 MB
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
	cout << (ok?"Yes":"No") << '\n';
}
const int N = 1<<18;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	string s;
	cin >> n;
	cin >> s;
	vector<int> zeros;
	bitset<N> zero_bitset[2];
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') {
			zero_bitset[0][zeros.size()] = i & 1;
			zeros.push_back(i);
		}
	}
	zero_bitset[1] = ~zero_bitset[0];
	auto count = [&](int l, int r) {//zeros in [l; r)
		return lower_bound(all(zeros), r) - lower_bound(all(zeros), l);
	};
	int q, a, b, len;
	cin >> q;
	while(q--) {
		cin >> a >> b >> len;
		a--, b--;
		int z1 = count(a, a + len);
		int z2 = count(b, b + len);
		int s1 = count(0, a);
		int s2 = count(0, b);
		if(z1 != z2) report(0);
		else {
			int mismatch = ((zero_bitset[0] >> s1) ^
						(zero_bitset[(a^b)&1] >> s2))._Find_first();
			report(mismatch >= z1);
		}
	}
}
