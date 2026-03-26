//Je Cruis En Moi
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+ 10;
int a[MAXN], mn[MAXN],mx[MAXN];

int main () {
	int t;
	cin >> t;
	while (t --) {
		long long x, y, a, b;
		cin >> x >> y >> a >> b;
		if ((y - x) % (a + b) == 0)
			cout << (y - x) / (a + b) << endl;
		else
			cout << -1 << endl;
	}
} 
