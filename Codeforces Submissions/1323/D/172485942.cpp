#include <algorithm>
#include <iostream>

using namespace std;

const int N = 400000;

int aa_[N], aa[N];
int n;

int query(int a) {
	int lower = -1, upper = n;
	while (upper - lower > 1) {
		int i = (lower + upper) / 2;
		if (aa[i] <= a)
			lower = i;
		else
			upper = i;
	}
	return lower + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> aa_[i];
	int ans = 0;
	for (int h = 0; h < 25; h++) {
		int m = 1 << h + 1;
		for (int i = 0; i < n; i++)
			aa[i] = aa_[i] % m;
		sort(aa, aa + n);
		int k = 0;
		for (int i = 0; i < n; i++) {
			int a = aa[i] % m;
			int l = ((1 << h) - a + m) % m;
			int r = l + (1 << h) - 1;
			if (r < m)
				k += query(r) - query(l - 1);
			else
				k += n - query(l - 1) + query(r - m);
			if ((a + a) % m >= 1 << h)
				k--;
		}
		k /= 2;
		if (k % 2)
			ans ^= 1 << h;
	}
	cout << ans << '\n';
	return 0;
}
