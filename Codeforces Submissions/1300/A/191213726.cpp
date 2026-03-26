// Problem: A. Non-zero
// Contest: Codeforces - Codeforces Round #618 (Div. 2)
// URL: https://codeforces.com/contest/1300/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 110;
int a[maxn];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sum = 0, cnt = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (!a[i]) ++cnt;
			sum += a[i];
		}
		if (sum + cnt == 0) {
			cout << cnt + 1 << endl;
		} else {
			cout << cnt << endl;
		}
	}
	
	return 0;
}