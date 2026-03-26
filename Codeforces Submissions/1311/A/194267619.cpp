#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (b > a) {
			int x = b - a;
			if (x % 2 == 0) {
				cout << 2 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
		else if (a == b) {
			cout << 0 << endl;
		}
		else if (a > b) {
			int r = a - b;
			if (r % 2 == 0) {
				cout << 1 << endl;
			}
			else {
				cout << 2 << endl;
			}
		}
	}
	return 0;
}