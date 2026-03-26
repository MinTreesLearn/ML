#include<bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for(int i = (x), stOyny = (y); i <= stOyny; ++i)
#define irep(i, x, y) for(int i = (x), stOyny = (y); i >= stOyny; --i)
#define pb emplace_back
#define point pair<int, ll>
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

il point operator -(const point &p, const point &q) { return point(p.fi - q.fi, p.se - q.se); }
ll det(const point &p, const point &q) { return p.fi * q.se - p.se * q.fi; }
signed main() {
//	freopen("1.in", "r", stdin);
	int n = read();
	vector<point> st;
	ll sum = 0;
	st.pb(0, 0ll);
	rep(i, 1, n) {
		point cur = point(i, sum += read());
		while(st.size() >= 2 && det(cur - st.end()[-2], st.back() - st.end()[-2]) >= 0) st.pop_back();
		st.push_back(cur);
	}
	point last = st[0];
	for(let t : st) if(t.fi) {
		let cur = t - last;
		rep(i, last.fi + 1, t.fi) printf("%.11Lf\n", (long double)cur.se / cur.fi);
		last = t;
	}
	return 0;
}
