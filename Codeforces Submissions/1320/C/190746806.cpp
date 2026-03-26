// Problem: C. World of Darkraft: Battle for Azathoth
// Contest: Codeforces - Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// URL: https://codeforces.com/contest/1320/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
#define int long long
const int inf = 1ll<<31;
struct Seg {
	int n;
	vector<int> mx, add;
	Seg(vector<array<int, 2>> armor) {
		n = 1;
		while(n < armor.size()) n *= 2;
		mx.resize(2*n, -inf);
		add.resize(2*n, 0);
		for(int i = 0; i < armor.size(); i++)
			mx[n + i] = -armor[i][1];
		for(int i = n; i--;) {
			mx[i] = max(mx[2*i], mx[2*i+1]);
		}
	}
	void upd(int p) {
		while(p /= 2)
			mx[p] = max(mx[2*p], mx[2*p+1]) + add[p];
	}
	void update(int l, int r, int v) {
		int L = l + n, R = r + n;
		for(l = L, r = R; l < r; l>>=1, r>>=1) {
			if(l & 1) {
				mx[l] += v;
				add[l] += v;
				l++;
			}
			if(r & 1) {
				--r;
				mx[r] += v;
				add[r] += v;
			}
		}
		if(L < R) {
			upd(L);
			upd(R-1);
		}
	}
	int getMax() { return mx[1]; }
};
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m, p;
	cin >> n >> m >> p;
	vector<array<int, 2>> weapons(n);
	for(auto &[a, c] : weapons)
		cin >> a >> c;
	vector<array<int, 2>> armor(m);
	for(auto &[b, c] : armor)
		cin >> b >> c;
	vector<array<int, 3>> monsters(p);
	for(auto &[x, y, z] : monsters)
		cin >> x >> y >> z;
		
	sort(all(weapons));
	sort(all(armor));
	sort(all(monsters));
	
	Seg profit(armor);
	int m_ptr = 0, ans = -inf;
	for(auto [a, cost] : weapons) {
		while(m_ptr < monsters.size() &&
			monsters[m_ptr][0] < a) {
			int R = lower_bound(all(armor), array{monsters[m_ptr][1], inf}) - armor.begin();
			profit.update(R, armor.size(), monsters[m_ptr][2]);
			// cout << "Add " << m_ptr << " " << R << " " << monsters[m_ptr][2] << endl;
			m_ptr++;	
		}
		// cout << a << " " << profit.getMax() << endl;
		ans = max(ans, profit.getMax() - cost);
	}
	cout << ans << '\n';
}
