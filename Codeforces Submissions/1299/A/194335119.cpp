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
int pre[N], suf[N], n, a[N]; 
signed main() {
//	freopen("1.in", "r", stdin);
	n = read();
	int pl = 0, ans = -1;
	rep(i, 1, n) a[i] = read(), pre[i] = pre[i - 1] | a[i];
	irep(i, n, 1) suf[i] = suf[i + 1] | a[i];
	rep(i, 1, n) {
		int x = a[i] - (a[i] & (pre[i - 1] | suf[i + 1]));
		if(x > ans) ans = x, pl = i;
	} 
	cout << a[pl] << ' ';
	rep(i ,1, n) if(i != pl) cout << a[i] << ' ';
	cout << '\n';
	return 0;
}
