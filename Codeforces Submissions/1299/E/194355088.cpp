#include<bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for(int i = (x), stOyny = (y); i <= stOyny; ++i)
#define irep(i, x, y) for(int i = (x), stOyny = (y); i >= stOyny; --i)
#define pb emplace_back
#define pii pair<int, int>
#define vint vector<int>
#define fi first
#define se second
#define let const auto
#define il inline
#define ci const int
#define all(S) S.begin(), S.end()
int read() {
	int res = 0, flag = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') flag = -1; c = getchar(); }
	while(c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
	return res * flag;
}
using namespace std;
template<typename T>
il void tmax(T &x, const T y) { if(x < y) x = y; }
template<typename T>
il void tmin(T &x, const T y) { if(x > y) x = y; }
mt19937 rnd(time(0));
bool query(vint a) {
	cout << "? " << a.size() << ' ';
	for(int x : a) cout << x << ' ';
	cout << endl;
	bool res;
	cin >> res;
	return res;
}
int ans[805], n;
void print() {
	if(ans[1] > n / 2) rep(i, 1, n) ans[i] = n + 1 - ans[i];
	cout << "! ";
	rep(i, 1, n) cout << ans[i] << ' ';
	cout << endl;
	exit(0);
}

void solve(vint a, int n, int dep, int va) {
	if(!dep) return;
	vint nxt, gg;
	for(int x : a) {
		vint b;
		for(int y : a) if(y != x) b.pb(y);
		if(query(b)) ans[x] = va, gg.pb(x);
		else nxt.pb(x);
	}
	solve(nxt, n - 2, dep - 1, va + 1);
}

vint plac, value;
int m, mxS, sum[1024];
vint prime;
vector<pair<int, vint>> ma[4];
void init() {
	rep(s, 0, mxS) rep(i, 0, m - 1) if((s >> i) & 1) sum[s] += value[i];
	rep(xby, 0, 3) {
		const int mod = prime[xby];
		auto &nma = ma[xby];
		nma.resize(mod);
		rep(i, 0, mod - 1) nma[i].fi = i;
		shuffle(all(nma), rnd);
		rep(i, 0, mod - 2) {
			rep(s, 0, mxS) if(__builtin_popcount(s) == mod - 1 && sum[s] % mod == (mod - nma[i].fi) % mod) {
				rep(j, 0, m - 1) if((s >> j) & 1) nma[i].se.pb(plac[j]);
				break;
			}
		}
	}
}
int query(int x) {
	vint res(4);
	rep(xby, 0, 3) {
		int mod = prime[xby];
		let nma = ma[xby];
		res[xby] = nma.back().fi;
		rep(i, 0, mod - 2) {
			vint cur = nma[i].se;
			cur.pb(x);
			if(query(cur)) { res[xby] = nma[i].fi; break; }
		}
	}
	rep(i, 1, n) {
		bool ok = true;
		rep(j, 0, 3) if(i % prime[j] != res[j]) ok = false;
		if(ok) return i;
	}
	return -1;
}

signed main() {
	memset(ans, -1, sizeof(ans));
	cin >> n;
	vint a;
	rep(i, 1, n) a.pb(i);
	solve(a, n, n <= 70 ? (n >> 1) : (n > 420 ? 5 : 4), 1);

	int pl = 0;
	rep(i, 1, n) if(ans[i] == 1) { ans[pl = i] = n; break; }
	rep(i, 1, n) if(ans[i] > 1 && ans[i] < n) {
		if(query(vint({pl, i})) == (n + ans[i]) % 2) ans[i] = n + 1 - ans[i];
	}
	if(n <= 70) print();
	
	rep(i, 1, n) if(~ans[i]) plac.pb(i), value.pb(ans[i]);
	m = plac.size(), mxS = (1 << m) - 1;
	prime = vint{3, 5, 7};
	prime.pb(n <= 210 ? 2 : ((n <= 420) ? 4 : 8));
	init();
	
	rep(i, 1, n) if(ans[i] == -1) ans[i] = query(i);
	print();
	return 0;
}
