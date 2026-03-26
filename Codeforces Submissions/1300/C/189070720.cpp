#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define endl '\n'
#define int long long
using namespace std;
int n, m;
int l, r;
int p;
int a[200010];
int b[200];
int t;

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	int smax = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int num = a[i];
		int k = 1;
		while (num) {
			if (num & 1) {
				b[k]++;
			}
			++k;
			num >>= 1;
			smax = max(smax, k);
		}
	}

	for (int i = 1; i <= n; i++) {
		int res = 0;
		int num = a[i];
		for (int j = 1; j <= smax; j++) {
			if ((num >> (j - 1) & 1) && b[j] == 1) {
				res += 1 << (j - 1);
			}
		}
		if (res > ans) {
			ans = res;
			t = i;
		}
	}
	if (t == 0) t = 1;
	swap(a[1], a[t]);
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

/*
1011
0110
0100
0000
*/


