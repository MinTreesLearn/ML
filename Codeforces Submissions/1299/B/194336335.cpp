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
const int N = 1e5 + 20;
int n;
bool solve2(int *a) {
	int mid = n >> 1;
	vint p; 
	rep(i, 1, mid) p.pb(a[i] + a[i + mid]);
	for(int x : p) if(x != p[0]) return false;
	return true;
}
int a[2][N];
bool solve() {
	n = read();
	if(n & 1) return false;
	rep(i, 1, n) rep(op, 0, 1) a[op][i] = read();
	return solve2(a[0]) && solve2(a[1]);
}
signed main() {
//	freopen("1.in", "r", stdin);
	cout << (solve() ? "YES\n" : "NO\n");
	return 0;
}
