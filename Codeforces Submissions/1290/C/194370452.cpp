/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mk make_pair
const int N = 301234;
vector <int> a[N], b[N];
int w[N], force[N], ans[N][2], all;
bool f[N], s[N];

int get (int v) {
	if (force[v] == 2) {
		return min(ans[v][0], ans[v][1]);
	} else {
		return ans[v][force[v]];
	}
}

void merge (int u, int v, bool we) {
	u = w[u], v = w[v];
	if (u == v)
		return;
	all -= get(u);
	all -= get(v);
	if (a[u].size() > a[v].size()) 
		swap (u, v);
	if (force[u] != 2) {
		force[v] = force[u] ^ we;
	}
	for (int x : a[u]) {
		a[v].push_back(x);
		f[x] ^= we;
		ans[v][f[x]]++;
		w[x] = v;
	}
	all += get(v);
}

int32_t main () {
	for (int i = 0; i < N; i++) {
		w[i] = i;
		a[i] = {i};
		f[i] = 0;
		force[i] = 2;
		ans[i][0] = 1;
	}
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		s[i] = (c - '0');
	}
	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		while (c--) {
			int x;
			cin >> x;
			x--;
			b[x].push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i].size() == 0) {
		} else if (b[i].size() == 1) {
			int v = b[i][0];
			all -= get(w[v]);
			force[w[v]] = s[i] ^ f[v];
			all += get(w[v]);
		} else {
			int u = b[i][0], v = b[i][1];
			int w = f[u] ^ f[v] ^ s[i] ^ 1;
			merge (u, v, w);
		}
		cout << all << '\n';
	}
}
