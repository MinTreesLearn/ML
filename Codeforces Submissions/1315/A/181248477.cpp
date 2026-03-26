#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
using ll = long long int;
using pii = pair<int, int>;
#ifndef ONLINE_JUDGE
#define deb(...) logger(__LINE__, #__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(int line, string vars, Args&&... values) {
	cout << line << ": ";
	cout << vars << " = ";
	string delim = "";
	(..., (cout << delim << values, delim = ", "));
	cout << "\n";
}
#else
#define deb(...) 0
#endif
 
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		int max_w = max(x, a - x - 1);
		int max_h = max(y, b - y - 1);
		cout << max(max_w * b, max_h * a) << "\n";
	}
	return;
}
int main() {
	cin.tie(0)->sync_with_stdio(false);
	solve();
	cout.flush();
	return 0;
}